<?php
/**
 * @file
 * c4s_frontpage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4s_frontpage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = 'Sitewide Front Page Context';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-featured_front_page-block' => array(
          'module' => 'views',
          'delta' => 'featured_front_page-block',
          'region' => 'three_33_first',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => 2,
          'region' => 'three_33_third',
          'weight' => '-24',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'three_33_third',
          'weight' => '-23',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => 4,
          'region' => 'three_33_third',
          'weight' => '-22',
        ),
        'views-news_announcements-block' => array(
          'module' => 'views',
          'delta' => 'news_announcements-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-event_calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'event_calendar-block_2',
          'region' => 'sidebar_second',
          'weight' => '-24',
        ),
        'views-news_all-block' => array(
          'module' => 'views',
          'delta' => 'news_all-block',
          'region' => 'sidebar_second',
          'weight' => '-23',
        ),
        'views-opportunities_positions-block' => array(
          'module' => 'views',
          'delta' => 'opportunities_positions-block',
          'region' => 'sidebar_second',
          'weight' => '-22',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide Front Page Context');
  $export['front_page'] = $context;

  return $export;
}
