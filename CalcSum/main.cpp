#include <stdio.h>
#include "calcFunc.h"

int main()
{	
	bool bRun = true;
	while (bRun)
	{
		int nInput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1:����, 2:���ϱ�, 3:������, 4:������): ");
		scanf_s("%d", &nInput);
		printf("���� 2���� �Է��ϼ���(num1 num2): ");
		scanf_s("%d %d", &num1, &num2);
		switch (nInput)
		{
		case 0:
		{
			printf("�� ���� ���� %d �Դϴ�.\n", AddNum(num1, num2));
		} break;
		case 1:
		{
			printf("�� ���� ���� %d �Դϴ�.\n", MinusNum(num1, num2));
		} break;
		case 2:
		{
			printf("�� ���� ���� %d �Դϴ�.\n", MultiplyNum(num1, num2));
		} break;
		case 3:
		{
			printf("�� ���� ������� %f �Դϴ�.\n", DivideNum(num1, num2));
		} break;
		case 4:
		{
			printf("�� ���� �������� %d �Դϴ�.\n", RemainNum(num1, num2));
		} break;

		default:
			break;
		}

		printf("���⸦ �����Ͻðڽ��ϱ�?(0:No, 1:Yes): ");
		scanf_s("%d", &nInput);

		switch (nInput)
		{
		case 1:
			bRun = false;
			break;
		}
	}

	return 0;
}