<?php

class AACRBiblioFiles extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    
    $this->machineName = 'AACRBiblioFiles';
    
    $this->dependencies[] = 'AACRBiblioMigrate';
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('files', 'f');
    $source_query->fields('f');
    $source_query->fields('n', array('nid'));
    $source_query->innerJoin('upload', 'up', 'up.fid = f.fid');
    $source_query->innerJoin('node', 'n', 'n.nid = up.nid');
    $source_query->condition('n.type', 'biblio', '=');
    
    $this->systemOfRecord = Migration::DESTINATION;
    
    $this->addFieldMapping('field_biblio_attachments:file_class')->defaultValue('MigrateFileUri');
    $this->addFieldMapping('field_biblio_attachments:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_biblio_attachments:file_replace')->defaultValue(FILE_EXISTS_RENAME);
    $this->addFieldMapping('field_biblio_attachments:preserve_files')->defaultValue(false);
    $this->addFieldMapping('field_biblio_attachments:source_dir')->defaultValue('crcstl_migrate');
    $this->addFieldMapping('field_biblio_attachments', 'filepath');
    $this->addFieldMapping('nid', 'nid')->sourceMigration('AACRBiblioMigrate');
    
    $this->destination = new MigrateDestinationNode('biblio');
    $this->source = new MigrateSourceSQL($source_query, array(), $source_query->countQuery(), array('map_joinable' => false));
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'fid' => array(
            'type' => 'int',
            'unsigned' => true,
          ),
        ),
        MigrateDestinationNode::getKeySchema());
  }
}