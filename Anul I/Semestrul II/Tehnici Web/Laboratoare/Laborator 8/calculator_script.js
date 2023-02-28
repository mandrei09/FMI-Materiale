window.onload = function(){
    function button1(){
        var input = document.getElementById("square-input");

        var c = document.getElementById("solution");
        var value = parseInt(input.value);
        c.innerText = value*value;
    }

    var b = document.getElementById("square-button");
    b.addEventListener("click", button1);

    function button2(){
        var input = document.getElementById("half-input");

        var c = document.getElementById("solution");
        var value = parseInt(input.value)
        c.innerText = value / 2;
    }

    var b = document.getElementById("half-button");
    b.addEventListener("click", button2);

    function button3(){
        var input1 = document.getElementById("percent1-input");
        var input2 = document.getElementById("percent2-input");

        var value1 = parseInt(input1.value);
        var value2 = parseInt(input2.value);

        var c = document.getElementById("solution");

        c.innerText =  value1 / 100 * value2;

    }

    var b = document.getElementById("percent-button");
    b.addEventListener("click", button3);

    function button4(){
        var raza = document.getElementById("area-input");

        var c = document.getElementById("soluiton");

        c.innerText = raza.value * 3.14 * 3.14;
    }

    var b = document.getElementById("area-button");
    b.addEventListener("click", button4);
}