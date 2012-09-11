<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of og_viewscontext_access_group_member
 *
 * @author mark
 */
class og_viewscontext_access_group_member extends views_plugin_access{
  function summary_title() {
    return t('Current User is Group Member');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['arg_pos'] = array('default' => 1);
    $options['nid_gid'] = array('default' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['arg_pos'] = array(
      '#type' => 'select',
      '#title' => t('Select the position of the arg'),
      '#description' => t('Remember that we start with 0'),
      '#options' => drupal_map_assoc(range(0, 9)),
      '#default_value' => $this->options['arg_pos'],
    );
    $form['nid_gid'] = array(
      '#type' => 'checkbox',
      '#title' => t('Convert the argument from a node id '),
      '#description' => t('Check if the argument will be a node id and not a group id'),
      '#default_value' => $this->options['nid_gid'],
    );
  }

  /**
   * Determine if the current user has access or not.
   */
  function access($account) {
    // default to no access controe
    return og_viewscontext_access_group_member_access($this->options['arg_pos'], $this->options['nid_gid']);
  }

  function get_access_callback() {
    return array('og_viewscontext_access_group_member_access', array($this->options['arg_pos'], $this->options['nid_gid']));
  }
}

?>
