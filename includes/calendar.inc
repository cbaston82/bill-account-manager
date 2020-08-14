<?php
  // check if user is has a premium account
  if ($user->premium_active_until < $unixTimeStamp){ redirect('index.php?view=home'); }

    $user = User::user_find_by_id($_SESSION['user_id']);

	$user_bills = $database->query("SELECT  concat('$',b.amount,' ',acc.name, ' - ',  b.description) as title, b.due_date AS start, b.status, b.close_date, b.due_date, b.id
										FROM bills b
										LEFT JOIN accounts acc ON acc.id = b.account_id
										WHERE b.user_id = $_SESSION[user_id]");
	$user_bills_array = array();
	foreach($user_bills as $key => $bill){
    $user_bills_array[$key]['title'] =  $bill['title'];
    $user_bills_array[$key]['start'] =  $bill['start'];
    $user_bills_array[$key]['id'] =  $bill['id'];
    
    if($bill['status'] == 1){
      $user_bills_array[$key]['backgroundColor'] = '#d9534f';
      if(Bill::bill_check_if_late($bill['due_date'])){
      $user_bills_array[$key]['backgroundColor'] = '#5CB85C';
      };
    }else{
      $user_bills_array[$key]['backgroundColor'] = '#cecbcb';
      $user_bills_array[$key]['borderColor'] = '#f9f9f9';
      $user_bills_array[$key]['textColor'] = '#424242';
    }
	}

  // echo "<pre>";
  // print_r($user_bills_array);
  // echo "</pre>";
 ?>

<script>
	var bills = <?php echo json_encode($user_bills_array) ?>;
	var fullDate = new Date();
</script>

<script type="text/javascript">
  var userbills = [];
  $.each(bills, function(i, v){
	   userbills[i] = {
      'id' : v.id,
      'title': v.title, 
      'start': v.start, 
      'backgroundColor' : v.backgroundColor, 
      'textColor' : v.textColor, 
      'borderColor' : v.borderColor
    }
	});
    
  $(document).ready(function() {
    $('#calendar').fullCalendar({
        header: {
            left: 'prev,next today',
            center: 'title',
            right: 'listDay,listWeek,month'
        },
        selectable: false,
        selectHelper: true,
        eventLimit: true,
        editable: false,
        views: {
            listDay: { buttonText: 'list day' },
            listWeek: { buttonText: 'list week' }
        },
        defaultView: 'month',
        defaultDate: fullDate,
        navLinks: true,
        events: userbills
    });
  });
 </script>

<div class="panel panel-primary">
    <div id='calendar'></div>
</div>


