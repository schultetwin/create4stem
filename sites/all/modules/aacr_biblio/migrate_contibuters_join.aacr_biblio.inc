<?php

class AACRBiblioContributersJoin extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    $this->machineName = 'AACRBiblioContributersJoin';
    $this->description = 'Actually migrate the biblio contributers';
    
    $this->dependencies[] = 'AACRBiblioMigrate';
    $this->dependencies[] = 'AACRBiblioContributers';
    
     $sub_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_keyword', 'bk');
    $sub_query->fields('bk', array('nid'));
    $sub_query->leftJoin('biblio_keyword_data', 'bkd', 'bk.kid = bkd.kid');
    $sub_query->condition('bkd.word', 'AACR', '=');
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_contributor', 'bc');
    $source_query->condition('bc.nid', $sub_query, 'IN');
    $source_query->groupBy("bc.nid, bc.cid, bc.auth_type, bc.rank");
    $source_query->fields('bc');
    
    $this->addSimpleMappings(array('auth_type', 'auth_category', 'rank'));
    $this->addFieldMapping('nid', 'nid');
    $this->addFieldMapping('cid', 'cid')->sourceMigration('AACRBiblioContributers');
    $this->addFieldMapping('vid', 'vid');
    
    $this->source = new MigrateSourceSQL($source_query, array(), $source_query->countQuery(), array('map_joinable' => false));
    $this->destination = new MigrateDestinationTable('biblio_contributor');
    $this->map = new MigrateSQLMap($this->machineName, 
        array(
          'vid' => array(
            'type' => 'int',
            'unsigned' => true,
          ),
          'cid' => array(
            'type' => 'int',
            'unsigned' => true,
          ),
          'auth_type' => array(
            'type' => 'int',
            'unsigned' => true,
          ),
          'rank' => array(
            'type' => 'int',
            'unsigned' => true,
          )
        ), MigrateDestinationTable::getKeySchema('biblio_contributor'));
    
  }
  
  public function prepareRow($row) {
    parent::prepareRow($row);
    
    $row->nid = $this->handleSourceMigration('AACRBiblioMigrate', $row->nid, 0);
    if ($row->nid == 0) {
      $this->saveMessage(t('Cannot find node for nid @nid', array('@nid' => $row->nid)), Migration::MESSAGE_ERROR);
      return false;
    }
    $row->vid = db_query('SELECT vid FROM {node} WHERE nid = :nid', array(':nid' => $row->nid))->fetchField();
    if ($row->vid == 0) {
      $this->saveMessage(t('Cannot find node for vid @vid', array('@vid' => $row->vid)), Migration::MESSAGE_ERROR);
      return false;
    }
    
    $row->cid = $this->handleSourceMigration('AACRBiblioContributers', $row->cid, 0);
    if ($row->cid == 0) {
      $this->saveMessage(t('Could not find cid from @cid', array('@cid' => $row->cid)), Migration::MESSAGE_ERROR);
      return false;
    }
  }
}
