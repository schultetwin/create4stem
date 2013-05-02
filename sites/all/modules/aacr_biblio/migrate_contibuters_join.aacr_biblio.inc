<?php

class AACRBiblioContributersJoin extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    $this->machineName = 'AACRBiblioContributersJoin';
    $this->description = 'Actually migrate the biblio contributers';
    
    $this->dependencies[] = 'AACRBiblioMigrate';
    $this->dependencies[] = 'AACRBiblioContributers';
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_contributor', 'bc');
    $source_query->fields('bc');
    
    $this->addSimpleMappings(array('auth_type', 'auth_category', 'rank'));
    $this->addFieldMapping('nid', 'nid')->sourceMigration('AACRBiblioMigrate');
    $this->addFieldMapping('cid', 'cid')->sourceMigration('AACRBiblioContributers');
    $this->addFieldMapping('vid', 'vid');
    
    $this->source = new MigrateSourceSQL($source_query, array(), $source_query->countQuery(), array('map_joinable' => false));
    $this->destination = new MigrateDestinationTable('biblio_contributor');
    $this->map = new MigrateSQLMap($this->machineName, MigrateDestinationTable::getKeySchema('biblio_contributor'), MigrateDestinationTable::getKeySchema('biblio_contributor'));
    
  }
  
  public function prepareRow($row) {
    parent::prepareRow($row);
    
    $row->nid = $this->handleSourceMigration('AACRBiblioMigrate', $row->nid);
    $row->vid = db_query('SELECT vid FROM {node} WHERE nid = :nid', array(':nid' => $row->nid))->fetchField();
  }
}
