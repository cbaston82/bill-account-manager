<?php 
	
	include('init.php');

	// get users with reset_key
	$users_with_reset_key = User::users_with_reset_key();

	// if reset key older than 2 days delete
	foreach ($users_with_reset_key as $u) {
		if (($u->date_reset_key != "") && (strtotime($u->date_reset_key) < strtotime('-2 days'))) {
			$u->reset_key = NULL;
			$u->date_reset_key = NULL;
			$u->save();
		}
	}

?>