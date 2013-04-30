<?php

class AACRBiblioContributers extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    $this->machineName = 'AACRBiblioContributers';
    $this->description = t('Imports the contributers from the old system');
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_contributor_data', 'bcd');
    $source_query->leftJoin('users', 'u', 'bcd.drupal_uid = u.uid');
    $source_query->fields('bcd');
    $source_query->fields('u', array('mail'));
    
    $this->addSimpleMappings(array('drupal_uid', 'name', 'lastname', 'firstname',
      'prefix', 'suffix', 'initials', 'affiliaion', 'md5'));
    
    $this->addFieldMapping('aka')->defaultValue(0);
    
    $this->destination = new MigrateDestinationTable('biblio_contributor_data');
    $this->source = new MigrateSourceSQL($source_query, array(), $source_query->countQuery(), array('map_joinable' => false));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'cid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      array(
        'cid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ));
    
    $this->addUnmigratedSources(array('mail'));
  }
  
  function prepareRow($row) {
    if (isset($row->mail) && !empty($row->mail)) {
      $uid_from_email = db_query('SELECT uid FROM users WHERE mail = :mail', array(':mail' => $row->mail))->fetchField();
      if ($uid_from_email) {
        $row->drupal_uid = $uid_from_email;
        $this->queueMessage(t('Able to get UID @uid from email address @mail', array('@uid' => $uid_from_email, '@mail' => $row->mail)), Migration::MESSAGE_INFORMATIONAL);
      }
      else {
        $this->queueMessage(t('Unable to get UID from email address @mail', array('@mail' => $row->mail)), Migration::MESSAGE_INFORMATIONAL);
        $row->drupal_uid = null;
      }
    }
    else {
      $row->drupal_uid = null;
    }
  }
}