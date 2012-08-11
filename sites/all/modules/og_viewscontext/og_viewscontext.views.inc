<?php

function og_viewscontext_views_plugins() {
  return array(
    'argument validator' => array(
      'nid_as_gid' => array(
        'title' => t('Node ID as GID'),
        'handler' => 'og_viewscontext_argument_validate_nid_as_gid',
        'uses options' => TRUE,
      ),
    ),
  );
}
