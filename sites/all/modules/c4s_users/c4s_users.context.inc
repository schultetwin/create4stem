<?php
/**
 * @file
 * c4s_users.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4s_users_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'profile_all';
  $context->description = 'Applies to all profile pages';
  $context->tag = 'profile';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-profile_about-block_1' => array(
          'module' => 'views',
          'delta' => 'profile_about-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Applies to all profile pages');
  t('profile');
  $export['profile_all'] = $context;

  return $export;
}
