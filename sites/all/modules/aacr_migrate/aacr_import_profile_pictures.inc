<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_import_profile_pictures
 *
 * @author mark
 */
class aacr_import_profile_pictures extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));
    $this->description = t('Profile images');
    $this->map = new MigrateSQLMap($this->machineName, array(
        'fid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Image ID.',
          'alias' => 'f',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $subquery = db_select(AACR_SOURCE_DATABASE . '.og_uid', 'ogu')
        ->fields('ogu', array('uid'))
        ->condition('ogu.nid', 55, '=')
        ->condition('ogu.is_active', 1, '=');
    
    $query = db_select(AACR_SOURCE_DATABASE . '.files', 'f')
          ->fields('f', array('fid', 'timestamp', 'filepath'))
        ->distinct();
    $query->innerJoin(AACR_SOURCE_DATABASE . '.image', 'i', 'i.fid = f.fid AND i.image_size = :size', array(':size' => '_original'));
    $query->innerJoin(AACR_SOURCE_DATABASE . '.image_attach', 'ia','i.nid = ia.iid');
    $query->innerJoin(AACR_SOURCE_DATABASE . '.node', 'n', 'ia.nid = n.nid AND n.type = :type', array(':type' => 'profile'));
    $query->condition('n.uid', $subquery, 'IN');
    

    
    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationFile();

    // In the simplest case, just map the incoming URL to 'value'.
    $this->addFieldMapping('value', 'filepath');
    $this->addFieldMapping('timestamp', 'timestamp');
    $this->addFieldMapping('uid')->defaultValue(1)->description(t('Imported before users, so setting UID to 1 for all files'));
    $this->addFieldMapping('destination_dir')->defaultValue('sites/default/files/user/pictures');
    $this->addFieldMapping('file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('source_dir')->defaultValue(AACR_SOURCE_FILES_DIR);
    $this->addFieldMapping('path');
    $this->addFieldMapping('destination_file')->description(t("Do nothing"));

    $this->removeFieldMapping('pathauto');
  }
}
