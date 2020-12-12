<?php
	error_reporting(E_ALL);
	require_once('config.php');
	require_once('functions.php');
	require_once('classes/Session.inc');
	require_once('classes/Database.inc');
	require_once('classes/User.inc');
	require_once('classes/Bill.inc');
	require_once('classes/UserPayment.inc');
	require_once('classes/Account.inc');
    require_once('classes/Note.inc');
    require_once('classes/Notification.inc');
    require_once('classes/DB_object.inc');

 	require_once('vendor/autoload.php');
 	\Stripe\Stripe::setApiKey("secret_key_here");


 	// ============================================
	// Global Settings
	// ============================================

	// unix time stamp
	$date = new DateTime();
	$unixTimeStamp = $date->getTimestamp();
