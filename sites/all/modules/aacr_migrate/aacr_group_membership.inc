<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_group_membership
 *
 * @author mark
 */
class aacr_group_membership extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));

    $this->description = t("Imports all the AACR group memberships");
    $this->dependencies = array('aacr_users', 'aacr_group_create');

    $query = db_select(AACR_SOURCE_DATABASE . '.og_uid', 'ogu')
        ->fields('ogu', array('nid', 'og_role', 'is_active', 'is_admin', 'uid', 'created'))
        ->condition('ogu.nid', 55, '=')
        ->condition('ogu.is_active', 1, '=');

    $source_fields = array(
      'gid' => t('Need to get group id'),
    );
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationOGMembership();

    $this->rules_to_disable[] = 'rules_og_member_active';
    $this->rules_to_disable[] = 'rules_og_group_content_notification';

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'ogu',
        ),
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'UID of the group membership',
          'alias' => 'ogu',
        )
      ),
      MigrateDestinationOGMembership::getKeySchema()
    );

    $this->addFieldMapping('gid', 'gid');
    $this->addFieldMapping(NULL,'nid')->description(t('Used in prepare role'));
    $this->addFieldMapping('uid', 'uid')->sourceMigration('aacr_users');
    $this->addFieldMapping('state')->defaultValue(OG_STATE_ACTIVE);
    $this->addFieldMapping('is_admin', 'is_admin')->defaultValue(0);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping(NULL, 'is_active')
        ->description(t("Only importing active users"))
        ->issueGroup('DNM');
    $this->addFieldMapping(NULL, 'og_role')
        ->description(t('No roles used in old group'))
        ->issueGroup('DNM');
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

  function prepareRow($row) {
    $nid = $row->nid;
    $new_nid = $this->handleSourceMigration('aacr_group_create', array('nid' => $nid));
    if ($new_nid) {
      $gid = reset(og_get_group_ids('node', array($new_nid)));
      $row->gid = $gid;
    }
    return TRUE;
  }
}

?>
