<?php

/**
 * Callback to unsubscribe a user for a group
 */
function c4s_group_unsubscribe_user($entity_type, $etid, $membership_id = NULL) {
  $membership = og_membership_load($membership_id);
  $group = $membership->group();
  $entities = entity_load($membership->entity_type, array($membership->etid));
  if (!empty($entities)) {
    $entity = array_pop($entities);
    og_ungroup($group->gid, $membership->entity_type, $entity);
    $membership->delete();
  }
  drupal_goto();
}