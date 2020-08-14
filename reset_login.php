<?php 

	require_once('init.php');


	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}

	// check email against DB
	$reset_key_check = User::user_find_by_reset_key($_GET['reset_key']);

	if ($reset_key_check) {
		
		// trim and clean user inputs
		if (isset($_POST['submit'])) {
			$username = trim($_POST['username']);
			$password = trim($_POST['password']);
			$password_confirm = trim($_POST['password_confirm']);
			
			if ($password == "") {
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
				// finally reset password
				$reset_key = $_GET['reset_key'];
				$reset_user_password = User::user_find_by_reset_key($reset_key);
				if (!$reset_user_password) {
					$the_message = "<div class='alert alert-danger'>
									    <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
									    <p>We could not reset your password. Please try agin later!!!</p>
									</div>";
				}else{
					$password = md5($password);
					$reset_user_password->password = $password;
					$reset_user_password->reset_key = "";
					$reset_user_password->date_reset_key = NULL;
					$reset_user_password->save();
					redirect("/login.php");
				}
				
			}


		}else{
			$the_message = "";
			$email = "";
			$username = "";
			$password  = "";
		}

	}else{
		redirect("/welcome.php");
	}

	

?>

<?php include("includes/layouts/head.inc") ?>

	<!-- login/register.css -->
	<link rel="stylesheet" href="assets/css/login-register.css">

	<?php include("includes/sections/reset-login.inc") ?> 
<?php include("includes/layouts/footer.inc") ?>





