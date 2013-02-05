<?php

/**
 * @file
 * Contains the administration forms for fasttoggle.module.
 */

require_once drupal_get_path('module', 'fasttoggle') .'/fasttoggle.inc';

/**
 * (Menu callback) Configures what fast toggling options are available.
 */
function fasttoggle_settings_form() {
  $form = array();

  $form['fasttoggle_label_style'] = array(
    '#type' => 'radios',
    '#title' => t('Label style'),
    '#description' => t('Select what kind of labels you want for fasttoggle links. See the README.txt for information about providing your own labels.'),
    '#options' => array(
      FASTTOGGLE_LABEL_STATUS => t('Status (reflects the current state, e.g. "published", "active")'),
      FASTTOGGLE_LABEL_ACTION => t('Action (shows what happens upon a click, e.g. "unpublish", "block")'),
    ),
    '#default_value' => variable_get('fasttoggle_label_style', FASTTOGGLE_LABEL_STATUS),
  );

  $custom_labels = variable_get('fasttoggle_labels', array());
  if (!empty($custom_labels)) {
    $form['fasttoggle_label_style']['#options'][FASTTOGGLE_LABEL_CUSTOM] = t('Custom (configure in your settings.php)');
  }

  $form['nodes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Posts'),
    '#description' => t('Select what options for fast toggling of post settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['nodes']['fasttoggle_node_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(published/unpublished)</small>'),
      'sticky' => t('Sticky <small>(stays at the top of listings)</small>'),
      'promote' => t('Promoted <small>(visible on the front page)</small>'),
      'comment' => t('Topic opened/closed <small>(users are allowed/disallowed to post comments)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_node_settings', array('status' => TRUE, 'sticky' => TRUE, 'promote' => TRUE, 'comment' => FALSE)))),
  );

  $form['nodes']['help_text'] = array(
    '#value' => t('Configure access restrictions for these settings on the <a href="@url">access control</a> page.', array('@url' => url('admin/user/permissions', array('fragment' => 'module-fasttoggle')))),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  $form['comments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Comments'),
    '#description' => t('Select what options for fast toggling of comment settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['comments']['fasttoggle_comment_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(published/unpublished)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_comment_settings', array('status' => TRUE)))),
    '#description' => t('Configure access restrictions for these settings on the <a href="@url">permissions</a> page.', array('@url' => url('admin/people/permissions', array('fragment' => 'module-fasttoggle')))),
  );

  $form['users'] = array(
    '#type' => 'fieldset',
    '#title' => t('Users'),
    '#description' => t('Select what options for fast toggling of user settings are available.'),
    '#access' => user_access('administer fasttoggle'),
  );

  $form['users']['fasttoggle_user_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Available settings'),
    '#options' => array(
      'status' => t('Status <small>(unblocked/blocked)</small>'),
    ),
    '#default_value' => array_keys(array_filter(variable_get('fasttoggle_user_settings', array('status' => TRUE)))),
    '#description' => t('Get a listing of all users on the <a href="@url">user overview</a> page.', array('@url' => url('admin/people/user'))),
  );

  $form['users']['fasttoggle_role_settings'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Roles that may be toggled'),
      '#options' => array(
      ),
      '#default_value' => variable_get('fasttoggle_role_settings', array()),
  );

  $available_roles = fasttoggle_potential_toggleable_roles();
  $roles = array();
  foreach ($available_roles as $key => $role_name) {
    $form['users']['fasttoggle_role_settings']['#options'][$key] = $role_name;
  }

  $form['fasttoggle_allow_block_user1'] = array(
    '#type' => 'checkbox',
    '#title' => t("Allow user 1's account to be blocked using Fasttoggle."),
    '#default_value' => variable_get('fasttoggle_allow_block_user1', 0),
  );

  $form['fasttoggle_enhance_node_overview_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add published/unpublished toggle links to the node overview page.'),
    '#default_value' => variable_get('fasttoggle_enhance_node_overview_page', TRUE),
  );

  $form['fasttoggle_enhance_user_overview_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add blocked/unblocked toggle links to the user overview page.'),
    '#default_value' => variable_get('fasttoggle_enhance_user_overview_page', TRUE),
  );

  return system_settings_form($form);
}
