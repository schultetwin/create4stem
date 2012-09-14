<?php
// AT Magazine
?>
<div id="page" class="container">

  <?php print render($page['menu_bar_top']); ?> <!-- /menu bar top -->

  <header id="header" class="clearfix">
    <div id="branding">
      <?php if ($linked_site_logo): ?>
        <div id="logo"><?php print $linked_site_logo; ?></div>
      <?php endif; ?>
      <?php if ($site_name || $site_slogan): ?>
        <hgroup<?php if (!$site_slogan && $hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>>
          <?php if ($site_name): ?>
            <h1 id="site-name"<?php if ($hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>><?php print $site_name; ?></h1>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
            <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        </hgroup>
      <?php endif; ?>
    </div>
    <?php print render($page['header']); ?> <!-- /header region -->
  </header> <!-- /header -->

  <?php if ($page['menu_bar']):?>
    <div id="menu-bar-wrapper" class="clearfix">
      <?php print render($page['menu_bar']); ?> <!-- /menu bar -->
    </div>
  <?php endif; ?>

  <?php if ($breadcrumb): ?>
    <div id="breadcrumb"><div class="breadcrumb-inner">
      <?php print $breadcrumb; ?>
    </div></div> <!-- /breadcrumb -->
  <?php endif;?>

  <?php print $messages; ?> <!-- /message -->
  <?php print render($page['help']); ?> <!-- /help -->

  <?php print render($page['secondary_content']); ?> <!-- /secondary-content -->

  <!-- Three column 3x33 Gpanel -->
  <?php if ($page['three_33_first'] || $page['three_33_second'] || $page['three_33_third']): ?>
    <div id="tripanel" class="three-3x33 gpanel clearfix<?php if (render($page['secondary_content'])): print ' with-featured'; endif;?>">
      <?php print render($page['three_33_first']); ?>
      <?php print render($page['three_33_second']); ?>
      <?php print render($page['three_33_third']); ?>
    </div>
  <?php endif; ?>

  <div id="columns" class="at-mag-columns<?php if (render($page['secondary_content'])): print ' with-featured'; endif;?>"><div class="columns-inner clearfix">
    <div id="content-column"><div class="content-inner">

      <?php print render($page['highlighted']); ?> <!-- /highlight -->

      <!-- Two column 2x50 Gpanel -->
      <?php if ($page['two_50_first'] || $page['two_50_second']): ?>
        <div id="bipanel" class="two-50 gpanel clearfix">
          <?php print render($page['two_50_first']); ?>
          <?php print render($page['two_50_second']); ?>
        </div>
      <?php endif; ?>

      <?php $tag = $title ? 'section' : 'div'; ?>
      <<?php print $tag; ?> id="main-content">

        <?php if ($title || $primary_local_tasks || $secondary_local_tasks || $action_links = render($action_links)): ?>
          <header class="clearfix">
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1 id="page-title" class="<?php print $title_class ?>"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>

            <?php if ($primary_local_tasks || $secondary_local_tasks || $action_links): ?>
              <div id="tasks" class="clearfix">
                <?php if ($primary_local_tasks): ?>
                  <ul class="tabs primary clearfix"><?php print render($primary_local_tasks); ?></ul>
                <?php endif; ?>
                <?php if ($secondary_local_tasks): ?>
                  <ul class="tabs secondary clearfix"><?php print render($secondary_local_tasks); ?></ul>
                <?php endif; ?>
                <?php if ($action_links = render($action_links)): ?>
                  <ul class="action-links clearfix"><?php print $action_links; ?></ul>
                <?php endif; ?>
              </div>
            <?php endif; ?>
          </header>
        <?php endif; ?>

        <?php print render($page['content']); ?> <!-- /content -->

      </<?php print $tag; ?>> <!-- /main-content -->

      <?php print render($page['content_aside']); ?> <!-- /content-aside -->

    </div></div> <!-- /content-column -->

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>

  </div></div> <!-- /columns -->

  <?php print render($page['tertiary_content']); ?> <!-- /tertiary-content -->

  <!-- Three column 50-25-25 Gpanel -->
  <?php if ($page['three_50_25_25_first'] || $page['three_50_25_25_second'] || $page['three_50_25_25_third']): ?>
    <div id="tripanel-2" class="three-50-25-25 gpanel clearfix">
      <?php print render($page['three_50_25_25_first']); ?>
      <?php print render($page['three_50_25_25_second']); ?>
      <?php print render($page['three_50_25_25_third']); ?>
    </div>
  <?php endif; ?>

  <!-- Three column 25-25-50 Gpanel -->
  <?php if ($page['three_25_25_50_first'] || $page['three_25_25_50_second'] || $page['three_25_25_50_third']): ?>
    <div id="tripanel-3" class="three-25-25-50 gpanel clearfix">
      <?php print render($page['three_25_25_50_first']); ?>
      <?php print render($page['three_25_25_50_second']); ?>
      <?php print render($page['three_25_25_50_third']); ?>
    </div>
  <?php endif; ?>

  <!-- Four column Gpanel -->
  <?php if ($page['four_first'] || $page['four_second'] || $page['four_third'] || $page['four_fourth']): ?>
    <div id="quadpanel" class="four-4x25 gpanel clearfix">
      <?php print render($page['four_first']); ?>
      <?php print render($page['four_second']); ?>
      <?php print render($page['four_third']); ?>
      <?php print render($page['four_fourth']); ?>
    </div>
  <?php endif; ?>

  <?php if ($page['footer'] || $feed_icons): ?>
    <footer id="footer"><div id="footer-inner" class="clearfix">
      <!-- Five column Gpanel -->
      <?php if ($page['five_first'] || $page['five_second'] || $page['five_third'] || $page['five_fourth'] || $page['five_fifth']): ?>
        <div id="footerpanel" class="five-5x20 gpanel clearfix">
          <?php print render($page['five_first']); ?>
          <?php print render($page['five_second']); ?>
          <?php print render($page['five_third']); ?>
          <?php print render($page['five_fourth']); ?>
          <?php print render($page['five_fifth']); ?>
        </div>
      <?php endif; ?>
      <?php print render($page['footer']); ?> <!-- /footer region -->
      <?php print $feed_icons; ?> <!-- /feed icons -->
    </div></footer> <!-- /footer/footer-inner -->
  <?php endif; ?>

</div> <!-- /page -->
