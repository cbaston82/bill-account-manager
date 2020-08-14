<!-- success -->
<?php if ($_SESSION['message']): ?>
  <div id="alertClose" class="alert alert-success">
    <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
    <p><?php echo $_SESSION['message']; ?></p>
  </div>
<?php endif ?>