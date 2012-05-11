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

  $view = new view;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['field_api_classes'] = 0;
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_level']['field_api_classes'] = 0;
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_topic']['field_api_classes'] = 0;
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['field_api_classes'] = 0;
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['field_api_classes'] = 0;
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_level']['field_api_classes'] = 0;
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_topic']['field_api_classes'] = 0;
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['field_api_classes'] = 0;
  /* Field: Content: Assigned Session */
  $handler->display->display_options['fields']['field_conference_session']['id'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['table'] = 'field_data_field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['field'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['label'] = 'Assigned';
  $handler->display->display_options['fields']['field_conference_session']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['field_api_classes'] = 0;
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
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Scheduling */
  $handler = $view->new_display('page', 'Scheduling', 'page_1');
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
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
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_presenters']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_presenters']['field_api_classes'] = 0;
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_conference_level']['id'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['table'] = 'field_data_field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['field'] = 'field_conference_level';
  $handler->display->display_options['fields']['field_conference_level']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_level']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_level']['field_api_classes'] = 0;
  /* Field: Content: Topic Area */
  $handler->display->display_options['fields']['field_conference_topic']['id'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['table'] = 'field_data_field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['field'] = 'field_conference_topic';
  $handler->display->display_options['fields']['field_conference_topic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_topic']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_topic']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_topic']['field_api_classes'] = 0;
  /* Field: Content: Not Available */
  $handler->display->display_options['fields']['field_conference_notavail']['id'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['table'] = 'field_data_field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['field'] = 'field_conference_notavail';
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_conference_notavail']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_conference_notavail']['field_api_classes'] = 0;
  /* Field: Content: Assigned Session */
  $handler->display->display_options['fields']['field_conference_session']['id'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['table'] = 'field_data_field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['field'] = 'field_conference_session';
  $handler->display->display_options['fields']['field_conference_session']['label'] = 'Session';
  $handler->display->display_options['fields']['field_conference_session']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_session']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_session']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'conference/list/scheduling';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scheduling';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Meals */
  $handler = $view->new_display('page', 'Meals', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Online Meal Signups';
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['type'] = 'name_default';
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: Content: Presenters */
  $handler->display->display_options['fields']['field_conference_presenters']['id'] = 'field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['table'] = 'field_data_field_conference_presenters';
  $handler->display->display_options['fields']['field_conference_presenters']['field'] = 'field_conference_presenters';
  /* Field: Content: Dietary Needs */
  $handler->display->display_options['fields']['field_conference_diet']['id'] = 'field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['table'] = 'field_data_field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['field'] = 'field_conference_diet';
  $handler->display->display_options['fields']['field_conference_diet']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_conference_diet']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_conference_diet']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_conference_diet']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['field_conference_meals_value']['expose']['reduce'] = 1;
  $handler->display->display_options['path'] = 'conference/list/meals';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Meals';
  $handler->display->display_options['menu']['weight'] = '35';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['conference_list'] = $view;

  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'You are giving the following presentations (click to edit):';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<A HREF=\'http://create4stem.msu.edu/node/add/conference-session\'>Sign up to present your work</A>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['empty'] = '<A HREF=\'http://create4stem.msu.edu/node/add/conference-session\'>Sign up to present your work</A>';
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
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
  $export['conference_signup'] = $view;

  return $export;
}
