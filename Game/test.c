#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***************************************\n");
	printf("*************1.play 0.exit*************\n");
	printf("***************************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//全部空格
	initboard(board);//初始化棋盘
	displayboard(board);//打印棋盘
	while (1)
	{
		PlayerMove(board);
		displayboard(board);
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board);
		displayboard(board);
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}