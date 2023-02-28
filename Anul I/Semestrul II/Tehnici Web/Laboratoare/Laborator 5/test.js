console.log("ceva");

var str1="inca ceva";
var a = 1;
var b = 1.1;
var obj = {
    nume: "Ion",
    prenume: "Vasile",
    varsta: 20,
    cursuri: ["Poo", "TW"],
    facultate:{
        nume: "FMI",
        oras: "Bucuresti",
    }
}
obj.cursuri.push("ABC");
console.log(obj);


var str2 = "abc";
var str3 = "def";
console.log(str2+str3);

console.log("abc" + 1);

function func(arg){
    return arg + "abc";
}
console.log(func("ceva"));

console.table(obj);