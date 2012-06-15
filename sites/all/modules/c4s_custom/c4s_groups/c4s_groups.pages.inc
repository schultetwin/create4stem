<?php

/**
 * Main callback to build the group admin page
 */
function c4s_groups_admin_page($nid) {
  $group = og_get_group('node', $nid);
  $view = views_embed_view('og_admin_members_users_', 'default', $group->gid);
  return $view;
}