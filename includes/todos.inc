<?php
  // check if user is has a premium account
  if ($user->premium_active_until < $unixTimeStamp){ redirect('index.php?view=home'); }
 ?>

<div class="alert alert-warning">
  <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
  <strong>Under Development</strong> This page is currently being developed.
</div>



<h3 class="breakdown-title">You have (0) tasks</h3>

<div class="panel panel-primary">

    <!-- if user has no notes -->
    <div class="list-group-item">
      <h3 class="list-group-item-heading"><strong>Coming Soon!!</strong><br><small>Under development.</small></h3>
    </div>
</div>

<!-- newTaskModal -->
<?php include("modals/newTaskModal.inc") ?>
