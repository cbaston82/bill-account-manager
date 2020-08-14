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
    			<div class="page-header"><h1>Thank you <small>we received your password reset request.</small></h1></div>
    			<p>An email was sent to you, please click on the link provided to reset your password.</p>
    		</div>     
    	</div>
    </section> 
<?php include("includes/layouts/footer.inc") ?>





