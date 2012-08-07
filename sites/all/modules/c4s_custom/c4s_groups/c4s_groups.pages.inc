<?php

/**
 * Main callback to build the group admin page
 */
function c4s_groups_admin_page($nid) {
  $output = array();
  $group = og_get_group('node', $nid);
  if (views_get_view_result('og_admin_members_users_', 'default', $group->gid)) {
    $output['user_view'] = array('#type' => 'markup', '#markup' => views_embed_view('og_admin_members_users_', 'default', $group->gid));
  }
  $output['add_user_form'] = drupal_get_form('c4s_groups_add_user_group', $group);
  if (views_get_view_result('group_content_publicity', 'default', $group->gid)) {
    $output['content_view'] = array('#type' => 'markup', '#markup' => views_embed_view('group_content_publicity', 'default', $group->gid));
  }
  return $output;
}