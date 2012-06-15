<?php

/**
 * Class to make it easy to change someone's state in a group
 */
class c4s_groups_views_handler_field_membership_form extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['id'] = 'id';
  }

  function render($values) {
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
      $div = $field_name . '-' . $form_element_row_id . '-state';
      $form[$field_name][$form_element_row_id]['state'] = array(
        '#prefix' => '<div id="' . $div . '">',
        '#suffix' => '</div>',
        '#type' => 'select',
        '#default_value' => $row->{$this->field_alias},
        '#options' => array(
          OG_STATE_ACTIVE => t('Active'),
          OG_STATE_PENDING => t('Pending'),
          OG_STATE_BLOCKED => t('Blocked'),
        ),
        '#ajax' => array(
          'callback' => 'c4s_group_og_membership_state_ajax',
          'wrapper' => $div,
        ),
      );
      $form[$field_name][$form_element_row_id]['id'] = array('#type' => 'value', '#value' => $row->{$this->aliases['id']});
    }
  }

  function views_form_submit($form, &$form_state) {
    foreach ($form_state['values']['membership_form'] as $info) {
      $membership = og_membership_load($info['id']);
      if ($membership && $membership->state != $info['state']) {
        $membership->state = $info['state'];
        $membership->save();
      }
    }
  }
}