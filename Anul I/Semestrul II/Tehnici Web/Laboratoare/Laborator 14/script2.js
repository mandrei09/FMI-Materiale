window.onload = function(){
    document.getElementById("culoare").onchange = function(){
        localStorage.setItem("culoare", document.getElementById("culoare").value);
    }
    if(localStorage.getItem("culoare")){
        document.body.style.backgroundColor = localStorage.getItem("culoare");
    }
    var t;
    var count=0;
    window.onkeydown = function(event){
        if(event.key>="0" && event.key<="9"){
            count++;
            if(count === 1){
                var start = parseInt(event.key)%2;
                var buttons = document.getElementsByTagName("button");
                // var buttons = document.querySelectorAll("button");
                
                t=setInterval(function(){
                    buttons[start].style.backgroundColor = document.getElementById("culoare").value;
                    start+=2;
                }, 1000);
            }
            else{
                clearInterval(t);
                var buttons = document.getElementsByTagName("button");

                for(let b of buttons){
                    if(!b.style.backgroundColor){
                        document.body.removeChild(b);
                    }
                }
            }
        }
    }
}