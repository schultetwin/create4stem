<?php
/**
 * @file
 * c4s_conference.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_conference_user_default_permissions() {
  $permissions = array();

  // Exported permission: create conference_session content
  $permissions['create conference_session content'] = array(
    'name' => 'create conference_session content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_conference_session
  $permissions['create field_conference_session'] = array(
    'name' => 'create field_conference_session',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete any conference_session content
  $permissions['delete any conference_session content'] = array(
    'name' => 'delete any conference_session content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own conference_session content
  $permissions['delete own conference_session content'] = array(
    'name' => 'delete own conference_session content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any conference_session content
  $permissions['edit any conference_session content'] = array(
    'name' => 'edit any conference_session content',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_conference_session
  $permissions['edit field_conference_session'] = array(
    'name' => 'edit field_conference_session',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own conference_session content
  $permissions['edit own conference_session content'] = array(
    'name' => 'edit own conference_session content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_conference_session
  $permissions['edit own field_conference_session'] = array(
    'name' => 'edit own field_conference_session',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: view field_conference_session
  $permissions['view field_conference_session'] = array(
    'name' => 'view field_conference_session',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_conference_session
  $permissions['view own field_conference_session'] = array(
    'name' => 'view own field_conference_session',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
