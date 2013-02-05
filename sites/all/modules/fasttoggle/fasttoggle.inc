<?php

/**
 * @file
 * Provides common routines.
 */

function fasttoggle_potential_toggleable_roles()
{
  static $roles = array();
  static $have_run = false;
  
  if ($have_run) {
    return $roles;
  }
  
  $roles = $available_roles = user_roles(TRUE);
  unset($roles[DRUPAL_ANONYMOUS_RID]);
  unset($roles[DRUPAL_AUTHENTICATED_RID]);
  
  $have_run = true;
  return $roles;
}

function fasttoggle_sitewide_toggleable_roles()
{
  static $roles = array();

  if (!empty($roles)) {
    return $roles;
  }
  
  $roles = fasttoggle_potential_toggleable_roles();
  $allowed_roles = variable_get('fasttoggle_role_settings', array());
  
  if (empty($allowed_roles))
    return array();
  
  if (!empty($roles)) {
    foreach($roles as $key => $name) {
      if (!array_key_exists($key, $allowed_roles)) {
        unset($roles[$key]);
      }
    }
  }
  
  return $roles;
}

function fasttoggle_user_toggleable_roles()
{
  static $roles = array();

  if (!empty($roles)) {
    return $roles;
  }

  $roles = fasttoggle_sitewide_toggleable_roles();

  if (!empty($roles)) {
    foreach($roles as $key => $name) {
      if (!user_access(fasttoggle_role_permission($name))) {
        unset($roles[$key]);
      }
    }
  }

  return $roles;
}
