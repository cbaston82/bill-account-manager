<?php
  // get user active bills
  $bills = Bill::bills_all_active($_SESSION['user_id']);

  // total amount due
  $total_bills_due = Bill::bills_all_active_total(1, 'due', $_SESSION['user_id']);
?>

<ul class="datatable-filter-buttons">
  <li class="btn btn-default btn-md"><a href="#" class="all">All</a></li>
  <li class="btn btn-default btn-md"><a href="#">Late</a></li>
  <li class="btn btn-default btn-md"><a href="#">Ok</a></li>
</ul>

<h3 class="breakdown-title">All Bills
  <?php echo (count($bills) > 0) ? "(".count($bills).")" : ""; ?>
  <strong><?php echo ($total_bills_due == '') ? "" : "&#x24;".currency($total_bills_due); ?></strong>
</h3>

<div class="panel panel-primary">
  <!-- if bills available -->
  <?php if (count($bills) > 0): ?>
    <div class="table-responsive">
      <table class="table table-hover responsive display bam-table-bills">
        <thead>
          <tr>
            <th>Title</th>
            <th>Amount Due</th>
            <th>Due Date</th>
            <!-- <th>Description</th> -->
            <th>Status</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
        <?php

          // loop throug bills
          foreach ($bills as $bill) {

            // check if bill is late
            $status = Bill::bill_check_if_late($bill->due_date);

            // get account name
            $account_name = Account::find_by_id($bill->account_id);

            // variables to pass through on bill-calculate
            $amount = $bill->amount;
            $bill_name = $account_name->name;

            ?>

              <tr class="<?php echo ($status == '1') ? 'OK' : 'bg-danger' ?>"  data-billDue="<?php echo $bill->due ?>">
                <td class="text-nowrap"><?php echo $account_name->name; ?></td>
                <td class="text-nowrap">
                  <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
                      <a class="c-pointer bill_options" data-toggle="tooltip" data-placement="bottom" title="add to calulator">
                        <i class="fa fa-calculator" aria-hidden="true"></i>
                      </a>
                  <?php endif; ?>
                  <span class="<?=(($status == '1')?'bg-success':'bg-danger')?>" data-toggle="tooltip" data-placement="bottom" title="&#x24;<?php echo $bill->due; ?>">&#x24;<?php echo currency($bill->due); ?> <?php echo ($account_name->auto_payment == 'yes') ? '<strong>A</strong>' : '' ?></span>
                </td>
                <td class="text-nowrap"><?php echo the_date($bill->due_date); ?></td>
                <!-- <td class="text-nowrap"><?php echo $bill->description; ?></td> -->
                <td class="text-nowrap"><?php echo ($status == '1') ? 'OK' : 'Late'; ?></td>
                <td class="text-nowrap">

                  <!-- action links -->
                  <a href="#" data-toggle="modal" data-target="#editBillModal<?php echo $bill->id; ?>"><i data-toggle="tooltip" data-placement="bottom" title="Edit Bill" class="fa fa-pencil-square-o"></i></a>

                  | <a href="#" data-toggle="modal" data-target="#makePaymentModal<?php echo $bill->id; ?>"><i title="Create Payment" class="fa fa-money"></i></a>

                  <?php if (count(Payment::payments_find_all_by_id($bill->id)) > 0): ?>
                    <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
                    | <a href="#" id="<?php echo $bill->id; ?>" data-toggle="modal" data-target="#paymentHistoryModal"><i class="c-link-orange fa fa-history"></i></a>  
                    <?php endif; ?>
                  <?php endif ?>

                </td>
              </tr>
              <?php include("modals/editBillModal.inc") ?>
              <?php include("modals/makePaymentModal.inc") ?>
          <?php }
        ?>
        </tbody>
      </table>
    </div>
  <?php endif ?>

  <!-- if user has no active bills -->
  <?php if (count($bills) < 1): ?>
    <div class="list-group-item">
      <h3 class="list-group-item-heading"><strong>YOU HAVE NO BILLS </strong><br><small>All active bills will be shown here once created.</small></h3>
    </div>
  <?php endif ?>
</div>

<script src="assets/js/calculator_event.js"></script>
<?php require("modals/paymentHistoryModal.inc") ?>
