<?php
// AT Magazine

/**
 * Override or insert variables into the html template.
 */
function at_magazine_preprocess_html(&$vars) {
  global $theme_key;

  $theme_name = 'at_magazine';
  $path_to_theme = drupal_get_path('theme', $theme_name);

  // Load the media queries styles
  $media_queries_css = array(
    $theme_name . '.responsive.style.css',
    $theme_name . '.responsive.gpanels.css'
  );
  load_subtheme_media_queries($media_queries_css, $theme_name);

  // Load IE specific stylesheets
  $ie_files = array(
    'IE 6'     => 'ie-6.css',
    'lte IE 7' => 'ie-lte-7.css',
    'IE 8'     => 'ie-8.css',
    'lte IE 9' => 'ie-lte-9.css',
  );
  load_subtheme_ie_styles($ie_files, $theme_name);

  // Add a class for the active color scheme
  if (module_exists('color')) {
    $class = check_plain(get_color_scheme_name($theme_key));
    $vars['classes_array'][] = 'color-scheme-' . drupal_html_class($class);
  }

  // Add class for the active theme
  $vars['classes_array'][] = drupal_html_class($theme_key);

  // Add theme settings classes
  $settings_array = array(
    'font_size',
    'body_background',
    'header_layout',
    'menu_bullets',
    'corner_radius',
    'box_shadows',
    'image_alignment',
    'page_title_case',
    'page_title_weight',
    'page_title_alignment',
    'page_title_shadow',
    'node_title_case',
    'node_title_weight',
    'node_title_alignment',
    'node_title_shadow',
    'comment_title_case',
    'comment_title_weight',
    'comment_title_alignment',
    'comment_title_shadow',
    'block_title_case',
    'block_title_weight',
    'block_title_alignment',
    'block_title_shadow',
  );
  foreach ($settings_array as $setting) {
    $vars['classes_array'][] = theme_get_setting($setting);
  }

  // Font family settings
  $fonts = array(
    'bf'  => 'base_font',
    'snf' => 'site_name_font',
    'ssf' => 'site_slogan_font',
	  'mmf' => 'main_menu_font',
    'ptf' => 'page_title_font',
    'ntf' => 'node_title_font',
    'ctf' => 'comment_title_font',
    'btf' => 'block_title_font'
  );
  $families = get_font_families($fonts, $theme_key);
  if (!empty($families)) {
    foreach($families as $family) {
      $vars['classes_array'][] = $family;
    }
  }

  // Add Noggin module settings extra classes, not all designs can support header images
  if (module_exists('noggin')) {
    if (variable_get('noggin:use_header', FALSE)) {
      $va = theme_get_setting('noggin_image_vertical_alignment');
      $ha = theme_get_setting('noggin_image_horizontal_alignment');
      $vars['classes_array'][] = 'ni-a-' . $va . $ha;
      $vars['classes_array'][] = theme_get_setting('noggin_image_repeat');
      $vars['classes_array'][] = theme_get_setting('noggin_image_width');
    }
  }

  // Special case for PIE htc rounded corners, not all themes include this
  if (theme_get_setting('ie_corners') == 1) {
    drupal_add_css($path_to_theme . '/css/ie-htc.css', array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 8',
        '!IE' => FALSE,
        ),
      'preprocess' => FALSE,
      )
    );
  }

}

/**
 * Override or insert variables into the html template.
 */
function at_magazine_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/**
 * Override or insert variables into the page template.
 */
function at_magazine_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
  if (isset($vars['node']) && _at_magazine_node_private($vars['node'])) {
    $vars['title_class'] = "drupal-private-title";
  }
}

/**
 * Override or insert variables into the block template.
 */
function at_magazine_preprocess_block(&$vars) {
  if ($vars['block']->region == 'sub_menu_bar' || $vars['block']->region == 'menu_bar_top') {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
  if ($vars['block']->module == 'superfish' || $vars['block']->module == 'nice_menu') {
    $vars['content_attributes_array']['class'][] = 'clearfix';
  }
  if (!$vars['block']->subject) {
    $vars['content_attributes_array']['class'][] = 'no-title';
  }
  if ($vars['block']->region == 'sub_menu_bar') {
    $vars['theme_hook_suggestions'][] = 'block__menu_bar';
  }
  if ($vars['block_id'] == 1) {
    $vars['classes_array'][] = 'block-first';
  }
}

/**
 * Returns HTML for a breadcrumb trail.
 */
function at_magazine_breadcrumb($vars) {
  $breadcrumb = $vars['breadcrumb'];
  $show_breadcrumb = theme_get_setting('breadcrumb_display');
  if ($show_breadcrumb == 'yes') {
    $show_breadcrumb_home = theme_get_setting('breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }
    if (!empty($breadcrumb)) {
      $heading = '<h2 class="breadcrumb-heading">' . t('You are here') . ':</h2>';
      $separator = filter_xss(theme_get_setting('breadcrumb_separator'));
      $output = '';
      foreach ($breadcrumb as $key => $val) {
        if ($key == 0) {
          $output .= '<li class="crumb">' . $val . '</li>';
        }
        else {
          $output .= '<li class="crumb"><span>' . $separator . '</span>' . $val . '</li>';
        }
      }
      return $heading . '<ol id="crumbs">' . $output . '</ol>';
    }
  }
  return '';
}

/**
 * Override or insert variables into the field template.
 */
function at_magazine_preprocess_field(&$vars) {
  $element = $vars['element'];
  $vars['classes_array'][] = 'view-mode-'. $element['#view_mode'];
  $vars['image_caption_teaser'] = FALSE;
  $vars['image_caption_full'] = FALSE;
  if(theme_get_setting('image_caption_teaser') == 1) {
    $vars['image_caption_teaser'] = TRUE;
  }
  if(theme_get_setting('image_caption_full') == 1) {
    $vars['image_caption_full'] = TRUE;
  }
  $vars['field_view_mode'] = '';
  $vars['field_view_mode'] = $element['#view_mode'];
}

/**
 * Preprocess node to add "private" class
 */
function at_magazine_preprocess_node(&$vars) {
  if (_at_magazine_node_private($vars['node'])) {
    $vars['title_attributes_array']['class'][] = "drupal-private-title";
  }
}

function _at_magazine_node_private($node) {
  $gids = array();

  $access = FALSE;
  if (!empty($node->{OG_ACCESS_FIELD}[LANGUAGE_NONE][0]['value']) && $group = og_get_group('node', $node->nid)) {
    // Group or group content that is explicitly set to be unpublic.
    $access = TRUE;
    $gids[] = $group->gid;
  }
  elseif (isset($node->{OG_CONTENT_ACCESS_FIELD}[LANGUAGE_NONE][0]['value'])) {
    switch ($node->{OG_CONTENT_ACCESS_FIELD}[LANGUAGE_NONE][0]['value']) {
      case OG_CONTENT_ACCESS_DEFAULT:
        if ($field = field_info_field(OG_ACCESS_FIELD)) {
          // Access should be determined by its groups. If group content belongs
          // to several groups, and one of them is private, then the group
          // content will private as-well.
          $gids = og_get_entity_groups('node', $node);

          $groups = og_load_multiple($gids);

          // Get all groups under their entity.
          $list = array();
          foreach ($groups as $group) {
            $list[$group->entity_type][$group->etid] = $group->etid;
          }

          // If group content belongs to several groups, and one of them is
          // private, then this variable decides what should happen -- if the
          // group content will be private as-well or become public.
          // By default, if one group is private then the group content will be
          // private.
          $strict_private = variable_get('group_access_strict_private', 1);

          $total_count = 0;

          foreach ($list as $entity_type => $entity_gids) {
            $query = new EntityFieldQuery;
            $count = $query
              ->entityCondition('entity_type', $entity_type)
              ->entityCondition('entity_id', $entity_gids, 'IN')
              ->fieldCondition(OG_ACCESS_FIELD, 'value', 1, '=')
              ->count()
              ->execute();

            if ($strict_private) {
              // There is at least one private group and 'strict private' is
              // TRUE so this group content should be private.
              if ($count) {
                $access = TRUE;
                break;
              }
            }
            else {
              // 'strict private' is FALSE so count all the groups, and only if
              // all of them are private then this group content should be
              // private.
              $total_count += $count;
            }
          }
          if ($total_count == count($gids)) {
            // All groups are private.
            $access = TRUE;
          }
        }
        break;

      case OG_CONTENT_ACCESS_PUBLIC:
        // Do nothing.
        break;

      case OG_CONTENT_ACCESS_PRIVATE:
        $access = TRUE;
        $gids = og_get_entity_groups('node', $node);
        break;

    }
  }
  return $access;
}