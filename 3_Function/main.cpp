#include <stdio.h>

//------------------------------------------Calculator
//함수형
//unsigned int : 반환 자료형
//CalculatorSum : 함수 이름
//(int x, int y) : 매개변수(파라메타)
unsigned int CalculatorSum(int x, int y)
{ //->함수 시작
	printf("함수 시작했다.\n");
	return x+y; //<-반환 및 종료 처리

	printf("함수 끝났다.\n");
} //->함수 끝

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

int ReFactorial(int Num) //재귀함수
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

int main()
{
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("함수 실행 결과 = %d\n", nResult);
	/*int x = 10, y = 3;
	printf("x+y=%d\n", CalculatorSum(x, y));
	printf("x-y=%d\n", CalculatorMinus(x, y));
	printf("x*y=%d\n", CalculatorMultiply(x, y));
	printf("x/y=%lf\n", CalculatorDivide(x, y));
	printf("x%%y=%d\n", CalculatorRemain(x, y));*/

	//반복문 for문
	//for (/*초기 설정*/int i = 0;/*반복 조건 체크*/i < 10;/*반복 후 처리*/i += 2)
	//{
	//	//반복 처리할 코드 시작
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

	////Factorial 함수 호출
	//int num = 3;
	//printf("%d! = %d\n", num, FactorialUp(num));

	//1~n까지 합 구하는 함수
	//int SumTo(int Num)
	int num = 5;
	printf("1~%d까지의 합 = %d\n", num, SumTo(num));


	return 0;
}