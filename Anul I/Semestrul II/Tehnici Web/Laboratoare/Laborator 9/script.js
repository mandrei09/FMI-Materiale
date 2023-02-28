var movePixels = 10; // numarul de pixeli
var delayMs = 50; // numarul de milisecunde
var photoTimer = null;
var audio = new Audio("videoplayback.m4a");
// Muta imaginea pe ecran cu 10px
function photoWalk() {
    var img = document.getElementsByTagName("img")[0];
    var currentLeft = parseInt(img.style.left);
    img.style.left = currentLeft + movePixels + "px";
    // reseteaza imaginea la pozitia de pornite
    if (currentLeft > window.innerWidth - img.width) {
        img.style.left = "0px";
    }
}

// Apeleaza functia photoWalk la fiecare 50 ms
function startphotoWalk() {
    photoTimer = window.setInterval(photoWalk, delayMs);
}

var sessionTimer = window.setTimeout(()=>{
    alert("Are you still watching?")}, 3000);

let buttonStart = document.getElementById("start-button");
buttonStart.addEventListener("click", ()=>{
    document.getElementById("info").innerText = "Viteza pisicii este de: " + movePixels + "px/s";
    startphotoWalk();
    sessionTimer = window.setTimeout(()=>{
        alert("Are you still watching?")}, 3000);
    buttonStart.disabled = true;
});

let buttonBecali = document.getElementById("becali");
buttonBecali.addEventListener("click",()=>{audio.play;});

let buttonStop = document.getElementById("stop-button");
buttonStop.addEventListener("click", ()=>{
    document.getElementById("info").innerText = "Viteza pisicii este de: " + movePixels + "px/s";
    clearInterval(photoTimer);
    sessionTimer = window.setTimeout(()=>{
        alert("Are you still watching?")}, 3000);
    buttonStart.disabled = false;
}); 

let speedButton = document.getElementById("speed-button");
speedButton.addEventListener("click", ()=>{
    movePixels+=5;
    document.getElementById("info").innerText = "Viteza pisicii este de: " + movePixels + "px/s";
    sessionTimer = window.setTimeout(()=>{
        alert("Are you still watching?")}, 3000);
});

let buttonsContainer = document.getElementById("buttons");
let resetButton = document.createElement("button");
resetButton.setAttribute("id", "reset-id");
resetButton.innerText = "Reset";
resetButton.onclick = function(){
    movePixels = 10;
    document.getElementById("info").innerText = "Viteza pisicii este de: " + movePixels + "px/s";
}
buttonsContainer.appendChild(resetButton);

