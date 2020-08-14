<?php

	require_once('init.php');

	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}

	// trim and clean user inputs
	if (isset($_POST['submit'])) {
		$username = trim($_POST['username']);
		$password = trim($_POST['password']);

		// verify user is in db
		$user_found = User::user_verify($username, $password);

		// find user in db
		if ($user_found) {
			if ($user_found->confirmed == "yes") {
				$session->login($user_found);
				$user_found->date_last_login = date('Y-m-d', strtotime($user_found->date_login));
				$user_found->date_login = date("Y-m-d");
				$user_found->save();

				if(isset($_POST['remember'])){
					setcookie("username", $username, time()+60*60*24*100, "/");
					setcookie("password", $password, time()+60*60*24*100, "/");
				}elseif(!isset($_POST['remember'])){
					setcookie("username", "", time()-(60*60*24), "/");
    			setcookie("password", "", time()-(60*60*24), "/");
				}

				redirect("index.php?view=home");
			}else{
				$the_message = "<div class='alert alert-danger'>
								    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
								    <p><i class='fa fa-exclamation-circle'></i> Your email has not yet been validated. Click on the link we emailed you to validate your email address.</p>
								</div>";
			}
		}else{
			$the_message = "<div class='alert alert-danger'>
								    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
								    <p><i class='fa fa-exclamation-circle'></i> That username or password is incorrect.</p>
								</div>";
		}
	}else{
		$the_message = "";
		$username = "";
		$password  = "";
	}
?>

<?php include("includes/layouts/head.inc") ?>

	<!-- login/register.css -->
	<link rel="stylesheet" href="assets/css/login-register.css">

	<?php include("includes/sections/login-section.inc") ?>
<?php include("includes/layouts/footer.inc") ?>
