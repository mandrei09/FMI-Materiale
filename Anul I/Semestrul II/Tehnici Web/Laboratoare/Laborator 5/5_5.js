Array.prototype.myMap = function(callbackFunction){
    const array = this;
    let newArray = [];
    // cod
    for(let i = 0; i < array.length; i++){
        newArray.push(callbackFunction(array[i]));
    }
    return newArray;
}

function multiplicator(element){
    return 2*element;
}

console.log([1, 2, 3].myMap(multiplicator));

