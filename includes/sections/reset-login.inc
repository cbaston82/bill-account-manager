<div class="section" id="register-section">
      <div class="container">
            <div class="col-md-4 col-md-offset-4 well">
			<h4 class="bg-danger"><?php echo $the_message; ?></h4>
            	<form action="?reset_key=<?php echo $reset_key_check->reset_key; ?>" method="post">

            		<div class="form-group">
            			<label for="username">Username</label>
            			<input type="text" class="form-control" readonly name="username" value="<?php echo $reset_key_check->username; ?>" >
            		</div>

            		<div class="form-group">
            			<label for="password">New Password</label>
            			<input type="password" class="form-control" name="password" value="<?php echo htmlentities($password); ?>">
            		</div>

            		<div class="form-group">
            			<label for="password_confirm">Confirm Password</label>
            			<input type="password" class="form-control" name="password_confirm" value="<?php echo htmlentities($password_confirm); ?>">
            		</div>

            		<div class="form-group">
            		<input type="submit" name="submit" value="Reset Password" class="btn btn-primary btn-block">
            		</div>
            	</form>
            </div>  
      </div>
</div>   