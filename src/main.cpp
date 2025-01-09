#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

//This will be how we check winners

int magicSquare[3][3] = {
    {8, 1, 6},
    {3, 5, 7},
    {4, 9, 2}
};

void displayBoard(const std::vector<std::vector<char>>& board) {
    system("clear");
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
    if (!(row < 0 || row > 2 || col < 0 || col > 2) && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += (board[i][j] == player ? magicSquare[i][j] : 0); // Row
            colSum += (board[j][i] == player ? magicSquare[j][i] : 0); // Column
        }
        if (rowSum == 15 || colSum == 15) return true;
    }

    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < 3; ++i) {
        diag1Sum += (board[i][i] == player ? magicSquare[i][i] : 0);       // Main diagonal
        diag2Sum += (board[i][2 - i] == player ? magicSquare[i][2 - i] : 0); // Anti-diagonal
    }
    if (diag1Sum == 15 || diag2Sum == 15) return true;

    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);
    srand(time(0));

    char currentPlayer = 'X';
    int row, col, players, cpuRow, cpuCol;
    bool gameWon = false;
    bool gameStarted = false;

    while (!gameWon) {

        if (!gameStarted) {
            system("clear");
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
        if (gameWon) break;
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter row and column (0-2) to make your move: ";
        cin >> row >> col;
        if (!makeMove(board, row, col, currentPlayer)) {
            cout << "Invalid move! Try again." << endl;
            cin.ignore();
            cin.get();
            continue;
        }
        gameWon = checkWin(board, currentPlayer);
        if (gameWon) break;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        if (players == 1) {
            //TODO: some sort of strategy
            while (true) {
                cpuRow =  rand() % 3;
                cpuCol =  rand() % 3;
                if (makeMove(board, cpuRow, cpuCol, currentPlayer)) {
                    gameWon = checkWin(board, currentPlayer);
                    if (gameWon) break;
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                    break;
                }
            }
        }

    }

    displayBoard(board);
    cout << "Player " << currentPlayer << " wins!" << endl;
    return 0;
}