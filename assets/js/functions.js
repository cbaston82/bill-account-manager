function numbersOnly(evt){
  var nbr;
  var nbr = (window.event) ? event.keyCode : evt.which;
  if ((nbr >= 48 && nbr <= 57) || nbr == 8 || nbr==40 ||nbr == 41 || nbr ==45 ){
    return true;
  }else{
    return false;
  }
}