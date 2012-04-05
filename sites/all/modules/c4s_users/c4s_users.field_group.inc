<?php
/**
 * @file
 * c4s_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4s_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|profile2|main|form';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_facebook',
      1 => 'field_profile_email',
      2 => 'field_profile_phone',
      3 => 'field_profile_twitter',
      4 => 'field_profile_linkedin',
      5 => 'field_profile_fax',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_profile_contact|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_courses|profile2|main|form';
  $field_group->group_name = 'group_profile_courses';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Courses Taught',
    'weight' => '5',
    'children' => array(
      0 => 'field_profile_courses',
      1 => 'field_profile_courselinks',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Courses Taught',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_profile_courses|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_position_2|user|user|form';
  $field_group->group_name = 'group_profile_position_2';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Position',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_institution',
      1 => 'field_profile_college',
      2 => 'field_profile_department',
      3 => 'field_profile_title',
      4 => 'field_profile_role',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_position_2|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_research|profile2|main|form';
  $field_group->group_name = 'group_profile_research';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Research Interests',
    'weight' => '3',
    'children' => array(
      0 => 'field_profile_research',
      1 => 'field_profile_researchlinks',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Research Interests',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_profile_research|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_groups|user|user|form';
  $field_group->group_name = 'group_user_groups';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '4',
    'children' => array(
      0 => 'group_audience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Groups',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_groups|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_password|user|user|form';
  $field_group->group_name = 'group_user_password';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Username & Password',
    'weight' => '3',
    'children' => array(
      0 => 'account',
      1 => 'timezone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Username & Password',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_password|user|user|form'] = $field_group;

  return $export;
}
