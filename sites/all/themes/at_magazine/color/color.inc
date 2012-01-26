<?php
// AT Magazine
$info = array(
  // Fields
  'fields' => array(
    'base'      => t('Base'),
    'bg'        => t('Background'),
    'pagebg'    => t('Page'),
    'accents'   => t('Accents hue'),
    'link'      => t('Links'),
    'top'       => t('Header'),
    'toptext'   => t('Header text'),
    'menubar'   => t('Main menu bar'),
    'submenu'   => t('Sub menu bar'),
    'text'      => t('Text'),
    'block'     => t('Sidebar Blocks'),
    'blockl'    => t('Sidebar links'),
    'borders'   => t('Borders'),
    'sticky'    => t('Sticky teaser'),
    'footertop' => t('Footer top'),
    'footerbot' => t('Footer bottom'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Magazine (default)'),
      'colors' => array(
        'base'      => '#ffffff',
        'bg'        => '#f3f4ee',
        'pagebg'    => '#feffff',
        'accents'   => '#efefef',
        'link'      => '#315690',
        'top'       => '#fefefe',
        'toptext'   => '#343434',
        'menubar'   => '#191919',
        'submenu'   => '#6d6d6d',
        'text'      => '#000000',
        'block'     => '#f1f4f0',
        'blockl'    => '#222222',
        'borders'   => '#bebfb9',
        'sticky'    => '#f7f7f7',
        'footertop' => '#111111',
        'footerbot' => '#2b2b2b',
      ),
    ),
    'magred' => array(
      'title' => t('Magazine Red'),
      'colors' => array(
        'base'      => '#ffffff',
        'bg'        => '#f3f4ee',
        'pagebg'    => '#feffff',
        'accents'   => '#f6e5e5',
        'link'      => '#d6121f',
        'top'       => '#fefefe',
        'toptext'   => '#343434',
        'menubar'   => '#1f1d1d',
        'submenu'   => '#6d6d6d',
        'text'      => '#000000',
        'block'     => '#f1f4f0',
        'blockl'    => '#222222',
        'borders'   => '#bebfb9',
        'sticky'    => '#f7f7f7',
        'footertop' => '#1f1d1c',
        'footerbot' => '#2b2b2b',
      ),
    ),
    'magblue' => array(
      'title' => t('Magazine Blue'),
      'colors' => array(
        'base'      => '#ffffff',
        'bg'        => '#f3f4ee',
        'pagebg'    => '#feffff',
        'accents'   => '#add6ee',
        'link'      => '#2888c1',
        'top'       => '#fefefe',
        'toptext'   => '#343434',
        'menubar'   => '#191919',
        'submenu'   => '#6d6d6d',
        'text'      => '#000000',
        'block'     => '#f1f4f0',
        'blockl'    => '#222222',
        'borders'   => '#bebfb9',
        'sticky'    => '#f7f7f7',
        'footertop' => '#111111',
        'footerbot' => '#2b2b2b',
      ),
    ),
    'magplum' => array(
      'title' => t('Magazine Plum'),
      'colors' => array(
        'base'      => '#ffffff',
        'bg'        => '#fffdf7',
        'pagebg'    => '#feffff',
        'accents'   => '#c4b4c8',
        'link'      => '#9d408d',
        'top'       => '#fefefe',
        'toptext'   => '#343434',
        'menubar'   => '#191919',
        'submenu'   => '#6d6d6d',
        'text'      => '#301313',
        'block'     => '#f1f4f0',
        'blockl'    => '#222222',
        'borders'   => '#bebfb9',
        'sticky'    => '#f7f7f7',
        'footertop' => '#2c2c28',
        'footerbot' => '#3c3333',
      ),
    ),
    'magorange' => array(
      'title' => t('Magazine Orange'),
      'colors' => array(
        'base'      => '#ffffff',
        'bg'        => '#f3f4ee',
        'pagebg'    => '#feffff',
        'accents'   => '#f6bb42',
        'link'      => '#c64605',
        'top'       => '#fefefe',
        'toptext'   => '#343434',
        'menubar'   => '#191919',
        'submenu'   => '#6d6d6d',
        'text'      => '#000000',
        'block'     => '#f1f4f0',
        'blockl'    => '#222222',
        'borders'   => '#bebfb9',
        'sticky'    => '#f7f7f7',
        'footertop' => '#282626',
        'footerbot' => '#3f3333',
      ),
    ),
  ),

  // CSS files
  'css' => array(
    'color/colors.css',
  ),

  // Images to copy over
  'copy' => array(
    'logo.png',
  ),

  // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('footertop', 'footerbot'),
    ),
  ),

  // Color areas to fill (x, y, width, height)
  'fill' => array(),

  // Coordinates of all the theme slices (x, y, width, height).
  'slices' => array(),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_image' => 'color/color-preview.png',
  'preview_css' => 'color/preview.css',

  // Base file for image generation
  'base_image' => 'color/base.png',
);