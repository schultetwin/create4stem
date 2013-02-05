<?php

class fasttoggle_views_handler_field_comment_link extends views_handler_field_comment_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    // We need these fields for state checking later in the render() function.
    $this->additional_fields['cid'] = 'cid';
    $this->additional_fields['status'] = 'status';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {
    $options = fasttoggle_get_options('comment', NULL);
    $key = $this->fasttoggle_key;
    if (!empty($options[$key])) {
      $status = $values->{$this->aliases['status']};
      $cid = $values->{$this->aliases['cid']};
      return fasttoggle($options[$key][intval($status)], 'comment/toggle/' . $cid . '/' . $key, TRUE, $key .'_'. $cid);
    }
  }
}
