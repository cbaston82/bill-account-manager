<?php 
  $bills_grand_totals = Bill::bills_grand_totals($_SESSION['user_id']);
?>
<div class="col-sm-12">
  <h3 class="breakdown-title">Total payouts</h3>

  <?php if(!empty($bills_grand_totals)) : ?>
    <link rel="stylesheet" href="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.css">
    <script src="//cdnjs.cloudflare.com/ajax/libs/raphael/2.1.0/raphael-min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/morris.js/0.5.1/morris.min.js"></script>

    <div id="myfirstchart" style="height: 250px;"></div>
    <script>
      Morris.Bar({
        element: 'myfirstchart',
        data: [
          <?php foreach($bills_grand_totals as $bgt) : 
            $account_info = Account::account_find_by_id($bgt->account_id);
            $accountName = $account_info->name;
            $accountName = explode(' ', $accountName);?>
            { y: '<?= $accountName[0] ?>', a: <?= round($bgt->amount, 2)?>},
          <?php endforeach; ?> 
        ],
        xkey: 'y',
        ykeys: ['a'],
        labels: ['Total Payed']
      });
    </script>
  <?php else: ?>
    <div class="panel panel-primary">
      <div class="list-group-item">
        <h3 class="list-group-item-heading"><strong>NO DATA FOUND TO GRAPH </strong><br><small>All your grand totals will show up here. e.g. (a continuous total paid to all your accounts)</small></h3>
      </div>
    </div>
  <?php endif; ?>


</div>