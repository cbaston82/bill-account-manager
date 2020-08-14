<!--Script Reference[1]-->
<script src="http://cdn.zingchart.com/zingchart.min.js"></script>
<!--Chart Placement[2]-->
  
<div class="ontime_late_chart">
  <div class="panel-heading">
    <h3 class="panel-title text-center">
      <span class="c-ontime"><strong>Ontime Payments</strong></span><br>
      <span>vs.</span><br>
      <span class="c-late"><strong>Late Payment</strong><br></span>
    </h3>
  </div>

<!--   <hr> -->
  <div id ='chartDiv'></div>
  <!-- <div class="panel-footer">This is a breakdown of your Ontime vs. Late bills <strong>payed</strong>. Once a bill is payed to <strong>ZERO</strong> your Ontime vs. Late Ratio will adjust accordanly.</div> -->
</div>


<script>
  var chartData={
      "type":"bar",  // Specify your chart type here.
      "series":[  // Insert your series data here.
          { "values": [4]},
          { "values": [6]}
      ]
    };
    zingchart.render({ // Render Method[3]
      id:'chartDiv',
      data:chartData,
      height:400,
      width:"100%"
    });
</script>
<style>
  #chartDiv-license{display: none;}
</style>