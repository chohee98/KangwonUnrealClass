#include "money.h"
#include <stdio.h>

//int g_money = 0; //전역 변수 모든 코드에서 하나만 있어야! (링킹 단계에서 오류)
static int s_money = 0;

extern int g_money; //변수를 만드는게 아니라! "어디선가 만든" 변수를 가져다 쓰는 역할 (미리 알려줌)

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