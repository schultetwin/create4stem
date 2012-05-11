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
  $field_group->identifier = 'group_about_me|profile2|main|form';
  $field_group->group_name = 'group_about_me';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_profile_stuff';
  $field_group->data = array(
    'label' => 'About Me',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_about',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'About Me',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Enter in this section a basic description of yourself and your interests.  This will be shown on the main profile display page for you at the institute.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_about_me|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|profile2|main|form';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_profile_stuff';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_facebook',
      1 => 'field_profile_phone',
      2 => 'field_profile_twitter',
      3 => 'field_profile_linkedin',
      4 => 'field_profile_fax',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Enter optional additional contact information to be linked to your online profile at the Institute.  Click on the additional tabs above to add brief sections "About Me", your "Research Interests", or your "Courses Taught".  These will appear along with your online profile to make it easier for fellow researchers who may share an interest in your work to identify and contact you.',
      ),
      'formatter' => 'closed',
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
  $field_group->parent_name = 'group_profile_stuff';
  $field_group->data = array(
    'label' => 'Courses Taught',
    'weight' => '5',
    'children' => array(
      0 => 'field_profile_courses',
      1 => 'field_profile_courselinks',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Courses Taught',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Add any additional information you may wish to share about the courses you have taught or your teaching interests that you may feel is relevant.  This may be used by colleagues in identifying fellow faculty or students who may be interested in collaborating on work.  You may also add links to course website(s) if you like.  This will appear on a separate tab on your profile.',
      ),
      'formatter' => 'closed',
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
  $field_group->parent_name = 'group_stuff';
  $field_group->data = array(
    'label' => 'Name & Position',
    'weight' => '3',
    'children' => array(),
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
  $field_group->parent_name = 'group_profile_stuff';
  $field_group->data = array(
    'label' => 'Research Interests',
    'weight' => '4',
    'children' => array(
      0 => 'field_profile_research',
      1 => 'field_profile_researchlinks',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Research Interests',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Add additional descriptions of your research work and interests for those who would like to know more, or who may be looking for a fellow Institute-related faculty member to consult with on a project.  You may also add links to your research website(s) below.  This information will appear as a tab on your personal profile.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_profile_research|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_stuff|profile2|main|form';
  $field_group->group_name = 'group_profile_stuff';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Stuff',
    'weight' => '0',
    'children' => array(
      0 => 'group_profile_contact',
      1 => 'group_profile_research',
      2 => 'group_profile_courses',
      3 => 'group_about_me',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_profile_stuff|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|user|user|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stuff';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_profile_role',
      1 => 'contact',
      2 => 'wysiwyg',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_settings|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stuff|user|user|form';
  $field_group->group_name = 'group_stuff';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stuff',
    'weight' => '1',
    'children' => array(
      0 => 'group_profile_position_2',
      1 => 'group_user_password',
      2 => 'group_user_groups',
      3 => 'group_settings',
      4 => 'group_photo',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_stuff|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_groups|user|user|form';
  $field_group->group_name = 'group_user_groups';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stuff';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '4',
    'children' => array(
      0 => 'group_audience',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
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
  $field_group->parent_name = 'group_stuff';
  $field_group->data = array(
    'label' => 'Username & Password',
    'weight' => '2',
    'children' => array(
      0 => 'field_user_name',
      1 => 'field_profile_institution',
      2 => 'field_profile_college',
      3 => 'field_profile_department',
      4 => 'field_profile_title',
      5 => 'field_profile_msu',
      6 => 'account',
      7 => 'timezone',
      8 => 'picture',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Username & Password',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please enter your basic information to create an account with the Institute.  Items with red * marks are required.  When you are done, enter any information you would like in the Profile section below.  YOU MUST CLICK "Create New Account" at the bottom of the screen to complete the process.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_user_password|user|user|form'] = $field_group;

  return $export;
}
