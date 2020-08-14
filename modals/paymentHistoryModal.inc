<!-- page requesting modal -->
<?php 
  if ($_GET['view'] == 'accounts') {
    $view = 'accounts';
  }elseif ($_GET['view'] == 'bills') {
    $view = 'bills';
  }
 ?>
<div id="paymentHistoryModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>

        <!-- Account name -->
        <h4 class="modal-title"></h4>
      </div>
      <div class="modal-body table-responsive">

          <div class="panel-body">
            <input type="text" class="form-control" id="payments-table-filter" data-action="filter" payments-filters="#payments-table<?php echo ($view == 'accounts') ? $account->id : $account_name->id ?>" placeholder="Filter payments" />
          </div>
          <div class="table-responsive">
            <table class="table table-hover" id="payments-table<?php echo ($view == 'accounts') ? $account->id : $account_name->id ?>">
              <thead>
                <tr>
                  <th>Date</th>
                  <th>Amount</th>
                  <th>Confirmation #</th>
                  <th>description</th>
                </tr>
              </thead>

     
                <tbody id="payments">
                  
                 </tbody>
              
            </table>
          </div>
      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

<script>
    $(document).ready(function(){
      $("#paymentHistoryModal").on("show.bs.modal", function(elem) {

        // clear out all modal data
        $('#payments').html('');
            $('.modal-title').html('');

        // set variables to send via ajax
        var id = elem.relatedTarget.id;
        var view = '<?php echo $view ?>';
        $.ajax({
          url : 'get_payment_history.php',
          type : 'post',
          dataType: 'json',
          data : {id : id, view : view},
          success: function(data){
            $('#payments').html(data.string);
            $('.modal-title').html(data.title + ' - total ( ' + data.total_payed + ' )' );
           console.log(data);
          }
        })
      });
    });
  </script>
<script>
  /**
  *   I don't recommend using this plugin on large tables, I just wrote it to make the demo useable. It will work fine for smaller tables 
  *   but will likely encounter performance issues on larger tables.
  *
  *   <input type="text" class="form-control" id="payments-table-filter" data-action="filter" payments-filters="#payments-table" placeholder="Filter Developers" />
  *   $(input-element).filterTable()
  *   
  * The important attributes are 'data-action="filter"' and 'payments-filters="#table-selector"'
  */
  (function(){
      'use strict';
    var $ = jQuery;
    $.fn.extend({
      filterTable: function(){
        return this.each(function(){
          $(this).on('keyup', function(e){
            $('.filterTable_no_results').remove();
            var $this = $(this), 
                          search = $this.val().toLowerCase(), 
                          target = $this.attr('payments-filters'), 
                          $target = $(target), 
                          $rows = $target.find('tbody tr');
                          
            if(search == '') {
              $rows.show(); 
            } else {
              $rows.each(function(){
                var $this = $(this);
                $this.text().toLowerCase().indexOf(search) === -1 ? $this.hide() : $this.show();
              })
              if($target.find('tbody tr:visible').size() === 0) {
                var col_count = $target.find('tr').first().find('td').size();
                var no_results = $('<tr class="filterTable_no_results"><td colspan="'+col_count+'">No results found</td></tr>')
                $target.find('tbody').append(no_results);
              }
            }
          });
        });
      }
    });
    $('[data-action="filter"]').filterTable();
  })(jQuery);

  $(function(){
      // attach table filter plugin to inputs
    $('[data-action="filter"]').filterTable();
    
    $('.container').on('click', '.panel-heading span.filter', function(e){
      var $this = $(this), 
        $panel = $this.parents('.panel');
      
      $panel.find('.panel-body').slideToggle();
      if($this.css('display') != 'none') {
        $panel.find('.panel-body input').focus();
      }
    });
    $('[data-toggle="tooltip"]').tooltip();
  })
</script>
