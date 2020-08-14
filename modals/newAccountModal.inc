<div id="newAccountModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">Add Account</h4>
      </div>
      <div class="modal-body">
          
        <!-- form start -->
        <form action="new.php" method="post">

          <div class="form-group col-sm-12">
            <input type="checkbox" name="auto_payment" id="auto_payment"> This account is set up for automatic payments
          </div>

          <!-- Accont Name -->
          <div class="form-group col-sm-12">
            <label for="name">Account Name</label>
            <input type="text" name="name" class="form-control input-lg" id="name" placeholder="Account Name" value="">
          </div>

          <!-- <div class="form-group">
            <input type="checkbox" id="otherAccountInfo"> Enter full acount information
          </div> -->
          
          <!-- <div id="AccountInfo" style="display: none;"> -->
            <!-- Accont Number -->
          <div class="form-group col-sm-6">
            <label for="account_number">Account #</label>
            <input type="text" name="account_number" class="form-control input-lg" id="account_number" placeholder="Account Number" value="">
          </div>

          <!-- Accont Phone -->
          <div class="form-group col-sm-6">
            <label for="phone">Phone</label>
            <input type="text" name="phone" onKeyPress = "return numbersOnly(event)" class="form-control input-lg" id="phone" placeholder="Phone Number" value="">
          </div>

          <!-- Accont Address -->
          <div class="form-group col-sm-6">
            <label for="address">Address</label>
            <input type="text" name="address" class="form-control input-lg" id="address" placeholder="Stree Address" value="">
          </div>

          <!-- Accont City -->
          <div class="form-group col-sm-6">
            <label for="city">City</label>
            <input type="text" name="city" class="form-control input-lg" id="city" placeholder="City" value="">
          </div>

          <!-- Accont State -->
          <div class="form-group col-sm-6">
            <label for="state">State</label>
            <select class="form-control input-lg" name="state" id="state">
              <option value=NULL>-- State --</option>
              <option value="AL">Alabama</option>
              <option value="AK">Alaska</option>
              <option value="AZ">Arizona</option>
              <option value="AR">Arkansas</option>
              <option value="CA">California</option>
              <option value="CO">Colorado</option>
              <option value="CT">Connecticut</option>
              <option value="DE">Delaware</option>
              <option value="DC">District Of Columbia</option>
              <option value="FL">Florida</option>
              <option value="GA">Georgia</option>
              <option value="HI">Hawaii</option>
              <option value="ID">Idaho</option>
              <option value="IL">Illinois</option>
              <option value="IN">Indiana</option>
              <option value="IA">Iowa</option>
              <option value="KS">Kansas</option>
              <option value="KY">Kentucky</option>
              <option value="LA">Louisiana</option>
              <option value="ME">Maine</option>
              <option value="MD">Maryland</option>
              <option value="MA">Massachusetts</option>
              <option value="MI">Michigan</option>
              <option value="MN">Minnesota</option>
              <option value="MS">Mississippi</option>
              <option value="MO">Missouri</option>
              <option value="MT">Montana</option>
              <option value="NE">Nebraska</option>
              <option value="NV">Nevada</option>
              <option value="NH">New Hampshire</option>
              <option value="NJ">New Jersey</option>
              <option value="NM">New Mexico</option>
              <option value="NY">New York</option>
              <option value="NC">North Carolina</option>
              <option value="ND">North Dakota</option>
              <option value="OH">Ohio</option>
              <option value="OK">Oklahoma</option>
              <option value="OR">Oregon</option>
              <option value="PA">Pennsylvania</option>
              <option value="RI">Rhode Island</option>
              <option value="SC">South Carolina</option>
              <option value="SD">South Dakota</option>
              <option value="TN">Tennessee</option>
              <option value="TX">Texas</option>
              <option value="UT">Utah</option>
              <option value="VT">Vermont</option>
              <option value="VA">Virginia</option>
              <option value="WA">Washington</option>
              <option value="WV">West Virginia</option>
              <option value="WI">Wisconsin</option>
              <option value="WY">Wyoming</option>
            </select>       
          </div>

          <!-- Accont State -->
          <div class="form-group col-sm-6">
            <label for="zip">Zip</label>
            <input type="text" name="zip" class="form-control input-lg" id="zip" placeholder="Zip Code" value="">
          </div>
          <!-- </div> -->

          <div class="form-group col-sm-12">
            <label for="ntes">Account Notes</label>
            <textarea class="form-control" rows="4" cols="50" name="notes" id="notes"></textarea>
          </div>

          <input type="hidden" name="user_id" id="user_id" value="<?php echo $_SESSION['user_id'] ?>">

          <div class="col-sm-12">
            <button type="submit" name="new" value="account" class="btn btn-primary btn-block btn-lg"><i class="fa fa-floppy-o"></i> Save</button>
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