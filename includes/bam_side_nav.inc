<ul class="nav nav-stacked"  id="bam_side_nav">

    <!-- bam home -->
    <li><a class="<?php echo ($_GET['view'] == 'home') ? 'active active-side-link' : '' ; ?>" href="index.php?view=home"><i class="fa fa-tachometer"></i> Dashboard</a></li>
    <hr>

    <!-- accounts -->
    <?php $count_accounts_nav = Account::accounts_all($_SESSION['user_id']) ?>
    <li>
      <a class="<?php echo ($_GET['view'] == 'accounts') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=accounts"><i class="fa fa-list-alt"></i> Accounts<span class="badge pull-right"><?= ((count($count_accounts_nav) > 0) ? count($count_accounts_nav) : '') ?></span></a>
      <a class="col-xs-2 c-pointer add-new" data-toggle="modal" data-target="#newAccountModal"><i class="fa fa-plus"></i></span></a>
      <div class="clearfix"></div>
    </li>
    <hr>

    <!-- bills -->
    <?php $count_bills_nav = Bill::bills_all_active($_SESSION['user_id']) ?>
    <li>
      <a class="<?php echo ($_GET['view'] == 'bills') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=bills"><i class="fa fa-money"></i> Bills <span class="badge pull-right"><?= ((count($count_bills_nav) > 0) ? count($count_bills_nav) : '') ?></span></a>
      <a class="col-xs-2 c-pointer add-new" data-toggle="modal" data-target="#newBillModal"><i class="fa fa-plus"></i></a>
      <div class="clearfix"></div>
    </li>
    <hr>

     <!-- notes -->
    <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
      <?php $count_notes_nav = Note::notes_all($_SESSION['user_id']) ?>
      <li>
        <a class="<?php echo ($_GET['view'] == 'notes') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=notes"><i class="fa fa-sticky-note-o"></i> Notes <span class="badge pull-right"><?= ((count($count_notes_nav) > 0) ? count($count_notes_nav) : '') ?></span></a>
        <a class="col-xs-2 c-pointer add-new" data-toggle="modal" data-target="#newNoteModal"><i class="fa fa-plus"></i></a>
        <div class="clearfix"></div>
      </li>
      <hr>
    <?php endif; ?>

    <!-- bills acrchived -->
    <?php $count_bills_archvied_nav = Bill::bills_all_inactive($_SESSION['user_id']) ?>
    <li>
      <a class="<?php echo ($_GET['view'] == 'archived') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=archived"><i class="fa fa-archive"></i> Bills Archived <span class="badge pull-right"><?= ((count($count_bills_archvied_nav) > 0) ? count($count_bills_archvied_nav) : '') ?></a>
      <div class="clearfix"></div>
      </li>
    <hr>

    <!-- payments -->
    <?php //$count_payments_nav = Payment::payments_find_all($_SESSION['user_id']) ?>
    <!-- <li>
      <a class="<?php echo ($_GET['view'] == 'payments') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=payments"><i class="fa fa-history"></i> Payment History <span class="badge pull-right"><?= ((count($count_payments_nav) > 0) ? count($count_payments_nav) : '') ?></span></a>
      <div class="clearfix"></div>
    </li>
    <hr> -->


    <!-- Tasks -->
    <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
    <!--   <li><a class="<?php echo ($_GET['view'] == 'tasks') ? 'active active-side-link' : '' ; ?>" href="index.php?view=tasks"><i class="fa fa-check-square-o"></i> Tasks <span class="badge pull-right"></span></a></li>
      <hr> -->
    <?php endif; ?>

    <!-- Calendar -->
    <?php if ($user->premium_active_until > $unixTimeStamp) : ?>
      <li>
        <a class="<?php echo ($_GET['view'] == 'calendar') ? 'active active-side-link' : '' ; ?> col-xs-10" href="index.php?view=calendar"><i class="fa fa-calendar" aria-hidden="true"></i> Calendar</a>
        <div class="clearfix"></div>
      </li>
      <hr>
    <?php endif; ?>
</ul>

<!-- bills button -->
<?php if($_GET['view'] == 'bills'):?>
    <!-- <a class="btn col-xs-12 col-sm-4 col-md-12 btn-warning btn-lg c-white" data-toggle="modal" data-target="#newBillModal" href=""><i class="fa fa-plus"></i> Add Bill</a> -->
    <!-- <div class="clearfix"></div> -->

    <div class="manage_selected"></div>
<?php endif ?>

<!-- accounts button -->
<?php if($_GET['view'] == 'accounts'):?>
    <!-- <a class="btn col-xs-12 col-sm-4 col-md-12 btn-warning btn-lg c-white" data-toggle="modal" data-target="#newAccountModal" href=""><i class="fa fa-plus"></i> Add Account</a> -->
    <!-- <div class="clearfix"></div> -->
<?php endif ?>

<!-- payment history -->
<?php //if ($_GET['view'] == 'home'): ?>
    <?php //include("includes/bam_side_recent_payments.inc") ?>
<?php //endif ?>

<!-- notes button -->
<?php if ($user->premium_active_until > $unixTimeStamp) : ?>
  <?php if($_GET['view'] == 'notes'):?>
      <!-- <a class="btn col-xs-12 col-sm-4 col-md-12 btn-warning btn-lg c-white" data-toggle="modal" data-target="#newNoteModal" href=""><i class="fa fa-plus"></i> Add Note</a> -->
      <!-- <div class="clearfix"></div> -->
  <?php endif ?>
<?php endif; ?>

<!-- tasks button -->
<?php if ($user->premium_active_until > $unixTimeStamp) : ?>
  <?php if($_GET['view'] == 'tasks'):?>
      <!-- <a class="btn col-xs-12 col-sm-4 col-md-12 btn-warning btn-lg c-white" data-toggle="modal" data-target="#newTaskModal" href=""><i class="fa fa-plus"></i> Add Task</a> -->
      <!-- <div class="clearfix"></div> -->
  <?php endif; ?>
<?php endif; ?>

