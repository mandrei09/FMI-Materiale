const express = require('express')
const app = express();

app.use('/post', express.urlencoded({extended:true}));

app.get('/', (req, res) => {
    res.sendFile(__dirname + "/p4.html")
})

app.post("/post", (req, res) => {
    let numere = req.body.numere;
    const sortare = req.body.sortare;

    const values = numere.split(",");
    console.log(values)

    let ok = true;

    for(let val of values) {
        if(isNaN(val)) {
            ok = false;
        }
    }

    if(ok) {
        values.sort((a, b) => {
            if(sortare === "crescator") {
                return a - b;
            } else {
                return b - a;
            }
        })
        let resp = "";
        for(let i = 0; i < values.length; i++) {
            if(i < values.length - 1) {
                resp += `${values[i]},`;
            } else {
                resp += values[i]
            }
        }
        res.send(resp);
    } else {
        res.send("date invalide");
    }
})

app.listen(3000, () => {
    console.log("Serverul a pornit");
})