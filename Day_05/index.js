const cells = document.querySelectorAll('.cell');
const statusText = document.getElementById('status');
const resetButton = document.getElementById('reset-button');
const overlay = document.getElementById('overlay');
const messageText = document.getElementById('message');

let currentPlayer = "X";
let gameActive = true;
let gameState = ["", "", "", "", "", "", "", "", ""];

const winningConditions = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], 
    [0, 3, 6], [1, 4, 7], [2, 5, 8], 
    [0, 4, 8], [2, 4, 6]             
];

function handleCellClick(e) {
    const clickedCell = e.target;
    const cellIndex = parseInt(clickedCell.getAttribute('data-index'));
    if (gameState[cellIndex] !== "" || !gameActive) {
        return;
    }

    updateCell(clickedCell, cellIndex);
    checkWinner();
}

function updateCell(cell, index) {
    gameState[index] = currentPlayer;
    cell.classList.add(currentPlayer.toLowerCase()); 
}

function checkWinner() {
    let roundWon = false;

    for (let i = 0; i < winningConditions.length; i++) {
        const [a, b, c] = winningConditions[i];
        if (gameState[a] === "" || gameState[b] === "" || gameState[c] === "") {
            continue;
        }
        if (gameState[a] === gameState[b] && gameState[b] === gameState[c]) {
            roundWon = true;
            break;
        }
    }

    if (roundWon) {
        endGame(`Player ${currentPlayer} Wins!`);
        return;
    }
    if (!gameState.includes("")) {
        endGame("It's a Draw!");
        return;
    }
    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.innerText = `Player ${currentPlayer}'s Turn`;
}

function endGame(message) {
    messageText.innerText = message;
    overlay.classList.add('show');
    gameActive = false;
}

function resetGame() {
    currentPlayer = "X";
    gameActive = true;
    gameState = ["", "", "", "", "", "", "", "", ""];
    statusText.innerText = "Player X's Turn";
    overlay.classList.remove('show');

    cells.forEach(cell => {
        cell.classList.remove('x', 'o');
    });
}
cells.forEach(cell => cell.addEventListener('click', handleCellClick));
resetButton.addEventListener('click', resetGame);
overlay.classList.remove('show');