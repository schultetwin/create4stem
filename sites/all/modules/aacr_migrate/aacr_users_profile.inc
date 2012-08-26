<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_users_profile
 *
 * @author mark
 */
class aacr_users_profile extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));

    $this->description = t("Imports additional user profile infor the users from the old system.");

    $this->dependencies = array('aacr_users');
    
    $source_fields = array(
      'uid' => t('User ID (mapped against previously imported uid'),
    );
    
    $query = db_select(AACR_SOURCE_DATABASE . '.users', 'u')
      ->condition('u.uid', 1, '>');
    $query->fields('u', array('uid'));
    $query->orderBy('u.uid', 'ASC');
    $query->join(AACR_SOURCE_DATABASE . '.og_uid', 'ogu', 'u.uid = ogu.uid');
    $query->condition('ogu.nid', 55, '=');
    $query->condition('ogu.is_active', 1, '=');
    $query->join(AACR_SOURCE_DATABASE . '.node', 'n', 'u.uid = n.uid AND n.type = :type', array(':type' => 'profile'));
    $query->join(AACR_SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->join(AACR_SOURCE_DATABASE . '.content_type_profile', 'pro', 'n.vid = pro.vid');
    $query->addField('pro', 'field_phone_no_value');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationProfile2('main', array());

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique User ID',
          'alias' => 'u',
        )
      ),
      MigrateDestinationProfile2::getKeySchema()
    );

    $this->addFieldMapping('uid', 'uid')->sourceMigration('aacr_users');
    $this->addFieldMapping('revision_uid')
        ->description(t('No migrating revision'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_profile_about', 'body')
        ->defaultValue('')
        ->description(t('Description field'));
    $this->addFieldMapping('field_profile_about:summary', 'teaser')
        ->defaultValue('')
        ->description(t('Description summary'));
    $this->addFieldMapping('field_profile_about:format', 'format')
      ->defaultValue('plain_text')
      ->description(t('The Text-Format of the description'));
    $this->addFieldMapping('field_profile_about:language')
      ->defaultValue('und')
      ->description(t('The language of the <br />("und" = no language)'));
    $this->addFieldMapping('field_profile_facebook')
        ->description(t('Cannot map from old system'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_profile_phone', 'field_phone_no_value')
        ->defaultValue('')
        ->description(t('Phone numbers'));
    $this->addFieldMapping('field_profile_phone:format')
        ->defaultValue('plain_text');
    $this->addFieldMapping('field_profile_phone:language')
        ->defaultValue('und');
    $this->addFieldMapping('language')
        ->defaultValue('und');
    $this->addFieldMapping('field_profile_twitter')
        ->description(t('Cannot migrate from any sources'))
        ->issueGroup('DNM');
    $this->addFieldMapping('field_profile_linkedin')
        ->description(t('Cannot migrate from any sources'))
        ->issueGroup('DNM');

    $this->addUnmigratedDestinations(array('field_profile_fax', 'field_profile_fax:format', 'field_profile_fax:language',
      'field_profile_research', 'field_profile_research:summary', 'field_profile_research:format', 'field_profile_research:language',
      'field_profile_courses', 'field_profile_courses:summary', 'field_profile_courses:format', 'field_profile_courses:language',
      'field_profile_courselinks', 'field_profile_researchlinks', 'path'), 'DNM');
  }

  public function prepareRow($current_row) {
    // Set the uid for the node revision.
    //$current_row->uid = $current_row->revision_uid = xdeb_migration_get_user($current_row->name);

    // Set the text format for the node.
    $current_row->format = aacr_migrate_get_text_format($current_row->format);
  }
}
