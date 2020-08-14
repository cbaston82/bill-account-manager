<?php 

	require_once('init.php');


	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}

	// trim and clean user inputs
	if (isset($_POST['submit'])) {
		$email = trim($_POST['email']);

		// start validation
		if (strlen($email) < 1) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>Please provide a valid email!!</p>
							</div>";
		}elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>That is not a valid email!!</p>
							</div>";
		}else{

			// find email
			$user_find_by_email = User::user_find_by_email($email);

			if (!$user_find_by_email) {
				$the_message = "<div class='alert alert-danger'>
								    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
								    <p>We did not find that email in our system. Please check the email!!</p>
								</div>";
			}else{
				$reset_user_info = Register::reset_user_info($user_find_by_email->email);
				redirect("reset_request.php");
			}

		}

	}else{
		$the_message = "";
		$email = "";
	}
?>

<?php include("includes/layouts/head.inc") ?>

	<!-- login/register.css -->
	<link rel="stylesheet" href="assets/css/login-register.css">

	<?php include("includes/sections/reset-section.inc") ?> 
<?php include("includes/layouts/footer.inc") ?>





