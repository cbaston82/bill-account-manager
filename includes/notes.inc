<?php
  // check if user is has a premium account
  if ($user->premium_active_until < $unixTimeStamp){ redirect('index.php?view=home'); }

  // get user notes
  $notes_all = Note::notes_all($_SESSION['user_id']);
 ?>

<!-- <link href="https://fonts.googleapis.com/css?family=Indie+Flower|Sriracha" rel="stylesheet"> -->
<!-- <script src="//cdn.tinymce.com/4/tinymce.min.js"></script> -->
<script src="https://cdn.tiny.cloud/1/no-api-key/tinymce/5/tinymce.min.js" referrerpolicy="origin"></script>
<h3 class="breakdown-title">You have (<?= count($notes_all) ?>) notes</h3>

<?php if (count($notes_all) < 1): ?>
   <div class="col-sm-4 note">
      <div class="note-container">
        <div class="note-actions pull-right">
          <a href="#" class="btn btn-danger btn-xs disabled" role="button"><i class="fa fa-trash" aria-hidden="true"></i></a>
          <a href="#" class="btn btn-primary btn-xs disabled" role="button"><i class="fa fa-pencil-square-o" aria-hidden="true"></i></a>
        </div>
        <div class="clearfix"></div>
        <div class="ellipsis note-content">
          <h4 class="note-title"><strong>Note Example</strong></h4>
          <div class="note-body">
          <p>This is a note <strong>example</strong>, you can add your current <a href="index.php?view=bills">bills</a> to a note just click the calcutor next to the bill amout.</p>
          <ul>
            <li>List item 1</li>
            <li>List item 2</li>
            <li>List item 3</li>
          </ul>
          <ol>
            <li>Ordered list item 1</li>
            <li>Ordered list item 2</li>
            <li>Ordered list item 3</li>
          </ol>
          </div>
        </div>
      </div>
  </div>
<?php endif; ?>

<div class="row" id="notes">
  <div class="col-sm-12">
    <?php foreach ($notes_all as $note): ?>
      <div class="col-sm-4 note">
          <div class="note-container">
            <div class="note-actions pull-right">
               <a href="delete.php?type=note&id=<?php echo $note->id; ?>&sui=<?php echo $note->user_id ?>" onclick="return confirm('Are you sure you want to permanently delete this note?')" class="btn btn-danger btn-xs" role="button"><i class="fa fa-trash" aria-hidden="true"></i></a>
                <a href="#" class="btn btn-primary btn-xs" role="button" data-toggle="modal" data-target="#editNoteModal<?= $note->id ?>"><i class="fa fa-pencil-square-o" aria-hidden="true"></i></a>
            </div>
            <div class="clearfix"></div>
            <div class="ellipsis note-content">
              <h4 class="note-title"><strong><?= $note->note_title ?></strong></h4>
              <div class="note-body"><?= $note->note_body ?></div>
            </div>
          </div>
      </div>
      <?php include'modals/editNoteModal.inc' ?>
    <?php endforeach; ?>
  </div>
</div>


<!-- newNoteModal -->
<?php include("modals/newNoteModal.inc") ?>


<script>
  $('#notes').masonry({
    // options
    itemSelector: '.note'
  });

   tinymce.init({
    selector:'textarea',
    height: 200,
    plugins: [
      'advlist autolink lists link charmap print preview',
      'searchreplace visualblocks',
      'insertdatetime contextmenu paste'
    ],
    toolbar: 'insertfile undo redo | styleselect | bold italic | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | link image'
  });
</script>
