#pragma once

//Class(변수, 자료형)
//Class는 사용자 정의 Type이라고 한다.
//C의 struct에 확장된 개념
//C++의 클래스는 세 가지 엑세스(접근) 지정자(private, protected, public)에 의해
//엑세스가 제어되는 멤버로 데이터 및 함수가 있는 사용자 정의 유형 또는 데이터 구조를 만든다.
//엑세스 지정자를 사용하여 데이터 및 함수를 만드는 걸 캡슐화라고도 한다.
//Class를 한글로 번역하면 형틀이라는 뜻, 사용 가능한 객체가 아님.
//객체를 생성하기 위한 모양을 나타낸다.

//객체(Object)
//Class를 사용해서 생성된걸 객체라고 한다.
//Class에 선언한 변수들이 생성되고 메모리에서 공간을 차지함

//객체 지향 프로그래밍
//객체 지향 프로그래밍은 컴퓨터 프로그램을 명령어의 목록으로 보는 시각에서 벗어나 여러 개의 독립된 단위
//즉, "객체"들의 모음으로 구조를 만들고 하는 패러다임
//각각의 객체는 메시지를 주고 받고, 데이터를 독립적으로 처리할 수 있다.
class CMyClass2	//변수형
{
	//접근지정자
	//private: 외부에서 접근 불가
	//protected: 상속관계일 때 접근이 가능, 이외에는 접근 불가
	//public: 어디서든 접근 가능
	//위에 접근 지정자가 없으면 기본적으로 private
	//클래스 안에 선언된 변수를 멤버 변수라고 한다. (개발자들은 형식적으로 멤버변수라는걸 표시하기 위해 m_를 붙이기도 한다.)
	int m_b;	
private:
	int c;
protected:
public:
	int a;
	CMyClass2(int valueA = 0);
	CMyClass2(int valueA, int valueB);
	~CMyClass2();
	void PrintB();
	void SetC(int num);
	void PrintAllValue();
};
