<?php

class og_viewscontext_argument_validate_nid_as_gid extends views_plugin_argument_validate {

  function access() {
    return TRUE;
  }
  function option_definition() {
    $options = parent::option_definition();
    $options['must_be_member'] = array('default' => FALSE);
    $options['entity_type'] = array('default' => 'node');
    $options['set_group_context'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['must_be_member'] = array(
      '#type' => 'checkbox',
      '#title' => t('Current user is Member'),
      '#default_value' => $this->options['must_be_member'],
    );
    $options = array();
    $entity_types = entity_get_info();
    foreach ($entity_types as $key => $entity_type) {
      $options[$key] = $entity_type['label'];
    }
    $form['entity_type'] = array(
      '#type' => 'select',
      '#title' => t('Entity Type'),
      '#description' => t('Select the entity type that the url is'),
      '#options' => $options,
      '#default_value' => $this->options['entity_type'],
    );
    $form['set_group_context'] = array(
      '#type' => 'checkbox',
      '#title' => t('Set Group Context'),
      '#description' => t('Set the group context using the entity id'),
      '#default_value' => $this->options['set_group_context'],
    );
  }

  function validate_argument($argument) {
    $group = og_get_group($this->options['entity_type'], $argument);
    if ($group == null) {
      return FALSE;
    }
    if ($this->options['must_be_member']) {
      if (!og_is_member($group->gid, 'user') && !user_access('administer groups')) return FALSE;
    }
    $this->argument->argument = $group->gid;
    if ($this->options['set_group_context']) {
      og_context($group);
    }
    return TRUE;
  }
}
