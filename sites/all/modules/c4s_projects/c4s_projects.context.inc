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
        'views-group_menu-block' => array(
          'module' => 'views',
          'delta' => 'group_menu-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
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
  $context->name = 'group_home_page';
  $context->description = 'Context for all group pages';
  $context->tag = 'Group';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-group_events-block_1' => array(
          'module' => 'views',
          'delta' => 'group_events-block_1',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'views-group_news-block' => array(
          'module' => 'views',
          'delta' => 'group_news-block',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'views-group_notes-block_1' => array(
          'module' => 'views',
          'delta' => 'group_notes-block_1',
          'region' => 'sidebar_second',
          'weight' => '-2',
        ),
        'views-group_members-block' => array(
          'module' => 'views',
          'delta' => 'group_members-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all group pages');
  t('Group');
  $export['group_home_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects_main_page';
  $context->description = '';
  $context->tag = 'C4S';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'projects' => 'projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-projects_home-block_1' => array(
          'module' => 'views',
          'delta' => 'projects_home-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('C4S');
  $export['projects_main_page'] = $context;

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
