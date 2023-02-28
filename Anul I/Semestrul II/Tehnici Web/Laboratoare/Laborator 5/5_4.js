const cart = {
    phone: "350",
    console: "250",
    tv: "450",
    headPhones: "10.60",
    watch: "20.34",
    bag: "22.36"
}

cart.phone;
cart["phone"];

function total(obj){
    var price_int = 0;
    var price_float = 0;
    var keys = Object.keys(obj);
    console.log(keys);
    for(var i = 0; i < keys.length; i++){
        price_int += parseInt(obj[keys[i]]);
        price_float += parseFloat(obj[keys[i]]);
    }
    console.log(price_int);
    console.log(price_float);
    console.log(price_float.toFixed(2));
   
}

total(cart);
