const NUMBER_OF_COLS = 10;
const NUMBER_OF_ROWS = 6;

function calc(col, row) {
    let x = Math.floor((224 / (NUMBER_OF_COLS - 1)) * col);
    let y = Math.floor((64 / (NUMBER_OF_ROWS - 1)) * row);
    return `{ ${x}, ${y}} `;
}

for (let col = 0; col < NUMBER_OF_COLS; col++) {
    let strings = "";
    for (let row = 0; row < NUMBER_OF_ROWS; row++) {
        strings += calc(col, row) + ", ";
    }
    console.log(strings);
}
