<?php 

	require_once('init.php');


	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}

	// trim and clean user inputs
	if (isset($_GET['key'])) {
		$key = trim($_GET['key']);

		// check key against DB
		$user = User::user_find_by_register_key($key);

		// find key in db
		if ($user) {
			$check = true;
			$user->confirmed = 'yes';
			$user->save();
		}else{
			$check = false;
		}
			
	}else{
		redirect("login.php");
	}


?>

<?php include("includes/layouts/head.inc") ?>
	<section>
		<div class="container">
			<div class="col-md-12">

		<?php if ($check): ?>	
	    	<div class="page-header"><h1>Thank you <small>your account is now activated.</small></h1></div>
	    	<p>We hope you enjoy using BAM. This application is in its BETA stages and is still currently under development. While under development we encourage you to give us your feedback on it. As it stands right now you may use it for free.</p>
	    	<p>Thank you and enjoy!!!</p>
	    	<p>Feel free to <a href="login.php">Login</a> and start using BAM for free.</p>
		<?php endif ?>

		<?php if (!$check): ?>
			<div class="page-header"><h1>Sorry <small>that activation key was not valid.</small></h1></div>
	    	<p>Most likely the registration key given has expired if you did not validate your email within a week of your registration.</p>
	    	<p>That's a simple solution just <a href="login.php">register</a> and check your email right after to validate your email.</p>
	    	<p>Thank you and sorry for the inconvenience.</p>
		<?php endif ?>
	</div>      
		</div>
	</section>
<?php include("includes/layouts/footer.inc") ?>





