<?php 
	
	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('login.php'); }

	// make sure payment type is set
	if (!isset($_POST['update'])) { redirect('index.php?view=home'); }

	// check if logged in user
	if ($user_id == $_SESSION['user_id']) { redirect('index.php?view=home'); }

	// create url params 
	$type = $_POST['update'];
	$user_id = $_POST['sui'];
	$bill_id = $_POST['bill_id'];
	$date = $_POST['date'];
	$account_id = $_POST['account_id'];
	$payment_amount  = $_POST['payment_amount'];
	$confirmation_number = $_POST['confirmation_number'];
	$description = $_POST['description'];
		

	// run payment type
	if ($type == 'payment') {

        // if payment found
        if ($bill = Bill::find_by_id($bill_id)) {

			// adjust bill
	        $bill_due = $bill->due;
	        $payment = $payment_amount;
	        $bill_adjust = $bill_due - $payment;

	        // update bill due
	        $bill->due = $bill_adjust;

	        // if bill due is 0
			if ($bill->due == 0) {

				// set date to 0000-00-00
				$bill->close_date = date('Y-m-d');
				$bill->status = 0;

			}

			// if bill saved
			if ($bill->save()) {
			
				// insert payment record
				$payment = new Payment();
				$payment->account_id = $account_id;
				$payment->bill_id = $bill_id;
				$payment->user_id = $user_id;
				$payment->date = $date;
				$payment->payment_amount = $payment_amount;
				$payment->confirmation_number = $confirmation_number;
				$payment->description = $description;
				$payment->status = 1;

				if ($payment->save()) {

				    // get account name
			      	$account_name = Account::find_by_id($payment->account_id);

			      	// success message
				    $session->message("Payment for {$account_name->name} was saved.");
					
				}

			}else{

				// error message
				$session->message("Could not insert payment");

			}


		}else{

			// error message
			$session->message("Bill was not found");

		}

		// redirect back to bills
		redirect('index.php?view=bills');

	}else{

		// redirect back to bills
		redirect('index.php?view=bills');

	}

?>