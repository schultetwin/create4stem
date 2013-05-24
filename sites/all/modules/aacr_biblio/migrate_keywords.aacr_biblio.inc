<?php

class AACRBiblioKeywords extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    $this->machineName = 'AACRBiblioKeywords';
    $this->description = t('Imports the keywords from the old system');
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_keyword_data', 'bkd');
    $source_query->condition('bkd.word', 'AACR-pub', '!=');
    $source_query->fields('bkd');
    
    $this->addSimpleMappings(array('word'));
    
    $this->destination = new MigrateDestinationTable('biblio_keyword_data');
    $this->source = new MigrateSourceSQL($source_query, array(), $source_query->countQuery(), array('map_joinable' => false));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'kid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      array(
        'kid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ));
  }
}