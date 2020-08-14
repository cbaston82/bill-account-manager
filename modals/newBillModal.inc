<!-- all accounts -->
<?php if ($session->is_signed_in()) : ?>
  <?php $all_accounts = Account::accounts_all($_SESSION['user_id']); ?>
<?php endif ?>

<div id="newBillModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">New Bill</h4>
      </div>
      <div class="modal-body">

        <!-- form start -->
        <?php if (count($all_accounts) == 0): ?>
          <h3>NO ACCOUNTS FOUND... <br><small>You must have at least one active account to tie a bill to. <br> Go to <a href="index.php?view=accounts">accounts</a></small></h3>
        <?php endif ?>

        <?php if (count($all_accounts) > 0): ?>
          <form action="new.php" method="post">

            <!-- select options -->
            <div class="form-group col-sm-12">
              <label for="account_id">Account Type</label>
              <select name="account_id" id="account_id" class="form-control input-lg">
                <option value="">-- Account Type --</option>

                <?php foreach ($all_accounts as $account): ?>
                  <option value="<?php echo $account->id; ?>"><?php echo $account->name; ?></option>
                <?php endforeach ?>
              </select>
            </div>


            <!-- amount -->
            <div class="form-group col-sm-6">
              <label for="amount">Amount</label>
              <input type="text" name="amount" class="form-control input-lg" id="amount" placeholder="Bill Amount" value="">
            </div>

             <!-- due_date -->
            <div class="form-group col-sm-6">
              <label for="due_date">Due Date</label>
              <input type="text" name="due_date" class="form-control pickDate input-lg" placeholder="Due Date" value="">
            </div>

            <!-- description -->
            <div class="form-group col-sm-12">
              <label for="description">Description</label>
              <textarea name="description" id="description" cols="30" rows="15" class="form-control input-lg"></textarea>
            </div>

            <div class="col-sm-12">
              <input type="hidden" name="user_id" id="user_id" value="<?php echo $_SESSION['user_id'] ?>">

              <button type="submit" name="new" value="bill" class="btn btn-primary btn-block btn-lg"><i class="fa fa-floppy-o"></i> Save</button>
            </div>
            <div class="clearfix"></div>
          </form>
        <?php endif ?>

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>

