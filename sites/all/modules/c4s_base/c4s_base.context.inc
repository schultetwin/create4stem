<?php
/**
 * @file
 * c4s_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4s_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages';
  $context->description = 'Context for all pages in site';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => 1,
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => 1,
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for all pages in site');
  $export['all_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_logged_in';
  $context->description = 'All pages for logged in user';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'menu_bar',
          'weight' => '-25',
        ),
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => 1,
          'region' => 'menu_bar',
          'weight' => '-24',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages for logged in user');
  $export['all_pages_logged_in'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages_logged_out';
  $context->description = 'All pages for logged out user';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4s_custom-user_login_link' => array(
          'module' => 'c4s_custom',
          'delta' => 'user_login_link',
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => 1,
          'region' => 'menu_bar',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages for logged out user');
  $export['all_pages_logged_out'] = $context;

  return $export;
}
