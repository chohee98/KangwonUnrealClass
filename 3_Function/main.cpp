#include <stdio.h>

//�Լ���
//unsigned int : ��ȯ �ڷ���
//CalculatorSum : �Լ� �̸�
//(int x, int y) : �Ű�����(�Ķ��Ÿ)
unsigned int CalculatorSum(int x, int y)
{ //->�Լ� ����
	printf("�Լ� �����ߴ�.\n");
	return x+y; //<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
} //->�Լ� ��

int CalculatorMinus(int x, int y)
{
	return x - y;
}

int CalculatorMultiply(int x, int y)
{
	return x * y;
}

double CalculatorDivide(double x, double y)
{
	return x / y;
}

int CalculatorRemain(int x, int y)
{
	return x % y;
}

int main()
{
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("�Լ� ���� ��� = %d\n", nResult);
	int x = 10, y = 3;
	printf("x+y=%d\n", CalculatorSum(x, y));
	printf("x-y=%d\n", CalculatorMinus(x, y));
	printf("x*y=%d\n", CalculatorMultiply(x, y));
	printf("x/y=%lf\n", CalculatorDivide(x, y));
	printf("x%%y=%d\n", CalculatorRemain(x, y));
	return 0;
}