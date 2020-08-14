<!-- all user active bills -->
<?php $bills = Bill::bills_all_inactive($_SESSION['user_id']); ?>

<h3 class="breakdown-title">Archived bills
  <?php echo (count($bills) > 0) ? "(".count($bills).")" : ""; ?>
</h3>

<div class="panel panel-primary">

  <!-- if user has archived bills -->
  <?php if (count($bills) > 0): ?>
    <div class="table-responsive">
      <table class="table table-hover responsive display bam-table-archived-bills">
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

            // get account name
            $account_name = Account::find_by_id($bill->account_id);?>

            <tr class="<?php echo (strtotime($bill->close_date) <= strtotime($bill->due_date)) ? 'OK' : 'bg-danger' ?>">
              <td><?php echo $account_name->name; ?></td>
              <td><span class="<?php echo (strtotime($bill->close_date) <= strtotime($bill->due_date)) ? 'bg-success' : 'bg-danger' ?>" data-toggle="tooltip" data-placement="bottom" title="&#x24;<?php echo $bill->amount; ?>">&#x24;<?php echo currency($bill->amount); ?></span></td>
              <td><?php echo the_date($bill->due_date); ?></td>
              <!-- <td><?php echo $bill->description; ?></td> -->
              <td><?php echo (strtotime($bill->close_date) <= strtotime($bill->due_date)) ? 'OK' : 'Late'; ?></td>
              <td>
                <a href="#" data-toggle="modal" data-target="#editBillModal<?php echo $bill->id; ?>"><i data-toggle="tooltip" data-placement="bottom" title="Edit Bill" class="fa fa-pencil-square-o"></i></a>

              </td>
            </tr>
            <?php include("modals/editBillModal.inc") ?>
          <?php }
        ?>
        </tbody>
      </table>
    </div>
  <?php endif ?>

  <!-- if user has no archived bills -->
  <?php if (count($bills) < 1): ?>
    <div class="list-group-item">
      <h3 class="list-group-item-heading"><strong>YOU HAVE NO ARCHIVED BILLS </strong><br><small>All archived bills will be shown here once they are closed.</small></h3>
    </div>
  <?php endif ?>
</div>