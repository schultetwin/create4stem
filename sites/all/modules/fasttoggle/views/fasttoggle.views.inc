<?php
/**
 * @file
 * Views data definitions for Fasttoggle.
 *
 * This file defines how Views should get Fasttoggle data.
 */

/**
 * Implementation of hook_views_data_alter()
 */

function fasttoggle_views_data_alter(&$data) {

  $data['node']['publish_node'] = array(
    'field' => array(
      'title' => t('Publish Link (Fasttoggle)'),
      'help' => t('Provide a simple link to publish the node.'),
      'handler' => 'fasttoggle_views_handler_field_node_link',
      'fasttoggle' => array(
        'key' => 'status',
      ),
    ),
  );
  $data['node']['promote_node'] = array(
    'field' => array(
      'title' => t('Promote Link (Fasttoggle)'),
      'help' => t('Provide a simple link to promote the node.'),
      'handler' => 'fasttoggle_views_handler_field_node_link',
      'fasttoggle' => array(
        'key' => 'promote',
        'additional_fields' => array('promote' => 'promote'),
      ),
    ),
  );
  $data['node']['sticky_node'] = array(
    'field' => array(
      'title' => t('Sticky Link (Fasttoggle)'),
      'help' => t('Provide a simple link to make the node sticky.'),
      'handler' => 'fasttoggle_views_handler_field_node_link',
      'fasttoggle' => array(
        'key' => 'sticky',
        'additional_fields' => array('sticky' => 'sticky'),
      ),
    ),
  );
  $data['users']['block_user'] = array(
    'field' => array(
      'title' => t('Block Link (Fasttoggle)'),
      'help' => t('Provide a simple link to block/unblock the user.'),
      'handler' => 'fasttoggle_views_handler_field_user_link',
    ),
  );
  $data['comments']['publish_comment'] = array(
    'field' => array(
      'title' => t('Publish Link (Fasttoggle)'),
      'help' => t('Provide a simple link to publish the comment.'),
      'handler' => 'fasttoggle_views_handler_field_comment_link',
    ),
  );
}

/**
 * Field handler to present a link toggle status.
 */
function fasttoggle_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'fasttoggle') . '/views',
    ),
    'handlers' => array(
      'fasttoggle_views_handler_field_node_link' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'fasttoggle_views_handler_field_user_link' => array(
        'parent' => 'views_handler_field_user_link',
      ),
      'fasttoggle_views_handler_field_comment_link' => array(
        'parent' => 'views_handler_field_comment_link',
      ),
    ),
  );
}
