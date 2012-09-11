<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of og_viewscontext_access_group_member
 *
 * @author mark
 */
class og_viewscontext_access_group_member extends views_plugin_access{
  function summary_title() {
    return t('Current User is Group Member');
  }

  /**
   * Determine if the current user has access or not.
   */
  function access($account) {
    // default to no access controe
    $group = og_context();
    if ($group == null) {
      return FALSE;
    }

    return og_is_member($group->gid, 'user', $account);
  }
}

?>
