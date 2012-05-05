<?php
/**
 * @file
 * c4s_documents.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4s_documents_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_documents';
  $strongarm->value = array();
  $export['menu_options_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_documents';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_documents';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_documents';
  $strongarm->value = '1';
  $export['node_preview_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_documents';
  $strongarm->value = 0;
  $export['node_submitted_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_documents';
  $strongarm->value = 'omitted';
  $export['og_group_type_documents'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_documents';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_documents'] = $strongarm;

  return $export;
}
