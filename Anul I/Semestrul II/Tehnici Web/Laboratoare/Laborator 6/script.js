var movies = [{
    title: "titlu1",
    duration: 128,
    actors: ["actor 1.1, actor 1.2"],
    vizualised: true
},
{
    title: "titlu2",
    duration: 145,
    actors: ["actor 2.1", "actor 2.2"],
    visualised: false
}]

window.onload = function(){
    for(var i = 0; i < movies.length; i++){
        const paragraph = document.createElement("p");
        paragraph.innerText = movies[i].title + " " + movies[i].duration + " " + movies[i].actors + " " + movies[i].visualised;
        document.body.appendChild(paragraph);
    }
}