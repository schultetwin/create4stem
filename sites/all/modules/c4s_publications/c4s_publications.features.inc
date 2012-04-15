<?php
/**
 * @file
 * c4s_publications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_publications_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_publications_views_api() {
  return array("version" => "3.0");
}
