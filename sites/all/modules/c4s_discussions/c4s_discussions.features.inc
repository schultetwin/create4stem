<?php
/**
 * @file
 * c4s_discussions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_discussions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_discussions_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_discussions_node_info() {
  $items = array(
    'discussion' => array(
      'name' => t('Discussion'),
      'base' => 'node_content',
      'description' => t('Discussion on a given topic, like a forum'),
      'has_title' => '1',
      'title_label' => t('Topic'),
      'help' => '',
    ),
  );
  return $items;
}
