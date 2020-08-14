<?php 

	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('login.php'); } 

	// make sure delete type is set
	if (!isset($_GET['type'])) { redirect("index.php?view=home"); } 

	// check if logged in user is user requesting to delete
	if ($_GET['sui'] != $_SESSION['user_id']) { redirect('index.php?view=home'); }

	// create url params 
	$type = $_GET['type'];
	$id = $_GET['id'];
	$user_id = $_GET['sui'];
	
	
	// if delete type is bill
	if ($type == 'bl') {

		// if bill id found
		if ($bill = Bill::find_by_id($id)) {

			// delete all payments if any for this bill
			$bill_payments = Payment::payments_delete_all_by_bill_id($id);

			// get account name for this bill
			$account = Account::find_by_id($bill->id);

			// delete bill
			if ($bill->delete()) {
				
				// create success message
				$session->message(" Bill {$account->name} was sccessfully deleted.");

			}else{

				// create success message
				$session->message("Bill could not be deleted.");
			}
		}else{

			// create error message
			$session->message("Bill could not be deleted.");

		}

		// redirect back to bills
		redirect('index.php?view=bills');

	}elseif ($type == 'ua') {
	
		// if account found
		if ($account = Account::find_by_id($id)) {

			// if account is deleted
			if ($account->delete()) {

				// success message
				$session->message(" Account {$account->name} was sccessfully deleted.");

			}else{

				// error message
				$session->message(" Account could not be deleted.");
			}
		}else{

			// error message
			$session->message(" Account could not be deleted.");

		}

			// redirect back to accounts
			redirect('index.php?view=accounts');

	}elseif ($type == 'pmt') {

		// if payment is found
		if ($payment_delete = Payment::find_by_id($id)) {	

			// if asociated bill found
			if ($bill = Bill::find_by_id($payment_delete->bill_id)) {
				
				// update bill due
				$bill->due = $bill->due + $payment_delete->payment_amount;
				$bill->save();

			}

			// if payment deleted
			if ($payment_delete->delete()) {
				
				// check bill status mark active or inactive
				$check_bill_status = Bill::bill_mark_inactive($bill->id);

				// success message
				$session->message("Payment was deleted.");
			}else{

				// error message
				$session->message("Payment could not be deleted.");
			}
				
		}else{

			// error message
			$session->message("No payment found.");

		}
			// redirect back to payments
			redirect("index.php?view=payments");

	}elseif ($type == 'note'){
		// if payment is found
		if ($note_delete = Note::find_by_id($id)) {	

			// if payment deleted
			if ($note_delete->delete()) {

				// success message
				$session->message("Note was deleted.");

			}else{

				// error message
				$session->message("Note could not be deleted.");
			}

		
		}else{

			// error message
			$session->message("No Note found.");

		}

		// redirect back to accounts
		redirect('index.php?view=notes');

	}else{

		// redirect back to payments
		redirect("index.php?view=home");

	}

?>

