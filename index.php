<?php

 	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('welcome.php'); }

	// check page request for any page under index
	$page_view = (isset($_GET['view'])) ? $_GET['view'] : 'home';

?>

<!-- include header. -->
<?php include("includes/layouts/head.inc") ?>

	<!-- bam css -->
	<link rel="stylesheet" href="assets/css/bam.css">

  	<!-- bam section -->
  	<?php include("includes/sections/bam-section.inc") ?>

  	<!-- makePaymentModal -->
	<?php include("modals/newBillModal.inc") ?>
	<!-- newNoteModal -->
	<?php include("modals/newNoteModal.inc") ?>
	<!-- editBillModal -->
	<?php include("modals/newAccountModal.inc") ?>

<!-- include footer. -->
<?php include("includes/layouts/footer.inc") ?>
