<?php 
require_once('vendor/autoload.php');
require_once('init.php');

$userID = $_SESSION['user_id'];

// get user from db
$user = User::user_find_by_id($userID);

// stripe subId
$subId = $_POST['subId'];

$reply = new stdClass();
$date = new DateTime();
$unixTimeStamp = $date->getTimestamp();

// cancel subscription
try {
	$sub = \Stripe\Subscription::retrieve($subId);
	if ($sub->cancel()) {
		//update the user record in the users table
		$user->account_type = 'free';
		$user->stripe_customer_cancelled = $unixTimeStamp;
		$user->save();

		$reply->stripe_subscription_cancelled = 'yes';
		$session->login($user);

		// create success message
		$session->message("You successfully cancelled your premium account");
	}

	$reply->status = 1;
	$reply->msg = "Subscription cancelled successfully";
} catch(Exception $e){
	$reply->status = 0;
	$reply->msg = "Could not cancel subscription";
}

$reply->subscription = $sub;
print json_encode($reply);

