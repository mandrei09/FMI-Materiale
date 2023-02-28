const express = require('express')
const app = express();

app.use('/post', express.urlencoded({extended:true}));

app.get('/', (req, res) => {
    res.sendFile(__dirname + "/p4.html")
})

app.post("/post", (req, res) => {
    let numere = req.body.numere;
    const operatie = req.body.operatie;

    const values = numere.split("/");

    let ok = true;

    for(let val of values) {
        if(isNaN(val)) {
            ok = false;
        }
    }

    if(ok) {
        switch(operatie) {
            case "suma":
                let sum = 0;
                for(let val of values) {
                    sum += parseInt(val);
                }
                res.send(sum.toString());
            case "medie":
                const avg = values.reduce((a, b) => parseInt(a) + parseInt(b), 0) / values.length;
                res.send(avg.toString());
            case "maxim":
                const numbers = values.map(val => parseInt(val));
                res.send(Math.max(...numbers).toString());
        }
    } else {
        res.send("date invalide");
    }
})

app.listen(3000, () => {
    console.log("Serverul a pornit");
})