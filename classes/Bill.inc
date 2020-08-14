<?php 


	class Bill extends DB_object{

		// properties
		protected static $db_table = "bills";
		protected static $db_table_fields = array('id', 'user_id', 'account_id', 'due_date', 'close_date', 'amount', 'due', 'description', 'status');
		public $id;
		public $user_id;
		public $account_id;
		public $due_date;
		public $close_date;
		public $amount;
		public $due;
		public $description;
		public $status;

		/**
		 * Get all ative bills
		 * @param get users active bills all.
		 */
		public static function bills_all_active($user_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "status = 1 AND user_id = {$user_id}";
			return $the_result_array = self::find_by_query($sql);
		}

		/**
		 * Get all ative bills
		 * @param get users active bills all.
		 */
		public static function bills_all_inactive($user_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "status = 0 AND user_id = {$user_id}";
			return $the_result_array = self::find_by_query($sql);
		}

		/**
		 * Gather all current bills $total.
		 * @param spedific to user logged in.
		 */
		public static function bills_all_active_total($status, $column, $user_id){
			global $database;

			$bills = self::bills_all_active($user_id);
			$total = "";

			foreach ($bills as $bill) {
				$total += $bill->$column;
			}
			return $total;
		}

		/**
		 * Gather all current late bills.
		 * @param spedific to user logged in.
		 */
		public static function bills_all_active_late($user_id){
			global $database;

			$bills = self::bills_all_active($user_id);
			$total = "";

			$late_bills_array = array();
			foreach ($bills as $bill) {
			 	if (!self::bill_check_if_late($bill->due_date)) {
					$late_bills_array[] = $bill;
				}
			 } 
			return $late_bills_array;
		}

        /**
         * Gather all late bills for all users.
         */
        public static function bills_all_late(){
            global $database;

            $sql = "SELECT * FROM " . self::$db_table . " WHERE ";
            $sql .= "status = 1";
            return $the_result_array = self::find_by_query($sql);

            $late_bills_array = array();
            foreach ($bills as $bill) {
                if (!self::bill_check_if_late($bill->due_date)) {
                    $late_bills_array[] = $bill;
                }
            }
            return $late_bills_array;
        }

		/**
		 * Gather all current late bills $total.
		 * @param spedific to user logged in.
		 */
		public static function bills_all_active_late_total($user_id){
			$late_bills = static::bills_all_active_late($user_id);

			$bills_late_total = "";
			foreach ($late_bills as $late_bill) {
				$bills_late_total += $late_bill->due;
			}
			return $bills_late_total;
		}

		/**
		 * Mark bill Inactive.
		 * @param the id of the bill marking inactive.
		 */
		public static function bill_mark_inactive($id){
			$bill = self::find_by_id($id);
			if ($bill) {
				if ($bill->due <= 0) {
					$bill->close_date = date('Y-m-d');
					$bill->status = 0;
					$bill->save();
				}elseif ($bill->due > 0) {
					$bill->close_date = NULL;
					$bill->status = 1;
					$bill->save();
				}
				return true;
			}else{
				return false;
			}
		}

		/**
		 * Determine whether bill is late or not.
		 * @param check $date against current date to determin if late or not
		 */
		public static function bill_check_if_late($date){
			 $now = strtotime('today midnight');
            if (strtotime($date) >= $now) {
                    return true;
                } else {
                   return false;
                }
		}

		/**
		 * Find bill by id
		 * @param bill_id for results
		 */
		public static function bill_find_by_id($bill_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "id =  {$bill_id}";
			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * get bill totals
		 * @param user_id
		 */
		public static function bills_grand_totals($userid){
			global $database;

			$sql = "SELECT SUM(amount) AS amount, account_id FROM " . self::$db_table . " WHERE ";
			$sql .= "status = 0 AND user_id = $userid GROUP BY account_id";
			$the_result_array = self::find_by_query($sql);
			return $the_result_array = self::find_by_query($sql);
		}

		/**
		 * get * bills active or inactive
		 * @param user_id
		 */
		public static function bills_all($userid){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$the_result_array = self::find_by_query($sql);
			return $the_result_array = self::find_by_query($sql);
		}


		/**
		 * delete all user bills - for closing of account
		 * @param user_id
		 */
		public static function bills_delete_all_user_bills($userid){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$database->query($sql);
			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}

	}
 ?>