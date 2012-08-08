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
 * Implements hook_flag_default_flags().
 */
function c4s_projects_flag_default_flags() {
  $flags = array();
  // Exported flag: "Featured Projects".
  $flags['featured_project'] = array(
    'content_type' => 'node',
    'title' => 'Featured Projects',
    'global' => '1',
    'types' => array(
      0 => 'project',
    ),
    'flag_short' => 'Feature',
    'flag_long' => 'Feature this project',
    'flag_message' => '',
    'unflag_short' => 'Unfeature',
    'unflag_long' => 'Un-feature this project',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '3',
        1 => '4',
      ),
      'unflag' => array(
        0 => '3',
        1 => '4',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'c4s_projects',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;
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
