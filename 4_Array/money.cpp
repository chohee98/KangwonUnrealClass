#include "money.h"
#include <stdio.h>

//int g_money = 0; //���� ���� ��� �ڵ忡�� �ϳ��� �־��! (��ŷ �ܰ迡�� ����)
static int s_money = 0;

extern int g_money; //������ ����°� �ƴ϶�! "��𼱰� ����" ������ ������ ���� ���� (�̸� �˷���)

int addMoney(int money)
{
	int t_money = 0;
	t_money += money;
	g_money += money;
	s_money += money;

	printf("t_money=%d\n", t_money);
	printf("g_money=%d\n", g_money);
	printf("s_money=%d\n", s_money);
	return 0;
}

int useMoney(int money)
{
	return 0;
}