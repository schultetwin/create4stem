<?php
/**
 * @file
 * c4s_conference.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4s_conference_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conference_presentation|node|conference_session|form';
  $field_group->group_name = 'group_conference_presentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference_session';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Presentation',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_conference_materials',
      2 => 'field_conference_notavail',
      3 => 'field_conference_topic',
      4 => 'field_conference_level',
      5 => 'field_conference_presenters',
      6 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Presentation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'If you are presenting at the conference, please fill in all of the information on your presentation below.  You may upload related materials (poster graphics, power point slides, related papers) in the section on materials.  If you cannot attend the full day of the conference on May 9, please indicate when you will NOT be available to present.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_conference_presentation|node|conference_session|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conference_signup|node|conference_session|form';
  $field_group->group_name = 'group_conference_signup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference_session';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sign Up',
    'weight' => '1',
    'children' => array(
      0 => 'field_conference_meals',
      1 => 'field_conference_diet',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sign Up',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please sign up for meals at the conference, and list any dietary restrictions.  There is no cost for meals.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_conference_signup|node|conference_session|form'] = $field_group;

  return $export;
}
