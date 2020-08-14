<?php
require('init.php');

// create params 
$id = $_POST['id'];
$view = $_POST['view'];

$reply = new stdClass();

$string = '';
$total_payed = 0;

if($view == 'accounts'){
	$payments = Payment::payments_find_all_by_account_id($id);
	$account = Account::find_by_id($id);
	$title =  $account->name;

	foreach ($payments as $payment){
       $string .= '<tr>
         <td>' .$payment->date.'</td>
         <td>&#x24; '.$payment->payment_amount.'</td>
         <td>'.$payment->confirmation_number.'</td>
         <td>'.$payment->description.'</td>
       </tr>';   
       $total_payed += $payment->payment_amount; 
	} 
}

if($view == 'bills'){

	$payments = Payment::payments_find_all_by_id($id);
	$bill = Bill::find_by_id($id);

	// get account name
    $account_name = Account::find_by_id($bill->account_id);
    $title = $account_name->name;

	foreach ($payments as $payment){
       $string .= '<tr>
         <td>' .$payment->date.'</td>
         <td>&#x24; '.currency($payment->payment_amount).'</td>
         <td>'.$payment->confirmation_number.'</td>
         <td>'.$payment->description.'</td>
       </tr>';    
       $total_payed += $payment->payment_amount;
	} 
	
}


$reply->id = $id;
$reply->string = $string;
$reply->title = $title;
$reply->data = $payments;
$reply->total_payed = currency($total_payed);

print json_encode($reply);

 ?>