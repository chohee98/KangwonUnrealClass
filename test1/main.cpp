#include <stdio.h>
#include <iostream>

int main()
{
	//2�� ��� ����ϱ�(0~100)
	printf("2�� ��� ����ϱ�\n");
	for (int i = 0; i <= 100/2; i++)
	{
		printf("%d ", 2 * i);
	} printf("\n\n");
	
	//n�� ��� ����ϱ� (���� �ϳ� �Է� �޾Ƽ�)
	int n = 0;
	printf("n�� ��� ����� ���� ���� �ϳ��� �Է�: ");
	scanf_s("%d", &n);
	for (int i = 0; i <= 100/n; i++)
	{
		printf("%d ", n * i);
	} printf("\n\n");

	//(0~100) 2�� ����� ���� ���
	int cnt = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)
			cnt++;
	} printf("(0~100) 2�� ���: %d��\n\n", cnt);

	//abcdef�� ������ ��� fedcba
	wchar_t szWChar[20] = L"abcdef";
	for (int i = wcslen(szWChar); i >= 0; i--)
	{
		wprintf(L"%c", szWChar[i]);
	}printf("\n\n");

	//wchar_t ������ ���� �Է� �ޱ�
	//"szWCharInput"�̸��� ���� "wchar_t"�������� [20]�� ũ��� �����ϰ�
	//L"" ���� �ʱⰪ���� �ִ´�.
	wchar_t szWCharInput[20] = L"";
	//wscanf_s�� �Է��� �޴� ����� ����ϰڴ�.
	//L"%ls" ���� ���·� �Է��� �޴´�.
	// "szWCharInput"������ �Է��� ���� �־��ְڴ�
	// "(unsigned)_countof(szWCharInput)" �� ���� ���� ������ ũ��
	//fflush(stdin);
	printf("���ڸ� �Է��Ͻÿ�: ");
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	wprintf(L"szWCharInput=%s", szWCharInput);
	printf("\n\n");

	//�Է� ���� ���ڿ����� 'a'���� ���� ���
	cnt = 0;
	for (int i = 0; i < wcslen(szWCharInput); i++)
	{
		if(*(szWCharInput +i) == 'a')
			cnt++;
	}
	printf("����: %d\n", cnt);

}