<?php
	require('init.php');
    // find user_error()
    $user = User::user_find_by_id($_SESSION['user_id']);

	$user_bills = Bill::bills_all_active($_SESSION['user_id']);
	$bills = new stdClass();
	$bills->user_bills = $user_bills;

?>

<script>
	var bills = <?php echo json_encode($user_bills) ?>
</script>

<?php
	
	print json_encode($user_bills);

 ?>