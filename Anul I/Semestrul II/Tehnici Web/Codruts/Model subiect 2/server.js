const { urlencoded } = require("express");
const express = require("express");
const app = express();
const port = 3000;

app.use("/post", express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/p4.html");
});

app.post("/post", (req, res) => {
  const nume = req.body.nume;

  const persoane = [
    { nume: "Ion", sex: "m", varsta: 3 },
    { nume: "Oana", sex: "f", varsta: 23 },
    { nume: "Daria", sex: "f", varsta: 10 },
    { nume: "Mihai", sex: "m", varsta: 19 },
    { nume: "Gabriel", sex: "m", varsta: 22 },
    { nume: "Simona", sex: "f", varsta: 11 },
    { nume: "Bogdan", sex: "m", varsta: 28 },
  ];

  const persoanaCautata = persoane.find((pers) => pers.nume === nume);

  if (persoanaCautata) {
    let resp = `${persoanaCautata.sex === "f" ? "fata" : "baiat"}, ${
      persoanaCautata.varsta >= 18 ? "nu este minor" : "este minor"
    }`;
    //   if(persoanaCautata.sex === "f") {
    //       resp += "fata, ";
    //   } else {
    //       resp += "baiat, ";
    //   }

    //   if(persoanaCautata.varsta >= 18) {
    //       resp += "nu este minor";
    //   } else {
    //       resp += "este minor";
    //   }

    res.send(resp);
  } else {
    res.send("Nu exista numele cautat");
  }
});

app.listen(port, () => {
  console.log("Serverul a pornit");
});
