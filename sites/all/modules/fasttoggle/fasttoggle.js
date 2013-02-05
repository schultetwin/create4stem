(function ($) {

  Drupal.behaviors.fasttoggle = {
    attach: function (context) {
      $('#edit-fasttoggle-togglable-options input', context).each(function () {
        // Disable non-togglable "Add to node links" options on page load
        document.getElementById(this.id.replace('togglable-options', 'add-to-node-links')).disabled = !this.checked;
        // Update "Add to node links" options when "Togglable options" change
        $(this).once().click(function () {
          document.getElementById(this.id.replace('togglable-options', 'add-to-node-links')).disabled = !this.checked;
        })
      });
    }
  };

})(jQuery);
