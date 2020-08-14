<?php 

	require_once('init.php');


	// see if user signed in
	if ($session->is_signed_in()) {
		redirect('index.php');
	}
	
?>

<?php include("includes/layouts/head.inc") ?>
    <section>
    	<div class="container">
    		<div class="col-md-12">
    			<div class="page-header"><h1>Thank you <small>for registering.</small></h1></div>
    			<p>An email was sent to you, please make sure to confirm your email by clicking on in the body of the email. If you do not see the email dont forget to check your spam box.</p>
    			<p>Once you have confirmed your email you may <a href="login.php">Sig in</a> and start using BAM for free.</p>
    		</div>     
    	</div>
    </section> 
<?php include("includes/layouts/footer.inc") ?>





