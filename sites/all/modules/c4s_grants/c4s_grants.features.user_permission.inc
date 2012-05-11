<?php
/**
 * @file
 * c4s_grants.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_grants_user_default_permissions() {
  $permissions = array();

  // Exported permission: create grantc4s content.
  $permissions['create grantc4s content'] = array(
    'name' => 'create grantc4s content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any grantc4s content.
  $permissions['delete any grantc4s content'] = array(
    'name' => 'delete any grantc4s content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own grantc4s content.
  $permissions['delete own grantc4s content'] = array(
    'name' => 'delete own grantc4s content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any grantc4s content.
  $permissions['edit any grantc4s content'] = array(
    'name' => 'edit any grantc4s content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own grantc4s content.
  $permissions['edit own grantc4s content'] = array(
    'name' => 'edit own grantc4s content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
