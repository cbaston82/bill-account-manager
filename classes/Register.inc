<?php


	class Register extends DB_object{

		// properties
		public $email;
		public $username;
		public $password;

		/**
		 * Register new user.
		 *@param user info to insert into DB
		 */
		public static function register_user($email, $username, $password){
			global $database;
			$email = $database->escape_string($email);
			$username = $database->escape_string($username);
			$password = $database->escape_string($password);
			$password = md5($password);

			// generate registration key unique to user
			$registration_key = self::register_user_key(64);

			// save user details to DB
			$new_user = new User();
			$new_user->email = $email;
			$new_user->username = $username;
			$new_user->password = $password;
            $new_user->confirmed = 'no';
            $new_user->account_type = 'free';
            $new_user->role = 'user';
            $new_user->subscribed = 1;
			$new_user->registration_key = $registration_key;
			$new_user->date_registered = date('Y-m-d');
			$new_user->premium_active_until = NULL;
			$new_user->stripe_customer_registered = NULL;
			$new_user->stripe_customer_cancelled = NULL;
			$new_user->stripe_customer_id = NULL;
			$new_user->save();

			$userNotifications_set = new Notification();
			$userNotifications_set->user_id = $new_user->id;
			$userNotifications_set->late_bills = 1;
			$userNotifications_set->save();

			// send user email confirmation
			$send_email = self::register_user_email($email, $registration_key);
		}

		/**
		 * Email new user.
		 *@param user info to insert into DB
		 */
		public static function register_user_email($email, $key){
			global $database;
			$to = $email;
			$subject = "BAM - Action Required";
			$message = "<img src='http://billaccountmanager.com/img/bam_email_header.jpg' />
			        <p>&nbsp;</p>
			        <p>Hello {$email},</p>
			        <p>Thank you for registering with BAM, please click on the link below to confirm your email.</p>
			        <p><a href='http://billaccountmanager.com/validate_email.php?key={$key}'>http://billaccountmanager.com/validate_email.php?key={$key}</a></p>
			        <p>Thank you from Bill Account Manger</p>";
			$headers  = "From: Bill Account Manger <no-reply@billaccountmanager.com>" . "\r\n";
			$headers .= "MIME-Version: 1.0\r\n";
			$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";

			if (!mail($to, $subject, $message, $headers, '-fbillaccountmanager')) {

			}
		}

		/**
		 * Generate registration key 64 chars
		 *@param The number of characters you want the sting to be
		 * @return returns a random string set to the number of characters you apply to $slength
		 */
		public static function register_user_key($length){
	   		$charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	   		$str = '';
	   		$count = strlen($charset);
	   	 	while ($length--) {
	        	$str .= $charset[mt_rand(0, $count-1)];
	    	}
	   		return $str;
		}

		/**
		 * Reset user.
		 *@param user info to insert into DB
		 */
		public static function reset_user_info($email){
			global $database;
			$email = $database->escape_string($email);

			// generate registration key unique to user
			$reset_key = self::register_user_key(64);

			// save user details to DB
			$user_found_by_email = User::user_find_by_email($email);
			$user_found_by_email->date_reset_key = date('Y-m-d');
			$user_found_by_email->reset_key = $reset_key;
			$user_found_by_email->save();

			// send user email confirmation
			$send_email = self::reset_login_email($email, $reset_key);
		}


		/**
		 * Email user reset.
		 *@param $email to reset $key to send
		 */
		public static function reset_login_email($email, $reset_key){
			global $database;

			$to = $email;
			$subject = "BAM - Password Reset";
			$message = "<img src='http://billaccountmanager.com/img/bam_email_header.jpg' />
			        <p>&nbsp;</p>
			        <p>Hello {$email},</p>
			        <p>A request to reset your password was made. If you did not request to reset your password no action is required.</p>
			        <p>To reset your password please click on the link below.</p>
			        <p><a href='http://billaccountmanager.com/reset_login.php?reset_key={$reset_key}'>http://billaccountmanager.com/reset_login.php?reset_key={$reset_key}</a></p>
			        <p>Thank you from Bill Account Manger</p>";
			$headers  = "From: Bill Account Manger <no-reply@billaccountmanager.com>" . "\r\n";
			$headers .= "MIME-Version: 1.0\r\n";
			$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";

			if (!mail($to, $subject, $message, $headers, '-fbillaccountmanager')) {

			}
		}
	}