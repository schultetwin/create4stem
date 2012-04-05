<?php
/**
 * @file
 * c4s_featured.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_featured_user_default_permissions() {
  $permissions = array();

  // Exported permission: create featured content
  $permissions['create featured content'] = array(
    'name' => 'create featured content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any featured content
  $permissions['delete any featured content'] = array(
    'name' => 'delete any featured content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own featured content
  $permissions['delete own featured content'] = array(
    'name' => 'delete own featured content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any featured content
  $permissions['edit any featured content'] = array(
    'name' => 'edit any featured content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own featured content
  $permissions['edit own featured content'] = array(
    'name' => 'edit own featured content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
