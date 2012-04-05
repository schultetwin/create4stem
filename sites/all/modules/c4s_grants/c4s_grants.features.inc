<?php
/**
 * @file
 * c4s_grants.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_grants_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_views_api().
 */
function c4s_grants_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_grants_node_info() {
  $items = array(
    'grantc4s' => array(
      'name' => t('GrantC4S'),
      'base' => 'node_content',
      'description' => t('Grants administered by the Institute to which other people may apply for funding'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
