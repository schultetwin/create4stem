<?php
/**
 * @file
 * c4s_note.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_note_user_default_permissions() {
  $permissions = array();

  // Exported permission: create notes content.
  $permissions['create notes content'] = array(
    'name' => 'create notes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any notes content.
  $permissions['delete any notes content'] = array(
    'name' => 'delete any notes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own notes content.
  $permissions['delete own notes content'] = array(
    'name' => 'delete own notes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any notes content.
  $permissions['edit any notes content'] = array(
    'name' => 'edit any notes content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own notes content.
  $permissions['edit own notes content'] = array(
    'name' => 'edit own notes content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
