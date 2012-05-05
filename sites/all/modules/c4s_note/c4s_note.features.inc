<?php
/**
 * @file
 * c4s_note.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_note_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_note_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_note_node_info() {
  $items = array(
    'notes' => array(
      'name' => t('Notes'),
      'base' => 'node_content',
      'description' => t('A general note type for meeting minutes, lab notebooks, or other items that serve an intranet purpose for a group or project.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
