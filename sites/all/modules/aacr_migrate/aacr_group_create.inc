<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_group_create
 *
 * @author mark
 */
class aacr_group_create extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));

    $this->description = t("First Migration, creates a new group for them");
    $this->dependencies = array('aacr_users');

    $this->rules_to_disable[] = 'rules_og_member_active';
    $this->rules_to_disable[] = 'rules_og_group_content_notification';
    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects. Usually, you'll use the MigrateSQLMap
    // class, which uses database tables for tracking. Pass the machine name
    // (BeerTerm) of this migration to use in generating map and message tables.
    // And, pass schema definitions for the primary keys of the source and
    // destination - we need to be explicit for our source, but the destination
    // class knows its schema already.
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
        ->fields('n', array('title', 'uid', 'created', 'changed', 'status', 'promote', 'sticky', 'comment', 'vid', 'type', 'nid'))
        ->condition('n.nid', 55, '=');
    $query->join(AACR_SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $source_fields = array(
      'nid' => t('The node ID of the aacr group'),
      'url_alias' => t('The url alias of the node'),
    );

    $this->source = new MigrateSourceSQL($query, $source_fields);

    $this->destination = new MigrateDestinationNode('project');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('uid', 'uid')->sourceMigration('aacr_users')->defaultValue(1);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('comment', 'comment');
    $this->addFieldMapping('path', 'url_alias');
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping(NULL, 'vid')->description(t('Not Importing revisions, only most recent'));
    $this->addFieldMapping(NULL, 'type')->description(t('Only importing one content type, so no reason to import'));
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format', 'format');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE)->description(t('Default to language none'));
    $this->addFieldMapping('log')->description(t('Not Importing, not importing revisions'));
    $this->addFieldMapping('tnid')->description(t('Not setting any translation information'));
    $this->addFieldMapping('revision_uid')->description(t('Not importing because not importing revisions'));
    $this->addFieldMapping('group_group')->defaultValue(TRUE)->description(t('Yes, this is a group, so make it so'));
    $this->addFieldMapping('field_project_shorttitle')->defaultValue('AACR')->description(t('Hard coded to aacr because only one project'));
    $this->addFieldMapping('field_project_shorttitle:language')->defaultValue(LANGUAGE_NONE)->description(t('Set to no value'));
    $this->addFieldMapping('field_project_shorttitle:format')->defaultValue('plain_text')->description(t('Hardcoding default to plain_text'));
    $this->addFieldMapping('group_access')->defaultValue(TRUE)->description(t('Defaulting this group to be visible to all'));
    $this->addFieldMapping('field_project_image')->description(t('No image to import'));
    $this->addFieldMapping('field_project_image:file_class')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:language')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:destination_dir')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:destination_file')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:file_replace')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:preserve_files')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:source_dir')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:alt')->description(t('No Image to import'));
    $this->addFieldMapping('field_project_image:title')->description(t('No Image to import'));
    $this->addFieldMapping('featured_project')->defaultValue(FALSE)->description(t('Defaults to not be a featured project'));
    $this->addFieldMapping('pathauto')->defaultValue(0)->description(t('Turn off path auto to not override old paths'));
    
    // Unmapped source fields
    //$this->addUnmigratedSources(array('vid', 'timestamp'));

    // Unmapped destination fields
    //$this->addUnmigratedDestinations(array( 'tnid', 'log', 'revision_uid', 'group_group'));
  
  }

    public function preImport() {
    parent::preImport();
    // Disable given active rules
    db_update('rules_config')
      ->fields(array('active' => 0))
      ->condition('name', $this->rules_to_disable, 'IN')
      ->execute();
    rules_clear_cache(TRUE);
  }

  public function postImport() {
    parent::postImport();
    // Re-enable rules
    db_update('rules_config')
      ->fields(array('active' => 1))
      ->condition('name', $this->rules_to_disable, 'IN')
      ->execute();
    rules_clear_cache(TRUE);
  }

  public function prepareRow($current_row) {
    // Set the uid for the node revision.
    //$current_row->uid = $current_row->revision_uid = xdeb_migration_get_user($current_row->name);

    // Set the text format for the node.
    $current_row->format = aacr_migrate_get_text_format($current_row->format);

    // Set the terms for the node.
    //$current_row->tags = aacr_format_get_terms($current_row->vid, XDEB_TERM_TAGS);

    // Set image data for the page image field.
    //$current_row->content_field_page_image = aacr_migrate_get_page_image($current_row->vid);

    // Set the url alias for the node.
    $current_row->url_alias = aacr_migrate_get_url_alias($current_row->nid);

    // We could also have used this function to decide to skip a row, in cases
    // where that couldn't easily be done through the original query. Simply
    // return FALSE in such cases.
    return TRUE;
  }
}
