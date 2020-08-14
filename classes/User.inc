<?php

	/**
	 * User class.
	 */
	class User extends DB_object{

		// properties
		protected static $db_table = "users";
		protected static $db_table_fields = array('email', 'username', 'password', 'first_name', 'last_name', 'address','city','state','zip','subscribed', 'confirmed', 'registration_key', 'reset_key', 'date_reset_key', 'date_registered', 'date_last_login', 'date_login', 'role', 'account_type', 'stripe_customer_id', 'stripe_customer_registered', 'stripe_customer_cancelled', 'premium_active_until');
		public $id;
		public $email;
		public $first_name;
		public $last_name;
		public $address;
		public $city;
		public $state;
		public $zip;
		public $subscribed;
		public $username;
		public $password;
		public $confirmed;
		public $registration_key;
		public $reset_key;
		public $date_reset_key;
		public $date_registered;
		public $date_last_login;
		public $date_login;
		public $role;
		public $account_type;
		public $stripe_customer_id;
		public $stripe_customer_registered;
		public $stripe_customer_cancelled;
		public $premium_active_until;

		/**
		 * Verify user is in db.
         * @param $username.
         * @param $password.
		 * @return returns true or false
		 */
		public static function user_verify($username, $password){
			global $database;
			$username =  $database->escape_string($username);
			$password =  $database->escape_string($password);
			$password = md5($password);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "username = '{$username}'";
			$sql .= "AND password = '{$password}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * Find user by email.
		 *	@param find user by $email.
		 * @return true or false
		 */
		public static function user_find_by_email($email){
			global $database;

			$email =  $database->escape_string($email);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "email = '{$email}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * Find user by stripe customer id.
		 *	@param find user by $stripe_customer_id.
		 * @return true or false
		 */
		public static function user_find_by_stripe_customer_id($stripe_customer_id){
			global $database;

			// $stripe_customer_id =  $database->escape_string($tripe_customer_id);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "stripe_customer_id = '{$stripe_customer_id}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * Find user by username.
		 *	@param find user by $username.
		 * @return trur or false
		 */
		public static function user_find_by_username($username){
			global $database;

			$username =  $database->escape_string($username);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "username = '{$username}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}


		/**
		 * Find registration key.
		 *	@param Find user by $key -> registration_key.
		 * @return true or false
		 */
		public static function user_find_by_register_key($key){
			global $database;

			$key =  $database->escape_string($key);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "registration_key = '{$key}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

        /**
         * Find all subcribed users
         * @param get all users payment by $user_id
		 * @return array
         */
        public static function users_subscribed_all(){
            global $database;
            $sql = "SELECT * FROM " . self::$db_table . " WHERE ";
            $sql .= "subscribed = 1 ";
            $the_result_array = self::find_by_query($sql);
            return $the_result_array;
        }


        /**
		 * Find reset key.
		 *	@param Find user by $reset_key.
		 * @return true or faslse
		 */
		public static function user_find_by_reset_key($key){
			global $database;

			$key =  $database->escape_string($key);

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "reset_key = '{$key}'";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * Find user by id.
		 *	@param Find user by $id.
		 * @return true or false
		 */
		public static function user_find_by_id($id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "id = '{$id}' ";
			$sql .= "LIMIT 1";

			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * Find all users with reset key older than 2 days.
		 *	@param Find user by $id.
		 * @return
		 */
		public static function users_with_reset_key(){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "reset_key != '' ";

			return $the_result_array = self::find_by_query($sql);
		}

	} //End of User class.


?>
