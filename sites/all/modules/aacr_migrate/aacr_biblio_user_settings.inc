<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of aacr_biblio_user_settings
 *
 * @author mark
 */
// abstract function arguments(...)
/**
 * Any one or more of these methods may be implemented
 */
//abstract public function fields();
//abstract public function prepare($entity, stdClass $row);
//abstract public function complete($entity, stdClass $row);
class aacr_biblio_user_settings extends MigrateDestinationHandler {
  public function __construct() {
    if (module_exists('biblio')) {
      $this->registerTypes(array('user'));
    }
  }

  public function fields() {
    $fields = array();
    $fields['biblio_show_profile'] = t('Show my publications on my profile page');
    $fields['biblio_my_pubs_menu'] = t('Show "My publications" item in the navigation menu');
    $fields['biblio_contributor_id'] = t('Link My Profile with this Author from the Biblio database');
    $fields['biblio_id_change_count'] = t('Drupal UserID to Biblio AuthorID mapping change count ');
    $fields['biblio_user_style'] = t('Bibliographic list view style');
    $fields['biblio_baseopenurl'] = t('Openurl base');
    $fields['biblio_openurl_sid'] = t('Openurl Site ID');
    $fields['biblio_crossref_pid'] = t('CrossRef Site Login');

    return $fields;
  }

  public function prepare($entity, stdClass $row) {
    foreach (array_keys($this->fields()) as $value) {
      if (isset($entity->{$value})) {
        $entity->data[$value] = $entity->{$value};
        unset($entity->{$value});
      }
    }
  }
}

?>
