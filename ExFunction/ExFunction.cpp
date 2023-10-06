#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divid.h"

//함수 이름 : Sum
//매개 변수 (파라메타) : int a, int b
//반환값 : int
//a와 b를 합한 결과를 반환하시오

//함수 이름 : Minus
//매개 변수 (파라메타) : int a, int b
//반환값 : int
//a와 b를 빼기한 결과를 반환하시오

//함수 이름 : Multi
//매개 변수 (파라메타) : int a, int b
//반환값 : int
//a와 b를 곱하기한 결과를 반환하시오

//함수 이름 : Divid
//매개 변수 (파라메타) : int a, int b
//반환값 : float
//a와 b를 나누기한 결과를 반환하시오

//함수이름 Average
//파라메타 int &Sum, int a, int b, int c
//반환값 없음
//레퍼런스 변수 Sum으로 a, b, c에 평균 값을 반환

//함수이름 ArraySum
//파라메타 int* arr, int length
//반환값 : int
//배열 "arr"와 배열의 길이 "length"를 파라미터로 받아서 모든 배열의 합 반환

// 클래스 이름 : CShop
// 맴버 변수 : m_value(기본값:0)
// 맴버 함수 추가 : printValue
// printValue 함수 결과 : "Value=%d"로 m_value 출력

// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
// 생성자 파라메타 : int PhoneCnt ( m_PhoneCnt에 값 적용 )
// 생성자 파라메타 : int PhonePrice ( m_PhonePrice에 값 적용 )
// 맴버 변수 : m_PhoneCnt
// 맴버 변수 : m_PhonePrice
// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력

// 클래스 이름 : CFruitShop
// 생성자 파라메타 : int FruitCnt ( m_FruitCnt에 값 적용 )
// 생성자 파라메타 : int FruitPrice ( m_FruitPrice에 값 적용 )
// 부모 클래스 : CShop
// 맴버 변수 : m_FruitCnt
// 맴버 변수 : m_FruitPrice
// printValue 함수 결과 : "Value=%d"로 m_FruitCnt * m_FruitPrice출력



void Average(int& Sum, int a, int b, int c)
{
	Sum = (a + b + c) / 3;
	
}

int ArraySum(int* arr, int length)
{
	int temp = 0;
	for (int i = 0; i < length; i++)
		temp += *(arr + i);
	return temp;
}

class CShop
{
public:
	int m_value = 0;
public:
	void printValue()
	{
		printf("Value=%d\n", m_value);
	}

};

class CPhoneShop : public CShop
{
public:
	int m_PhoneCnt;
	int m_PhonePrice;
public:
	CPhoneShop(int PhoneCnt, int PhonePrice) : m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{	}
	void printValue()
	{
		printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
	}
	~CPhoneShop()
	{ }
};

class CFruitShop : public CShop
{
public:
	int m_FruitCnt;
	int m_FruitPrice;
public:
	CFruitShop(int FruitCnt, int FruitPrice) : m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{ }
	void printValue()
	{
		printf("Value=%d\n", m_FruitCnt * m_FruitPrice);
	}
	~CFruitShop()
	{ }

};

int main()
{
	int x = 5, y = 2, z = 2;
	int sum=0;
	int Arr[3] = { 1, 2, 3 };
	printf("Sum = %d\n", Sum(x, y));
	printf("Minus = %d\n", Minus(x, y));
	printf("Multi = %d\n", Multi(x, y));
	printf("Divid = %f\n", Divid(x, y));

	Average(sum, x, y, z);
	printf("Average = %d\n", sum);
	printf("ArraySum = %d\n", ArraySum(Arr, 3));

	CPhoneShop phone(10, 100);
	phone.printValue();
	CFruitShop fruit(10, 100);
	fruit.printValue();
}