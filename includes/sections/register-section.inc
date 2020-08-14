<div class="section" id="register-section">
      <div class="container">
            <div class="col-md-4 col-md-offset-4 well">
				<h4 class="bg-danger"><?php echo $the_message; ?></h4>
            	<form action="" method="post">

            		<div class="form-group">
            			<label for="email">Email</label>
            			<input type="text" class="form-control" name="email" value="<?php echo htmlentities($email); ?>" >

            		</div>

            		<div class="form-group">
            			<label for="username">Username</label>
            			<input type="text" class="form-control" name="username" value="<?php echo htmlentities($username); ?>" >

            		</div>

            		<div class="form-group">
            			<label for="password">Password</label>
            			<input type="password" class="form-control" name="password" value="<?php echo htmlentities($password); ?>">

            		</div>

            		<div class="form-group">
            			<label for="password_confirm">Confirm Password</label>
            			<input type="password" class="form-control" name="password_confirm" value="<?php echo htmlentities($password_confirm); ?>">

            		</div>

            		<div class="form-group">
            		<input type="submit" name="submit" value="Register" class="btn btn-primary btn-block">
            		</div>
            	</form>
                  <p>Already have an account? <a href="login.php">Login.</a></p>
            </div>
      </div>
</div>
