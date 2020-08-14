<!-- all accounts -->
<?php if ($session->is_signed_in()) : ?>

<?php endif ?>

<div id="newTaskModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">New Task</h4>
      </div>
      <div class="modal-body">

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

<script>
  $('.datepicker').datepicker({});
</script>
