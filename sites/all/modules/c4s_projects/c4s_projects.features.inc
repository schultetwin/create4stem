<?php
/**
 * @file
 * c4s_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_projects_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_projects_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project is a currently active project associated with the institute, configured as an organic group.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
