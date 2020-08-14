<div id="makePaymentModal<?php echo $bill->id; ?>" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title"><?php echo $account_name->name; ?> <small> Balance due - (<?php echo '$'.$bill->due; ?>)</small></h4>
      </div>
      <div class="modal-body">

       <!-- form start -->
       <form action="payments.php" method="post">

         <!-- Accont Name -->
         <div class="form-group">
           <label for="payment_amount">Payment Amount</label>
           <input type="text" name="payment_amount" class="form-control input-lg" id="payment_amount" placeholder="Payment Amount" value="<?php echo $bill->due ?>">
         </div>
         
         <!-- Confirmation Number -->
         <div class="form-group">
           <label for="confirmation_number">Conformation #</label>
           <input type="text" name="confirmation_number" class="form-control input-lg" id="confirmation_number" placeholder="Confirmation Number" autofocus="autofocus" value="">
         </div>

          <!-- Date -->
         <div class="form-group">
           <label for="date">Date</label>
           <input type="text" name="date" class="form-control input-lg pickDate"  placeholder="Date" value="<?php echo date('Y-m-d'); ?>">
         </div>

         <!-- Description -->
         <div class="form-group">
           <label for="description">Payment Description</label>
           <input type="text" name="description" class="form-control input-lg" id="description" placeholder="Payment Description" value="">
         </div>

         <input type="hidden" name="bill_id" id="bill_id" value="<?php echo $bill->id ?>">
         <input type="hidden" name="account_id" id="account_id" value="<?php echo $bill->account_id ?>">
         <input type="hidden" name="sui" id="user_id" value="<?php echo $bill->user_id ?>">

         <button type="submit" name="update" value="payment" class="btn btn-success btn-block btn-lg">Save</button>
       </form>

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>