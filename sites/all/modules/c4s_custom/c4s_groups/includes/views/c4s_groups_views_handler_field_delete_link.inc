<?php

class c4s_groups_views_handler_field_delete_link extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['entity_type'] = 'entity_type';
    $this->additional_fields['etid'] = 'etid';
  }
  function render($values) {
    return l(t('Unsubscribe'),
      'group/' . $values->{$this->aliases['entity_type']} . '/' . $values->{$this->aliases['etid']} . '/unsubscribe/' . $values->{$this->field_alias},
      array('query' => drupal_get_destination())
    );
  }
}
