<?php
/**
 * @file
 * c4s_note.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4s_note_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'group_notes';
  $view->description = 'Project or group notes (intranet)';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group Notes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project Notes';
  $handler->display->display_options['css_class'] = 'group-notes';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No notes in group';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Task';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  /* Field: Content: Assigned To */
  $handler->display->display_options['fields']['field_task_assign']['id'] = 'field_task_assign';
  $handler->display->display_options['fields']['field_task_assign']['table'] = 'field_data_field_task_assign';
  $handler->display->display_options['fields']['field_task_assign']['field'] = 'field_task_assign';
  $handler->display->display_options['fields']['field_task_assign']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_assign']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_assign']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_assign']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_assign']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_assign']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_task_assign']['field_api_classes'] = 0;
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_task_due']['id'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['table'] = 'field_data_field_task_due';
  $handler->display->display_options['fields']['field_task_due']['field'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['label'] = 'Due in';
  $handler->display->display_options['fields']['field_task_due']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_due']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_due']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_due']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_due']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_due']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_due']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_due']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_due']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_task_due']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_task_due']['settings'] = array(
    'interval' => '1',
    'interval_display' => 'raw time hence',
  );
  $handler->display->display_options['fields']['field_task_due']['field_api_classes'] = 0;
  /* Field: Content: Complete */
  $handler->display->display_options['fields']['field_task_complete']['id'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['field'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['field_api_classes'] = 0;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Group: Group Node ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['gid']['not'] = 0;
  $handler->display->display_options['arguments']['gid']['set_group_context'] = 1;
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
    'notes' => 'notes',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['path'] = 'node/%/notes';
  $handler->display->display_options['menu']['title'] = 'Materials';
  $handler->display->display_options['menu']['description'] = 'Downloadable materials from events or presentations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'changed' => 'changed',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['row_options']['separator'] = '  ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'n/j/y';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  $handler->display->display_options['block_description'] = 'Project Notes';
  $export['group_notes'] = $view;

  return $export;
}
