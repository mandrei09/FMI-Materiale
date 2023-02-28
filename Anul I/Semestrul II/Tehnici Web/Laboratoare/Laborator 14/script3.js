function generateRandom(min, max){
return Math.floor(Math.random()*(max-min))+min;
}

window.onload=function(){
    
    var n = generateRandom(5,10);
    for(let i=0; i<n; i++)
    {
     var div=document.createElement("div");
     div.className="patrat";
     div.innerText="Div"+(i+1);
     div.style.position="relative";
     div.style.left="0px";
     document.body.appendChild(div);
    div.onclick=function(event){
     this.style.left=parseInt(this.style.left)+10+px;
     event.stopPropagation;
    }

    }
    document.body.onclick=function(event){
    let nr = generateRandom(0,n-1);
    let divs=document.getElementsByClassName("patrat");
    divs[nr].style.position="absolute";
    divs[nr].style.left=event.clientX+"px";
    divs[nr].style.top=event.clientY+"px";




    }



}