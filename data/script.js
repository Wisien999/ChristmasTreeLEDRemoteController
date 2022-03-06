const API_URL = "/"
const GET_POWER_STATE_URL = `${API_URL}/power`
const SET_POWER_STATE_URL = `${API_URL}/power`
const CHANGE_MODE_URL = `${API_URL}/mode`

function init() {
    // document.getElementById("js-disabled-buttons").style.display = "none";
    document.getElementById("js-enabled-buttons").style.display = "";
}

// setInterval(function () { getSensorData(); }, 1000); // Call the update function every set interval e.g. 1000mS or 1-sec

function getPowerState() {
    let xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState === 4 && this.status === 200) {
            document.getElementById("power-status").innerText = "The power is " + this.responseText;
            document.getElementById("power-button-js-enabled").innerText = "Turn " + (this.responseText === "ON" ? "OFF" : "ON")
        }
    };
    xhttp.open("GET", GET_POWER_STATE_URL, true);
    xhttp.send();
}

function setPowerState() {
    let xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState !== 4) {
            return;
        }

        getPowerState();
    }

    xhttp.open("PATCH", SET_POWER_STATE_URL, true)
    xhttp.send();
}