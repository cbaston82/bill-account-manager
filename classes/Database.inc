<?php 

	require_once('init.php');
	error_reporting(0);

	class Database{

		public $connection;

		/**
		 * Open up database connection automaticaly using __construct.
		 */
		function __construct(){
			$this->open_db_connection();

		}

		/**
		 * Create the database connenction.
		 */
		public function open_db_connection(){
			$this->connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
			if ($this->connection->connect_errno) {
				die("Database connection failed. " . $this->connection->connect_error);
			}
		}

		/**
		 * Query the database.
		 * @param SQL getting passed in
		 */
		public function query($sql){
			$result = $this->connection->query($sql);
			return $result;
		}

		/**
		 * Confirm the query being passed.
		 */
		private function confirm_query(){
			if (!$result) {
				die('Query failed.' . $this->connection->error);
			}
		}

		/**
		 * Escape all strings.
		 * @param we want to make the user inputs clean ans safe for DB.
		 */
		public function escape_string($string){
			$escaped_string = $this->connection->real_escape_string($string);
			return $escaped_string;
		}

		/**
		 * Return last ID
		 */
		public function the_insert_id(){
			return mysqli_insert_id($this->connection);
		}

	}

	// Instantiatte the DB
	$database = new Database();
?>