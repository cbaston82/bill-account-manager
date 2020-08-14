
<div id="updateCardModal" class="modal fade" role="dialog">
  <div class="modal-dialog">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header bg-primary">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title">Update Card</small></h4>
      </div>
      <div class="modal-body">
          <!-- select options -->
          <div class="form-group col-sm-12">
            <label for="cc-number">Card Number</label>
            <input name="cc-number" id="cc-number" autocomplete="cc-number" class="form-control" placeholder="**** **** **** <?php echo $card['last4']; ?>">
          </div>
          
          <div class="form-group col-sm-4">
            <label for="cc-expiration-year">Exp Year</label>
            <input name="cc-expiration-year" id="cc-expiration-year" autocomplete="cc-expiration-year" class="form-control" type="number" value="<?php echo $card['expYear'] ?>">
          </div>

          <div class="form-group col-sm-4">
            <label for="cc-expiration-month">Exp Month</label>
            <input name="cc-expiration-month" id="cc-expiration-month" autocomplete="cc-expiration-month" class="form-control" type="number" value="<?php echo $card['expMonth'] ?>" >
          </div>

          <div class="form-group col-sm-4">
            <label for="cc-cvc">CVV</label>
            <input name="cc-cvc" id="cc-cvc" autocomplete="cc-cvc" class="form-control" type="text" name="">
          </div>

          <button name="update" id="card-update" class="btn btn-primary"><i class="fa fa-floppy-o"></i> Save</button>
      </div>
      <div class="modal-footer bg-primary">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>