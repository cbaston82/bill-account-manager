<?php

 	require_once('init.php');
	// check if user logged in
	if (!$session->is_signed_in()) { redirect('welcome.php'); }


	$session->message("Thank you for subscribing to the premium plan. You can now take advantage of the extra features and all future premium updates");