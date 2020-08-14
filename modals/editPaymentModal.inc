<div id="editPaymentModal<?php echo $payment->id; ?>" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title"><?php echo $account_name->name; ?> <small>Payment made ( &#x24;<?php echo $payment->payment_amount; ?> )</small></h4>
      </div>
      <div class="modal-body">

        <!-- form start -->
        <form action="update.php" method="post">

           <!-- payment_amount -->
          <div class="form-group">
            <label for="payment_amount">Payment amount</label>
            <input type="text" name="payment_amount" class="form-control" id="payment_amount" placeholder="Amount Due" value="<?php echo $payment->payment_amount; ?>">
          </div>

           <!-- date -->
          <div class="form-group">
            <label for="date">Date</label>
            <input type="text" name="date" class="form-control pickDate" id="date" placeholder="Date" readonly value="<?php echo $payment->date; ?>">
          </div>

           <!-- confirmation number -->
          <div class="form-group">
            <label for="confirmation_number">Confirmation Number</label>
            <input type="text" name="confirmation_number" class="form-control" id="confirmation_number" placeholder="Confirmation Number" value="<?php echo $payment->confirmation_number; ?>">
          </div>

          <!-- description -->
          <div class="form-group">
            <label for="description">Description</label>
            <textarea name="description" id="description" cols="30" rows="3" class="form-control"><?php echo $payment->description; ?></textarea>
          </div>

          <input type="hidden" name="id" id="id" value="<?php echo $payment->id ?>">
          <input type="hidden" name="sui" id="user_id" value="<?php echo $payment->user_id ?>">

          <button type="submit" name="update" value="pmt" class="btn btn-primary"><i class="fa fa-floppy-o"></i> Save</button>
          <a class="btn btn-danger" onclick="return confirm('Are you sure you want to permanently delete this record? You wont be able to get it back!! ')" role="button" href="delete.php?type=pmt&id=<?php echo $payment->id; ?>&sui=<?php echo $payment->user_id ?>"><i class="fa fa-trash"></i> Delete</a>
        </form>
      

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>