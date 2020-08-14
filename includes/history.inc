<?php 
  
  if (!isset($_GET['type'])) {
    redirect("index.php?view=home");
  }

  // make sure original user
  if ($_GET['sui'] != $_SESSION['user_id']) {
    redirect("index.php?view=home");
  }

  // get accounts
  $account = Account::account_find_by_id($_GET['id']);

  // get bill
  $bill = Bill::bill_find_by_id($_GET['id']);

  
?>


<!-- if user account -->
  <?php if ($account->user_id != $_SESSION['user_id']) {
      redirect("index.php?view=accounts"); 
    }else{?>
     <div class="panel panel-primary history-panel">
       <div class="table-responsive">
         <table class="table table-hover display responsive bam-table1">
           <thead>
             <tr>
               <th>Date</th>
               <th>Amount</th>
               <th>Confirmation #</th>
               <th>description</th>
             </tr>
           </thead>

           <!-- if accounts -->
           <?php if ($_GET['type'] == 'ua'): ?>

           <!-- get all account payments -->
            <?php $payments = Payment::payments_find_all_by_account_id($account->id);?>
             <tbody>

                <!-- all account payments -->
                <?php foreach ($payments as $payment): ?>
                <tr>
                  <td><?php echo $payment->date; ?></td>
                  <td>&#x24;<?php echo $payment->payment_amount; ?></td>
                  <td><?php echo $payment->confirmation_number; ?></td>
                  <td><?php echo $payment->description; ?></td>
                </tr>
                      
                <?php endforeach ?>
              </tbody>
           <?php endif ?>
           
           <!-- if bills -->
           <?php if ($_GET['type'] == 'bl'): ?>
           <!-- get all account payments -->
            <?php $payments = Payment::payments_find_all_by_id($bill->id);?>
             <tbody>

                <!-- all account payments -->
                <?php foreach ($payments as $payment): ?>
                <tr>
                  <td><?php echo $payment->date; ?></td>
                  <td>&#x24;<?php echo $payment->payment_amount; ?></td>
                  <td><?php echo $payment->confirmation_number; ?></td>
                  <td><?php echo $payment->description; ?></td>
                </tr>
                      
                <?php endforeach ?>
              </tbody>
           <?php endif ?>

       


           </tbody>
         </table>
       </div>
     </div>
    <?php } ?>