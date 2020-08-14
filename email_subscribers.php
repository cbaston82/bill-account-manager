<?php
require('init.php');

$all_subscribed_users = User::users_subscribed_all();

echo "<pre>";
print_r($all_subscribed_users);

// If you are using Composer (recommended)
require 'vendor/autoload.php';

foreach ($all_subscribed_users as $subscribed) {
    $sentFrom = 'noreply@billaccountmanager.com';
    $sendTo = $subscribed->email;
    $subject = "Here is what's new to Bill Account Manager";
    $username = $subscribed->email;

    $from = new SendGrid\Email(null, $sentFrom);
    $to = new SendGrid\Email(null, $sendTo);

    $content = new SendGrid\Content(
        "text/html",
        "<img src='http://billaccountmanager.com/img/bam_email_header.jpg' />
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>Hello ".$username.",</p>
        <p>&nbsp;</p>
        <p>Here is what is new to Bill Account Manager.  First of all, we are happy to say that your information is safer that ever as we are now using a <a href='https://www.sslshopper.com/why-ssl-the-purpose-of-using-ssl-certificates.html'>Secure Socket Layer (SSL)</a>. Second, You can now upgrade to a premium account for FREE to take advantage of the following new premium features to BAM.</p>
        <p>&nbsp;</p>
        <p><span style=\"color:red;\">**Note**</span>  You can upgrade to our premium membership for free at the moment with no charge EVER. If ever there is a premium charge you will be grandfathered in for life as a premium user.</p>
        
        <h4>Here is what is new.</h4>
        
        <ul>
            <li><strong>Calculator (Premium Accounts Only) -</strong> You now have the ability to calculate your bills on the fly by clicking on the calculator next to the bill amount.</li>
            <li><strong>Notes (Premium Accounts Only) -</strong> By upgrading you will see a notes section where you can create as many notes as you please to stay more organized. You can quickly calculate your bills and turn them into notes from your bills page when clicking on the calculator next to the bill.</li>
            <li><strong>Account Page (All Account Types) -</strong> You have an account page now where you can update your personal information.</li>
            <li><strong>Notifications (All Account Types) -</strong> We are building a robust notification system where you can set choose what to be notified on. At the moment there is one option to receive an email upon any late bills. More options are in the works.</li>
        </ul>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>You are receiving this email because you are subscribed to receive them. If you want to opt out of receiving theses emails simply un-subscribe from within your
            <a href='https://billaccountmanager.com/index.php?view=account'>account</a>. </p>

"
    );
    $mail = new SendGrid\Mail($from, $subject, $to, $content);

    $apiKey = "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";
    $sg = new \SendGrid($apiKey);

    $response = $sg->client->mail()->send()->post($mail);
}














