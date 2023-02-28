var ar = [1, 3 , 5 , 2, 6];
ar = ar.map(element => element*2);
var ar2 = [5, 6, 1, 7];
ar2 = ar2.filter(element => element%2 == 0);

console.log(ar);
console.log(ar2);

var ar3 = ["aaa", "bbb", "ccc"];
var i = ar3.indexOf("bbb");

console.log(i);