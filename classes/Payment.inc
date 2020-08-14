<?php 


	class Payment extends DB_object{

		// properties
		protected static $db_table = "payments";
		protected static $db_table_fields = array('id', 'user_id', 'account_id', 'bill_id', 'confirmation_number', 'date', 'payment_amount', 'description', 'status');
		public $id;
		public $user_id;
		public $account_id;
		public $bill_id;
		public $confirmation_number;
		public $date;
		public $payment_amount;
		public $description;
		public $status;


		/**
		 * Find all payments
		 * @param get all users payment by $user_id
		 */
		public static function payments_find_all($user_id, $order_by = ''){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = {$user_id} ";
			$sql .= "{$order_by}";
			$the_result_array = self::find_by_query($sql);

			return $the_result_array;
		}

		/**
		 * Find all payments by bill id
		 * @param for payment history, find all payments made b $bill_id
		 */
		public static function payments_find_all_by_id($bill_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "bill_id = $bill_id";
			$the_result_array = self::find_by_query($sql);

			return $the_result_array;
		}

		/**
		 * Find all payments by bill id
		 * @param find all payments related to account by $account_id
		 */
		public static function payments_find_all_by_account_id($account_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "account_id = $account_id";
			$the_result_array = self::find_by_query($sql);

			return $the_result_array;
		}

		/**
		 * Delete all payments by bill id.
		 * @param delete all payment history for bill, when bill deleted by $bill_id
		 */
		public static function payments_delete_all_by_bill_id($bill_id){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "bill_id = $bill_id";
			$database->query($sql);

			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}

		/**
		 * Find payment by id
		 * @param payment_id for results
		 */
		public static function payment_find_by_id($payment_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "id =  {$payment_id}";
			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
			
		}

		/**
		 * delete all user payments - for closing of account
		 * @param user_id
		 */
		public static function payments_delete_all_user_payments($userid){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$database->query($sql);
			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}

	}
?>