#include <iostream>
using namespace std;

#define SIZE 3

// Function to check the winner
char checkWinner(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];  // Return the winning player ('X' or 'O')
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];  // Return the winning player ('X' or 'O')
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];  // Return the winning player ('X' or 'O')
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];  // Return the winning player ('X' or 'O')
    }

    // No winner yet
    return '-';
}

int main() {
    // 3x3 Tic Tac Toe board example
    char board[SIZE][SIZE] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'-', 'X', 'X'}
    };

    char result = checkWinner(board);

    if (result == '-') {
        cout << "No winner yet, or the game is a draw." << endl;
    } else {
        cout << "The winner is: " << result << endl;
    }

    return 0;
}
