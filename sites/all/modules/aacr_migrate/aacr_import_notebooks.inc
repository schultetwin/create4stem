<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_import_notebooks
 *
 * @author mark
 */
class aacr_import_notebooks extends Migration{

  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));

    $this->description = t('Imports the old notebooks into the notes content type');

    $this->dependencies = array('aacr_users');
    
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select(AACR_SOURCE_DATABASE . '.node', 'n')
        ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'))
        ->condition('n.type', 'blog', '=');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $query->join(AACR_SOURCE_DATABASE . '.users', 'u', 'n.uid = u.uid');
    $query->join(AACR_SOURCE_DATABASE . '.og_uid', 'ogu', 'u.uid = ogu.uid AND ogu.nid = :nid AND ogu.is_active = :active', array(':nid' => 55, ':active' => 1));
    $query->leftjoin(AACR_SOURCE_DATABASE . '.og_access_post', 'oga', 'oga.nid = n.nid');
    $query->addField('oga', 'og_public');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.og_ancestry', 'oa', 'oa.nid = n.nid');
    $query->addField('oa', 'group_nid');
    $query->orderBy('n.nid', 'ASC');

    $source_fields = array(
      'nid' => t('The node ID of the page'),
      'url_alias' => t('The url alias of the node'),
      //'tags' => t('The terms for the node'),
      'file_upload' => t('File upload'),
      'file_upload_description' => t('File Upload Description'),
      'image_attach' => t('Images attached via the Image Assist Module in D6'),
    );

    $this->source = new MigrateSourceSQL($query, $source_fields);

    $this->destination = new MigrateDestinationNode('notes');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('uid', 'uid')->sourceMigration('aacr_users');
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('revision_uid', 'uid')->sourceMigration('aacr_users')->defaultValue(1);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('promote', 'promote')->defaultValue(0);
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('comment', 'comment');
    $this->addFieldMapping('path', 'url_alias');
    $this->addFieldMapping('group_audience', 'group_nid')->description(t('Importing all notebook entries of users, even if they
      don\'t exist in the AACR group'));
    $this->addFieldMapping('group_content_access', 'og_public')
        ->defaultValue(OG_CONTENT_ACCESS_PRIVATE)
        ->description(t('Defaults to private unless set to public on the old site'));
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format', 'format');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_notes_attachments', 'file_upload');
    $this->addFieldMapping('field_notes_attachments:source_dir')->defaultValue(AACR_SOURCE_FILES_DIR);
    $this->addFieldMapping('field_notes_attachments:description', 'file_upload_description');
    $this->addFieldMapping('field_notes_attachments:file_class')->description(t('Letting default to default file class'));
    $this->addFieldMapping('field_notes_attachments:language')
        ->defaultValue(LANGUAGE_NONE)
        ->description(t('Defaulting to no language'));
    $this->addFieldMapping('field_notes_attachments:destination_dir')
        ->description(t('Will default to the field location for files'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_notes_attachments:destination_file')
        ->description(t('Defaulting to existing file name'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_notes_attachments:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE)
        ->description(t('We replace existing files'));
    $this->addFieldMapping('field_notes_attachments:preserve_files')
        ->defaultValue(FALSE)
        ->description(t('We delete files when we rollback.'));
    $this->addFieldMapping('field_notes_attachments:display')
        ->description(t('Not importing. Would a default like to be set?'))
        ->issueGroup('DNM');

    $this->addFieldMapping(NULL, 'image_attach')
        ->description(t('Attached images will be added as attachments'));
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Unmapped source fields
    $this->addUnmigratedSources(array('vid', 'type', 'language', 'moderate', 'tnid', 'translate'));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('log', 'tnid'));
  }

  function prepareRow($current_row) {
    $current_row->format = aacr_migrate_get_text_format($current_row->format);

    $current_row->url_alias = aacr_migrate_get_url_alias($current_row->nid);

    $current_row->group_nid = $this->handleSourceMigration('aacr_group_create', array('nid' => $current_row->group_nid));
    if ($current_row->group_nid) {
      $gid = reset(og_get_group_ids('node', array($current_row->group_nid)));
      $current_row->group_nid = $gid;
    }
    
    $files = aacr_migrate_get_file_uploads($current_row->vid);
    $current_row->file_upload = $files['file_name'];
    $current_row->file_upload_name = $files['file_name'];
    $current_row->file_upload_description = $files['description'];

    $more_files = aacr_migrate_img_assist($current_row->nid);
    $current_row->file_upload = array_merge($current_row->file_upload, $more_files);
    
    
  }
}

?>
