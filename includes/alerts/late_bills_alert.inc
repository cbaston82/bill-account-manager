<!-- get late bills -->
<?php $late_bills = Bill::bills_all_active_late($_SESSION['user_id']); ?>
   
<!-- show alert if any late bills -->
<?php if (count($late_bills) > 0 && !$_SESSION['late_bills'] == 'not aknowledged'): ?>
  <div id="late_bills_alert" class="alert alert-danger">
    <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
    <h4><?php echo count($late_bills); ?> late bills.</h4>
    <p>There are bills that are past due. Please take care of them as soon as possible.</p>
  </div>
<?php endif ?>