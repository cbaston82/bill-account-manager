<?php

  if (!isset($_GET['type'])) {
    redirect("index.php?view=home");
  }

  // make sure original user
  if ($_GET['sui'] != $_SESSION['user_id']) {
    redirect("index.php?view=home");
  }



  // get bill
  $bill = Bill::bill_find_by_id($_GET['id']);

  // get accounts
  $account = Account::account_find_by_id($bill->account_id);

?>


<!-- if user account -->
<?php if ($_GET['type'] == 'bl'): ?>
  <?php if ($bill->user_id != $_SESSION['user_id']) {
      redirect("index.php?view=accounts");
    }else{?>
      <div class="panel panel-primary edit-panel">
        <div class="panel-heading">
          <strong><?php echo $account->name; echo ' - $'.$bill->amount; ?></strong>
        </div>

        <!-- form start -->
        <form class="bam-edit-form" action="payments.php" method="post">

          <!-- Accont Name -->
          <div class="form-group">
            <label for="payment_amount">Payment Amount</label>
            <input type="text" name="payment_amount" class="form-control" id="payment_amount" placeholder="Payment Amount" value="">
          </div>

          <!-- Confirmation Number -->
          <div class="form-group">
            <label for="confirmation_number">Conformation #</label>
            <input type="text" name="confirmation_number" class="form-control" id="confirmation_number" placeholder="Confirmation Number" value="">
          </div>

           <!-- Date -->
          <div class="form-group">
            <label for="date">Date</label>
            <input type="text" name="date" class="form-control pickDate" id="date" placeholder="Date" value="<?php echo date('Y-m-d'); ?>">
          </div>

          <!-- Description -->
          <div class="form-group">
            <label for="description">Payment Description</label>
            <input type="text" name="description" class="form-control" id="description" placeholder="Payment Description" value="">
          </div>

          <input type="hidden" name="bill_id" id="bill_id" value="<?php echo $bill->id ?>">
          <input type="hidden" name="account_id" id="account_id" value="<?php echo $bill->account_id ?>">
          <input type="hidden" name="sui" id="user_id" value="<?php echo $bill->user_id ?>">

          <button type="submit" name="update" value="payment" class="btn btn-danger"><i class="fa fa-usd"></i> Log Payment</button>
        </form>


      </div>
    <?php } ?>
<?php endif ?>
