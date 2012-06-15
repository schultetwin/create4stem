<?php

/**
 * Implements hook_views_data_alter().
 */
function c4s_groups_views_data_alter(&$data) {
  $data['og_membership']['membership_form'] = array(
    'title' => t('OG Membership Form'),
    'help' => t('Provides an AJAX form to allow to add/remove people from a group'),
    'real field' => 'state',
    'field' => array(
      'handler' => 'c4s_groups_views_handler_field_membership_form',
      'click sortable' => FALSE,
    ),
  );
  $data['og_membership']['remove_member_link'] = array(
    'title' => t('Delete Membership Link'),
    'help' => t('This link will delete a member from a group'),
    'real field' => 'id',
    'field' => array(
      'handler' => 'c4s_groups_views_handler_field_delete_link',
      'click sortable' => FALSE,
    ),
  );
  $data['og_membership']['roles_form'] = array(
    'title' => t('C4S Groups Form'),
    'help' => t('Provides a field to make or remove someone a group admin'),
    'real field' => 'id',
    'field' => array(
      'handler' => 'c4s_groups_views_handler_role_form',
      'click sortable' => FALSE,
    ),
  );
}