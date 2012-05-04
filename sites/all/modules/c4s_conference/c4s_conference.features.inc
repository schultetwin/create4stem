<?php
/**
 * @file
 * c4s_conference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_conference_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_conference_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4s_conference_node_info() {
  $items = array(
    'conference_session' => array(
      'name' => t('Conference Session'),
      'base' => 'node_content',
      'description' => t('An individual paper or presentation as part of a conference.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('If you are coming as a participant to the conference, please sign up for conference meals you are planning to attend.   There is no charge for the meals.
If you are presenting at the conference, please click on "Presentation" and enter the information about your presentation, including any materials or files you wish to share.  The presentation abstract and materials will be made available through the CREATE website for interested colleagues.'),
    ),
  );
  return $items;
}
