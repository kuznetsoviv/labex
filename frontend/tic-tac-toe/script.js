const board = document.getElementById('board');
const cells = document.querySelectorAll('.cell');
const statusText = document.getElementById('status');
const resetBtn = document.getElementById('reset-btn');
const xScoreDisplay = document.getElementById('x-score');
const oScoreDisplay = document.getElementById('o-score');

let currentPlayer = 'X';
let gameState = ["", "", "", "", "", "", "", "", ""];
let xScore = 0;
let oScore = 0;

const winConditions = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], // Rows
    [0, 3, 6], [1, 4, 7], [2, 5, 8], // Columns
    [0, 4, 8], [2, 4, 6]             // Diagonals
];

function handleCellClick(e) {
    const clickedCell = e.target;
    const cellIndex = parseInt(clickedCell.getAttribute('data-index'));

    if (gameState[cellIndex] !== "" || checkWinner()) return;

    gameState[cellIndex] = currentPlayer;
    clickedCell.innerText = currentPlayer;

    if (checkWinner()) {
        statusText.innerText = `Player ${currentPlayer} Wins!`;
        updateScore();
        highlightWinner();
    } else if (!gameState.includes("")) {
        statusText.innerText = "It's a Draw!";
    } else {
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    }
}

function checkWinner() {
    return winConditions.some(condition => {
        return condition.every(index => gameState[index] === currentPlayer);
    });
}

function highlightWinner() {
    winConditions.forEach(condition => {
        if (condition.every(index => gameState[index] === currentPlayer)) {
            condition.forEach(index => cells[index].classList.add('winner'));
        }
    });
}

function updateScore() {
    if (currentPlayer === 'X') {
        xScore++;
        xScoreDisplay.innerText = xScore;
    } else {
        oScore++;
        oScoreDisplay.innerText = oScore;
    }
}

function resetGame() {
    currentPlayer = 'X';
    gameState = ["", "", "", "", "", "", "", "", ""];
    statusText.innerText = "";
    cells.forEach(cell => {
        cell.innerText = "";
        cell.classList.remove('winner');
    });
}

cells.forEach(cell => cell.addEventListener('click', handleCellClick));
resetBtn.addEventListener('click', resetGame);