<?php
// AT Magazine
include_once(drupal_get_path('theme', 'adaptivetheme') . '/inc/google.web.fonts.inc');

// Override noggin selector
if (module_exists('noggin')) {
  $default_var = variable_get('noggin:header_selector', 'div#header');
  if ($default_var == 'div#header') {
    variable_set('noggin:header_selector', 'header#header');
  }
}

/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function at_magazine_form_system_theme_settings_alter(&$form, &$form_state)  {

  // Header layout
  $form['at']['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header layout'),
    '#description' => t('<h3>Header layout</h3><p>Change the position of the logo, site name and slogan. Note that his will automatically alter the header region layout also. If the branding elements are centered the header region will center below them, otherwise the header region will float in the opposite direction.</p>'),
  );
  $form['at']['header']['header_layout'] = array(
    '#type' => 'radios',
    '#title' => t('Branding position'),
    '#default_value' => theme_get_setting('header_layout'),
    '#options' => array(
      'hl-l'  => t('Left'),
      'hl-r'  => t('Right'),
      'hl-c' => t('Centered'),
    ),
  );
  $form['at']['font'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fonts'),
    '#description' => t('<h3>Fonts</h3><p>Here you can set a default font which will style all text. You can also set unique fonts for the page title, site name and slogan, and fonts for node, comment and block titles. First select the font type (Websafe or Google web font), then select the font family. You can preview Google web fonts here: <a href="!link" target="_blank">http://www.google.com/webfonts</a></p>', array('!link' => 'http://www.google.com/webfonts')),
  );
  $form['at']['font']['base_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Default font'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['base_font_wrapper']['base_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('base_font_type'),
  );
  $form ['at']['font']['base_font_wrapper']['base_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="base_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['base_font_wrapper']['base_font_container']['base_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('base_font'),
    '#options' => array(
      'bf-sss' => t('Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'bf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'bf-a'   => t('Arial, Helvetica, sans-serif'),
      'bf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'bf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'bf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'bf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'bf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'bf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at'] ['font']['base_font_wrapper']['base_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="base_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['base_font_wrapper']['base_font_gwf_container']['base_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('base_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['site_name_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Site Name'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('site_name_font_type')
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_name_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_container']['site_name_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_name_font'),
    '#options' => array(
      'snf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'snf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'snf-a'   => t('Arial, Helvetica, sans-serif'),
      'snf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'snf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'snf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'snf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'snf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'snf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_name_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_gwf_container']['site_name_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_name_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['site_slogan_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Site Slogan'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['site_slogan_font_wrapper']['site_slogan_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('site_slogan_font_type')
  );
  $form ['at']['font']['site_slogan_font_wrapper']['site_slogan_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_slogan_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_container']['site_slogan_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_slogan_font'),
    '#options' => array(
      'ssf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ssf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ssf-a'   => t('Arial, Helvetica, sans-serif'),
      'ssf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ssf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ssf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ssf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ssf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ssf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_slogan_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_gwf_container']['site_slogan_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_slogan_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['page_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Page Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('page_title_font_type')
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="page_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_container']['page_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('page_title_font'),
    '#options' => array(
      'ptf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ptf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ptf-a'   => t('Arial, Helvetica, sans-serif'),
      'ptf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ptf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ptf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ptf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ptf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ptf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="page_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_gwf_container']['page_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('page_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Node title font
  $form['at']['font']['node_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Node Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['node_title_font_wrapper']['node_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('node_title_font_type')
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="node_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_container']['node_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('node_title_font'),
    '#options' => array(
      'ntf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ntf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ntf-a'   => t('Arial, Helvetica, sans-serif'),
      'ntf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ntf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ntf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ntf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ntf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ntf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="node_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_gwf_container']['node_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('node_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Comment title font
  $form['at']['font']['comment_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Comment Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['comment_title_font_wrapper']['comment_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('comment_title_font_type')
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="comment_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_container']['comment_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('comment_title_font'),
    '#options' => array(
      'ctf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ctf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ctf-a'   => t('Arial, Helvetica, sans-serif'),
      'ctf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ctf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ctf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ctf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ctf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ctf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at']['font']['comment_title_font_wrapper']['comment_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="comment_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_gwf_container']['comment_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('comment_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Block title font
  $form ['at']['font'] ['block_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Block Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  // Block title font
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('block_title_font_type')
  );
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="block_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['block_title_font_wrapper']['block_title_font_container']['block_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('block_title_font'),
    '#options' => array(
      'btf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'btf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'btf-a'   => t('Arial, Helvetica, sans-serif'),
      'btf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'btf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'btf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'btf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'btf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'btf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="block_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['block_title_font_wrapper']['block_title_font_gwf_container']['block_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('block_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['size'] = array(
    '#type' => 'fieldset',
    '#title' => t('Font Size'),
    '#description' => t('<h3>Font Size</h3>'),
  );
  $form['at']['size']['font_size'] = array(
    '#type' => 'select',
    '#title' => t('Font Size'),
    '#default_value' => theme_get_setting('font_size'),
    '#description' => t('This sets a base font-size on the body element - all text will scale relative to this value.'),
    '#options' => array(
      'fs-smallest' => t('Smallest'),
      'fs-small'    => t('Small'),
      'fs-medium'   => t('Medium'),
      'fs-large'    => t('Large'),
      'fs-largest'  => t('Largest'),
    ),
  );
  $form['at']['headings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Heading Styles'),
    '#description' => t('<h3>Heading Styles</h3><p>Add extra styles to headings. Shadows only work for CSS3 capable browsers such as Firefox, Safari, IE9 etc.</p>'),
  );
  // Page title
  $form['at']['headings']['page_title']  = array(
    '#type' => 'fieldset',
    '#title' => t('Page title'),
    '#description' => t('<strong>Page title settings</strong>'),
  );
  $form['at']['headings']['page_title']['page_title_case'] = array(
    '#type' => 'radios',
    '#title' => t('Case'),
    '#default_value' => theme_get_setting('page_title_case'),
    '#options' => array(
      'ptc-n'  => t('Normal'),
      'ptc-uc' => t('Upper case'),
      'ptc-lc' => t('Lower case'),
      'ptc-c'  => t('Capitalize'),
      'ptc-sc' => t('Small caps'),
    ),
  );
  $form['at']['headings']['page_title']['page_title_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#default_value' => theme_get_setting('page_title_weight'),
    '#options' => array(
      'ptw-n' => t('Normal'),
      'ptw-b' => t('Bold'),
    ),
  );
  $form['at']['headings']['page_title']['page_title_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('Alignment'),
    '#default_value' => theme_get_setting('page_title_alignment'),
    '#options' => array(
      'pta-l' => t('Left'),
      'pta-r' => t('Right'),
      'pta-c' => t('Centered')
    ),
  );
  $form['at']['headings']['page_title']['page_title_shadow'] = array(
    '#type' => 'radios',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting('page_title_shadow'),
    '#options' => array(
      'pts-n' => t('None'),
      'pts-l' => t('Light'),
      'pts-d' => t('Dark'),
      'pts-w' => t('White')
    ),
  );
  // Node title
  $form['at']['headings']['node_title']  = array(
    '#type' => 'fieldset',
    '#title' => t('Node titles'),
    '#description' => t('<strong>Node title settings</strong>'),
  );
  $form['at']['headings']['node_title']['node_title_case'] = array(
    '#type' => 'radios',
    '#title' => t('Case'),
    '#default_value' => theme_get_setting('node_title_case'),
    '#options' => array(
      'ntc-n'  => t('Normal'),
      'ntc-uc' => t('Upper case'),
      'ntc-lc' => t('Lower case'),
      'ntc-c'  => t('Capitalize'),
      'ntc-sc' => t('Small caps'),
    ),
  );
  $form['at']['headings']['node_title']['node_title_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#default_value' => theme_get_setting('node_title_weight'),
    '#options' => array(
      'ntw-n' => t('Normal'),
      'ntw-b' => t('Bold'),
    ),
  );
  $form['at']['headings']['node_title']['node_title_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('Alignment'),
    '#default_value' => theme_get_setting('node_title_alignment'),
    '#options' => array(
      'nta-l' => t('Left'),
      'nta-r' => t('Right'),
      'nta-c' => t('Centered')
    ),
  );
  $form['at']['headings']['node_title']['node_title_shadow'] = array(
    '#type' => 'radios',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting('node_title_shadow'),
    '#options' => array(
      'nts-n' => t('None'),
      'nts-l' => t('Light'),
      'nts-d' => t('Dark'),
      'nts-w' => t('White')
    ),
  );
  // Comment title
  $form['at']['headings']['comment_title']  = array(
    '#type' => 'fieldset',
    '#title' => t('Comment titles'),
    '#description' => t('<strong>Comment title settings</strong>'),
  );
  $form['at']['headings']['comment_title']['comment_title_case'] = array(
    '#type' => 'radios',
    '#title' => t('Case'),
    '#default_value' => theme_get_setting('comment_title_case'),
    '#options' => array(
      'ctc-n'  => t('Normal'),
      'ctc-uc' => t('Upper case'),
      'ctc-lc' => t('Lower case'),
      'ctc-c'  => t('Capitalize'),
      'ctc-sc' => t('Small caps'),
    ),
  );
  $form['at']['headings']['comment_title']['comment_title_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#default_value' => theme_get_setting('comment_title_weight'),
    '#options' => array(
      'ctw-n' => t('Normal'),
      'ctw-b' => t('Bold'),
    ),
  );
  $form['at']['headings']['comment_title']['comment_title_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('Alignment'),
    '#default_value' => theme_get_setting('comment_title_alignment'),
    '#options' => array(
      'cta-l' => t('Left'),
      'cta-r' => t('Right'),
      'cta-c' => t('Cectered')
    ),
  );
  $form['at']['headings']['comment_title']['comment_title_shadow'] = array(
    '#type' => 'radios',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting('comment_title_shadow'),
    '#options' => array(
      'cts-n' => t('None'),
      'cts-l' => t('Light'),
      'cts-d' => t('Dark'),
      'cts-w' => t('White')
    ),
  );
  // Block title
  $form['at']['headings']['block_title']  = array(
    '#type' => 'fieldset',
    '#title' => t('Block titles'),
    '#description' => t('<strong>Block title settings</strong>'),
  );
  $form['at']['headings']['block_title']['block_title_case'] = array(
    '#type' => 'radios',
    '#title' => t('Case'),
    '#default_value' => theme_get_setting('block_title_case'),
    '#options' => array(
      'btc-n'  => t('Normal'),
      'btc-uc' => t('Upper case'),
      'btc-lc' => t('Lower case'),
      'btc-c'  => t('Capitalize'),
      'btc-sc' => t('Small caps'),
    ),
  );
  $form['at']['headings']['block_title']['block_title_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#default_value' => theme_get_setting('block_title_weight'),
    '#options' => array(
      'btw-n' => t('Normal'),
      'btw-b' => t('Bold'),
    ),
  );
  $form['at']['headings']['block_title']['block_title_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('Alignment'),
    '#default_value' => theme_get_setting('block_title_alignment'),
    '#options' => array(
      'bta-l' => t('Left'),
      'bta-r' => t('Right'),
      'bta-c' => t('Centered')
    ),
  );
  $form['at']['headings']['block_title']['block_title_shadow'] = array(
    '#type' => 'radios',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting('block_title_shadow'),
    '#options' => array(
      'bts-n' => t('None'),
      'bts-l' => t('Light'),
      'bts-d' => t('Dark'),
      'bts-w' => t('White')
    ),
  );
  $form['at']['corners'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rounded corners'),
    '#description' => t('<h3>Rounded Corners</h3><p>Rounded corners are implimented using CSS and only work in modern compliant browsers. You can set the radius for both the main content and main menu tabs.</p>'),
  );
  $form['at']['corners']['corner_radius'] = array(
    '#type' => 'select',
    '#title' => t('Main content radius'),
    '#default_value' => theme_get_setting('corner_radius'),
    '#description' => t('Change the corner radius for the main content area.'),
    '#options' => array(
      'rc-0' => t('none'),
      'rc-4' => t('4px'),
      'rc-6' => t('6px'),
      'rc-8' => t('8px'),
      'rc-10' => t('10px'),
      'rc-12' => t('12px'),
    ),
  );
  $form['at']['corners']['htc'] = array(
    '#type' => 'fieldset',
    '#title' => t('IE corners'),
  );
  $form['at']['corners']['htc']['ie_corners'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable rounded corners for Internet Explorer 6, 7 and 8'),
    '#default_value' => theme_get_setting('ie_corners'),
    '#description' => t('<p>NOTE: For this to work you must download install the <a href="!link">CSS3PIE</a> library to <code>sites/all/libraries/PIE</code>.</p><p>The path should be like this: <code>sites/all/libraries/PIE/PIE.htc</code></p><p>Then you MUST change the path in <strong>ie-htc.css</strong> to be absolute and match this path, e.g. <code>http://examplesite.com/sites/all/libraries/PIE/PIE.htc</code> - look in the <code>/css</code> folder to find this file.<p>Usage is at your own risk. Elements such as text inside other JS items such as drop menus or slideshows may be degraded in Internet Explorer.</p>', array('!link' => 'http://css3pie.com/')),
  );
  $form['at']['pagestyles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Box Shadows and Textures'),
    '#description' => t('<h3>Shadows and Textures</h3><p>The box shadows are implimented using CSS and only work in modern compliant browsers. The textures are small, semi-transparent images that tile to fill the entire background.</p>'),
  );
  $form['at']['pagestyles']['shadows'] = array(
    '#type' => 'fieldset',
    '#title' => t('Box Shadows'),
    '#description' => t('<h3>Box Shadows</h3><p>Box shadows (a drop shadow/glow effect) apply to the main content column and work only in CSS3 compliant browsers such as Firefox, Safari and Chrome.</p>'),
  );
  $form['at']['pagestyles']['shadows']['box_shadows'] = array(
    '#type' => 'radios',
    '#title' => t('<strong>Apply a box shadow to the main content column</strong>'),
    '#default_value' => theme_get_setting('box_shadows'),
    '#options' => array(
      'bs-n' => t('None'),
      'bs-l' => t('Box shadow - light'),
      'bs-d' => t('Box shadow - dark'),
    ),
  );
  $form['at']['pagestyles']['textures'] = array(
    '#type' => 'fieldset',
    '#title' => t('Textures'),
    '#description' => t('<h3>Body Textures</h3><p>This setting adds a texture over the main background color - the darker the background the more these stand out, on light backgrounds the effect is subtle.</p>'),
  );
  $form['at']['pagestyles']['textures']['body_background'] = array(
    '#type' => 'select',
    '#title' => t('Select texture'),
    '#default_value' => theme_get_setting('body_background'),
    '#options' => array(
      'bb-n'   => t('None'),
      'bb-b'   => t('Bubbles'),
      'bb-hs'  => t('Horizontal stripes'),
      'bb-dp'  => t('Diagonal pattern'),
      'bb-dll' => t('Diagonal lines - loose'),
      'bb-dlt' => t('Diagonal lines - tight'),
      'bb-sd'  => t('Small dots'),
      'bb-bd'  => t('Big dots'),
    ),
  );
  // Image styles
  $form['at']['images'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Settings'),
    '#description' => '<h3>Image Settings</h3>',
  );
  $form['at']['images']['alignment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Alignment'),
  );
  $form['at']['images']['alignment']['image_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('<strong>Image field alignment</strong>'),
    '#default_value' => theme_get_setting('image_alignment'),
    '#description' => t('This will only affect images added using an image-field. If you use another method such as embedding images directly into text areas this will not affect those images.'),
    '#options' => array(
      'ia-n' => t('None'),
      'ia-l' => t('Left'),
      'ia-c' => t('Centered'),
      'ia-r' => t('Right'),
    ),
  );
  $form['at']['images']['captions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Captions'),
    '#description' => t('<strong>Display the image title as a caption</strong>'),
  );
  $form['at']['images']['captions']['image_caption_teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show captions on teaser view'),
    '#default_value' => theme_get_setting('image_caption_teaser'),
  );
  $form['at']['images']['captions']['image_caption_full'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show captions on full view'),
    '#default_value' => theme_get_setting('image_caption_full'),
  );
  $form['at']['menu_styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu Bullets'),
    '#description' => t('<h3>Menu Bullets</h3><p>This setting allows you to customize the bullet images used on menus items. Bullet images only show on normal vertical block menus.</p>'),
  );
  $form['at']['menu_styles']['menu_bullets'] = array(
    '#type' => 'select',
    '#title' => t('Menu Bullets'),
    '#default_value' => theme_get_setting('menu_bullets'),
    '#options' => array(
      'mb-n' => t('None'),
      'mb-dd' => t('Drupal default'),
      'mb-ah' => t('Arrow head'),
      'mb-ad' => t('Double arrow head'),
      'mb-ca' => t('Circle arrow'),
      'mb-fa' => t('Fat arrow'),
      'mb-sa' => t('Skinny arrow'),
    ),
  );
  // Collapse all other forms.
  $form['theme_settings']['#collapsible'] = TRUE;
  $form['theme_settings']['#collapsed'] = TRUE;
  $form['logo']['#collapsible'] = TRUE;
  $form['logo']['#collapsed'] = TRUE;
  $form['favicon']['#collapsible'] = TRUE;
  $form['favicon']['#collapsed'] = TRUE;
  // Noggin
  if (module_exists('noggin')) {
    // Rewrite the selector to suit Adaptivetheme and HTML5
    $form['noggin']['settings']['header_selector']['#default_value'] = variable_get('noggin:header_selector', 'header#header');
    // Extra fields for noggin settings
    $form['atnoggin'] = array(
      '#type' => 'fieldset',
      '#title' => t('Header Image Extra Styles'),
      '#description' => t('These settings extend the Noggin module Header Image Settings.'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#states' => array(
        'invisible' => array(
          'input[name="use_header"]' => array('checked' => FALSE),
        ),
      ),
    );
    $form['atnoggin']['noggin_image_vertical_alignment'] = array(
      '#type' => 'radios',
      '#title' => t('Image alignment - vertical'),
      '#default_value' => theme_get_setting('noggin_image_vertical_alignment'),
      '#options' => array(
        't' => t('Top'),
        'c' => t('Middle'),
        'b' => t('Bottom'),
      ),
    );
    $form['atnoggin']['noggin_image_horizontal_alignment'] = array(
      '#type' => 'radios',
      '#title' => t('Image alignment - horizontal'),
      '#default_value' => theme_get_setting('noggin_image_horizontal_alignment'),
      '#options' => array(
        'l' => t('Left'),
        'r' => t('Right'),
        'c' => t('Center'),
      ),
    );
    $form['atnoggin']['noggin_image_repeat'] = array(
      '#type' => 'radios',
      '#title' => t('Image repeat'),
      '#default_value' => theme_get_setting('noggin_image_repeat'),
      '#options' => array(
        'ni-r-r' => t('Repeat'),
        'ni-r-rx' => t('Horizontal repeat'),
        'ni-r-ry' => t('Vertical repeat'),
        'ni-r-nr' => t('No repeat'),
      ),
    );
    $form['atnoggin']['noggin_image_width'] = array(
      '#type' => 'radios',
      '#title' => t('Image width'),
      '#default_value' => theme_get_setting('noggin_image_width'),
      '#options' => array(
        'ni-w-a' => t('Auto <span class="description">- use actual image dimensions</span>'),
        'ni-w-ftw' => t('100% width <span class="description"> - stretch to fit, this only works in modern CSS3 capable browsers</span>'),
      ),
    );
  }
}
