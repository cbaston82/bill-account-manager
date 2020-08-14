<?php

	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('login.php'); }

	// make sure add type is set
	if (!isset($_POST['new'])) { redirect('index.php?view=home'); }

	// create url params
	$type = $_POST['new'];
	$user_id = $_POST['user_id'];

	// check if logged in user
	if ($user_id != $_SESSION['user_id']) { redirect('index.php?view=home'); }

	// run new type
	if ($type == 'bill') {

		// create new bill
		$new_bill = new Bill();
		$new_bill->account_id = $_POST['account_id'];
		$new_bill->user_id = $_POST['user_id'];
		$new_bill->due_date = $_POST['due_date'];
		$new_bill->close_date = NULL;
		$new_bill->amount = $_POST['amount'];
		$new_bill->due = $_POST['amount'];
		$new_bill->description = $_POST['description'];
		$new_bill->status = 1;

		// if bill saved
		if ($new_bill->save()) {

			// get bill account name
			$account = Account::find_by_id($new_bill->account_id);

			// success message
			$session->message("New {$account->name} bill was sccessfully created.");

		}else{

			// error message
			$session->message("Bill could not be created.");

		}

		// redirect back to bills
		redirect('index.php?view=bills');

	}elseif ($type == 'account') {

		// create new account
		$new_account = new Account();
		$new_account->user_id = $_SESSION['user_id'];
		$new_account->name = $_POST['name'];
		$new_account->account_number = $_POST['account_number'];
		$new_account->phone = $_POST['phone'];
		$new_account->address = $_POST['address'];
		$new_account->city = $_POST['city'];
		$new_account->state = $_POST['state'];
		$new_account->zip = $_POST['zip'];
		$new_account->status = 1;
		$new_account->notes = $_POST['notes'];

		if(isset($_POST['auto_payment']) && $_POST['auto_payment'] == 'on'){
			$new_account->auto_payment = 'yes';
		}else{
			$new_account->auto_payment = 'no';
		}

		// if account saved
		if ($new_account->save()) {

			// success message
			$session->message("New {$new_account->name} account was sccessfully created.");

		}else{

			// error message
			$session->message("Account could not be created.");

		}

		// redirect back to accounts
		redirect('index.php?view=accounts');

	}elseif($type == 'note'){

				// create new account
				$new_note = new Note();
				$new_note->user_id = $_SESSION['user_id'];
				$new_note->note_title = $_POST['note_title'];
				$new_note->note_body = $_POST['note_body'];

				if ($new_note->save()) {

					// success message
					$session->message("Note was sccessfully created.");

				}else{

					// error message
					$session->message("Note could not be created.");

				}

				// redirect back to bills
				redirect('index.php?view=notes');

	}else{

		// redirect back to home
		redirect('index.php?view=home');

	}

?>
