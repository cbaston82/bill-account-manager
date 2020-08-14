<?php



	/**
	 * Session class.
	 */
	class Session{

		// properties
		private $signed_in = false;
		public $user_id;
		public $user_role;
		public $email;
		public $message;

		/**
		 * Turn on sessions automaticaly
		 */
		function __construct(){
			ob_start();
			session_start();
			$this->check_the_login();
			$this->check_message();
		}

		/**
		 * Create Session
		 */
		public function message($msg = ""){
			if (!empty($msg)) {
				$_SESSION['message'] = $msg;
			}else{
				return $this->message;
			}
		}

		/**
		 * Check the message
		 */
		private function check_message(){
			if (isset($_SESSION['message'])) {
				$this->message = $_SESSION['message'];
				// unset($_SESSION['message']);
			}else{
				$this->message = "";
			}
		}

		/**
		 * Check if user signed in.
		 */
		public function is_signed_in(){
			return $this->signed_in;
		}

		/**
		 * Login user.
		 * @param user being logged in $user.
		 */
		public function login($user){
			if ($user) {
				$this->user_id = $_SESSION['user_id'] = $user->id;
				$this->user_role = $_SESSION['user_role'] = $user->role;
				$this->account_type = $_SESSION['account_type'] = $user->account_type;
				$this->email = $_SESSION['email'] = $user->email;
				$this->signed_in = true;
			}
		}

		/**
		 * Logout User.
		 */
		public function logout(){
			unset($_SESSION['user_id']);
			unset($this->user_id);
			unset($_SESSION['user_role']);
			unset($this->user_role);
			unset($_SESSION['account_type']);
			unset($this->account_type);
			unset($_SESSION['email']);
			unset($this->email);
			$this->signed_in = false;
		}

		/**
		 * Check user login status.
		 */
		private function check_the_login(){
			if (isset($_SESSION['user_id'])) {
				$this->user_id = $_SESSION['user_id'];
				$this->signed_in = true;
			}else{
				unset($this->user_id);
				$this->signed_in = false;
			}
		}

	}

	// start session
	$session = new Session();
 ?>
