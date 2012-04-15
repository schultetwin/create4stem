<?php

/**
 * Expose organic groups group types as a context condition.
 */
class context_og_condition_group_type extends context_condition {
  function condition_values() {
    $values = array(
      '_none_' => t('Not in any group'),
      '_any_' => t('In any group'),
    );
    foreach (node_type_get_types() as $type) {
      if (og_is_group_type('node', $type->type)) {
        $values[$type->type] = $type->name;
      }
    }
    return $values;
  }

  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'node_form' => array(
        '#title' => t('Set on node form'),
        '#type' => 'checkbox',
        '#description' => t('Set this context on node forms'),
        '#default_value' => isset($defaults['node_form']) ? $defaults['node_form'] : TRUE,
      ),
    );
  }

  function execute($group) {
    $node = $group ? node_load($group->etid) : FALSE;
    $type = $node ? $node->type : '_none_';
    $node_form = ((arg(0) == 'node') && ((is_numeric(arg(1)) && (arg(2) == 'edit')) || (arg(1) == 'add')));
    $contexts = $this->get_contexts($type);
    $this->values[$type] = array();

    // check if we are in _any_ group as well
    if ($type != '_none_') {
      $allcontexts = $this->get_contexts('_any_');
      $this->values['_any_'] = array();
      foreach($allcontexts as $acontext) {
        $options = $this->fetch_from_context($acontext, 'options');
        if (!$node_form || !empty($options['node_form'])) {
          $this->condition_met($acontext, '_any_');
        }
      }
    }
    
    foreach ($contexts as $context) {
      $options = $this->fetch_from_context($context, 'options');
      // The condition is met unless we are looking at a node form
      // and the "Set on node form" option is unchecked.
      if (!$node_form || !empty($options['node_form'])) {
        $this->condition_met($context, $type);
      }
    }
  }
}
