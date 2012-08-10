<?php

function og_viewscontext_views_data() {
  $data = array();
  
  $data['field_data_group_audience']['table']['group'] = t('Group');
  
  $data['field_data_group_audience']['gid'] = array(
    'title' => t('Group Node ID'),
    'help' => t('Translate the node ID to the corresponding group ID.'),
    'real field' => 'group_audience_gid',
    'argument' => array(
      'handler' => 'og_viewscontext_handler_argument_numeric',
    ),
  );
  
  return $data;
}

class og_viewscontext_handler_argument_numeric extends views_handler_argument_numeric {
  function construct() {
    parent::construct();
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['entity_type'] = array('default' => 'node');
    $options['set_group_context'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
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
  
  function set_argument($arg) {
    if (is_numeric($arg)) {
      $group = og_get_group($this->options['entity_type'], $arg);
      $arg = $group->gid;
      if ($this->options['set_group_context']) {
        og_context($group);
      }
    }
    $this->argument = $arg;
    return $this->validate_arg($arg);
  }
}

