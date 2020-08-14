<?php
if (!isset($_GET['view'])) {
    redirect("index.php?view=account");
}

// get user
$userID = $_SESSION['user_id'];
$user = User::user_find_by_id($userID);
$account_type = $user->account_type;

// echo "<pre>";
// print_r($browser);
// print_r($user);
// echo "</pre>";

// get user notification settings
$userNotifications = Notification::notifactions_for_users($userID);

// get stripe customer
if(isset($user->stripe_customer_id) && $user->stripe_customer_id != ''){
    $cusObj = \Stripe\Customer::retrieve($user->stripe_customer_id)->__toJSON();
    $cusObj = json_decode($cusObj);
    $subId = $cusObj->subscriptions->data[0]->id;

    $card = array();
    $card['id'] = $cusObj->sources->data[0]->id;
    $card['country'] = $cusObj->sources->data[0]->country;
    $card['address_state'] = $cusObj->sources->data[0]->address_state;
    $card['brand'] = $cusObj->sources->data[0]->brand;
    $card['last4'] = $cusObj->sources->data[0]->last4;
    $card['expMonth'] = $cusObj->sources->data[0]->exp_month;
    $card['expYear'] = $cusObj->sources->data[0]->exp_year;
    $card['exp'] = $cusObj->sources->data[0]->exp_month . "/" . $cusObj->sources->data[0]->exp_year;
    // echo "<pre>";
    // print_r($cusObj);
    // echo "</pre>";
}

?>

<script src="https://checkout.stripe.com/checkout.js"></script>
<h3 class="breakdown-title">What would you like to do today?</h3>

<div class="panel panel-primary">
    <div class="panel-heading">Update Personal Info</div>
    <div class="panel-body">
        <div class="row">
            <form action="edit.php" method="post">
                <div class="col-sm-12">
                    <p><span class="label label-default"><strong>Note:</strong> We will not send you any mail, share your address or spam you in any way.</span>
                    </p>
                </div>
                <div class="col-sm-6 form-group">
                    <label for="first_name">First Name</label>
                    <input class="form-control" type="text" id="first_name" placeholder="First Name" name="first_name"
                           value="<?= $user->first_name ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="last_name">Last Name</label>
                    <input class="form-control" type="text" id="last_name" placeholder="Last Name" name="last_name"
                           value="<?= $user->last_name ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="address">Address</label>
                    <input class="form-control" type="text" id="address" placeholder="Address" name="address"
                           value="<?= $user->address ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="city">City</label>
                    <input class="form-control" type="text" id="city" placeholder="City" name="city"
                           value="<?= $user->city ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="state">State</label>
                    <input class="form-control" type="text" id="state" placeholder="State" name="state"
                           value="<?= $user->state ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="zip">Zip</label>
                    <input class="form-control" type="text" id="zip" placeholder="Zip" name="zip"
                           value="<?= $user->zip ?>">
                </div>
                <div class="col-sm-6 form-group">
                    <label for="subscribed">Subscription</label>
                    <select class="form-control" name="subscribed" id="subscribed">
                        <option <?= (($user->subscribed == 0) ? 'selected' : '') ?> value="0">Dont Subscribe</option>
                        <option <?= (($user->subscribed == 1) ? 'selected' : '') ?> value="1">Subscribe to latest news
                        </option>
                    </select>
                </div>
                <div class="col-sm-12">
                    <input type="hidden" name="user_id" id="user_id" value="<?php echo $user->id ?>">
                    <button type="submit" name="edit" value="pi" class="btn btn-primary"><i class="fa fa-floppy-o"></i>
                        Save Personal Info
                    </button>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- <div class="panel panel-primary">
	<div class="panel-heading">Update Emails</div>
    <div class="panel-body">
    	<div class="row">

    		<div class="col-sm-12">
    			<p>Your <strong>primary BAM email addrss</strong> is automatically set as your  primary email. To change your primary email address you must verify it once again.</p>

    			<p>
    				<span class="pull-left">1. <?= $user->email ?></span>
    				<span class="pull-right"> <span class="label label-info">Verified</span> <span class="label label-primary">Primary</span></span>
    			</p>
    			<br>
    			<hr>
    		</div>
    		<form>

	    		<div class="col-sm-6 form-group">
	    			<label for="name">Email</label>
	    			<input class="form-control" type="text" id="email" placeholder="Email Address" name="email" >
	    		</div>
	    		<div class="col-sm-3 form-group">
	    			<label for="">&nbsp;</label>
	    			<input class="form-control btn btn-large btn-primary" type="submit" name="updatePersonalInfo" value="Add Email">
	    		</div>
    		</form>
    	</div>
    </div>
</div>
-->

<div class="panel panel-success">
    <div class="panel-heading">
        Change Account Type
    </div>
    <div class="panel-body">
        <div class="row">
            <div class="col-sm-12">
                <div class="col-sm-2">Plan</div>
                <div class="col-sm-6">
                    <?= ((($user->premium_active_until > $unixTimeStamp) && $user->premium_active_until != 0) ? 'Your account is premium until <strong>'. date('D, F j, Y', $user->premium_active_until).'</strong>' : 'Your account is Free, get all the premium features. Only $4.99/month') ?>
                </div>
                <div class="col-sm-4">
                    <?php if ($user->premium_active_until > $unixTimeStamp && ($user->stripe_customer_id != '' || $user->stripe_customer_id != null) && ($user->stripe_customer_cancelled == '' || $user->stripe_customer_cancelled == 0 || $user->stripe_customer_cancelled == null)): ?>
                        <button class="btn btn-primary" id="cancel-premium">Cancel Premium</button>
                    <?php endif; ?>

                    <?php if ($user->premium_active_until < $unixTimeStamp || $user->premium_active_until == null || $user->premium_active_until == '' || $user->premium_active_until == 0): ?>
                        <div class="premium-upgade-button-column">
                            <button class="btn btn-primary" id="premium-upgrade">Upgrade to Premium</button>            
                            
                        </div>
                    <?php endif; ?>
                </div>
                
                <?php if (isset($user->stripe_customer_id) && $user->stripe_customer_id != null): ?>
                    <hr>
                    <div class="col-sm-2">Payment</div>
                    <div class="col-sm-6">
                        <?php if ($user->stripe_customer_id != '' || $user->stripe_customer_id != null): ?>
                            <?php echo $card['brand']; ?> **** **** **** <?php echo $card['last4']; ?> Expiration: <?php echo $card['exp']; ?> <br>
                            <?php if ($user->stripe_customer_cancelled == NULL || $user->stripe_customer_cancelled == 0): ?>
                                Next payment due: <?php echo date('Y-m-d', $user->premium_active_until) ?><br>
                                Total Amount: $4.99 
                            <?php else: ?>
                                You have no payment due at this time. <br>
                            <?php endif; ?>

                            
                        <?php else: ?>
                            Your account is free and have no payment info at this time.
                        <?php endif; ?>
                    </div>
                    <div class="col-sm-4">
                        <button data-toggle="modal" data-target="#updateCardModal" class="btn btn-default">Update Card</button>
                    </div>
                <?php endif ?>
            </div>
        </div>
    </div>
</div>

<div class="panel panel-primary">
    <div class="panel-heading">Change Notification Settings</div>
    <div class="panel-body">
        <div class="row">
            <form action="edit.php" method="post">

                <div class="col-sm-12 form-group">
                    <label>
                        <input type="checkbox" id="notification" <?= (($userNotifications->late_bills == 1) ? checked : '')?> name="notifications[]" value="late_bills"> Receive an
                        email when a bill is late..
                    </label>
                    <br>
                </div>
                <div class="col-sm-12">
                    <input type="hidden" name="user_id" id="user_id" value="<?php echo $user->id ?>">
                    <input type="hidden" name="edit" id="edit" value="notifications">
                    <input type="submit" class="btn btn-large btn-primary" value="Update Notification Settings">
                </div>
            </form>
        </div>
    </div>
</div>
<!--
<div class="panel panel-primary">
    <div class="panel-heading">Change Password</div>
    <div class="panel-body">
    	<div class="row">
    		<form>
    			<div class="col-sm-6 form-group">
    			<label for="name">Password</label>
    			<input class="form-control" type="text" id="password" placeholder="Password" name="password" >
    		</div>
    		<div class="col-sm-6 form-group">
    			<label for="name">Confirm Password</label>
    			<input class="form-control" type="text" id="confirmPassword" placeholder="Confrim new password" name="confirmPassword" >
    		</div>

    		<div class="col-sm-12">
    			<input type="submit" class="btn btn-large btn-primary" name="" value="Change your Password">
    		</div>
    		</form>
    	</div>
    </div>
</div> -->

<div class="panel panel-danger">
    <div class="panel-heading">Delete Account</div>
    <div class="panel-body">
        <div class="row">
            <form action="delete_account.php" method="post">
                <div class="col-sm-12">
                    <p>Once you delete your account, there is no going back. Pleace be certain.</p>
                </div>
                <div class="form-group col-sm-6">
                    <label for="email">For security reasons you must confirm your email address.</label>
                    <input class="form-control" type="text" name="email" id="email" placeholder="Email Address">
                </div>
                <div class="form-group col-sm-3">
                    <label>&nbsp;</label>
                    <button class='form-control btn btn-large btn-danger' name="delete" value="account" type="submit">
                        Delete your account
                    </button>
                </div>
                <input type="hidden" name="user_id" id="user_id" value="<?php echo $user->id ?>">
            </form>
        </div>
    </div>
</div>

<?php include('modals/updateCardModal.inc') ?>

<script type="text/javascript">
    $(function(){
        
        var userEmail = '<?php echo $_SESSION[email]; ?>';
        var handler = StripeCheckout.configure({
            key: 'pk_test_sAakzDLC9sCOQ6iIcZEuowXb',
            // key: 'pk_live_459PUfCxFVzZETdQdqh5BlYl',
            image: 'http://billaccountmanager.com/img/BAM-logo.png',
            locale: 'auto',
            token: function(token) {
                // You can access the token ID with `token.id`.
                // Get the token ID to your server-side code for use.
                $.ajax({
                    url:'stripe-account-upgrade.php',
                    method:'post',
                    data: {stripeToken:token},
                    dataType: 'json',
                    success:function(res){
                        console.log(res);
                        if(res.status == 'success'){
                            window.location.href = "/thank_you_premium.php";
                        }
                    }
                });
            }
        });

        // upgrade account
        $('#premium-upgrade').on('click', function(){
            handler.open({
                zipCode:true,
                email:userEmail,
                billingAddress:true,
                name: 'Bill Account Manager',
                description: 'Premium Plan',
                amount: 499,
                allowRememberMe:false
            });
        });

        // cancel account
        $('#cancel-premium').on('click', function(){
            var subId = '<?php echo $subId ?>';
            swal({
                title: 'Are you sure?',
                text: "You won't be able to revert this!",
                type: 'warning',
                showCancelButton: true,
                confirmButtonColor: '#3085d6',
                cancelButtonColor: '#d33',
                confirmButtonText: 'Yes, cancel it!'
            }).then(function () {
                $.ajax({
                    url:'stripe-cancel.php',
                    method: 'post',
                    data: {subId:subId},
                    dataType:'json',
                    success:function(res){
                        if(res.status == true){
                            // console.log(res);
                            window.location.href = "/index.php?view=account";
                           swal(
                                'Cancelled!',
                                'Your account is now free',
                                'success'
                            );
                       }
                    }
                });
            });  
        });

        // card update - new card
        $('#card-update').on('click', function(){
            var data = {
                cc_number : $('#cc-number').val(),
                cc_expiration_year : $('#cc-expiration-year').val(),
                cc_expiration_month : $('#cc-expiration-month').val(),
                cc_cvc : $('#cc-cvc').val()
            };
            $.ajax({
                url:'stripe-card-update.php',
                method: 'post',
                data: data,
                dataType:'json',
                success:function(res){
                    console.log(res);
                    var cvc_check = (typeof res.cvc_check != 'undefined') ? res.cvc_check : "fail";
                    console.log(cvc_check);
                    if(cvc_check == 'pass'){
                        window.location.href = "/index.php?view=account";
                   }
                }
            });
        });

        // Close Checkout on page navigation:
        window.addEventListener('popstate', function() {
            handler.close();
        });
    });
</script>