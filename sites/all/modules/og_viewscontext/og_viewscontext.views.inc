<?php

/**
 * Implements hook_views_plugins().
 */
function og_viewscontext_views_plugins() {
  return array(
    'argument validator' => array(
      'nid_as_gid' => array(
        'title' => t('Node ID as GID'),
        'handler' => 'og_viewscontext_argument_validate_nid_as_gid',
        'uses options' => TRUE,
      ),
    ),
    'access' => array(
      'group_member' => array(
        'title' => t('Current User is Group Member'),
        'handler' => 'og_viewscontext_access_group_member',
        'uses options' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function og_viewscontext_views_data() {
  $data['views']['add_content_link'] = array(
    'title' => t('Add Content Link'),
    'help' => t('Provide a link to add content of a given type'),
    'area' => array(
      'handler' => 'views_handler_area_add_content_link',
    ),
  );

  return $data;
}