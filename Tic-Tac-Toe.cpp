#include<bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 3;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = '-';

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
char currentPlayer = PLAYER_X;

void printBoard() {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
}

bool isBoardFull() {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY) {
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin(char player) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    cout << "Tic-Tac-Toe Game" << endl;

    int row, col;
    char winner = EMPTY;

    while (winner == EMPTY && !isBoardFull()) {
        printBoard();

        cout << "Current Player: " << currentPlayer << endl;
        cout << "Enter row (0-" << (BOARD_SIZE - 1) << "): ";
        cin >> row;
        cout << "Enter column (0-" << (BOARD_SIZE - 1) << "): ";
        cin >> col;

        if (!makeMove(row, col)) {
            cout << "Invalid move. Try again." << endl;
        }

        if (checkWin(currentPlayer)) {
            winner = currentPlayer;
        }
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    printBoard();

    if (winner == EMPTY) {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << winner << " wins!" << endl;
    }

    return 0;
}
