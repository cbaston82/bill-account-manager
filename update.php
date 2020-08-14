<?php
	
	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('login.php'); }

	// make sure update type is set
	if (!isset($_POST['update'])) { redirect("index.php?viwe=home");}
		
	// check if logged in user
	if ($user_id != $_SESSION['user_id']) {redirect("index.php?viwe=home");}

	// clear out any alerts
	unset($_SESSION['message']);

	// create url params 
	$type = $_POST['update'];
	$id = $_POST['id'];
	$user_id = $_POST['sui'];


	// if bill or archived bill
	if ($type == 'bl' OR $type == 'ab') {

		// if bill found 
		if ($bill = Bill::find_by_id($id)) {

			// get bill account name
			$account_name = Account::find_by_id($bill->account_id);

			// get payments history for bill
			$bill_paymet_history = Payment::payments_find_all_by_id($id);

			// if post amount higher than amount
			if ($bill->amount < $_POST['amount']) {

				if ($bill_paymet_history) {

					$add_to_due_bill = $_POST['amount'] - $bill->amount;
					$new_due = $bill->due + $add_to_due_bill;

					// update amounts
					$bill->amount = $_POST['amount'];
					$bill->due = $new_due;

				}else{

					$bill->amount = $_POST['amount'];
					$bill->due = $_POST['amount'];
					$bill->account_id = $_POST['account_id'];
					$bill->due_date = $_POST['due_date'];
					$bill->description = $_POST['description'];
				}

			// if post amount is less than amount
			}elseif ($bill->amount > $_POST['amount']) {

				if ($bill_paymet_history) {

					$remove_from_due_bill = $bill->amount - $_POST['amount'];
					$new_due = $bill->due - $remove_from_due_bill;

					// update amounts
					$bill->amount = $_POST['amount'];
					$bill->due = $new_due;

				}else{

					$bill->amount = $_POST['amount'];
					$bill->due = $_POST['amount'];
					$bill->account_id = $_POST['account_id'];
					$bill->due_date = $_POST['due_date'];
					$bill->description = $_POST['description'];
				}

			// if post amount the same as amount
			}else{

				if ($bill_paymet_history) {

					$bill->amount = $_POST['amount'];
					$bill->due = $_POST['due'];
					$bill->account_id = $_POST['account_id'];
					$bill->due_date = $_POST['due_date'];
					$bill->description = $_POST['description'];

				}else{

					$bill->amount = $_POST['amount'];
					$bill->due = $_POST['amount'];
					$bill->account_id = $_POST['account_id'];
					$bill->due_date = $_POST['due_date'];
					$bill->description = $_POST['description'];

				}
			
			}

			if ($bill->save()) {
				
				// success message
				$session->message("{$account_name->name} bill successfully saved.");
			
				// check if bill needs to be marked inactive
				$check_bill_status = Bill::bill_mark_inactive($id);


			}else{

				// error message
				$session->message("Bill could not be saved.");

			}

		}else{

			// error message
			$session->message("Bill could not be saved.");
		}

		// redirect back to original page
		if ($type == 'bl') {

			redirect('index.php?view=bills');

		}else{

			redirect('index.php?view=archived');

		}

	}elseif ($type == 'ua') {

		// find account
		if ($account = Account::find_by_id($id)) {

			print_r($_POST);

			// update account
			$account->name = $_POST['name'];
			$account->account_number = $_POST['account_number'];
			$account->phone = $_POST['phone'];
			$account->address = $_POST['address'];
			$account->city = $_POST['city'];
			$account->state = $_POST['state'];
			$account->zip = $_POST['zip'];
			$account->status = 1;
			$account->notes = $_POST['notes'];

			if(isset($_POST['auto_payment']) && $_POST['auto_payment'] == 'on'){
				$account->auto_payment = 'yes';
			}else{
				$account->auto_payment = 'no';
			}
			
			// if account saved
			if ($account->save()) {
				
				// success message
				$session->message("{$account->name} account successfully saved.");

			}else{

				// error message
				$session->message("Could not save account.");

			}

		}else{

			// error message
			$session->message("Could not find account.");

		}

		// redirect to accounts
		redirect('index.php?view=accounts');

	}elseif ($type == 'pmt') {

		// find Payment found
		if ($payment = Payment::find_by_id($id)) {

			// get payment account name
			$account_name = Account::find_by_id($payment->account_id);

			// if bill found
			if ($bill = Bill::find_by_id($payment->bill_id)) {

				// if payment post more that payment amount
				if ($payment->payment_amount < $_POST['payment_amount']) {

					// udpate bill
					$remove_from_due_bill = $_POST['payment_amount'] - $payment->payment_amount;
					$bill->due = $bill->due - $remove_from_due_bill;
					$bill->save();

					// update payment
					$payment->payment_amount = $_POST['payment_amount'];
					$payment->confirmation_number = $_POST['confirmation_number'];
					$payment->description = $_POST['description'];
					$payment->save();

				// if post payment amount less that payment amount
				}elseif ($payment->payment_amount > $_POST['payment_amount']) {

					// udpate bill
					$add_to_due_bill = $payment->payment_amount - $_POST['payment_amount'];
					$bill->due = $bill->due + $add_to_due_bill;
					$bill->save();

					// update payment
					$payment->payment_amount = $_POST['payment_amount'];
					$payment->confirmation_number = $_POST['confirmation_number'];
					$payment->description = $_POST['description'];
					$payment->save();

				}else{

					$payment->payment_amount = $_POST['payment_amount'];
					$payment->confirmation_number = $_POST['confirmation_number'];
					$payment->description = $_POST['description'];
					$payment->save();

				}

				// mark bill inactive 
				$check_bill_status = Bill::bill_mark_inactive($bill->id);

				// success message
				$session->message("{$account_name->name} payment successfully saved.");
								

			}else{

				// error message
				$session->message("Could not find the bill payment belongs to, did not save.");

			}

		}else{

			// error message
			$session->message("Could not find that payment.");

		}

		// redirect back to payments
		redirect("index.php?view=payments");

	}else{

		// redirect to home
		redirect("index.php?view=home");

	}
		

?>