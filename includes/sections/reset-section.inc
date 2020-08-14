<div class="section" id="login-section">
    <div class="container">
        <div class="col-sm-4 col-sm-offset-4 well">
			<h4 class="bg-danger"><?php echo $the_message; ?></h4>
        	<form action="" method="post">
        		
        		<div class="form-group">
                    <label for="email">Email</label>
                    <input type="text" class="form-control" name="email" placeholder="Email Address" value="<?php echo htmlentities($email); ?>" >
                </div>

        		<div class="form-group">
        		<input type="submit" name="submit" value="Reset password" class="btn btn-primary btn-block">
        		</div>
        	</form>
            <p class="text-danger">You will receive an email to confirm your password reset.</p>
        </div>      
    </div>
</div>