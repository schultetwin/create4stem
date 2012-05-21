<?php
/**
 * @file
 * c4s_projects.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_projects_user_default_permissions() {
  $permissions = array();

  // Exported permission: create group_content_access.
  $permissions['create group_content_access'] = array(
    'name' => 'create group_content_access',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create project content.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any project content.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own project content.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any project content.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit group_content_access.
  $permissions['edit group_content_access'] = array(
    'name' => 'edit group_content_access',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own group_content_access.
  $permissions['edit own group_content_access'] = array(
    'name' => 'edit own group_content_access',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own project content.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view group_content_access.
  $permissions['view group_content_access'] = array(
    'name' => 'view group_content_access',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own group_content_access.
  $permissions['view own group_content_access'] = array(
    'name' => 'view own group_content_access',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
