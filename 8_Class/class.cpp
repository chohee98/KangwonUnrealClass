#include <stdio.h>
#include "MyClass.h"

struct stMyStruct //변수형
{
	int a;

	stMyStruct() :a(0)
	{

	}
};

class CMyClass
{
	int m_b;
private:
	int c;
protected:
public:
	int a;


	CMyClass(int valueA=0) : a(valueA), m_b(0), c(0)
	{
		printf("생성자A가 호출됨.\n");
	}

	CMyClass(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
	{
		printf("생성자B가 호출됨.\n");
	}
	CMyClass(int valueA, int valueB, int valueC) : a(valueA), m_b(valueB), c(valueC)
	{
		printf("생성자C가 호출됨.\n");
	}
	~CMyClass()
	{
		printf("파괴자가 호출됨.\n");
	}

	void PrintB()
	{
		printf("B=%d", m_b);
	}

	void PrintAllValue()
	{
		printf("A=%d, B=%d, C=%d\n", a, m_b, c);
	}

	void SetC(int num)
	{
		//this : 클래스 안에 함수를 호출한 대상 객체를 의미함
		this->c = num;
	}
	//연산자 오버로딩
	//대입연산자 (기본적으로 생성됨)
	//const CMyClass& : 왼쪽으로 반환 될 변수형
	//operator= : 오버로딩 할 연산자
	//(const CMYClass& other) : 오른쪽에 입력될 변수
	const CMyClass& operator=(const CMyClass& other)
	{
		a = other.a;
		m_b = other.m_b;
		c = other.c;

		return *this;
	}

	//cMy3 = cMy + cMy2;
	//cMy3 = CMyClass(a + other.a, m_b + other.m_b, c + other.c); 
	const CMyClass& operator+(const CMyClass& other)
	{
		return CMyClass(a + other.a, m_b + other.m_b, c + other.c);
	}
};

int main()
{
	{
		//레퍼런스 참조
		//메모리가 복제가 되지 않고 원본을 참조하여 메모리를 효율적으로 사용하기 위한 연산자
		//특정 기능을 가지고 있으면 연산자라고 부름
		int num = 100;
		stMyStruct stTest;

		//포인터 참조는 포인터 변수의 주소 값을 참조한다.
		//포인터 변수의 주소값과 포인터가 가리키고 있는 주소값이 다르다.
		int* pNum = &num; //pNum 포인터 변수에는 num의 주소값이 들어간다. 즉, pNum은 num변수를 가리키고 있다.
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));

		//레퍼런스 참조는 원본 대상의 주소 값과 동일하다.
		int& refNum = num;
		stMyStruct& refTest = stTest;
		refTest.a = 0;
		printf("&refNum == &num ? %d\n", (int(&refNum) == int(&num)));
	}

	stMyStruct stMy;
	stMy.a = 0;

	CMyClass cMy(100);	//생성자 호출
	CMyClass cMy2(100, 200);
	printf("cMy.a=%d\n", cMy.a);
	cMy.a = 0;	
	cMy.SetC(0);	//특정 변수를 서정하기 위한 정수를 생성해서 개발하는 게 기본 규칙이다.
	//cMy.c = 100	//만약 변수가 Private로 되어있다면 개발자가 직접 접근하지 말라는 의도가 있다는 것
	cMy.PrintAllValue();
	cMy2.PrintAllValue();

	CMyClass2 aa;

	CMyClass cMy3;
	cMy.a = 1000;
	cMy.PrintAllValue();
	cMy2.PrintAllValue();
	cMy3 = cMy + cMy2;
	cMy3.PrintAllValue();


} //파괴자 호출