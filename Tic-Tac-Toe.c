#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard() {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
board[i][j] = ' ';
}
}
}

// Function to print the board
void printBoard() {
printf("\n");
for (int i = 0; i < 3; i++) {
printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
if (i != 2)
printf("\n---|---|---\n");
}
printf("\n\n");
}

// Function to check if a player has won
int checkWinner() {
// Check rows and columns
for (int i = 0; i < 3; i++) {
if (board[i][0] == currentPlayer &&
board[i][1] == currentPlayer &&
board[i][2] == currentPlayer)
return 1;

if (board[0][i] == currentPlayer &&
board[1][i] == currentPlayer &&
board[2][i] == currentPlayer)
return 1;
}

// Check diagonals
if (board[0][0] == currentPlayer &&
board[1][1] == currentPlayer &&
board[2][2] == currentPlayer)
return 1;

if (board[0][2] == currentPlayer &&
board[1][1] == currentPlayer &&
board[2][0] == currentPlayer)
return 1;

return 0;
}

// Function to check if the board is full
int isFull() {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (board[i][j] == ' ')
return 0;
}
}
return 1;
}

// Function to switch player
void switchPlayer() {
if (currentPlayer == 'X')
currentPlayer = 'O';
else
currentPlayer = 'X';
}

int main() {
int row, col;

printf("\n==== TIC TAC TOE GAME ====\n");
initializeBoard();
printBoard();

while (1) {
printf("Player %c, enter row and column (1-3): ", currentPlayer);
if (scanf("%d %d", &row, &col) != 2) {
printf("Invalid input! Please enter two numbers.\n");
while (getchar() != '\n'); // clear buffer
continue;
}

if (row < 1 || row > 3 || col < 1 || col > 3) {
printf("Invalid position! Try again.\n");
continue;
}

if (board[row - 1][col - 1] != ' ') {
printf("That spot is already taken! Try again.\n");
continue;
}

board[row - 1][col - 1] = currentPlayer;
printBoard();

if (checkWinner()) {
printf("🎉 Player %c wins the game!\n", currentPlayer);
break;
}

if (isFull()) {
printf("😄 It's a draw!\n");
break;
}

switchPlayer();
}

printf("\n==== Game Over ====\n");
return 0;
}