var billWindowHeight = $(window).height() - $('.bam-table-bills').offset().top - 130; 
var table = $('.bam-table-bills').DataTable({
  // ordering: false,
  "order": [ [ 2, 'asc' ]],
  "iDisplayLength": 10,
  "paging": false,
  // "scrollY":  billWindowHeight+"px",
  "scrolly":"600px",
  "language": {
    "zeroRecords": "Sorry, no bills to display", //changes words used
    "lengthMenu": "Show _MENU_ bills per page", //changes words used
    "info": "Showing _START_ to _END_ of _TOTAL_ bills", //changes words used
    "search": "", //changes words used originally - Search programs:
    "searchPlaceholder": "Search Bills",
    "infoFiltered": "(filtered from _MAX_ total bills)"
  }
});

// table.column(1).visible(false);
$('ul.datatable-filter-buttons').on('click', 'a', function() {
  

  if($(this).text() == 'All'){
    table
      .search('')
      .columns(4)
      .search('')
      .draw();
  }else{
    table
      .columns(4)
      .search($(this).text())
      .draw();
  }
  
  var totalBillsFound = $('.bam-table-bills tbody tr');

  var total = 0;
  $.each(totalBillsFound, function(i, v){
    var bill_amount = v.cells[1].innerText;
    amount = bill_amount.split('$');
    total += parseFloat(amount[1]);
    console.log(total);
  });

  // if($(this).text() != 'All') totalBillsAmountDue = total;

  $('h3.breakdown-title').text($(this).text() +' Bills ('+totalBillsFound.length+') $'+total.toFixed(2));

});
