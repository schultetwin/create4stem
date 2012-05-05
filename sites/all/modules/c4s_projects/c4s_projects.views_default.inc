<?php
/**
 * @file
 * c4s_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4s_projects_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'group_events';
  $view->description = 'Events lists for a given project or group';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['css_class'] = 'group-events';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';

  /* Display: Upcoming Page */
  $handler = $view->new_display('page', 'Upcoming Page', 'page');
  $handler->display->display_options['path'] = 'group/%/events';
  $handler->display->display_options['menu']['title'] = 'Upcoming';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Past Page */
  $handler = $view->new_display('page', 'Past Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Events';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'group/%/events/past';
  $handler->display->display_options['menu']['title'] = 'Recent';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Group Upcoming Events';
  $export['group_events'] = $view;

  $view = new view;
  $view->name = 'group_front_page';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Group Front Page';
  $view->core = 0;
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'featured' => 'featured',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'group/%/front';
  $export['group_front_page'] = $view;

  $view = new view;
  $view->name = 'group_list';
  $view->description = 'Show active groups that are nodes';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group List';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Institute Groups and Affiliated Projects';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'group_access',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'group_access' => 'group_access',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'group_access' => array(
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
  /* Relationship: Group: Node group */
  $handler->display->display_options['relationships']['og_rel']['id'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_rel']['field'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Group visibility */
  $handler->display->display_options['fields']['group_access']['id'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['table'] = 'field_data_group_access';
  $handler->display->display_options['fields']['group_access']['field'] = 'group_access';
  $handler->display->display_options['fields']['group_access']['label'] = '';
  $handler->display->display_options['fields']['group_access']['exclude'] = TRUE;
  $handler->display->display_options['fields']['group_access']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['group_access']['alter']['text'] = '<br>';
  $handler->display->display_options['fields']['group_access']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['external'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['group_access']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['group_access']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['group_access']['alter']['html'] = 0;
  $handler->display->display_options['fields']['group_access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_access']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['group_access']['hide_empty'] = 0;
  $handler->display->display_options['fields']['group_access']['empty_zero'] = 0;
  $handler->display->display_options['fields']['group_access']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['group_access']['field_api_classes'] = 0;
  /* Filter criterion: OG group: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Group: Group\'s state';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'group-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['description'] = 'Institute Projects or Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['group_list'] = $view;

  $view = new view;
  $view->name = 'group_members';
  $view->description = 'List of members of a given project or group';
  $view->tag = 'group';
  $view->base_table = 'users';
  $view->human_name = 'Group Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group Members';
  $handler->display->display_options['css_class'] = 'group-members';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  /* Relationship: Group membership: User group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 1;
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
  $handler->display->display_options['fields']['uid']['alter']['more_link'] = 0;
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
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
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
  $handler->display->display_options['fields']['field_profile_department']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  /* Field: Profile: About Me */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_about']['label'] = 'About';
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
  $handler->display->display_options['fields']['field_profile_about']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_about']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_about']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_profile_about']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_profile_about']['field_api_classes'] = 0;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'group/%/members';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See all members';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'picture' => 'picture',
    'field_user_name' => 'field_user_name',
    'field_profile_title' => 'field_user_name',
    'field_profile_department' => 'field_user_name',
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
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['uid']['alter']['more_link'] = 0;
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
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'small_thumb';
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
  $handler->display->display_options['fields']['field_profile_department']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_department']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_department']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_department']['field_api_classes'] = 0;
  $export['group_members'] = $view;

  $view = new view;
  $view->name = 'group_news';
  $view->description = 'Group or project news items and announcements';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project News';
  $handler->display->display_options['css_class'] = 'group-news';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Field: Groups audience (group_audience:gid) */
  $handler->display->display_options['sorts']['group_audience_gid']['id'] = 'group_audience_gid';
  $handler->display->display_options['sorts']['group_audience_gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['sorts']['group_audience_gid']['field'] = 'group_audience_gid';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
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
    'story' => 'story',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'group/%/news';
  $handler->display->display_options['menu']['title'] = 'Institute News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Project News';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'group/%/news.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
    'block' => 'block',
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Project News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '125';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 1;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  $handler->display->display_options['block_description'] = 'Group News';
  $export['group_news'] = $view;

  $view = new view;
  $view->name = 'group_publications';
  $view->description = 'Publications associated with a project or group';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group Publications';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Project Publications';
  $handler->display->display_options['css_class'] = 'group-publications';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'name';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'Nothing found';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Field: Biblio: Biblio Citation */
  $handler->display->display_options['fields']['citation']['id'] = 'citation';
  $handler->display->display_options['fields']['citation']['table'] = 'biblio';
  $handler->display->display_options['fields']['citation']['field'] = 'citation';
  $handler->display->display_options['fields']['citation']['label'] = '';
  $handler->display->display_options['fields']['citation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['citation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['citation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['citation']['style_name'] = 'vancouver';
  /* Sort criterion: Biblio: Year of Publication */
  $handler->display->display_options['sorts']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['sorts']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['sorts']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['sorts']['biblio_year']['order'] = 'DESC';
  /* Sort criterion: Biblio: Type of Publication */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'biblio_types';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Biblio: Year of Publication */
  $handler->display->display_options['arguments']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['arguments']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['biblio_year']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biblio' => 'biblio',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Groups audience (group_audience:gid) */
  $handler->display->display_options['filters']['group_audience_gid']['id'] = 'group_audience_gid';
  $handler->display->display_options['filters']['group_audience_gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['filters']['group_audience_gid']['field'] = 'group_audience_gid';
  $handler->display->display_options['filters']['group_audience_gid']['operator'] = 'not empty';

  /* Display: Group by Year */
  $handler = $view->new_display('page', 'Group by Year', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'biblio_year';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Biblio: Biblio Citation */
  $handler->display->display_options['fields']['citation']['id'] = 'citation';
  $handler->display->display_options['fields']['citation']['table'] = 'biblio';
  $handler->display->display_options['fields']['citation']['field'] = 'citation';
  $handler->display->display_options['fields']['citation']['label'] = '';
  $handler->display->display_options['fields']['citation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['citation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['citation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['citation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['citation']['style_name'] = 'vancouver';
  /* Field: Biblio: Year of Publication */
  $handler->display->display_options['fields']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['label'] = '';
  $handler->display->display_options['fields']['biblio_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['biblio_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['biblio_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['biblio_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['biblio_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['biblio_year']['biblio_label'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Biblio: Year of Publication */
  $handler->display->display_options['arguments']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['arguments']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['biblio_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['biblio_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['biblio_year']['specify_validation'] = 1;
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'default';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  $handler->display->display_options['path'] = 'group/%/publications';
  $handler->display->display_options['menu']['title'] = 'By Year';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Publications';
  $handler->display->display_options['tab_options']['description'] = 'Institute Publications, papers, and academic work';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['group_publications'] = $view;

  $view = new view;
  $view->name = 'projects_home';
  $view->description = 'Show active groups that are nodes';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'Projects - Home';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Projects List';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Group: Node group */
  $handler->display->display_options['relationships']['og_rel']['id'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_rel']['field'] = 'og_rel';
  $handler->display->display_options['relationships']['og_rel']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: OG group: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_rel';
  $handler->display->display_options['fields']['created']['label'] = 'Since';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Filter criterion: OG group: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Group: Group\'s state';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'projects-list';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'group-list/feed';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $export['projects_home'] = $view;

  return $export;
}
