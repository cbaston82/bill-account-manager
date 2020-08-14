<div id="editBillModal<?php echo $bill->id; ?>" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title"><?php echo $account_name->name; ?> <small>Balance due ( &#x24;<?php echo $bill->due; ?> )</small></h4>
      </div>
      <div class="modal-body">

        <!-- form start -->
        <form class="bam-edit-form" action="update.php" method="post" role="form">

                <!-- select options -->
                <div class="form-group col-sm-6">
                  <label for="account_id">Account Type</label>
                  <select name="account_id" id="account_id" class="form-control input-lg">
                    <option value="">-- Account Type --</option>

                    <!-- all accounts -->
                    <?php $all_accounts = Account::accounts_all($_SESSION['user_id']); ?>

                    <?php foreach ($all_accounts as $account): ?>
                      <option <?php echo ($account->id == $bill->account_id)? 'selected' : '' ?> value="<?php echo $account->id; ?>"><?php echo $account->name; ?></option>
                    <?php endforeach ?>
                  </select>
                </div>
                

                <!-- amount -->
                <div class="form-group col-sm-6">
                  <label for="amount">Amount</label>
                  <input type="text" name="amount" class="form-control input-lg" id="amount" placeholder="Bill Amount" value="<?php echo currency($bill->amount); ?>">
                </div>

                 <!-- amount -->
                <div class="form-group col-sm-6">
                  <label for="due">Due</label>
                  <input type="text" name="due" class="form-control input-lg" id="due" placeholder="Amount Due" readonly value="<?php echo currency($bill->due); ?>">
                </div>

                 <!-- due_date -->
                <div class="form-group col-sm-6">
                  <label for="due_date">Due Date</label>
                  <input type="text" name="due_date" class="form-control input-lg pickDate" id="due_date" placeholder="Due Date" value="<?php echo $bill->due_date; ?>">
                </div>

                <!-- description -->
                <div class="form-group col-sm-12">
                  <label for="description">Description</label>
                  <textarea name="description" id="description" cols="30" rows="3" class="form-control input-lg"><?php echo $bill->description; ?></textarea>
                </div>

                <input type="hidden" name="id" id="id" value="<?php echo $bill->id ?>">
                <input type="hidden" name="sui" id="user_id" value="<?php echo $bill->user_id ?>">

                <div class="col-sm-12">
                  <button type="submit" name="update" value="bl" class="btn btn-primary btn-lg col-sm-6"><i class="fa fa-floppy-o"></i> Save</button>
                
                <a class="btn btn-danger btn-lg col-sm-6" onclick="deleteBill(<?php echo $bill->id ?>, <?php echo $account->user_id ?>)" role="button" href="#"><i class="fa fa-trash"></i> Delete</a>
                </div>
                <div class="clearfix"></div>
              </form>
      

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

<script type="text/javascript">
  function deleteBill(bill_id, user_id){
    
    var url = 'delete.php';
    var form = $('<form action="' + url + '" method="get">' +
    '<input type="hidden" name="type" id="type" value="bl">'+
    '<input type="hidden" name="id" id="id" value="' + bill_id + '" />'+
    '<input type="hidden" name="sui" id="sui" value="' + user_id + '" />'+
    '</form>');
    $('body').append(form);
    
    swal({
      title: 'Are you sure?',
      text: "You won't be able to revert this!",
      type: 'warning',
      showCancelButton: true,
      confirmButtonColor: '#3085d6',
      cancelButtonColor: '#d33',
      confirmButtonText: 'Yes, delete it!'
    }).then(function () {
      swal(
        'Deleted!',
        'The bill has been deleted.',
        'success'
      )
      form.submit();
    })
  }
</script>