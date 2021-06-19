#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void initboard(char board[ROW][COL]);
void displayboard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
int IsFull(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);