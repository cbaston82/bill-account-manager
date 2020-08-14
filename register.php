<?php 

	require_once('init.php');


	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}

	// trim and clean user inputs
	if (isset($_POST['submit'])) {
		$email = trim($_POST['email']);
		$username = trim($_POST['username']);
		$password = trim($_POST['password']);
		$password_confirm = trim($_POST['password_confirm']);

		// check email against DB
		$email_check = User::user_find_by_email($email);

		// check username
		$username_check = User::user_find_by_username($username);
		
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
		}elseif ($email_check) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>That email is already registered!!!</p>
							</div>";
		}elseif ($username_check) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>That Username is already taken!!!</p>
							</div>";
		}elseif ($username == "") {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>Username cannot be empty!!!</p>
							</div>";
		}elseif (strlen($username) <= 3) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>Username must be 4 characters or greater!!!</p>
							</div>";
		}elseif ($password == "") {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>Password cannot be empty!!!</p>
							</div>";
		}elseif ($password !== $password_confirm) {
			$the_message = "<div class='alert alert-danger'>
							    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
							    <p>Passwords do not match!!!</p>
							</div>";
		}else{
			// register new user
			$register_user = Register::register_user($email, $username, $password);
			if (!$register_user) {
				$the_message = "<div class='alert alert-danger'>
								    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
								    <p>We could not register you at the moment. Please try agin later!!!</p>
								</div>";
			}
				redirect("thank_you.php");
		}


	}else{
		$the_message = "";
		$email = "";
		$username = "";
		$password  = "";
	}
?>

<?php include("includes/layouts/head.inc") ?>

	<!-- login/register.css -->
	<link rel="stylesheet" href="assets/css/login-register.css">

	<?php include("includes/sections/register-section.inc") ?> 
<?php include("includes/layouts/footer.inc") ?>





