#define  _CRT_SECURE_NO_WARNINGS 1
//����ģ��
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
	initboard(board,ROW,COL);          //��ʼ������
	displayboard(board, ROW, COL);     //��ӡ����
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
		printf("��ϲ���ʤ!\n");
	}
	else if (ret == '#')
	{
		printf("���ź���ʧ����\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}