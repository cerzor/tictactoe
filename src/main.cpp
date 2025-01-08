#include <iostream>
#include <vector>
#include <cstdlib>  // For system() to clear the terminal
#include <limits>   // For numeric limits
using namespace std;

void displayBoard(const std::vector<std::vector<char>>& board) {
    system("clear");  // Use "cls" on Windows instead of "clear"
    // system("CLS");
    // cout << "\033[2J\033[H";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
}

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {}
        }
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);

    char currentPlayer = 'X';
    int row, col, players;
    bool gameWon = false;
    bool gameStarted = false;

    while (!gameWon) {

        if (!gameStarted) {
            cout << "How many players? 1-2" << endl;

            while (true) {
                cin >> players;
                if (cin.fail() || players < 1 || players > 2) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Try again." << endl;
                } else {
                    gameStarted = true;
                    break;
                }
            }
        }

        if (players == 2) {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter row and column (0-2) to make your move: ";
            cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2 || !makeMove(board, row, col, currentPlayer)) {
                cout << "Invalid move! Try again." << endl;
                cin.ignore();
                cin.get();
                continue;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

    }
    return 0;
}