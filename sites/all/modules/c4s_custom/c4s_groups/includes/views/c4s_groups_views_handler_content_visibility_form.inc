<?php

class c4s_groups_views_handler_content_visibility_form extends views_handler_field_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['entity_id'] = 'entity_id';
    $this->additional_fields['entity_type'] = 'entity_type';
  }
  
  function render_items($values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  function form_element_name() {
    // Make sure this value is unique for all the view fields
    return $this->options['id'];
  }

  function form_element_row_id($row_id) {
    // You could use values from $this->view->result[$row_id]
    // to provide complex row ids.
    return $row_id;
  }

  function views_form(&$form, &$form_state) {
    if (empty($this->view->result)) {
      return;
    }

    $form['#action'] = $this->view->get_url();
    $field_name = $this->form_element_name();
    $form[$field_name] = array(
      '#tree' => TRUE,
    );
    foreach ($this->view->result as $row_id => $row) {
      $form_element_row_id = $this->form_element_row_id($row_id);
      $div = $field_name . '-' . $form_element_row_id . '-content-access';
      $form[$field_name][$form_element_row_id]['content'] = array(
        '#type' => 'select',
        '#options' => array(
          OG_CONTENT_ACCESS_DEFAULT => t('Default Group Access'),
          OG_CONTENT_ACCESS_PRIVATE => t('Private (Visible only to group)'),
          OG_CONTENT_ACCESS_PUBLIC => t('Public (Visible to all)'),
        ),
        '#default_value' => $row->field_alter_form[$row_id]['raw']['value'],
        '#ajax' => array(
          'callback' => 'c4s_group_ajax_content_access',
          'wrapper' => $div,
        ),
      );
      $etid = entity_extract_ids($row->_field_data[$this->field_alias]['entity_type'], $row->_field_data[$this->field_alias]['entity']);
      $form[$field_name][$form_element_row_id]['etid'] = array('#type' => 'value', '#value' => array_shift($etid));
      $form[$field_name][$form_element_row_id]['entity_type'] = array('#type' => 'value', '#value' => $row->_field_data[$this->field_alias]['entity_type']);
    }
  }

  function views_form_submit($form, &$form_state) {
    foreach ($form_state['values'][$this->form_element_name()] as $values) {
      $entity = entity_load($values['entity_type'], array($values['etid']));
      $entity_wrapper = entity_metadata_wrapper($values['entity_type'], array_pop($entity));
      $entity_wrapper->{OG_CONTENT_ACCESS_FIELD}->set($values['content']);
      $entity_wrapper->save();
    }
  }
}
