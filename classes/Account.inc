<?php 


	class Account extends DB_object{

		// properties
		protected static $db_table = "accounts";
		protected static $db_table_fields = array('id', 'user_id', 'name', 'account_number', 'phone', 'address', 'city', 'state', 'zip', 'status', 'notes', 'auto_payment');
		public $id;
		public $user_id;
		public $name;
		public $account_number;
		public $phone;
		public $address;
		public $city;
		public $state;
		public $zip;
		public $status;
		public $notes;
		public $auto_payment;

		/**
		 * Find all accounts
		 * @param user_id for results
		 */
		public static function accounts_all($user_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "status = 1 AND user_id = {$user_id}";
			return $the_result_array = self::find_by_query($sql);
		}

		/**
		 * Find account by id
		 * @param account_id for results
		 */
		public static function account_find_by_id($account_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "id =  {$account_id}";
			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
			
		}


		/**
		 * delete all user accounts - for closing of account
		 * @param user_id
		 */
		public static function accounts_delete_all_user_accounts($userid){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$database->query($sql);
			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}


	}





 ?>