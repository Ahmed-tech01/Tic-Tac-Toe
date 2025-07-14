#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>  // For system("cls")
using namespace std;

char board[3][3];
char currentPlayer = 'X';
int choice;
bool gameOver = false;
string playerX, playerO;

// Function to reset board
void resetBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
}

// Function to display board
void displayBoard() {
    system("cls");  // Clear the screen
    cout << playerX << " [X]  vs  " << playerO << " [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

// Function for player's move
void playerTurn() {
    cout << ((currentPlayer == 'X') ? playerX : playerO)
         << " (" << currentPlayer << "), enter a number (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Press any key to try again...\n";
        _getch();
        playerTurn();
    } else {
        board[row][col] = currentPlayer;
    }
}

// Win check
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

// Draw check
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

// Switch current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Enter name for Player X: ";
    getline(cin, playerX);
    cout << "Enter name for Player O: ";
    getline(cin, playerO);

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        gameOver = false;
        currentPlayer = 'X';

        while (!gameOver) {
            displayBoard();
            playerTurn();
            if (checkWin()) {
                displayBoard();
                cout << ((currentPlayer == 'X') ? playerX : playerO) << " (" << currentPlayer << ") wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();  // to handle leftover newline in buffer
    }

    cout << "\nThank you for playing!\n";
    return 0;
}