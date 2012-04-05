<?php
/**
 * @file
 * c4s_job_posting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_job_posting_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_job_posting_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_job_posting_node_info() {
  $items = array(
    'posting' => array(
      'name' => t('Posting'),
      'base' => 'node_content',
      'description' => t('This is a job or internship posting for C4S or for one of the C4S projects'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
