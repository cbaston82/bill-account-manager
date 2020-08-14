<?php

	class Note extends DB_object{

		// properties
		protected static $db_table = "notes";
		protected static $db_table_fields = array('id', 'user_id', 'note_title', 'note_body');
		public $id;
		public $user_id;
		public $note_title;
		public $note_body;

		/**
		 * Get all notes
		 * @param int - user id.
		 */
		public static function notes_all($user_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = {$user_id}";
			return $the_result_array = self::find_by_query($sql);
		}

		/**
		 * Find bill by id
		 * @param int - note id.
		 */
		public static function note_find_by_id($note_id){
			global $database;

			$sql = "SELECT * FROM " . self::$db_table . " WHERE ";
			$sql .= "id =  {$note_id}";
			$the_result_array = self::find_by_query($sql);
			return !empty($the_result_array) ? array_shift($the_result_array) : false;
		}

		/**
		 * delete all user nots - for closing of account
		 * @param user_id
		 */
		public static function notes_delete_all_user_notes($userid){
			global $database;

			$sql = "DELETE FROM " . self::$db_table . " WHERE ";
			$sql .= "user_id = $userid";
			$database->query($sql);
			return (mysqli_affected_rows($database->connection) == 1)? true : false;
		}

	}
 ?>
