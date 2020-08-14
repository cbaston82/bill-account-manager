<?php $payments = Payment::payments_find_all($_SESSION['user_id'], 'ORDER BY date DESC') ?>
<div class="panel panel-primary">
    <div class="panel-heading">Recent Payments</div>
        <ul class="list-group">

            <!-- if user has payments -->
            <?php if (count($payments) > 0): ?>
                <?php $display = 0; ?>
                <?php foreach ($payments as $payment): ?>
                    <?php $account_name = Account::account_find_by_id($payment->account_id) ?>
                    <?php $bill = Bill::bill_find_by_id($payment->bill_id) ?>
                    <li class="list-group-item">
                        <strong><?php echo $account_name->name; ?></strong><br> 
                        <?php echo the_date($payment->date); ?><br>
                        <?php echo  ($payment->confirmation_number != "") ? "Conf: <strong>".$payment->confirmation_number."</strong>" : "" ?><br>
                        <span>Payed:  <span class="bg-success">&#x24;<?php echo currency($payment->payment_amount); ?></span></span><br>
                        
                    </li>
                    <?php if ($disply++ == 3) break; ?>
                <?php endforeach ?>
            <?php endif ?>

            <!-- if user has no payments -->
            <?php if (count($payments) < 1): ?>
                <li class="list-group-item">
                    No payment history.
                </li>
            <?php endif ?>

        </ul>
    <div class="panel-footer"><a href="index.php?view=payments">All Payments</a></div>
</div>