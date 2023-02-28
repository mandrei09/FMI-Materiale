window.onload = function(){
    var h1 = document.getElementById("header");
    h1.style.color = "yellow";

    var spans = document.getElementsByTagName("span");
    for(let i = 0 ; i < spans.length; i++){
        spans[i].innerText = "span" + i;
    }

    // metoda 1 - dinamic
    var div = document.getElementById("dinamic");
    div.innerHTML = "<span> pisici in span dinamic </span> <span> prea multe chestii cu pisici </span>" + "<p> paragraf cu pisici </p>" + "<h2> h2 pisicos </h2>";

    // metoda 2 - dinamic
    var div = document.getElementById("dinamic");
    var span1 = document.createElement("span");
    span1.innerText = "pisici in cel de-al doilea span dinamic"
    span1.style.color = "blue";
    span1.setAttribute("id", "span-dinamic");
    
    span1.className = "cls1 cls2"; 
    // sau span1.classList.add("clas1"); span1.classList.add("class2");
    div.appendChild(span1);
}