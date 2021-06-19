#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void initboard(char board[ROW][COL])
{
	int a = 0;
	for (a = 0; a < ROW; a++)
	{
		int b = 0;
		for (b = 0; b < COL; b++)
		{
			board[a][b] = ' ';
		}
	}
}

void displayboard(char board[ROW][COL])
{
	int a = 0;
	for (a = 0; a < ROW; a++)
	{
		int b = 0;
		for (b = 0; b < COL; b++)
		{
			printf(" %c ", board[a][b]);
			if (b < COL - 1)
				printf("|");
		}
		printf("\n");
		if (a < ROW - 1)
		{
			for (b = 0; b < COL; b++)
			{
				printf("---");
				if (b < COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	printf("玩家回合:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标被下过了!\n");
		}
		else
			printf("输入错误,请重新输入!\n");
	}
}

void ComputerMove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL])
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL])
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}	
	for (i = 0; i < COL; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1 == IsFull(board))
	{
		return 'Q';
	}
	return 'C';
}