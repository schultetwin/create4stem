<?php
/**
 * @file
 * c4s_publications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4s_publications_user_default_permissions() {
  $permissions = array();

  // Exported permission: access biblio content
  $permissions['access biblio content'] = array(
    'name' => 'access biblio content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: administer biblio
  $permissions['administer biblio'] = array(
    'name' => 'administer biblio',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: create biblio content
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any biblio content
  $permissions['delete any biblio content'] = array(
    'name' => 'delete any biblio content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own biblio content
  $permissions['delete own biblio content'] = array(
    'name' => 'delete own biblio content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any biblio content
  $permissions['edit any biblio content'] = array(
    'name' => 'edit any biblio content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit biblio authors
  $permissions['edit biblio authors'] = array(
    'name' => 'edit biblio authors',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit by all biblio authors
  $permissions['edit by all biblio authors'] = array(
    'name' => 'edit by all biblio authors',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit own biblio content
  $permissions['edit own biblio content'] = array(
    'name' => 'edit own biblio content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: import from file
  $permissions['import from file'] = array(
    'name' => 'import from file',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show download links
  $permissions['show download links'] = array(
    'name' => 'show download links',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show export links
  $permissions['show export links'] = array(
    'name' => 'show export links',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show filter tab
  $permissions['show filter tab'] = array(
    'name' => 'show filter tab',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show own download links
  $permissions['show own download links'] = array(
    'name' => 'show own download links',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show sort links
  $permissions['show sort links'] = array(
    'name' => 'show sort links',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: view full text
  $permissions['view full text'] = array(
    'name' => 'view full text',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'biblio',
  );

  return $permissions;
}
