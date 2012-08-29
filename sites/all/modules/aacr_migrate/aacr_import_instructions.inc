<?php

/*
 * THIS IS A TERRIBLE IMPLEMENTATION!! SHould be abstracted much better (first use of Migrate module)
 */


/**
 * Imports the "Instructions" tab of the AACR group into the wiki content type in a book format.
 *
 * @author mark
 */
class aacr_import_instructions extends Migration{
  private $topNid = 1642;
  private $bid = 55;
  
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));

    // Define a "top" nid for the source book
    $this->description = t('Imports the old instructions into the wiki content type');

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

    // Menu links are not in the normal menu links table, but in a special domain table.
    $table = '.domain_' . AACR_DOMAIN . '_menu_links';

    // We're selecting only part of the book.
    $nids = db_select(AACR_SOURCE_DATABASE . $table, 'ml')
        ->fields('ml', array('mlid'));
    $nids->innerJoin(AACR_SOURCE_DATABASE . '.book', 'b', 'ml.mlid = b.mlid AND b.bid = :bid', array(':bid' => $this->bid));
    $nids->condition('b.nid', $this->topNid, '=');

    $query = db_select(AACR_SOURCE_DATABASE . '.node', 'n')
        ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'))
        ->condition('n.type', 'book', '=');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $query->innerJoin(AACR_SOURCE_DATABASE . '.book', 'b', 'b.nid = n.nid AND b.bid = :bid', array(':bid' => $this->bid));
    $query->leftJoin(AACR_SOURCE_DATABASE . $table, 'ml', 'ml.mlid = b.mlid');
    $query->condition('ml.p2', $nids, 'IN');
    $query->addField('b', 'bid', 'book_id');
    $query->addField('ml', 'weight', 'book_weight');
    $query->addField('ml', 'plid', 'parent_id');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.og_access_post', 'oga', 'oga.nid = n.nid');
    $query->addField('oga', 'og_public');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.og_ancestry', 'oa', 'oa.nid = n.nid');
    $query->addField('oa', 'group_nid');
    $query->orderBy('n.changed');

    $source_fields = array(
      'nid' => t('The node ID of the page'),
      'url_alias' => t('The url alias of the node'),
      //'tags' => t('The terms for the node'),
      'file_upload' => t('File upload'),
      'file_upload_description' => t('File Upload Description'),
      'image_attach' => t('Images attached via the Image Assist Module in D6'),
    );

    $this->highwaterField = array(
      'name' => 'changed',
      'alias' => 'n',
    );

    $this->source = new MigrateSourceSQL($query, $source_fields);

    $this->destination = new MigrateDestinationNode('wiki');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('uid', 'uid')->sourceMigration('aacr_users')->defaultValue(1);
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

    $this->addFieldMapping('field_wiki_attachments', 'file_upload');
    $this->addFieldMapping('field_wiki_attachments:source_dir')->defaultValue(AACR_SOURCE_FILES_DIR);
    $this->addFieldMapping('field_wiki_attachments:description', 'file_upload_description');
    $this->addFieldMapping('field_wiki_attachments:file_class')->description(t('Letting default to default file class'));
    $this->addFieldMapping('field_wiki_attachments:language')
        ->defaultValue(LANGUAGE_NONE)
        ->description(t('Defaulting to no language'));
    $this->addFieldMapping('field_wiki_attachments:destination_dir')
        ->description(t('Will default to the field location for files'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_wiki_attachments:destination_file')
        ->description(t('Defaulting to existing file name'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_wiki_attachments:file_replace')
        ->defaultValue(FILE_EXISTS_REPLACE)
        ->description(t('We replace existing files'));
    $this->addFieldMapping('field_wiki_attachments:preserve_files')
        ->defaultValue(FALSE)
        ->description(t('We delete files when we rollback.'));
    $this->addFieldMapping('field_wiki_attachments:display')
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

    if ($current_row->nid != $this->topNid) $this->lookupMigratedBook($this->topNid);
    //$node->book['bid'] = $book_id;
    //$node->book['weight'] = $current_row->book_weight;
  }
  
  /**
   * Acts right after a book node has been saved. Map the book hierarchy.
   *
   * @param object $node
   *   A node object for the newly migrated book.
   * @param stdClass $row
   *   An object representing data from the source row.
   */
   public function complete($node, stdClass $row) {
    // If this is a top-level book, don't set a parent.
    $book_id = $row->nid == $this->topNid ? $node->nid : $this->lookupMigratedBook($this->topNid);
    // Parent menu item
    //$parent_id = $row->nid == $row->book_id ? '' : $this->lookupMigratedBook($row->parent_id);
    // Book id - effectively, parent nid.
    $node->book['bid'] = $book_id;
    //$node->book['plid'] = $parent_id;
    $node->book['weight'] = $row->book_weight;
    //_book_update_outline($node);
    node_save($node);
  }

  /**
   * Returns a mapping for a migrated book.
   *
   * @param int $source_book_nid
   *   Nid of book in source database to lookup.
   */
  protected function lookupMigratedBook($source_book_nid) {
    $dest_book_nid = parent::handleSourceMigration('aacr_import_instructions', $source_book_nid);
    return $dest_book_nid;
  }

  protected function createStub($migration, $source_id) {
    $node = new stdClass;
    $node->title = t('Stub for') . $source_id[0];
    $node->body = t('Stub body');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    $book_id = $source_id[0] == $this->topNid ? 'new' : $this->lookupMigratedBook($this->topNid);
    $node->book['bid'] = $book_id;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
  
}

?>
