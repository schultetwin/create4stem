<?php
/**
 * @file
 * c4s_grants.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4s_grants_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_grantc4s';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_grantc4s';
  $strongarm->value = 0;
  $export['comment_anonymous_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_grantc4s';
  $strongarm->value = 1;
  $export['comment_default_mode_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_grantc4s';
  $strongarm->value = '50';
  $export['comment_default_per_page_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_grantc4s';
  $strongarm->value = 1;
  $export['comment_form_location_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_grantc4s';
  $strongarm->value = '1';
  $export['comment_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_grantc4s';
  $strongarm->value = '1';
  $export['comment_preview_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_grantc4s';
  $strongarm->value = 1;
  $export['comment_subject_field_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_grantc4s';
  $strongarm->value = array();
  $export['menu_options_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_grantc4s';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_grantc4s';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_grantc4s';
  $strongarm->value = '1';
  $export['node_preview_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_grantc4s';
  $strongarm->value = 0;
  $export['node_submitted_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_content_type_grantc4s';
  $strongarm->value = 'omitted';
  $export['og_group_content_type_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_grantc4s';
  $strongarm->value = 'omitted';
  $export['og_group_type_grantc4s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_grantc4s_pattern';
  $strongarm->value = 'grant/[node:title]';
  $export['pathauto_node_grantc4s_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_grantc4s';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_grantc4s'] = $strongarm;

  return $export;
}
