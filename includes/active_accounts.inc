<!-- all user accounts -->
<?php $accounts = Account::accounts_all($_SESSION['user_id']); ?>

<h3 class="breakdown-title">Active Accounts
   <?php echo (count($accounts) > 0) ? "(".count($accounts).")" : ""; ?>
</h3>

<div class="panel panel-primary">

  <!-- if active accounts -->
  <?php if (count($accounts) > 0): ?>
    <div class="table-responsive">
      <table class="table table-hover display responsive bam-table-active-accounts">
        <thead>
          <tr>
            <th>Name</th>
            <th>Account #</th>
            <th>Phone</th>
            <!-- <th>Address</th> -->
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
        <?php

          // loop through accounts
          foreach ($accounts as $account) { 

            // show active accounts
            if ($account->status == 1) {?>
              <tr>
                <td><?php echo $account->name; ?></td>
                <td><code data-toggle="tooltip" data-placement="bottom" title="<?php echo $account->account_number; ?>"><?php echo $account->account_number; ?></code></td>
                <td><?php echo formatPhone($account->phone); ?></td>
                <!-- <td><?php echo $account->address." ".$account->city." ".$account->state." ".$account->zip?></td> -->
                <td>
                  
  
                  <!-- action links -->
                  <a href="#" data-toggle="modal" data-target="#editAccountModal<?php echo $account->id; ?>"><i data-toggle="tooltip" data-placement="bottom" title="Edit Bill" class="fa fa-pencil-square-o"></i></a>

                  <?php if (count(Payment::payments_find_all_by_account_id($account->id)) > 0): ?>
                    <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
                      | <a href="#" id="<?php echo $account->id; ?>" data-toggle="modal" data-target="#paymentHistoryModal"><i class="c-link-orange fa fa-history"></i></a>   
                    <?php endif ?> 
                  <?php endif ?>



                </td>
              </tr>
              <?php include("modals/editAccountModal.inc") ?>

            <?php } ?>

         <?php } 
        ?>
        </tbody>
      </table>
    </div>
  <?php endif ?>

  <!-- if user has no accounts -->
  <?php if (count($accounts) < 1): ?>
    <div class="list-group-item">
      <h3 class="list-group-item-heading"><strong>YOU HAVE NO ACCOUNTS </strong><br><small>All active accounts will be shown here once created.</small></h3>
    </div>
  <?php endif ?>
</div>

<?php require("modals/paymentHistoryModal.inc") ?>
