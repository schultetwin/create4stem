<?php

class c4s_groups_views_handler_role_form extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['entity_type'] = 'entity_type';
    $this->additional_fields['etid'] = 'etid';
    $this->additional_fields['gid'] = 'gid';
    $this->additional_fields['c4s_uid'] = array(
      'table' => 'users_og_membership',
      'field' => 'uid',
    );
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['c4s_groups_exclude_roles'] = array('default' => array(1, 2));

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['c4s_groups_exclude_roles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Exclude Roles'),
      '#description' => t('Check the roles you want to exclude from allowing people to check. We recommend leaving anonymous/authenticated excluded'),
      '#options' => og_roles(),
      '#default_value' => $this->options['c4s_groups_exclude_roles'],
    );
  }


  function pre_render(&$values) {
    foreach ($values as &$value) {
      $uid = $value->{$this->aliases['c4s_uid']};
      $value->c4s_roles = og_get_user_roles($value->{$this->aliases['gid']}, $uid, TRUE);
    }
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
      $div = $field_name . '-' . $form_element_row_id . '-roles';
      $options = og_roles($row->{$this->aliases['gid']});
      foreach (array_filter($this->options['c4s_groups_exclude_roles']) as $exclude) {
        unset($options[$exclude]);
      }
      $form[$field_name][$form_element_row_id]['roles'] = array(
        '#prefix' => '<div id="' . $div . '">',
        '#suffix' => '</div>',
        '#type' => 'checkboxes',
        '#default_value' => $row->c4s_roles,
        '#options' => $options,
        //'#ajax' => array(
        //  'callback' => 'c4s_group_og_membership_state_ajax',
        //  'wrapper' => $div,
        //),
      );
      $form[$field_name][$form_element_row_id]['gid'] = array('#type' => 'value', '#value' => $row->{$this->aliases['gid']});
      $form[$field_name][$form_element_row_id]['uid'] = array('#type' => 'value', '#value' => $row->{$this->aliases['c4s_uid']});
    }
  }

  function views_form_submit($form, &$form_state) {
    $field_name = $this->form_element_name();
    foreach ($form_state['values'][$field_name] as $info) {
      $roles = og_get_user_roles($info['gid'], $info['uid']);
      foreach ($info['roles'] as $rid => $role) {
        if ($role && !in_array($rid, $roles)) {
          og_role_grant($info['gid'], $info['uid'], $rid);
        }
        else if (!$role && in_array($rid, $roles)) {
          og_role_revoke($info['gid'], $info['uid'], $rid);
        }
      }
    }
  }
}
