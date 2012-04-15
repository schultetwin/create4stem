<?php
/**
 * @file
 * c4s_featured.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4s_featured_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4s_featured_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function c4s_featured_image_default_styles() {
  $styles = array();

  // Exported image style: featured_front_page
  $styles['featured_front_page'] = array(
    'name' => 'featured_front_page',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '594',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      3 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => '594',
          'height' => '355',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function c4s_featured_node_info() {
  $items = array(
    'featured' => array(
      'name' => t('Featured'),
      'base' => 'node_content',
      'description' => t('A content type for front page or group rotating banner features.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
