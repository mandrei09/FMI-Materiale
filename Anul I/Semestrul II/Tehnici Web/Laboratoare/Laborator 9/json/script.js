var currentphotoId;

function fetchphotos(){
    let content = document.getElementById("content");
    let body = document.getElementsByTagName("body")[0];

    let p = document.createElement("p");
    p.innerText = "loading...";
    p.setAttribute("id", "loading");
    body.appendChild(p);

    fetch('http://localhost:3000/photos',
        {   
            method: 'get'
        }
    ).then(function(response){
        response.json().then((data)=>{
            if(data.length){
                body.removeChild(p);
            }
            for(let i = 0; i < data.length; i++){
                let image = document.createElement("img");
                image.setAttribute("src", data[i].img);
                image.width = 100;
                content.appendChild(image);
        
                let h2 = document.createElement("h2");
                h2.innerText = data[i].name;
                content.appendChild(h2);
                
                let editButton = document.createElement("button");
                editButton.innerText = "Edit";
                editButton.onclick = function(){
                    document.getElementById("name").value = data[i].name;
                    document.getElementById("image").value = data[i].img;
                    currentphotoId = data[i].id;
                }
                content.appendChild(editButton);

                let deleteButton = document.createElement("button");
                deleteButton.innerText = "Delete";
                deleteButton.onclick = function(){
                    deletephoto(data[i].id);
                }
                content.appendChild(deleteButton);

                let hr = document.createElement("hr");
                content.appendChild(hr);
            }
        })
    })

}

fetchphotos()

function addphoto(){
    var name = document.getElementById("name").value;
    var image = document.getElementById("image").value;

    var newphoto ={
        name: name,
        img: image
    }

    fetch('http://localhost:3000/photos',{
        method: 'post',
        headers:{
            'Content-Type':'application/json'
        },
        body: JSON.stringify(newphoto)
    }).then(function(response){
        window.location.reload();
    })
}

function editphoto(){
    var name = document.getElementById("name").value;
    var image = document.getElementById("image").value;

    var newphoto = {
        name: name,
        img: image
    }

    fetch('http://localhost:3000/photos/'+currentphotoId,{
        method: 'put',
        headers: {
            'Content-Type':'application/json'
        },
        body: JSON.stringify(newphoto)
    }).then(function(response){
        window.location.reload();
    })

}