<?php 
require_once('init.php');

$userID = $_SESSION['user_id'];

// get user from db
$user = User::user_find_by_id($userID);

// get customers stripe customerId
$stripe_customer_id = $user->stripe_customer_id;

$reply = new stdClass();
$reply->post = $_POST;
$reply->stripeId = $stripe_customer_id;

try {
	$customer = \Stripe\Customer::retrieve($stripe_customer_id);
	$reply->customer = $customer;

	// get the users stripe default card
	$original_card = $customer->sources->data[0]->id;

	// new card updating to
	$cardArray = array(
		"object" => "card",
		"exp_month" => $_POST['cc_expiration_month'],
		"exp_year" => $_POST['cc_expiration_year'],
		"number" => $_POST['cc_number'],
		"cvc" => $_POST['cc_cvc']
	);

	// create new card
	$createCard = $customer->sources->create(array("source" => $cardArray));
	$reply->customer = $createCard;
	
	if ($createCard->cvc_check = 'pass') {
		$customer->sources->retrieve($original_card)->delete();
		$reply->cvc_check = 'pass';
	}else{
		$reply->cvc_check = 'failed';
	}

} catch(Exception $e){}


print json_encode($reply);

