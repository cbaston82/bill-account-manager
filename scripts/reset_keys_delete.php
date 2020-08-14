<?php 
	
	include('init.php');

	$users_with_reset_key = User::users_with_reset_key();

	foreach ($users_with_reset_key as $u) {
		echo $u->reset_key;
	}



?>