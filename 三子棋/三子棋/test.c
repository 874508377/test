#define  _CRT_SECURE_NO_WARNINGS 1
//测试模块
#include"game.h"

void menu()
{
	printf("******************************************\n");
	printf("*****      1.play        0.exit      *****\n");
	printf("******************************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board,ROW,COL);          //初始化数组
	displayboard(board, ROW, COL);     //打印棋盘
	while (1)
	{
		playmove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	 }
	if (ret == '*')
	{
		printf("恭喜你获胜!\n");
	}
	else if (ret == '#')
	{
		printf("很遗憾你失败了\n");
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
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}