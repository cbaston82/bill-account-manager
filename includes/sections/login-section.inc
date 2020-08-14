<?php

if(isset($_COOKIE['username']))
{
	$username=$_COOKIE['username'];
	$password=$_COOKIE['password'];
}


 ?>
<div class="section" id="login-section">
    <div class="container">
        <div class="col-sm-4 col-sm-offset-4 well">
			<h4 class="bg-danger"><?php echo $the_message; ?></h4>
        	<form action="" method="post">

        		<div class="form-group">
        			<label for="username">Username</label>
        			<input type="text" class="form-control" name="username" value="<?php echo htmlentities($username); ?>" >

        		</div>

        		<div class="form-group">
        			<label for="password">Password</label>
        			<input type="password" class="form-control" name="password" value="<?php echo htmlentities($password); ?>">

        		</div>

            <div class="form-group">
                <label for="remember">Remember me</label>
                  <input type="checkbox" <?php echo (isset($_COOKIE['username'])) ? 'checked' : '' ?> name="remember">
              </div>

        		<div class="form-group">
        		<input type="submit" name="submit" value="Login" class="btn btn-primary btn-block">
        		</div>
        	</form>
            <p>Registration is disabled. Contact <a href="https://www.imaginedesigndevelop.com/" target="_blank">Contact me</a> if you would like to see a live demo.</p>
        	<!-- <p>Not yet a member? <a href="register.php">Register</a> for free.</p> -->
            <!-- <p><a href="reset.php">Forgot password</a></p> -->
        </div>
    </div>
</div>
