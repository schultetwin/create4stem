<?php
/**
 * @file
 * c4s_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function c4s_users_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: content editor
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => '3',
  );

  return $roles;
}
