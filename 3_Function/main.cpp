#include <stdio.h>

//------------------------------------------Calculator
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

double CalculatorDivide(int x, int y)
{
	return (double)x / y;
}

int CalculatorRemain(int x, int y)
{
	return x % y;
}

//------------------------------------------Factorial

int FactorialDown(int Num)
{
	int FacResult = 1;
	for (int i = Num; i > 0; --i)
	{
		FacResult *= i;
	}

	return FacResult;
}

int FactorialUp(int Num)
{
	int FacResult = 1;
	for (int i = 1; i <= Num; ++i)
	{
		FacResult *= i;
	}

	return FacResult;
}

int ReFactorial(int Num) //����Լ�
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1);
}

int SumTo(int Num)
{
	int Sum = 0;
	for (int i = 1; i <= Num; ++i)
	{
		Sum += i;
	}
	return Sum;
}

int AAA()
{
	while (1)
	{
		printf("1st While! Start\n");
		break;
		printf("1st While! End\n");
	}
	while (1)
	{
		printf("2st While! Start\n");
		return 0;	//while���� �ƴ� �Լ� ��ü�� ����
		printf("2st While! End\n");
	}
	while (1)
	{
		printf("3st While! Start\n");
		break;
		printf("3st While! End\n");
	}
	return 0;
}

int main()
{
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("�Լ� ���� ��� = %d\n", nResult);
	/*int x = 10, y = 3;
	printf("x+y=%d\n", CalculatorSum(x, y));
	printf("x-y=%d\n", CalculatorMinus(x, y));
	printf("x*y=%d\n", CalculatorMultiply(x, y));
	printf("x/y=%lf\n", CalculatorDivide(x, y));
	printf("x%%y=%d\n", CalculatorRemain(x, y));*/

	//�ݺ��� for��
	//for (/*�ʱ� ����*/int i = 0;/*�ݺ� ���� üũ*/i < 10;/*�ݺ� �� ó��*/i += 2)
	//{
	//	//�ݺ� ó���� �ڵ� ����
	//	printf("%d\n", i);
	//}

	////Factorial 5!
	//int FacResult = 1;
	//int num = 3;
	//for (int i = 1; i <= num; ++i)
	//{
	//	FacResult *= i;
	//}
	//printf("%d! = %d\n", num, FacResult);
	//FacResult = 1;
	//int FacNum = 4;
	//for (int i = FacNum; i > 0; --i)
	//{
	//	FacResult *= i;
	//}
	//printf("%d! = %d\n", FacNum, FacResult);

	////Factorial �Լ� ȣ��
	//int num = 3;
	//printf("%d! = %d\n", num, FactorialUp(num));

	//1~n���� �� ���ϴ� �Լ�
	//int SumTo(int Num)
	//int num = 5;
	//printf("1~%d������ �� = %d\n", num, SumTo(num));


	////while ��
	////���ǽ��� ���̸� �Ʒ� ���� �ȿ� �ڵ带 �����Ѵ�.
	////���ǽ��� �����̸� while���� �����ϰ� ���� �ڵ� ����.
	//int nResult = 1;
	//int i = 1;
	//while (true /*���ǽ�*/)
	//{
	//	printf("i=%d\n", i);
	//	i++;
	//	printf("break ������\n");
	//	break;//�� ��ɾ ������ while ��� �����Ѵ�. �Ʒ� �ڵ� ���� �ȵ�.
	//	printf("break ������\n");
	//}

	////0~Num���� ¦���� ���ϱ�
	//int i = 0, Num = 10;
	//int nResult = 0;
	//while (i <= Num)
	//{
	//	i++;
	//	if (i % 2 != 0)
	//		continue;
	//	
	//	nResult += i;
	//}
	//printf("0~Num EvenSum=%d", nResult);

	/*int nResult = 0, Num = 10;
	for (int i = 0; i <= Num; i++)
	{
		if (i % 2 == 0)
			nResult += i;
	}
	printf("0~Num EvenSum=%d", nResult);*/

	//AAA();


	return 0;
}