<?php
/**
 * @file
 * c4s_frontpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_frontpage_ctools_plugin_api() {
  return array("version" => "3");
}

/**
 * Implements hook_views_api().
 */
function c4s_frontpage_views_api() {
  return array("version" => "3.0");
}
