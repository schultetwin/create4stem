<?php

class views_handler_area_add_content_link extends views_handler_area {
  function option_definition() {
    $options = parent::option_definition();

    $options['bundle'] = array('default' => '');
    $options['into_group'] = array('default' => FALSE);
    $options['link_title'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['bundle'] = array(
      '#type' => 'select',
      '#title' => t('Content Type'),
      '#default_value' => $this->options['bundle'],
      '#description' => t('Choose what type of node you would like to create a link for'),
      '#options' => node_type_get_names(),
    );
    $form['link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link Title'),
      '#default_value' => $this->options['link_title'],
      '#description' => t('Enter the text you want to display as the link'),
    );
    $form['into_group'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Group Context to Post Node Into Group'),
      '#default_value' => $this->options['into_group'],
    );
  }
  function render($empty = FALSE) {
    $options = array();
    if (!$empty || $this->options['empty']) {
      if ($this->options['into_group'] && $group = og_context()) {
        $options['query'] = array('gids_' . $group['group_type'] . '[]' => $group['gid']);
      }

      $link = 'node/add/' . str_replace('_', '-', $this->options['bundle']);
      if (drupal_valid_path($link)) {
        return '<div class="views-header-content-link">' . l($this->options['link_title'], $link, $options) . '</div>';
      }
    }
  }
}
