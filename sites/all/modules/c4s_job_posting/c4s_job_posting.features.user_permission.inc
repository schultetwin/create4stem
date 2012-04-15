<?php
/**
 * @file
 * c4s_job_posting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_job_posting_user_default_permissions() {
  $permissions = array();

  // Exported permission: create posting content
  $permissions['create posting content'] = array(
    'name' => 'create posting content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any posting content
  $permissions['delete any posting content'] = array(
    'name' => 'delete any posting content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own posting content
  $permissions['delete own posting content'] = array(
    'name' => 'delete own posting content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any posting content
  $permissions['edit any posting content'] = array(
    'name' => 'edit any posting content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own posting content
  $permissions['edit own posting content'] = array(
    'name' => 'edit own posting content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
