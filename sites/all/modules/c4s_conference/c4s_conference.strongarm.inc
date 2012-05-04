<?php
/**
 * @file
 * c4s_conference.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4s_conference_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_conference_session';
  $strongarm->value = array();
  $export['menu_options_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_conference_session';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_conference_session';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_conference_session';
  $strongarm->value = '1';
  $export['node_preview_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_conference_session';
  $strongarm->value = 1;
  $export['node_submitted_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_content_type_conference_session';
  $strongarm->value = 'omitted';
  $export['og_group_content_type_conference_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_conference_session';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_conference_session'] = $strongarm;

  return $export;
}
