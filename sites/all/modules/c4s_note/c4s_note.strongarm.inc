<?php
/**
 * @file
 * c4s_note.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4s_note_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_notes';
  $strongarm->value = array();
  $export['menu_options_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_notes';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_notes';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_notes';
  $strongarm->value = '1';
  $export['node_preview_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_notes';
  $strongarm->value = 1;
  $export['node_submitted_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_notes';
  $strongarm->value = 'omitted';
  $export['og_group_type_notes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_notes';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_notes'] = $strongarm;

  return $export;
}
