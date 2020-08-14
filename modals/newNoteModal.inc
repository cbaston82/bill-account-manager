<!-- all accounts -->
<?php if ($session->is_signed_in()) : ?>

<?php endif ?>

<script src="//cdn.tinymce.com/4/tinymce.min.js"></script>
<script>
  tinymce.init({
  selector: '#newNoteModal textarea',
  height: 200,
  plugins: [
    'advlist autolink lists link charmap print preview',
    'searchreplace visualblocks',
    'insertdatetime contextmenu paste'
  ],
  toolbar: 'insertfile undo redo | styleselect | bold italic | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | link image'
});
</script>

<div id="newNoteModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">New Note</h4>
      </div>
      <div class="modal-body">
        <form class="form" action="new.php" method="post">
          <div class="form-group">
            <label for="note_title">Note Title</label>
            <input class="form-control" placeholder="Note Title" type="text" name="note_title" id="note_title" value="">
          </div>
          <div class="form-group">
            <label for="note_content">Note Body</label>
            <textarea class="form-control" id="note_body" name="note_body" rows="15" cols="40"></textarea>
          </div>

          <input type="hidden" name="user_id" id="user_id" value="<?php echo $_SESSION['user_id'] ?>">
          <button type="submit" name="new" value="note" class="btn btn-primary"><i class="fa fa-floppy-o"></i> Save</button>
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
