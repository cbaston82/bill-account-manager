$('a.bill_options').click(function(e){

      e.preventDefault();

      // hide all span
      $(this).find('i').toggleClass('fa fa-calculator fa fa-check');

      var bills_to_calculate = $("a.bill_options").find('i.fa-check').closest('tr');
      // bills_to_calculate[0].cells[3].innerText

      var total_calculated = 0;
      var selected_bills = bills_to_calculate.length;

      if (selected_bills > 0) {
        var total = 0;
        for (var i = 0; i < selected_bills; i++) {
          var bill_amount = bills_to_calculate[i].cells[1].innerText;

          amount = bill_amount.split('$');
          total += parseFloat(amount[1]);
        }




        $('div.manage_selected').html(
          '<div text-center">'+
            '<div class="box">'+
                '<div class="box-content">'+
                    '<p class="text-center total_calculated">$'+total.toFixed(2)+'</p>'+
                    '<br />'+
                    '<hr />'+
                    '<p class="tag-title"><i class="fa fa-cogs" aria-hidden="true"></i> Options</p>'+
                    '<hr />'+
                    '<br />'+
                    '<a id="manageBills" data-toggle="modal" title="Add to note" data-bills="'+bills_to_calculate+'" href="#newNoteModal" class="btn btn-block btn-primary"><i class="fa fa-sticky-note" aria-hidden="true"></i> Create Note</a>'+
                '</div>'+
                '</div>'+
                '<div class="clearfix"></div>'+
            '</div>'
        );
      }else{
        $('div.manage_selected').html('');
      }

      $('#manageBills').on('click', function(){

         tinyMCE.activeEditor.setContent('');

         tinyMCE.activeEditor.execCommand(
          'mceInsertContent',
          false,
          '<br>'+
          '<p>Total: <b>$'+total.toFixed(2)+'</b></p>');

        jQuery(bills_to_calculate).each(function(i, bill){
          var bill_name = bills_to_calculate[i].cells[0].innerText;
          var bill_amount = bills_to_calculate[i].cells[1].innerText;
          var date = bills_to_calculate[i].cells[3].innerText;

          tinyMCE.activeEditor.execCommand(
            'mceInsertContent',
            false,
            '<li>'+bill_name+': <b>'+bill_amount+'</b></li>'
          );

        })
      })
  });