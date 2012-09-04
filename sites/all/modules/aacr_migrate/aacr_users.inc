<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_users
 *
 * @author mark
 */
class aacr_users extends Migration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('aacr_import'));
    $this->dependencies = array('aacr_import_profile_pictures');

    $this->description = t("Imports all members from the old AACR group. (Only Active members)");
    //$this->dependencies = array('aacr_import_profile_pictures');

    $this->rules_to_disable[] = 'rules_og_member_active';
    $this->rules_to_disable[] = 'rules_og_group_content_notification';

    $source_fields = array(
      'uid' => t('User ID'),
      'biblio_show_profile' => t('Show on Biblio on profile'),
      'biblio_my_pubs_menu' => t('Add link to "My Publications in Navigation menu'),
      'biblio_contributor_id' => t('Link My Profile with this Author from the Biblio database'),
      'biblio_user_style' => t('Biblio User Style'),
      'biblio_crossref_pid' => t('Biblio CrossRef PId'),
      'biblio_baseopenurl' => t('Biblio User Base URL'),
      'biblio_openurl_sid' => t('Biblio User SID'),
    );
    $query = db_select(AACR_SOURCE_DATABASE . '.users', 'u')
      ->fields('u', array('uid', 'name', 'data', 'pass', 'mail', 'created', 'access', 'login', 'status', 'init'));
    $query->orderBy('u.uid', 'ASC');
    $query->join(AACR_SOURCE_DATABASE . '.og_uid', 'ogu', 'u.uid = ogu.uid');
    $query->condition('ogu.nid', 55, '=');
    $query->condition('ogu.is_active', 1, '=');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.node', 'n', 'u.uid = n.uid AND n.type = :type', array(':type' => 'profile'));
    $query->leftjoin(AACR_SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->leftjoin(AACR_SOURCE_DATABASE . '.content_type_profile', 'pro', 'n.vid = pro.vid');
    $query->leftJoin(AACR_SOURCE_DATABASE . '.image_attach', 'ia', 'n.nid = ia.nid');
    $query->leftJoin(AACR_SOURCE_DATABASE . '.image', 'i', 'ia.iid = i.nid AND i.image_size = :size', array(':size' => '_original'));
    $query->leftJoin(AACR_SOURCE_DATABASE . '.files', 'f', 'i.fid = f.fid');
    $query->addField('f', 'fid');
    $query->addField('pro', 'nid');
    $query->addField('pro', 'field_bio_additional_title_value');
    $query->addField('pro', 'field_firstname_value');
    $query->addField('pro', 'field_surname_value');
    //$query->addField('pro', 'field_phone_no_value');
    //$query->addField('pro', 'field_address_value');
    //$query->addField('pro', 'field_address_format');
    $query->addField('pro', 'field_dept_title');
    //$query->addField('nr', 'body');
    //$query->addField('nr', 'teaser');
    //$query->addField('nr', 'format');

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationUser();

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
      MigrateDestinationUser::getKeySchema()
    );

    // Make the mappings
    $this->addFieldMapping('is_new')->defaultValue(TRUE)->description(t('Importing all new users to the system'));
    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail')->dedupe('users', 'mail');
    $this->addFieldMapping('roles')
        ->defaultValue(DRUPAL_AUTHENTICATED_RID)
        ->description(t('Give all imported users the "Authenticated User" role'));
    $this->addFieldMapping('language')->defaultValue('');
    $this->addFieldMapping('theme')->defaultValue('');
    $this->addFieldMapping('signature')->defaultValue('');
    $this->addFieldMapping('signature_format')->defaultValue('plain_text');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('access', 'access');
    $this->addFieldMapping('login', 'login');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('picture', 'fid')->sourceMigration('aacr_import_profile_pictures');
    $this->addFieldMapping('init', 'init');
    $this->addFieldMapping('timezone')->defaultValue(NULL);
    $this->addFieldMapping('biblio_show_profile', 'biblio_show_profile')->defaultValue(TRUE);
    $this->addFieldMapping('biblio_my_pubs_menu', 'biblio_my_pubs_menu')->defaultValue(FALSE);
    $this->addFieldMapping('biblio_contributor_id', 'biblio_contributor_id')->defaultValue('');
    $this->addFieldMapping('biblio_user_style', 'biblio_user_style')->defaultValue('');
    $this->addFieldMapping('biblio_crossref_pid', 'biblio_crossref_pid')->defaultValue('');
    $this->addFieldMapping('biblio_baseopenurl', 'biblio_baseopenurl')->defaultValue('');
    $this->addFieldMapping('biblio_openurl_sid', 'biblio_openurl_sid')->defaultValue('');
    $this->addFieldMapping(NULL, 'nid')->description(t('Nid of content profile, used to get picture'));

    // Import users names
    $arguments = array(
      'family' => array('source_field' => 'field_surname_value'),
    );
   // The given name should be passed in as the primary value.
   $this->addFieldMapping('field_user_name', 'field_firstname_value')->arguments($arguments);
   $this->addFieldMapping(NULL, 'field_surname_value');
   $this->addFieldMapping(NULL, 'data')->description(t('Used in the prepareRow() function to get biblio values'));

   
   $this->addFieldMapping('field_profile_title', 'field_bio_additional_title_value');
   $this->addFieldMapping('field_profile_title:format')->defaultValue('plain_text');
   $this->addFieldMapping('field_profile_title:language')->defaultValue(LANGUAGE_NONE);

   $this->addFieldMapping('field_profile_department', 'field_dept_title');
   $this->addFieldMapping('field_profile_department:format')->defaultValue('plain_text');
   $this->addFieldMapping('field_profile_department:language')->defaultValue(LANGUAGE_NONE);

   $this->addFieldMapping('field_profile_college')->defaultValue(t('Michigan State University'));
   $this->addFieldMapping('field_profile_college:format')->defaultValue('plain_text');
   $this->addFieldMapping('field_profile_college:language')->defaultValue(LANGUAGE_NONE);

   $this->addFieldMapping('field_profile_institution')->defaultValue(t('Automated Analysis of Constructed Response Research Group'));
   $this->addFieldMapping('field_profile_institution:format')->defaultValue('plain_text');
   $this->addFieldMapping('field_profile_institution:language')->defaultValue(LANGUAGE_NONE);

   $this->addUnmigratedDestinations(array('group_audience', 'role_names', 'field_profile_role', 'field_profile_role:source_type',
     'field_profile_role:create_term', 'field_profile_msu:source_type', 'field_profile_msu:create_term', 'path', 'biblio_id_change_count',
     'field_profile_msu'));
   $this->addFieldMapping('pathauto')->defaultValue(0);
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
    $data = $row->data;
    if (unserialize($data)) $data = unserialize($data);
    $row->biblio_show_profile = isset($data['biblio_show_profile']) ? $data['biblio_show_profile'] : null;
    $row->biblio_my_pubs_menu = isset($data['biblio_my_pubs_menu']) ? $data['biblio_my_pubs_menu'] : null;
    $row->biblio_contributor_id = isset($data['biblio_contributor_id']) ? $data['biblio_contributor_id'] : null;
    $row->biblio_user_style = isset($data['biblio_user_style']) ? $data['biblio_user_style'] : null;
    $row->biblio_crossref_pid = isset($data['biblio_crossref_pid']) ? $data['biblio_crossref_pid'] : null;
    $row->biblio_baseopenurl = isset($data['biblio_baseopenurl']) ? $data['biblio_baseopenurl'] : null;
    $row->biblio_openurl_sid = isset($data['biblio_openurl_sid']) ? $data['biblio_openurl_sid'] : null;

  }
}

?>
