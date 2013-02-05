
(function ($) {

  function multi_node_add_fields() {
    var fields = new Array();
    $("input.multi-node-add").each(function (i) {
      if ($(this).attr('checked')) {
        fields.push($(this).attr('value'));
      }
    });
    return fields.join(',');
  }

  var multi_node_add_NumNode = 0;

  function multi_node_add_show_forms(numForms) {
    if (numForms < 1) {
      throw "Number of forms must be non-zero";
    }
    for (var i = 0; i < numForms; i++) {
      var fields = '';
      if (Drupal.settings.multi_node_add_preload) {
        fields = Drupal.settings.multi_node_add_preload.fields;
      }
      else {
        fields = multi_node_add_fields();
      }
      $("#multi_node_add_frames").append('<div><iframe class="autoHeight" width="100%" name="node_' + (multi_node_add_NumNode++) + '" src="' + Drupal.settings.multi_node_add.callback + '/' + fields + '"></iframe></div>');
    }
    multi_node_add_doIframe();
  }


  Drupal.behaviors.multi_node_add = {
    attach: function (context) {

      try {
        multi_node_add_show_forms(Drupal.settings.multi_node_add_preload.num);
      }
      catch (err) {

        $('#edit-create', context).hide(0);
        $('#edit-addmore', context).hide(0);

        $('#edit-show', context).click(function () {
          if ($("input.multi-node-add:checked").size() == 0) {
            alert(Drupal.t('Select at least one field'));
            return false;
          }
          multi_node_add_show_forms($("#edit-number").val());
          $(this).hide(0);
          $('#edit-shortcut').hide(0);
          $('#edit-create').show(0);
          $('#edit-addmore').show(0);
          return false;
        });

        $('#edit-shortcut', context).click(function () {
          if ($("input.multi-node-add:checked").size() == 0) {
            alert(Drupal.t('Select at least one field'));
          }
          else {
            alert(window.location + "?fields=" + multi_node_add_fields() + "&num=" + $("#edit-number").val());
          }
          return false;
        });
      }

      $('#edit-addmore', context).click(function () {
        multi_node_add_show_forms(2);
        return false;
      });

      $('#edit-create', context).click(function () {
        for (var i = 0; i < multi_node_add_NumNode; i++) {
          try {
            window.frames['node_'+i].document.forms[0].submit();
          } catch (err) {} // not an error, maybe submitted w/ the single Create button
        }
        return false;
      });


    }
  };

  /* From jquery plugin: autoHeight */

  function multi_node_add_addEvent(obj, evType, fn){
    if (obj.addEventListener) {
      obj.addEventListener(evType, fn,false);
      return true;
    } else if (obj.attachEvent){
      var r = obj.attachEvent("on"+evType, fn);
      return r;
    } else {
      return false;
    }
  }

  function multi_node_add_doIframe(){
    o = document.getElementsByTagName('iframe');
    for (i=0;i<o.length;i++){
      if (/\bautoHeight\b/.test(o[i].className)) {
        multi_node_add_setHeight(o[i]);
        multi_node_add_addEvent(o[i],'load', multi_node_add_doIframe);
      }
    }
  }

  function multi_node_add_setHeight(e){
    var height = 50;
    var success = 0;
    if (e.contentDocument) {
      try {
        height = e.contentDocument.body.offsetHeight + 35;
        success = 1;
      } catch (e) {}
    }

    if (success == 0) {
      try {
        height = e.contentWindow.document.body.scrollHeight;
        success = 1;
      } catch (e) {}
    }
    e.height = height;
  }

})(jQuery);
