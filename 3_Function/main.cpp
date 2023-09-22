#include <stdio.h>

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
	//printf("함수 실행 결과 = %d\n", nResult);
	int x = 10, y = 3;
	printf("x+y=%d\n", CalculatorSum(x, y));
	printf("x-y=%d\n", CalculatorMinus(x, y));
	printf("x*y=%d\n", CalculatorMultiply(x, y));
	printf("x/y=%lf\n", CalculatorDivide(x, y));
	printf("x%%y=%d\n", CalculatorRemain(x, y));
	return 0;
}