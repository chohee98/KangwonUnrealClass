#include <stdio.h>
#include <iostream>

int main()
{
	//2의 배수 출력하기(0~100)
	printf("2의 배수 출력하기\n");
	for (int i = 0; i <= 100/2; i++)
	{
		printf("%d ", 2 * i);
	} printf("\n\n");
	
	//n에 배수 출력하기 (숫자 하나 입력 받아서)
	int n = 0;
	printf("n의 배수 출력을 위한 숫자 하나를 입력: ");
	scanf_s("%d", &n);
	for (int i = 0; i <= 100/n; i++)
	{
		printf("%d ", n * i);
	} printf("\n\n");

	//(0~100) 2의 배수의 갯수 출력
	int cnt = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
			cnt++;
	} printf("(0~100) 2의 배수: %d개\n\n", cnt);

	//abcdef를 역으로 출력 fedcba
	wchar_t szWChar[20] = L"abcdef";
	for (int i = wcslen(szWChar); i >= 0; i--)
	{
		wprintf(L"%c", szWChar[i]);
	}printf("\n\n");

	//wchar_t 형으로 문자 입력 받기
	//"szWCharInput"이름을 가진 "wchar_t"변수형을 [20]의 크기로 생성하고
	//L"" 값을 초기값으로 넣는다.
	wchar_t szWCharInput[20] = L"";
	//wscanf_s는 입력을 받는 기능을 사용하겠다.
	//L"%ls" 변수 형태로 입력을 받는다.
	// "szWCharInput"변수에 입력한 값을 넣어주겠다
	// "(unsigned)_countof(szWCharInput)" 는 값을 넣을 변수에 크기
	//fflush(stdin);
	printf("문자를 입력하시오: ");
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	wprintf(L"szWCharInput=%s", szWCharInput);
	printf("\n\n");

	//입력 받은 문자열에서 'a'문자 갯수 출력
	cnt = 0;
	for (int i = 0; i < wcslen(szWCharInput); i++)
	{
		if(*(szWCharInput +i) == 'a')
			cnt++;
	}
	printf("개수: %d\n", cnt);

}