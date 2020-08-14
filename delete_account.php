<?php

	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) {
		redirect('login.php'); 

	}elseif (!isset($_POST['delete'])) { // make sure delete type is set
		$session->message("There was a problem deleting your account");
		redirect("index.php?view=account"); 
		exit();
	}elseif ($_POST['email'] != $_SESSION['email']) { //make sure make sure email account = session email
		$session->message("The email entered did not match account email.");
		redirect("index.php?view=account"); 
		exit();
	}elseif ($_POST['user_id'] != $_SESSION['user_id']) { //check if logged in user is user requesting to delete
		$session->message("There was a problem deleting your account");
		redirect("index.php?view=account");  
		exit();
	}else{
		// create params 
	$user_id = $_POST['user_id'];
	$email = $_POST['email'];

	// find user
	if ($user_delete = User::user_find_by_id($user_id)) {
		
		// get user bills
		$user_bills = Bill::bills_all($user_id);
		if (count($user_bills > 0)) {
			$delete_user_bills = Bill::bills_delete_all_user_bills($user_id);
		}


		// get user accounts
		$user_accounts = Account::accounts_all($user_id);
		if (count($user_accounts) > 0) {
			$delete_user_accounts = Account::accounts_delete_all_user_accounts($user_id);
		}

		// get user notes
		$user_notes = Note::notes_all($user_id);
		if (count($user_notes) > 0) {
			$delete_user_notes = Note::notes_delete_all_user_notes($user_id);
		}

		// get user payments
		$user_payments = Payment::payments_find_all($user_id);
		if (count($user_payments) > 0) {
			$delete_user_payments = Payment::payments_delete_all_user_payments($user_id);
		}

		// get user notification settins
		$user_notifications = Notification::notifactions_for_users($user_id);
		if (count($user_notifications) > 0) {
			$delete_user_notifications = Notification::delete_all_user_notifications($user_id);
		}

		// finally delete user , log out user 
		$user_delete->delete();
		$session->logout();

		redirect('welcome.php');

	}
	

	echo '<pre>';
	echo count($user_payments);
	print_r($user_payments);

	}

	