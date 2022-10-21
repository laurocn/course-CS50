function check(){
     var email1 = document.getElementById('email1');
     var email2 = document.getElementById('email2');
     if (email1.value != email2.value) {
          alert("The two e-mails must match!");
          return false;
     }
}
function billingFunction(){
     if (document.getElementById('same').checked){
         billingName.value = shippingName.value;
         billingZip.value = shippingZip.value;
     }
     
     else{
         billingName.value = null;
         billingZip.value = null;
     }
 }
