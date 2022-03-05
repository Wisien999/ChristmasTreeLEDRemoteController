const API_URL = "/"
const GET_POWER_STATE_URL = `${API_URL}/power`
const SET_POWER_STATE_URL = `${API_URL}/power`

function init() {

}

// setInterval(function () { getSensorData(); }, 1000); // Call the update function every set interval e.g. 1000mS or 1-sec

function getPowerState() {
    let xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("power-status").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", GET_POWER_STATE_URL, true);
    xhttp.send();
}

function setPowerState() {
    let xhttp = new XMLHttpRequest();
    xhttp.open("POST", )
}