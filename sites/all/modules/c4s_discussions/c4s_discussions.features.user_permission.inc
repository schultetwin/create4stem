<?php
/**
 * @file
 * c4s_discussions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_discussions_user_default_permissions() {
  $permissions = array();

  // Exported permission: create discussion content.
  $permissions['create discussion content'] = array(
    'name' => 'create discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any discussion content.
  $permissions['delete any discussion content'] = array(
    'name' => 'delete any discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own discussion content.
  $permissions['delete own discussion content'] = array(
    'name' => 'delete own discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any discussion content.
  $permissions['edit any discussion content'] = array(
    'name' => 'edit any discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own discussion content.
  $permissions['edit own discussion content'] = array(
    'name' => 'edit own discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
