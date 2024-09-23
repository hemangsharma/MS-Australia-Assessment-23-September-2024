#include <iostream>
using namespace std;

struct Node {
    char value;
    int row, col;
    Node* next;
};

// Function to create a new node
Node* createNode(char value, int row, int col) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = nullptr;
    return newNode;
}

// Function to check who won in Tic Tac Toe
char checkWinner(Node* head) {
    char board[3][3] = {{'-', '-', '-'},
                        {'-', '-', '-'},
                        {'-', '-', '-'}};

    // Fill the board based on the linked list
    Node* current = head;
    while (current != nullptr) {
        board[current->row][current->col] = current->value;
        current = current->next;
    }

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];  // Return the winner
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];  // Return the winner
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];  // Return the winner
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];  // Return the winner
    }

    return '-';  // No winner
}

int main() {
    // Creating a linked list representing a Tic Tac Toe board
    Node* head = createNode('X', 0, 0);
    head->next = createNode('O', 0, 1);
    head->next->next = createNode('X', 0, 2);
    head->next->next->next = createNode('O', 1, 1);
    head->next->next->next->next = createNode('X', 1, 0);
    head->next->next->next->next->next = createNode('X', 2, 0);

    // Check the winner
    char winner = checkWinner(head);

    if (winner == '-') {
        cout << "No winner yet, or the game is a draw." << endl;
    } else {
        cout << "The winner is: " << winner << endl;
    }

    return 0;
}
