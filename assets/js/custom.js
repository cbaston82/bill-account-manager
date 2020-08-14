$(document).ready(function(){

var dataTable1 = $('.bam-table1');
if (dataTable1.length) {
  // var height = $(window).height() - $('.bam-table1').offset().top - 130; 
}

	// kill session message
	$('#alertClose').on('close.bs.alert', function () {
		$.post("killAlertSession.php");
	});

	window.onbeforeunload = function() {
    	$.post("killAlertSession.php");
	}

	// kill session message
	$('#late_bills_alert').on('close.bs.alert', function () {
		$.post("acknowledge_late_bill.php");
	});

   // datepicker
   $('.pickDate').datepicker({dateFormat: "yy-mm-dd"});

   // masked inputs
   $("#phone").mask("(999)999-9999");
   $("#cc-number").mask("9999 9999 9999 9999");

   // onclick events
   $('input[type="checkbox"]#otherAccountInfo').click(function(){
      if($('#otherAccountInfo').prop('checked')) {
        $("#AccountInfo").slideDown();  // checked
        console.log('show');
      } else {
        $("#AccountInfo").slideUp();  // unchecked
        console.log('hide');
      }
    });

})
