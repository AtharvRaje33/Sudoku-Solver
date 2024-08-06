var arr = [[], [], [], [], [], [], [], [], []];

for (var i = 0; i < 9; i++) {
    for (var j = 0; j < 9; j++) {
        arr[i][j] = document.getElementById(i * 9 + j);
    }
}

var board = [[], [], [], [], [], [], [], [], []];

function FillBoard(board) {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (board[i][j] != 0) {
                arr[i][j].innerText = board[i][j];
            } else {
                arr[i][j].innerText = '';
            }
        }
    }
}

let GetPuzzle = document.getElementById('GetPuzzle');
let SolvePuzzle = document.getElementById('SolvePuzzle');

GetPuzzle.onclick = function () {
    board = generateSudoku();
    FillBoard(board);
}

SolvePuzzle.onclick = () => {
    SudokuSolver(board, 0, 0);
};

function SudokuSolver(board, row, col) {
    if (row == 9) {
        FillBoard(board);
        return true;
    }

    if (col == 9) {
        return SudokuSolver(board, row + 1, 0);
    }

    if (board[row][col] != 0) {
        return SudokuSolver(board, row, col + 1);
    }

    for (var num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (SudokuSolver(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

function isValid(board, row, col, num) {
    for (var x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num || board[3 * Math.floor(row / 3) + Math.floor(x / 3)][3 * Math.floor(col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

function generateSudoku() {
    let board = Array.from({ length: 9 }, () => Array(9).fill(0));
    SudokuSolver(board, 0, 0);

    for (let i = 0; i < 81; i++) {
        let row = Math.floor(Math.random() * 9);
        let col = Math.floor(Math.random() * 9);
        board[row][col] = 0;
    }
    return board;
}
