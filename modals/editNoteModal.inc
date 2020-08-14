<div id="editNoteModal<?= $note->id ?>" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">New Note</h4>
      </div>
      <div class="modal-body">
        <form class="form" action="edit.php" method="post">
          <div class="form-group">
            <label for="note_title">Note Title</label>
            <input class="form-control" placeholder="Note Title" type="text" name="note_title" id="note_title" value="<?= $note->note_title ?>">
          </div>
          <div class="form-group">
            <label for="note_content">Note Body</label>
            <textarea class="form-control" id="note_body<?= $note->id ?>" name="note_body" cols="40"><?= $note->note_body ?></textarea>
          </div>

          <input type="hidden" name="user_id" id="user_id" value="<?php echo $_SESSION['user_id'] ?>">
          <input type="hidden" name="id" id="id" value="<?= $note->id ?>">
          <button type="submit" name="edit" value="note" class="btn btn-primary"><i class="fa fa-floppy-o"></i> Save</button>
        </form>
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