<section id="bam-top-hero">
  <div class="container">
     <div class="row">
       <div class="col-md-12">

        <!-- home -->
        <?php if ($page_view == 'home'): ?>
          <h1>DASHBOARD</h1>
          <p class="lead">An overview of all your current bills and accounts. All changes to your account will reflect here on your dashboard. This application calculates your current bills. </p>
        <?php endif ?>

        <!-- accounts -->
        <?php if ($page_view == 'accounts'): ?>
          <h1>CURRENT ACCOUNTS</h1>
          <p class="lead">Keep track of all your payment history for each account you create. Click on the <i class="c-link-orange fa fa-history"></i> icon to see the payment history for that account.</p>
        <?php endif ?>

        <!-- bills -->
        <?php if ($page_view == 'bills'): ?>
          <h1>CURRENT BILLS</h1>
          <p class="lead">Add all your new bills here as you receive them. They will reflect on your <a class="c-link-orange" href="index.php?view=home">BAM HOME</a> page.</p>
        <?php endif ?>

        <!-- bills archived -->
        <?php if ($page_view == 'archived'): ?>
          <h1>ARCHIVED BILLS</h1>
          <p class="lead">View all your closed out bills. You may also want to look up bill payment history.</p>
        <?php endif ?>

        <!-- payment history -->
        <?php if ($page_view == 'payments'): ?>
          <h1>PAYMENT HISTORY</h1>
          <p class="lead">Complete payment history. Lookup any payment made quickly and easy.</p>
        <?php endif ?>

        <!-- notes -->
        <?php if ($page_view == 'notes'): ?>
          <h1>Notes</h1>
          <p class="lead">Create a note on the fly.</p>
        <?php endif ?>

        <!-- tasks -->
        <?php if ($page_view == 'tasks'): ?>
          <h1>Tasks</h1>
          <p class="lead">Lorem ipsum dolor sit amet, consectetur adipisicing elit,in culpa qui officia deserunt mollit anim id est laborum.</p>
        <?php endif ?>

        <!-- tasks -->
        <?php if ($page_view == 'account'): ?>
          <h1>Account and Settings</h1>
          <p class="lead">Welcome to your new account and settings page. Manage your account here.</p>
        <?php endif ?>

        <!-- calendar -->
        <?php if ($page_view == 'calendar'): ?>
          <h1>Your new calendar view</h1>
          <p class="lead">Welcome to your new calendar page. You can manage your dates here.</p>
        <?php endif ?>

        <!-- edit -->
        <?php if ($page_view == 'edit'): ?>
          <?php if (isset($_GET[id])) : ?>
              <?php if ($_GET['type'] == 'ua') : ?>
                <?php $account = Account::account_find_by_id($_GET['id']);?>
                <h1>Edit <small class="c-white"><?php echo $account->name; ?> account</small></h1>
              <?php elseif ($_GET['type'] == 'bl' OR $_GET['type'] == 'ab') : ?>
                <?php $bill = Bill::bill_find_by_id($_GET['id']);?>
                <?php $account = Account::account_find_by_id($bill->account_id);?>
                <h1>Edit <small class="c-white"><?php echo $account->name; ?> bill</small></h1>
              <?php elseif ($_GET['type'] == 'pmt') : ?>
                <?php $payment = Payment::payment_find_by_id($_GET['id']) ?>
                <?php $account = Account::account_find_by_id($payment->account_id);?>
                <h1>Edit <small class="c-white"><?php echo $account->name; ?> payment</small></h1>
              <?php else : ?>
                <?php redirect("index.php?view=home"); ?>
              <?php endif; ?>
          <?php endif; ?>
        <?php endif; ?>

        <!-- payment -->
        <?php if ($page_view == 'payment'): ?>
          <?php if (isset($_GET['id'])) : ?>
            <?php if ($_GET['type'] == 'bl') : ?>
              <?php $bill = Bill::bill_find_by_id($_GET['id']);?>
                <?php if ($bill) : ?>
                  <?php if ($bill->user_id == $_SESSION['user_id']) : ?>
                    <?php $account = Account::account_find_by_id($bill->account_id);?>
                    <h1>Payment for <small class="c-white"><?php echo $account->name; ?> <br><?= (($account->account_number != '') ? 'Account: '.$account->account_number : '')?> </small></h1>
                  <?php else: ?>
                    <?php redirect("index.php?view=home") ?>
                  <?php endif; ?>
                <?php else: ?>
                  <?php redirect("index.php?view=home") ?>
                <?php endif; ?>
            <?php else: ?>
              <?php redirect("index.php?view=home") ?>
            <?php endif; ?>
          <?php endif; ?>
        <?php endif; ?>

       </div>
     </div>
   </div>
</section>

<section class="c-section-content-1" id="bam-section">
  <div class="container">
    <div class="row">
      <div class="col-md-12">
        <?php if($page_view == 'account') : ?>
        <div class="col-md-12">
          <!-- Success alert -->
          <?php include("includes/alerts/success_alert.inc") ?>
          <?php include("includes/account.inc") ?>
        </div>
      <?php elseif($page_view == 'calendar') :?>
        <!-- calendar -->
          <?php include("includes/calendar.inc") ?>
      <?php else: ?>
        <!-- side nav -->
      <div class="col-md-3">

        <!-- side navigation -->
        <?php include("includes/bam_side_nav.inc"); ?>

      </div>


      <!-- main content -->
      <div class="col-md-9">

        <!-- Success alert -->
        <?php include("includes/alerts/success_alert.inc") ?>

        <!-- Late bills alert -->
        <?php include("includes/alerts/late_bills_alert.inc") ?>

        <!-- accounts overview -->
        <?php if ($page_view == 'home'): ?>
          <?php include("includes/accounts_overview.inc") ?>
        <?php endif ?>

        <!-- Active bills -->
        <?php if ($page_view == 'bills'): ?>
          <?php include("includes/active_bills.inc") ?>
        <?php endif ?>

        <!-- Active accounts -->
        <?php if ($page_view == 'accounts'): ?>
          <?php include("includes/active_accounts.inc") ?>
        <?php endif ?>

        <!-- Payed bills -->
        <?php if ($page_view == 'archived'): ?>
          <?php include("includes/payed_bills.inc") ?>
        <?php endif ?>

        <!-- payments -->
        <?php if ($page_view == 'payments'): ?>
          <?php include("includes/all_payments.inc") ?>
        <?php endif ?>

         <!-- edit -->
        <?php if ($page_view == 'edit'): ?>
          <?php include("includes/edit.inc") ?>
        <?php endif ?>

        <!-- payment -->
        <?php if ($page_view == 'payment'): ?>
          <?php include("includes/payment.inc") ?>
        <?php endif ?>

        <!-- notes -->
        <?php if ($page_view == 'notes'): ?>
          <?php include("includes/notes.inc") ?>
        <?php endif ?>

        <!-- todos -->
        <?php if ($page_view == 'tasks'): ?>
          <?php include("includes/todos.inc") ?>
        <?php endif ?>
      
        <!-- payouts graph -->
        <?php if ($_SESSION['account_type'] == 'premium' && $page_view == 'home') : ?>
          <?php include("includes/payouts_graph.inc") ?>
        <?php endif; ?>

      </div>
      <?php endif; ?>

    </div>
  </div>
</section>
