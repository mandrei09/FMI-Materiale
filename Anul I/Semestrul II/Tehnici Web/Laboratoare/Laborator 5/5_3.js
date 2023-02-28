var movie = {
    title: "The Godfather",
    duration: 168,
    actors: ["Marlon Brando", "Al Pacino", "James Caan", "Richard Castellano"]
}

function func(movie){
    var result = '"' + movie.title + '"' + " running time is " + movie.duration + " minutes. Starring: ";
    for(var i = 0; i < movie.actors.length; i++){
        result = result + movie.actors[i] + "; "
    }
    console.log(result);
}
func(movie);