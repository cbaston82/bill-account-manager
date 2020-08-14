<?php 

require_once('init.php');

$userID = $_SESSION['user_id'];

// get user from users table.
$user = User::user_find_by_id($userID);

$reply = new stdClass();
$date = new DateTime();
$unixTimeStamp = $date->getTimestamp();

// check if user has a stripe account.
if($user->stripe_customer_id == '' || $user->stripe_customer_id == null){
	//create the stripe account for user.
	$customer = \Stripe\Customer::create(array('email'=>$user->email));

	// set user stripe info in users table.
	$user->stripe_customer_id = $customer->id;
	$user->stripe_customer_registered = $customer->created;
}else{
	// if already a stripe user, get the users stripe customer info from stripe.
	$customer = \Stripe\Customer::retrieve($user->stripe_customer_id);
	$reply->stripe_customer_found_in_db = 'yes';
}

// set user account type in users table
$user->account_type = 'premium';
$user->stripe_customer_cancelled = NULL;

// get stripe customer Id from stripe customer
$customer_stripe_id = $customer->id;

// save cutomer card to stripe
$customer->source = $_POST['stripeToken']['id'];
$customer->save();

try{
	$sub = \Stripe\Subscription::create(array(
		"customer" => $customer_stripe_id,
		"items" => array(
			array(
			 	"plan" => "premium_plan",
			),
		)
	));
	$reply->status = 1;
	$reply->msg = "Subscription added successfully";
	$reply->txid = $sub->id;
} catch(Exception $e){
	$reply->status = 0;
	$reply->error_msg = "Failed to add subscription.";
}

// update user
if ($user->save()) {
	$reply->stripe_customer_created = 'yes';
	$session->login($user);

	$reply->status = 'success';

	// create success message
	$session->message("Thank you for subscribing to the premium plan. You can now take advantage of the extra features and all future premium updates");
}


$reply->customerObj = $customer;
print json_encode($reply);
