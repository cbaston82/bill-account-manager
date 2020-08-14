<?php 
  $auto_payment_check = '';
  if ($account->auto_payment == 'yes') $auto_payment_check = 'checked';
?>
<div id="editAccountModal<?php echo $account->id; ?>" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title"><?php echo $account->name; ?> <small>Account Info</small></h4>
      </div>
      <div class="modal-body">
          
        <!-- form start -->
        <form class="bam-edit-form" action="update.php?type=account" method="post">

          <div class="form-group col-sm-12">
            <input <?php echo $auto_payment_check ?> type="checkbox" name="auto_payment" id="auto_payment"> This account is set up for automatic payments
          </div>

          <!-- Accont Name -->
          <div class="form-group col-sm-6">
            <label for="name">Account Name</label>
            <input type="text" name="name" class="form-control input-lg" id="name" placeholder="Account Name" value="<?php echo $account->name; ?>">
          </div>
          
          <!-- Accont Number -->
          <div class="form-group col-sm-6">
            <label for="account_number">Account #</label>
            <input type="text" name="account_number" class="form-control input-lg" id="account_number" placeholder="Account Number" value="<?php echo $account->account_number; ?>">
          </div>

          <!-- Accont Phone -->
          <div class="form-group col-sm-6">
            <label for="phone">Phone</label>
            <input type="text" onKeyPress = "return numbersOnly(event)" name="phone" class="form-control input-lg" id="phone" placeholder="Phone Number" value="<?php echo $account->phone; ?>">
          </div>

          <!-- Accont Address -->
          <div class="form-group col-sm-6">
            <label for="address">Address</label>
            <input type="text" name="address" class="form-control input-lg" id="address" placeholder="Stree Address" value="<?php echo $account->address; ?>">
          </div>

          <!-- Accont City -->
          <div class="form-group col-sm-6">
            <label for="city">City</label>
            <input type="text" name="city" class="form-control input-lg" id="city" placeholder="City" value="<?php echo $account->city; ?>">
          </div>

          <!-- Accont State -->
          <div class="form-group col-sm-6">
            <label for="state">State</label>
            <select name="state" class="form-control input-lg" >
                <option <?= (($account->state == '')? 'selected' : '')?> value=NULL>-- State --</option>
                <option <?= (($account->state == 'AL')? 'selected' : '')?> value="AL">Alabama</option>
                <option <?= (($account->state == 'AK')? 'selected' : '')?> value="AK">Alaska</option>
                <option <?= (($account->state == 'AZ')? 'selected' : '')?> value="AZ">Arizona</option>
                <option <?= (($account->state == 'AR')? 'selected' : '')?> value="AR">Arkansas</option>
                <option <?= (($account->state == 'CA')? 'selected' : '')?> value="CA">California</option>
                <option <?= (($account->state == 'CO')? 'selected' : '')?> value="CO">Colorado</option>
                <option <?= (($account->state == 'CT')? 'selected' : '')?> value="CT">Connecticut</option>
                <option <?= (($account->state == 'DE')? 'selected' : '')?> value="DE">Delaware</option>
                <option <?= (($account->state == 'DC')? 'selected' : '')?> value="DC">District Of Columbia</option>
                <option <?= (($account->state == 'FL')? 'selected' : '')?> value="FL">Florida</option>
                <option <?= (($account->state == 'GA')? 'selected' : '')?> value="GA">Georgia</option>
                <option <?= (($account->state == 'HI')? 'selected' : '')?> value="HI">Hawaii</option>
                <option <?= (($account->state == 'ID')? 'selected' : '')?> value="ID">Idaho</option>
                <option <?= (($account->state == 'IL')? 'selected' : '')?> value="IL">Illinois</option>
                <option <?= (($account->state == 'IN')? 'selected' : '')?> value="IN">Indiana</option>
                <option <?= (($account->state == 'IA')? 'selected' : '')?> value="IA">Iowa</option>
                <option <?= (($account->state == 'KS')? 'selected' : '')?> value="KS">Kansas</option>
                <option <?= (($account->state == 'KY')? 'selected' : '')?> value="KY">Kentucky</option>
                <option <?= (($account->state == 'LA')? 'selected' : '')?> value="LA">Louisiana</option>
                <option <?= (($account->state == 'ME')? 'selected' : '')?> value="ME">Maine</option>
                <option <?= (($account->state == 'MD')? 'selected' : '')?> value="MD">Maryland</option>
                <option <?= (($account->state == 'MA')? 'selected' : '')?> value="MA">Massachusetts</option>
                <option <?= (($account->state == 'MI')? 'selected' : '')?> value="MI">Michigan</option>
                <option <?= (($account->state == 'MN')? 'selected' : '')?> value="MN">Minnesota</option>
                <option <?= (($account->state == 'MS')? 'selected' : '')?> value="MS">Mississippi</option>
                <option <?= (($account->state == 'MO')? 'selected' : '')?> value="MO">Missouri</option>
                <option <?= (($account->state == 'MT')? 'selected' : '')?> value="MT">Montana</option>
                <option <?= (($account->state == 'NE')? 'selected' : '')?> value="NE">Nebraska</option>
                <option <?= (($account->state == 'NV')? 'selected' : '')?> value="NV">Nevada</option>
                <option <?= (($account->state == 'NH')? 'selected' : '')?> value="NH">New Hampshire</option>
                <option <?= (($account->state == 'NJ')? 'selected' : '')?> value="NJ">New Jersey</option>
                <option <?= (($account->state == 'NM')? 'selected' : '')?> value="NM">New Mexico</option>
                <option <?= (($account->state == 'NY')? 'selected' : '')?> value="NY">New York</option>
                <option <?= (($account->state == 'NC')? 'selected' : '')?> value="NC">North Carolina</option>
                <option <?= (($account->state == 'ND')? 'selected' : '')?> value="ND">North Dakota</option>
                <option <?= (($account->state == 'OH')? 'selected' : '')?> value="OH">Ohio</option>
                <option <?= (($account->state == 'OK')? 'selected' : '')?> value="OK">Oklahoma</option>
                <option <?= (($account->state == 'OR')? 'selected' : '')?> value="OR">Oregon</option>
                <option <?= (($account->state == 'PA')? 'selected' : '')?> value="PA">Pennsylvania</option>
                <option <?= (($account->state == 'RI')? 'selected' : '')?> value="RI">Rhode Island</option>
                <option <?= (($account->state == 'SC')? 'selected' : '')?> value="SC">South Carolina</option>
                <option <?= (($account->state == 'SD')? 'selected' : '')?> value="SD">South Dakota</option>
                <option <?= (($account->state == 'TN')? 'selected' : '')?> value="TN">Tennessee</option>
                <option <?= (($account->state == 'TX')? 'selected' : '')?> value="TX">Texas</option>
                <option <?= (($account->state == 'UT')? 'selected' : '')?> value="UT">Utah</option>
                <option <?= (($account->state == 'VT')? 'selected' : '')?> value="VT">Vermont</option>
                <option <?= (($account->state == 'VA')? 'selected' : '')?> value="VA">Virginia</option>
                <option <?= (($account->state == 'WA')? 'selected' : '')?> value="WA">Washington</option>
                <option <?= (($account->state == 'WV')? 'selected' : '')?> value="WV">West Virginia</option>
                <option <?= (($account->state == 'WI')? 'selected' : '')?> value="WI">Wisconsin</option>
                <option <?= (($account->state == 'WY')? 'selected' : '')?> value="WY">Wyoming</option>
              </select>
          </div>

          <!-- Accont zip -->
          <div class="form-group col-sm-6">
            <label for="zip">Zip</label>
            <input type="text" name="zip" class="form-control input-lg" id="zip" placeholder="Zip Code" value="<?php echo $account->zip; ?>">
          </div>

          <!-- Account notes -->
          <div class="form-group col-sm-12">
            <label for="ntes">Account Notes</label>
            <textarea class="form-control" rows="4" cols="50" name="notes" id="notes"><?php echo $account->notes; ?></textarea>
          </div>

          <input type="hidden" name="id" id="id" value="<?php echo $account->id ?>">
          <input type="hidden" name="sui" id="user_id" value="<?php echo $account->user_id ?>">

          <div class="col-sm-12">
            <button type="submit" name="update" value="ua" class="btn btn-primary btn-lg col-sm-6"><i class="fa fa-floppy-o"></i> Save</button>
          
          <a class="btn btn-danger btn-lg col-sm-6" onclick="deleteAccount(<?php echo $account->id; ?>,<?php echo $account->user_id ?>)" role="button" href="#"><i class="fa fa-trash"></i> Delete</a>
          </div>
          <div class="clearfix"></div>
        </form>

      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>


<script type="text/javascript">
  function deleteAccount(account_id, user_id){
    var url = 'delete.php';
    var form = $('<form action="' + url + '" method="get">' +
    '<input type="hidden" name="type" id="type" value="ua">'+
    '<input type="hidden" name="id" id="id" value="' + account_id + '" />'+
    '<input type="hidden" name="sui" id="sui" value="' + user_id + '" />'+
    '</form>');
    $('body').append(form);
    
    swal({
      title: 'Are you sure?',
      text: "You won't be able to revert this!",
      type: 'warning',
      showCancelButton: true,
      confirmButtonColor: '#3085d6',
      cancelButtonColor: '#d33',
      confirmButtonText: 'Yes, delete it!'
    }).then(function () {
      swal(
        'Deleted!',
        'The account has been deleted',
        'success'
      )
      form.submit();
    })
  }
</script>