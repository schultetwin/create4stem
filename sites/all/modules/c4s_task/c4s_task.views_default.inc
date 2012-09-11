<?php
/**
 * @file
 * c4s_task.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function c4s_task_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'group_tasks';
  $view->description = 'Work tasks associated with a project or group (intranet)';
  $view->tag = 'group';
  $view->base_table = 'node';
  $view->human_name = 'Group Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project Tasks';
  $handler->display->display_options['css_class'] = 'group-tasks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'group_member';
  $handler->display->display_options['access']['arg_pos'] = '1';
  $handler->display->display_options['access']['nid_gid'] = 1;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_1' => 'title_1',
    'timestamp' => 'title_1',
    'field_task_assign' => 'field_task_assign',
    'field_task_due' => 'field_task_due',
    'field_task_complete' => 'field_task_complete',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_assign' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_due' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_complete' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Add Content Link */
  $handler->display->display_options['header']['add_content_link']['id'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['table'] = 'views';
  $handler->display->display_options['header']['add_content_link']['field'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['empty'] = TRUE;
  $handler->display->display_options['header']['add_content_link']['bundle'] = 'task';
  $handler->display->display_options['header']['add_content_link']['into_group'] = 1;
  $handler->display->display_options['header']['add_content_link']['link_title'] = 'Add new Task';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No tasks in this group';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Task';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = TRUE;
  /* Field: Content: Assigned To */
  $handler->display->display_options['fields']['field_task_assign']['id'] = 'field_task_assign';
  $handler->display->display_options['fields']['field_task_assign']['table'] = 'field_data_field_task_assign';
  $handler->display->display_options['fields']['field_task_assign']['field'] = 'field_task_assign';
  /* Field: Content: Due Date */
  $handler->display->display_options['fields']['field_task_due']['id'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['table'] = 'field_data_field_task_due';
  $handler->display->display_options['fields']['field_task_due']['field'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['label'] = 'Due in';
  $handler->display->display_options['fields']['field_task_due']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_task_due']['settings'] = array(
    'interval' => '1',
    'interval_display' => 'raw time hence',
  );
  /* Field: Content: Complete */
  $handler->display->display_options['fields']['field_task_complete']['id'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['field'] = 'field_task_complete';
  /* Sort criterion: Content: Complete (field_task_complete) */
  $handler->display->display_options['sorts']['field_task_complete_value']['id'] = 'field_task_complete_value';
  $handler->display->display_options['sorts']['field_task_complete_value']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['sorts']['field_task_complete_value']['field'] = 'field_task_complete_value';
  /* Sort criterion: Content: Due Date (field_task_due) */
  $handler->display->display_options['sorts']['field_task_due_value']['id'] = 'field_task_due_value';
  $handler->display->display_options['sorts']['field_task_due_value']['table'] = 'field_data_field_task_due';
  $handler->display->display_options['sorts']['field_task_due_value']['field'] = 'field_task_due_value';
  /* Contextual filter: Field: Groups audience (group_audience:gid) */
  $handler->display->display_options['arguments']['group_audience_gid']['id'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['arguments']['group_audience_gid']['field'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group_audience_gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group_audience_gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['group_audience_gid']['validate']['type'] = 'nid_as_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['must_be_member'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['set_group_context'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate']['fail'] = 'access denied';
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
    'task' => 'task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Complete (field_task_complete) */
  $handler->display->display_options['filters']['field_task_complete_value']['id'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['filters']['field_task_complete_value']['field'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_task_complete_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator_id'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['label'] = 'Show tasks which are';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['identifier'] = 'field_task_complete_value';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/tasks';
  $handler->display->display_options['menu']['title'] = 'Materials';
  $handler->display->display_options['menu']['description'] = 'Downloadable materials from events or presentations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['group_tasks'] = $view;

  return $export;
}
