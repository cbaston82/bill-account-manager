<?php 
require_once('init.php');

$input = @file_get_contents("php://input");
$event_json = json_decode($input);

$reply = new stdClass();

echo $type_of_event = $event_json->type;
echo "<br>";
echo $plan = $event_json->data->object->lines->data[0]->plan->id;
echo "<br>";
echo $plan_expires = $event_json->data->object->lines->data[0]->period->end;
echo "<br>";
echo $stripe_customer_id = $event_json->data->object->customer;

// find user by customer id
$user = User::user_find_by_stripe_customer_id($stripe_customer_id);
// print_r($user);

if($type_of_event == "invoice.payment_succeeded"){
  try {
    $premium_active_until = $plan_expires + (1.5 * 24 * 60 * 60);
    $user->premium_active_until = $premium_active_until;
    $user->save();
  } catch (Exception $e) {}

  try{
    $log_payment = new UserPayment();
    $log_payment->stripe_customer_id = $stripe_customer_id;
    $log_payment->date = $unixTimeStamp;
    $log_payment->amount = 499;
    $log_payment->product = 'premium_plan';
    $log_payment->save();
  } catch(Exception $e){ }
}

http_response_code(200);

?>