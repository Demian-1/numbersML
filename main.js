// alert('hola')
var numberOfPasses = 0;

const butt = document.createElement("button");

const buttons = document.getElementById("myButtons");
const child = document.getElementById("initial");

for (var i = 0; i < 10; i++) {
    buttons.insertBefore(butt, child);
}
