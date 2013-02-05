<?php
/**
 * @file
 * The field node link views handler for fasttoggle.
 *
 * This file defines the Views handler for rendering fasttoggle links.
 */
class fasttoggle_views_handler_field_node_link extends views_handler_field_node_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    if (isset($this->definition['fasttoggle']) && isset($this->definition['fasttoggle']['key'])) {
      $this->fasttoggle_key = $this->definition['fasttoggle']['key'];
    }
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity);
    }
  }

  function render_link($node) {
    if (!node_access('update', $node)) {
      return '';
    }

    // Now we set the status to the actual value so that we get the
    // correct labels.
    $options = fasttoggle_get_options('node', $node);
    $key = $this->fasttoggle_key;

    if (!empty($options[$key])) {
      $link_info = fasttoggle($options[$key][intval($node->$key)],
              'node/' . $node->nid . '/toggle/' . $key, FASTTOGGLE_FORMAT_LINK_ARRAY,
      $key . '_' . $node->nid,
              'fasttoggle-status-node-' . $node->nid . '-' . $key . '-' . $node->$key);
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $link_info['href'];
      $this->options['alter']['text'] = $link_info['title'];
      $this->options['alter']['query'] = $link_info['query'];
      $this->options['alter']['link_class'] = implode(' ', $link_info['attributes']['class']);
      $this->options['alter']['title'] = $link_info['attributes']['title'];

      $text = $options[$key][intval($node->$key)];
      return $text;

    }
  }
}
