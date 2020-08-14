<?php

	class Notification extends DB_object{

		// properties
		protected static $db_table = "notifications";
		protected static $db_table_fields = array('id', 'user_id', 'late_bills', 'upcoming_bills');
		public $id;
		public $user_id;
        public $late_bills;
        public $upcoming_bills;

		/**
		 * Get user notification settings
		 * @param int - user id.
		 * @return array
		 */
		public static function notifactions_for_users($user_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = {$user_id}";
            $the_result_array = self::find_by_query($sql);
            return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

        /**
         * Get all notification settings
         * @param int - user id.
         * @return array
         */
        public static function notifactions_all(){
            global $database;

            $sql = "SELECT * FROM " . self::$db_table;
            $the_result_array = self::find_by_query($sql);
            return $the_result_array;
        }

        /**
		 * delete all user notifactions - for closing of account
		 * @param user_id
		 */
		public static function delete_all_user_notifications($userid){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$database->query($sql);
			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}

	}

