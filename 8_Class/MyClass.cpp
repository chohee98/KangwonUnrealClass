#include "MyClass.h"
#include <stdio.h>

//생성자
//클래스가 생성될 때 호출되는 함수
//선언 하지 않아도 기본 생성자가 존재
//생성자도 private면은 외부에 호출 불가. 반드시 public으로 선언
//생성자도 파라미터의 갯수와 타입에 따라 Overload(타입별 여러개 함수를 생성)할 수 있다.
//(int valueA = 0) 이런 방식으로 생성시 파라메타를 넣어줄 수 있다.
//:a(valueA), m_b(valueB), c(0) 이런 방식으로 생성 시 멤버변수에 초기값을 셋팅할 수 있다.
// 파라메타 변수의 형태가 입력 방식에 의해 선택이 불가능하면 문제가 발생한다.

//파괴자
//클래스가 파괴될 때 호출되는 함수
//선언하지 않아도 기본 파괴자가 존재
//파괴자도 public이 아니면 호출 불가능. 반드시 public으로 선언

CMyClass2::CMyClass2(int valueA) : a(valueA), m_b(0), c(0)
{
	printf("CMyClass2 생성자A가 호출됨.\n");
}

CMyClass2::CMyClass2(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
{
	printf("CMyClass2 생성자B가 호출됨.\n");
}

CMyClass2::~CMyClass2()
{
	printf("CMyClass2 파괴자가 호출됨.\n");
}

void CMyClass2::PrintB()
{
	printf("B=%d", m_b);
}

void CMyClass2::PrintAllValue()
{
	printf("A=%d, B=%d, C=%d\n", a, m_b, c);
}

void CMyClass2::SetC(int num)
{
	c = num;
}

