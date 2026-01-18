let startTime = 0;
let elapsedTime = 0;
let timerInterval;

const display = document.getElementById("display");
const laps = document.getElementById("laps");
const clickSound = document.getElementById("clickSound");

function playSound() {
    clickSound.currentTime = 0;
    clickSound.play();
}

function formatTime(time) {
    let ms = time % 1000;
    time = Math.floor(time / 1000);

    let seconds = time % 60;
    time = Math.floor(time / 60);

    let minutes = time % 60;
    let hours = Math.floor(time / 60);

    return (
        String(hours).padStart(2, '0') + ":" +
        String(minutes).padStart(2, '0') + ":" +
        String(seconds).padStart(2, '0') + "." +
        String(ms).padStart(3, '0')
    );
}

function start() {
    playSound();
    if (timerInterval) return;

    startTime = Date.now() - elapsedTime;
    timerInterval = setInterval(() => {
        elapsedTime = Date.now() - startTime;
        display.textContent = formatTime(elapsedTime);
    }, 10);
}

function pause() {
    playSound();
    clearInterval(timerInterval);
    timerInterval = null;
}

function reset() {
    playSound();
    clearInterval(timerInterval);
    timerInterval = null;
    elapsedTime = 0;
    display.textContent = "00:00:00.000";
    laps.innerHTML = "";
}

function lap() {
    playSound();
    if (!timerInterval) return;

    const li = document.createElement("li");
    li.textContent = formatTime(elapsedTime);
    laps.appendChild(li);
}
