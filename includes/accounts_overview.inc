<!-- all accounts -->
<?php $accounts = Account::accounts_all($_SESSION['user_id']) ?>

<!-- bills -->
<?php $bills = Bill::bills_all_active($_SESSION['user_id']) ?>

<!-- total amount due -->
<?php $total_bills_due = Bill::bills_all_active_total(1, 'due', $_SESSION['user_id']) ?>

<!-- total amount -->
<?php $total_bills = Bill::bills_all_active_total(1, 'amount', $_SESSION['user_id']) ?>

<!-- get late bills -->
<?php $late_bills = Bill::bills_all_active_late($_SESSION['user_id']); ?>

<?php $late_bills_total = Bill::bills_all_active_late_total($_SESSION['user_id']) ?>

<!-- find user -->
<?php $user = User::user_find_by_id($_SESSION['user_id']) ?>

<!-- get email without the @ -->
<?php $user_email_parts = explode("@", $user->email); ?>

<div class="row clearfix" id="account-overview-section">

  <!-- bills breakdown -->
  <div class="col-md-12">

    <h1 class="welcome-back">Welcome,<br class="visible-xs"> <?php echo $user->email; ?> <small><br class="visible-xs"><?php echo (the_date($user->date_last_login) == "Dec 31, 1969")? 'last login: Never' : 'last login: '.the_date($user->date_last_login); ?></small></h1>
    <p>Account type: <span class="label label-default"><?= (($user->premium_active_until > $unixTimeStamp) ? 'Premium' : 'Free')?></span><span> <?= (($user->premium_active_until > $unixTimeStamp) ? '' : '<a href="index.php?view=account">upgrade to Premium</a>')?></span></p>
    <h3 class="breakdown-title">Bills Overview</h3>
    <div class="panel panel-primary">

      <!-- Start of Cost To Date Information-->
      <div class="panel-heading"><span class="badge"><?php echo count($bills); ?></span> bills in progress</div>
      <div class="list-group">

          <div class="list-group-item">
            <h3 class="list-group-item-heading">TOTAL BILLS<br class="visible-xs"> <?php echo ($total_bills != "") ? "<code class='text-success'>&#x24;".currency($total_bills)."</code>" : "<code class='text-success'>No bills found.</code>" ?><br><small>Total for all active bills.</small></h3>
          </div>

          <div class="list-group-item">
            <h3 class="list-group-item-heading">TOTAL BILLS DUE<br class="visible-xs"> <?php echo ($total_bills_due != "")  ? "<code class='text-success'>&#x24;".currency($total_bills_due)."</code>" : "<code class='text-success'>No bills due.</code>" ?><br><small>Total amount due after any payments.</small></h3>
          </div>

          <div class="list-group-item">
            <h3 class="list-group-item-heading">TOTAL BILLS LATE<br class="visible-xs"> <?php echo ($late_bills_total != "") ? "<code>&#x24;".currency($late_bills_total)."</code><br class='visible-xs'> <span class='text-muted'>( Total bills late " . count($late_bills) . ")</pan>" : "<code>No late bills found.</code>" ?> <br><small>Total of bills that are past due. Adjusted to any payments made.</small></h3>
          </div>

      </div>
    </div>
  </div>

  <!-- bills breakdown -->
  <div class="col-md-12">
    <h3 class="breakdown-title">Accounts Overview</h3>
    <div class="panel panel-primary">

      <!-- Start of Cost To Date Information-->
      <div class="panel-heading"><span class="badge"><?php echo count($accounts) ?></span> accounts</div>
      <div class="list-group">

        <!-- start display counter -->
        <?php $disply = 0 ?>

        <!-- loop through accounts found / only display 4 -->
        <?php foreach ($accounts as $account): ?>
          <div class="list-group-item">
            <h3 class="list-group-item-heading"><?php echo $account->name; ?><br>
              <?php if ($account->account_number != ""): ?>
                <small><code><?php echo $account->account_number; ?></code></small>
              <?php endif ?>
            </h3>

          </div>
          <?php if ($disply++ == 3) break; ?>
        <?php endforeach ?>

        <!-- if no accounts found display this -->
        <?php if (count($accounts) == 0): ?>
          <div class="list-group-item">
            <h3 class="list-group-item-heading">YOU HAVE NO ACCOUNTS<br><small>Start adding your accounts. <br> <a href="index.php?view=accounts">View accounts</a></small></h3>
          </div>
        <?php endif ?>

      </div>
      <!-- if accouts found display this -->
      <?php if (count($accounts) > 0): ?>
        <div class="panel-footer">
          <a href="index.php?view=accounts">View accounts</a>
        </div>
      <?php endif ?>
    </div>
  </div>
</div>
