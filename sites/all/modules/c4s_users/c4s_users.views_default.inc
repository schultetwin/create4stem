<?php
/**
 * @file
 * c4s_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4s_users_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'people_advisory_board';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Advisory Board';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advisory Board';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
    'field_profile_institution' => 'field_profile_institution',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_institution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_profile_institution']['id'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['table'] = 'field_data_field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['field'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['label'] = '';
  $handler->display->display_options['fields']['field_profile_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: C4S Relationship (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['value'] = array(
    13 => '13',
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'institute_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/advisory-board';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Advisory Board';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['people_advisory_board'] = $view;

  $view = new view;
  $view->name = 'people_collaborators';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Collaborators';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'External Collaborators';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
    'field_profile_institution' => 'field_profile_institution',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_institution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_profile_institution']['id'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['table'] = 'field_data_field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['field'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['label'] = '';
  $handler->display->display_options['fields']['field_profile_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: C4S Relationship (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'institute_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/collaborators';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'External Collaborators';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['people_collaborators'] = $view;

  $view = new view;
  $view->name = 'people_directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Institute Directory';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
    'field_profile_institution' => 'field_profile_institution',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_institution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'To search the institute directory for a particular person, enter any part of their first and/or last names below and click "apply".';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_profile_institution']['id'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['table'] = 'field_data_field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['field'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['label'] = '';
  $handler->display->display_options['fields']['field_profile_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['filters']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['filters']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['filters']['field_user_name_family']['field'] = 'field_user_name_family';
  $handler->display->display_options['filters']['field_user_name_family']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_name_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_name_family']['expose']['operator_id'] = 'field_user_name_family_op';
  $handler->display->display_options['filters']['field_user_name_family']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['field_user_name_family']['expose']['operator'] = 'field_user_name_family_op';
  $handler->display->display_options['filters']['field_user_name_family']['expose']['identifier'] = 'field_user_name_family';
  $handler->display->display_options['filters']['field_user_name_family']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_user_name_family']['expose']['multiple'] = FALSE;
  /* Filter criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['filters']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['filters']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['filters']['field_user_name_given']['field'] = 'field_user_name_given';
  $handler->display->display_options['filters']['field_user_name_given']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_name_given']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_name_given']['expose']['operator_id'] = 'field_user_name_given_op';
  $handler->display->display_options['filters']['field_user_name_given']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_user_name_given']['expose']['operator'] = 'field_user_name_given_op';
  $handler->display->display_options['filters']['field_user_name_given']['expose']['identifier'] = 'field_user_name_given';
  $handler->display->display_options['filters']['field_user_name_given']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_user_name_given']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/directory';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Directory';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['people_directory'] = $view;

  $view = new view;
  $view->name = 'people_faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collaborating Faculty';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: C4S Relationship (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'institute_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/faculty';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Collaborating Faculty';
  $handler->display->display_options['menu']['description'] = 'Faculty collaborating with the Institute';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['people_faculty'] = $view;

  $view = new view;
  $view->name = 'people_post_docs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Post-Docs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Post-Doctoral Fellows';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: C4S Relationship (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['value'] = array(
    11 => '11',
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'institute_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/post-docs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Post-Docs';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['people_post_docs'] = $view;

  $view = new view;
  $view->name = 'people_staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'People - Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Institute Personnel';
  $handler->display->display_options['css_class'] = 'staff';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_about' => 'field_user_name',
    'field_profile_email' => 'field_profile_email',
    'field_profile_phone' => 'field_profile_phone',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_about' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_email']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_email']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_email']['field_api_classes'] = 0;
  /* Field: Profile: Phone */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_phone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_phone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_phone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_phone']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_phone']['field_api_classes'] = 0;
  /* Sort criterion: User: Name (field_user_name:family) */
  $handler->display->display_options['sorts']['field_user_name_family']['id'] = 'field_user_name_family';
  $handler->display->display_options['sorts']['field_user_name_family']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_family']['field'] = 'field_user_name_family';
  /* Sort criterion: User: Name (field_user_name:given) */
  $handler->display->display_options['sorts']['field_user_name_given']['id'] = 'field_user_name_given';
  $handler->display->display_options['sorts']['field_user_name_given']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['sorts']['field_user_name_given']['field'] = 'field_user_name_given';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: C4S Relationship (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'institute_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'people/staff';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Institute Personnel';
  $handler->display->display_options['menu']['description'] = 'Core Institute Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'People';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['people_staff'] = $view;

  $view = new view;
  $view->name = 'profile_about';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Profile - About';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'family';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_title']['field_api_classes'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 1;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 0;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_profile';
  /* Field: User: Department */
  $handler->display->display_options['fields']['field_profile_department']['id'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['table'] = 'field_data_field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['field'] = 'field_profile_department';
  $handler->display->display_options['fields']['field_profile_department']['label'] = '';
  $handler->display->display_options['fields']['field_profile_department']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: User: College/Division */
  $handler->display->display_options['fields']['field_profile_college']['id'] = 'field_profile_college';
  $handler->display->display_options['fields']['field_profile_college']['table'] = 'field_data_field_profile_college';
  $handler->display->display_options['fields']['field_profile_college']['field'] = 'field_profile_college';
  $handler->display->display_options['fields']['field_profile_college']['label'] = '';
  $handler->display->display_options['fields']['field_profile_college']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_college']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_college']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_college']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_college']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_college']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_college']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_college']['field_api_classes'] = 0;
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_profile_institution']['id'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['table'] = 'field_data_field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['field'] = 'field_profile_institution';
  $handler->display->display_options['fields']['field_profile_institution']['label'] = '';
  $handler->display->display_options['fields']['field_profile_institution']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_institution']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_institution']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_institution']['field_api_classes'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'profile-about';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['label'] = '';
  $handler->display->display_options['fields']['field_profile_about']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'user/%';
  $handler->display->display_options['menu']['title'] = 'About';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'User Profile';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'profile-block';
  $handler->display->display_options['block_description'] = 'Profile Picture/Info';
  $export['profile_about'] = $view;

  $view = new view;
  $view->name = 'profile_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Profile - Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'family';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: Profile: Courses */
  $handler->display->display_options['fields']['field_profile_courses']['id'] = 'field_profile_courses';
  $handler->display->display_options['fields']['field_profile_courses']['table'] = 'field_data_field_profile_courses';
  $handler->display->display_options['fields']['field_profile_courses']['field'] = 'field_profile_courses';
  $handler->display->display_options['fields']['field_profile_courses']['relationship'] = 'profile';
  /* Field: Profile: Courses Links */
  $handler->display->display_options['fields']['field_profile_courselinks']['id'] = 'field_profile_courselinks';
  $handler->display->display_options['fields']['field_profile_courselinks']['table'] = 'field_data_field_profile_courselinks';
  $handler->display->display_options['fields']['field_profile_courselinks']['field'] = 'field_profile_courselinks';
  $handler->display->display_options['fields']['field_profile_courselinks']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_courselinks']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_profile_courselinks']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_courselinks']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_profile_courselinks']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_profile_courselinks']['field_api_classes'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/courses';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['description'] = 'Courses Developed or Taught';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'User Profile';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['profile_courses'] = $view;

  $view = new view;
  $view->name = 'profile_research';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Profile - Research';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Research Interests';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'family';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: Profile: Research */
  $handler->display->display_options['fields']['field_profile_research']['id'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['table'] = 'field_data_field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['field'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['relationship'] = 'profile';
  /* Field: Profile: Research Links */
  $handler->display->display_options['fields']['field_profile_researchlinks']['id'] = 'field_profile_researchlinks';
  $handler->display->display_options['fields']['field_profile_researchlinks']['table'] = 'field_data_field_profile_researchlinks';
  $handler->display->display_options['fields']['field_profile_researchlinks']['field'] = 'field_profile_researchlinks';
  $handler->display->display_options['fields']['field_profile_researchlinks']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_researchlinks']['type'] = 'link_separate';
  $handler->display->display_options['fields']['field_profile_researchlinks']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_profile_researchlinks']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_researchlinks']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_profile_researchlinks']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_profile_researchlinks']['field_api_classes'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/research';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Research';
  $handler->display->display_options['menu']['description'] = 'Research Background & Interests';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'User Profile';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['profile_research'] = $view;

  return $export;
}
