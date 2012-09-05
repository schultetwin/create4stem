<?php
/**
 * @file
 * c4s_conference.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4s_conference_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conference_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference - List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Conference Presentations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_conference_presenters' => 'field_conference_presenters',
    'field_conference_level' => 'field_conference_level',
    'field_conference_topic' => 'field_conference_topic',
    'field_conference_notavail' => 'field_conference_notavail',
    'field_conference_session' => 'field_conference_session',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_presenters' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_level' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_topic' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_notavail' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_session' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'conference_session' => 'conference_session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  /* Field: Content: Assigned Session */
  $handler->display->display_options['fields']['field_conference_session']['id'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['table'] = 'field_data_field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['field'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['label'] = 'Assigned';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'conference_session' => 'conference_session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'not';
  $handler->display->display_options['filters']['title']['value'] = 'only';
  $handler->display->display_options['path'] = 'conference/list/presentations';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Presentations';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Conference';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Scheduling */
  $handler = $view->new_display('page', 'Scheduling', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_conference_session',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_conference_presenters' => 'field_conference_presenters',
    'field_conference_level' => 'field_conference_level',
    'field_conference_topic' => 'field_conference_topic',
    'field_conference_notavail' => 'field_conference_notavail',
    'field_conference_session' => 'field_conference_session',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_presenters' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_level' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_topic' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_notavail' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_session' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  /* Field: Content: Assigned Session */
  $handler->display->display_options['fields']['field_conference_session']['id'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['table'] = 'field_data_field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['field'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['label'] = 'Session';
  $handler->display->display_options['fields']['field_conference_session']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'conference/list/scheduling';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scheduling';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Meals */
  $handler = $view->new_display('page', 'Meals', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Online Meal Signups';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_name' => 'field_user_name',
    'field_conference_diet' => 'field_conference_diet',
    'field_conference_meals' => 'field_conference_meals',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_diet' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_conference_meals' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['type'] = 'name_default';
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  /* Field: Content: Dietary Needs */
  $handler->display->display_options['fields']['field_conference_diet']['id'] = 'field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['table'] = 'field_data_field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['field'] = 'field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'conference_session' => 'conference_session',
  );
  /* Filter criterion: Content: Meals (field_conference_meals) */
  $handler->display->display_options['filters']['field_conference_meals_value']['id'] = 'field_conference_meals_value';
  $handler->display->display_options['filters']['field_conference_meals_value']['table'] = 'field_data_field_conference_meals';
  $handler->display->display_options['filters']['field_conference_meals_value']['field'] = 'field_conference_meals_value';
  $handler->display->display_options['filters']['field_conference_meals_value']['value'] = array(
    'Dinner (May 8)' => 'Dinner (May 8)',
    'Breakfast (May 9)' => 'Breakfast (May 9)',
    'Lunch (May 9)' => 'Lunch (May 9)',
  );
  $handler->display->display_options['filters']['field_conference_meals_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['operator_id'] = 'field_conference_meals_value_op';
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['label'] = 'Select Meal';
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['operator'] = 'field_conference_meals_value_op';
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['identifier'] = 'field_conference_meals_value';
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['path'] = 'conference/list/meals';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Meals';
  $handler->display->display_options['menu']['weight'] = '35';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['conference_list'] = $view;

  $view = new view();
  $view->name = 'conference_signup';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conference - Signup';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CREATE Conference';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['content'] = 'You are giving the following presentations (click to edit):';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<A HREF=\'http://create4stem.msu.edu/node/add/conference-session\'>Sign up to present your work</A>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '<A HREF=\'http://create4stem.msu.edu/node/add/conference-session\'>Sign up to present your work</A>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'conference_session' => 'conference_session',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['conference_signup'] = $view;

  return $export;
}
