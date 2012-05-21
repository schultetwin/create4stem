<?php
/**
 * @file
 * c4s_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4s_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_all';
  $context->description = 'Context for all group pages';
  $context->tag = 'Group';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-group_members-block' => array(
          'module' => 'views',
          'delta' => 'group_members-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-group_events-block_1' => array(
          'module' => 'views',
          'delta' => 'group_events-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-group_news-block' => array(
          'module' => 'views',
          'delta' => 'group_news-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-group_notes-block_1' => array(
          'module' => 'views',
          'delta' => 'group_notes-block_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all group pages');
  t('Group');
  $export['group_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'specific_group_crcstl';
  $context->description = 'Context for a specific group (for group menu)';
  $context->tag = 'Group';
  $context->conditions = array(
    'context_og_condition_group_node' => array(
      'values' => array(
        14 => 14,
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        'group/1/*' => 'group/1/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-crcstl' => array(
          'module' => 'menu',
          'delta' => 'menu-crcstl',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for a specific group (for group menu)');
  t('Group');
  $export['specific_group_crcstl'] = $context;

  return $export;
}
