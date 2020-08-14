<!-- find user payments -->
<?php $payments = Payment::payments_find_all($_SESSION['user_id']); ?>

<h3 class="breakdown-title">Payments History
  <?php echo (count($payments) > 0) ? "(".count($payments).")" : ""; ?>
</h3>

<div class="panel panel-primary">

  <!-- if user has payments -->
  <?php if (count($payments) > 0): ?>
    <div class="table-responsive">
      <table class="table table-hover responsive display bam-table-payment-history">
        <thead>
          <tr>
            <th>Account</th>
            <th>Payment</th>
            <th>Conf #</th>
            <th>Date</th>
            <!-- <th>Description</th> -->
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
        <?php 

          // loop through payments
          foreach ($payments as $payment) { 

            // get account name
            $account_name = Account::find_by_id($payment->account_id);
            ?>
              <tr>
                <td><?php echo $account_name->name; ?></td>
                <td><span class="bg-success" data-toggle="tooltip" data-placement="bottom" title="<?php echo $payment->payment_amount; ?>">&#x24;<?php echo currency($payment->payment_amount); ?></span></td>
                <td><strong class="bg-success"><?php echo $payment->confirmation_number; ?></strong></td>
                <td><?php echo the_date($payment->date)?></td>
                <!-- <td><?php echo $payment->description; ?></td> -->
                <td>
                   <!-- action links -->
                  <a href="index.php?view=edit&type=pmt&id=<?php echo $payment->id; ?>&sui=<?php echo $payment->user_id ?>"><i data-toggle="tooltip" data-placement="bottom" title="Edit Payment" class="fa fa-pencil-square-o"></i></a>
                 
                </td>
              </tr>
          <?php } 
        ?>
        </tbody>
      </table>
    </div>
  <?php endif ?>

  <!-- if user has no payments made -->
  <?php if (count($payments) < 1): ?>
    <div class="list-group-item">
      <h3 class="list-group-item-heading"><strong>YOU HAVE NO PAYMENTS HISTORY </strong><br><small>All payments made will be shown here once created.</small></h3>
    </div>
  <?php endif ?>
</div>