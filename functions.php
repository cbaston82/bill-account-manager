<?php 

	// autoload classes
	function classAutoLoader($class){
		$class = ucfirst($class);
		$the_path = "classes/{$class}.inc";
		if (file_exists($the_path)) {
			require_once($the_path);
		}else{
			die("This file name {$class}.php was not found!!");
		}
	}
	spl_autoload_register('classAutoLoader');

	// redirect
	function redirect($location){
		header("Location: {$location}");
	}

	function the_date($date){
		$date = strtotime($date);
		$date = date('M d, Y', $date);
		return $date;
	}

	function formatPhone($phone){
		$unformattedPhone = $phone;
		$phone = preg_replace("/[^0-9]/", "", $phone);
		

		if(strlen($phone) == 7)
			return preg_replace("/([0-9]{3})([0-9]{4})/", "$1-$2", $phone);
		elseif(strlen($phone) == 10)
			return preg_replace("/([0-9]{3})([0-9]{3})([0-9]{4})/", "($1) $2-$3", $phone);
		elseif(strlen($phone) == 11 && substr($phone, 0, 1) != '1')
			return preg_replace("/([0-9]{3})([0-9]{4})([0-9]{4})/", "$1-$2 ext. $3", $phone);
		elseif(strlen($phone) == 11 && substr($phone, 0, 1) == '1')
			return preg_replace("/([0-9]{1})([0-9]{3})([0-9]{3})([0-9]{4})/", "($2) $3-$4", $phone);	
		elseif(strlen($phone) == 14)
			return preg_replace("/([0-9]{3})([0-9]{3})([0-9]{4})([0-9]{4})/", "($1) $2-$3 ext. $4", $phone);	
		else
			return $unformattedPhone;
	}

	function currency($var){
		return number_format((float)$var, 2, '.', '');
	}
?>