window.onload = function(){
    setTimeout(function(){alert("Salut")}, 3000);
    const a = setInterval(function(){console.log("pisici")}, 2000);

    var b = document.getElementById("my-button");
    b.addEventListener("click", function(){
        alert("button pressed");
    });

    // inlocuitor pentru codul cu b
    //p = document.createElement('p');
    //p.click = function(){}; SAU p.addEventListener(...)
}
function stopInterval(){
    clearInterval(a); 
}