<?php

class fasttoggle_views_handler_field_user_link extends views_handler_field_user_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    // We need these fields for state checking later in the render() function.
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['status'] = 'status';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {

    $account = new stdClass();
    $account->uid = $values->{$this->aliases['uid']};
    $account->status = $values->{$this->aliases['status']};

    $settings = variable_get('fasttoggle_user_settings', array('status' => TRUE));

    if ($settings['status'] !== 0 && ($account->uid != 1 || variable_get('fasttoggle_allow_block_user1', FALSE)) && (user_access('administer users') || user_access('moderate users'))) {
      $links = fasttoggle_link('user', $account, TRUE);
      if (!empty($links)) {
        return l($links['fasttoggle_status']['title'], $links['fasttoggle_status']['href'], $links['fasttoggle_status']);
      }
    }
  }
}
