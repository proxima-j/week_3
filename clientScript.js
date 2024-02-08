const socket = new WebSocket("ws://localhost:1880/testPage");

// socket.addEventListener("open", handleSocketOpen);

// function handleSocketOpen(){
//     document.body.style.backgroundColor= "green"
// }

socket.addEventListener("message", handleMessage);

function handleMessage(event){
        document.body.style.backgroundColor= "green"
        //document.getElementById("socket_data").innerHTML=event.data;
    };