window.onload = function(){
    
    function makeStory(){
        var input1 = document.getElementById("places");
        var input2 = document.getElementById("characteristics");
        var input3 = document.getElementById("people");

        var c = document.getElementById("story")
        c.innerText = input1.value + input2.value + input3.value;
    }

    var b = document.getElementById("story-button");
    b.addEventListener("click", makeStory);
}