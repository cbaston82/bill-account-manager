<?php
require('init.php');

$all_notifications_uses = Notification::notifactions_all();

$users_to_notify = array();

foreach ($all_notifications_uses as $notify) {
    if (($notify->late_bills == 0 || $notify->late_bills == null) && ($notify->upcoming_bills == 0 || $notify->upcoming_bills == null)) {
        $notify->delete();
    } else {
        $user_to_notify = User::find_by_id($notify->user_id);

        if ($notify->late_bills == 1) {

            //user info
            $users_to_notify[$notify->user_id][user_info][email] = $user_to_notify->email;
            $users_to_notify[$notify->user_id][user_info][name] = $user_to_notify->first_name . ' ' . $user_to_notify->last_name;

            $user_late_bills = Bill::bills_all_active_late($notify->user_id);
            foreach ($user_late_bills as $late_bill) {

                $late_bill_account_info = Account::find_by_id($late_bill->account_id);

                //bill info
                $users_to_notify[$notify->user_id][late_bills][$late_bill->id][account] = $late_bill_account_info->name;
                $users_to_notify[$notify->user_id][late_bills][$late_bill->id][due_date] = the_date($late_bill->due_date);
                $users_to_notify[$notify->user_id][late_bills][$late_bill->id][due] = '$' . currency($late_bill->due);

            }

        }
    }
}

// If you are using Composer (recommended)
require 'vendor/autoload.php';

foreach ($users_to_notify as $notify_user) {
    if($notify_user[user_info][email] != "" && isset($notify_user[late_bills])) {

        $bills_list = "";

        // echo "<pre>";
        // print_r($notify_user);
        // echo "</pre>";
        $sentFrom = 'noreply@billaccountmanager.com';
        $sendTo = $notify_user[user_info][email];
        $subject = "Bill Notifications";
        $username = $notify_user[user_info][name];
        $useremail = $notify_user[user_info][email];

        $from = new SendGrid\Email(null, $sentFrom);
        $to = new SendGrid\Email(null, $sendTo);

        // count bills
        $billsCount = (count($notify_user[late_bills]) > 1) ? "bills" : "bill";

        foreach ($notify_user[late_bills] as $late_bill) {
            $bills_list .= "<li>$late_bill[account] was due on $late_bill[due_date] for the amount of $late_bill[due]</li>";
        }


        $content = new SendGrid\Content(
            "text/html",
            "<p>Hello $useremail,</p>
            <br>
            
            <p>You have <strong>" . count($notify_user[late_bills]) . "</strong> past due " . $billsCount . ".</p>
            <br>
            <p><strong>Your past due bills:</strong></p>
            <ul>" .
            $bills_list
            . "</ul>
            <br>
            <br>
            <p>You opted to be notified upon any late bills. To change your notifications please visit your account settings <a href='https://billaccountmanager.com/index.php?view=account'>here<a>.</p>
            "
        );

        echo $sendTo;
        echo $bills_list;
        echo "<br>";
        $mail = new SendGrid\Mail($from, $subject, $to, $content);

        $apiKey = $stripeKey;
        $sg = new \SendGrid($apiKey);

        $response = $sg->client->mail()->send()->post($mail);
    }
}



