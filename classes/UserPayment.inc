<?php 


	class UserPayment extends DB_object{

		// properties
		protected static $db_table = "user_payments";
		protected static $db_table_fields = array('id', 'stripe_customer_id', 'date', 'amount', 'product');
		public $id;
		public $stripe_customer_id;
		public $date;
		public $amount;
		public $product;
	}
 ?>