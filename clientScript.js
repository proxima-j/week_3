//const socket = new WebSocket("ws://localhost:1880/testPage");
const socket = new WebSocket("ws://localhost:1880/week3_HW");
// socket.addEventListener("open", handleSocketOpen);

// function handleSocketOpen(){
//     document.body.style.backgroundColor= "green"
// }

socket.addEventListener("message", handleMessage);

    function handleMessage(event){
        const data = event.data.split(",");
        const analogValue = parseInt(data[0]);
        const switchState = parseInt(data[1]);
        const r = Math.round(Math.random() * 255);

    
            //document.body.style.backgroundColor= "green"
            //document.getElementById("socket_data").innerHTML=event.data;
            //document.getElementById("socket_data").innerHTML=analogValue;
            if (switchState == 1) {
                document.getElementById("socket_data").innerHTML= "Hello";
        } else {
                document.getElementById("socket_data").innerHTML="";
        }
        const colorIntensity = Math.round(analogValue / 1023 * 255);
        document.body.style.backgroundColor = `rgb(${colorIntensity}, ${r}, ${r})`;
    
            // Update HTML content with analog value
            document.getElementById("analogValue").innerText = `Analog value: ${analogValue}`;
        
           // document.body.style.backgroundColor = "rgb(" + event.data*255 + ",0,0)";
        };