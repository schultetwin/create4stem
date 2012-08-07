<?php

/*
 * Implements hook_views_default_views().
 */
function c4s_groups_views_default_views() {
  $views = array();
  $view = new view;
  $view->name = 'og_admin_members_users_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'og_membership';
  $view->human_name = 'OG Admin Members (Users)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'access administration pages';
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
    'field_user_name' => 'field_user_name',
    'mail' => 'mail',
    'created' => 'created',
    'membership_form' => 'membership_form',
    'roles_form' => 'roles_form',
    'remove_member_link' => 'remove_member_link',
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
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'membership_form' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'roles_form' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'remove_member_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['required'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'og_membership_related_user';
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
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['field_user_name']['settings'] = array(
    'format' => 'default',
    'markup' => 0,
    'output' => 'default',
    'multiple' => 'default',
    'multiple_delimiter' => ', ',
    'multiple_and' => 'text',
    'multiple_delimiter_precedes_last' => 'never',
    'multiple_el_al_min' => '3',
    'multiple_el_al_first' => '1',
  );
  $handler->display->display_options['fields']['field_user_name']['field_api_classes'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'og_membership_related_user';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: OG membership: OG Membership Form */
  $handler->display->display_options['fields']['membership_form']['id'] = 'membership_form';
  $handler->display->display_options['fields']['membership_form']['table'] = 'og_membership';
  $handler->display->display_options['fields']['membership_form']['field'] = 'membership_form';
  $handler->display->display_options['fields']['membership_form']['label'] = 'Member State';
  $handler->display->display_options['fields']['membership_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['membership_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['membership_form']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['membership_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['membership_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['membership_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['membership_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['membership_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['membership_form']['hide_alter_empty'] = 1;
  /* Field: OG membership: C4S Groups Form */
  $handler->display->display_options['fields']['roles_form']['id'] = 'roles_form';
  $handler->display->display_options['fields']['roles_form']['table'] = 'og_membership';
  $handler->display->display_options['fields']['roles_form']['field'] = 'roles_form';
  $handler->display->display_options['fields']['roles_form']['label'] = 'User Group Roles';
  $handler->display->display_options['fields']['roles_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['roles_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['roles_form']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['roles_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['roles_form']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['roles_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['roles_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['roles_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['roles_form']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['roles_form']['c4s_groups_exclude_roles'] = array(
    0 => 1,
    1 => '1',
    2 => '2',
    3 => 0,
  );
  /* Field: OG membership: Delete Membership Link */
  $handler->display->display_options['fields']['remove_member_link']['id'] = 'remove_member_link';
  $handler->display->display_options['fields']['remove_member_link']['table'] = 'og_membership';
  $handler->display->display_options['fields']['remove_member_link']['field'] = 'remove_member_link';
  $handler->display->display_options['fields']['remove_member_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['remove_member_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['remove_member_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['remove_member_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['remove_member_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['remove_member_link']['hide_alter_empty'] = 1;
  /* Sort criterion: OG membership: State */
  $handler->display->display_options['sorts']['state']['id'] = 'state';
  $handler->display->display_options['sorts']['state']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['state']['field'] = 'state';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: OG membership: OG group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;

  $views[$view->name] = $view;

  return $views;
}
