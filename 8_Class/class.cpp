#include <stdio.h>
#include "MyClass.h"

struct stMyStruct //������
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
		printf("������A�� ȣ���.\n");
	}

	CMyClass(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
	{
		printf("������B�� ȣ���.\n");
	}
	CMyClass(int valueA, int valueB, int valueC) : a(valueA), m_b(valueB), c(valueC)
	{
		printf("������C�� ȣ���.\n");
	}
	~CMyClass()
	{
		printf("�ı��ڰ� ȣ���.\n");
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
		//this : Ŭ���� �ȿ� �Լ��� ȣ���� ��� ��ü�� �ǹ���
		this->c = num;
	}
	//������ �����ε�
	//���Կ����� (�⺻������ ������)
	//const CMyClass& : �������� ��ȯ �� ������
	//operator= : �����ε� �� ������
	//(const CMYClass& other) : �����ʿ� �Էµ� ����
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
		//���۷��� ����
		//�޸𸮰� ������ ���� �ʰ� ������ �����Ͽ� �޸𸮸� ȿ�������� ����ϱ� ���� ������
		//Ư�� ����� ������ ������ �����ڶ�� �θ�
		int num = 100;
		stMyStruct stTest;

		//������ ������ ������ ������ �ּ� ���� �����Ѵ�.
		//������ ������ �ּҰ��� �����Ͱ� ����Ű�� �ִ� �ּҰ��� �ٸ���.
		int* pNum = &num; //pNum ������ �������� num�� �ּҰ��� ����. ��, pNum�� num������ ����Ű�� �ִ�.
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));

		//���۷��� ������ ���� ����� �ּ� ���� �����ϴ�.
		int& refNum = num;
		stMyStruct& refTest = stTest;
		refTest.a = 0;
		printf("&refNum == &num ? %d\n", (int(&refNum) == int(&num)));
	}

	stMyStruct stMy;
	stMy.a = 0;

	CMyClass cMy(100);	//������ ȣ��
	CMyClass cMy2(100, 200);
	printf("cMy.a=%d\n", cMy.a);
	cMy.a = 0;	
	cMy.SetC(0);	//Ư�� ������ �����ϱ� ���� ������ �����ؼ� �����ϴ� �� �⺻ ��Ģ�̴�.
	//cMy.c = 100	//���� ������ Private�� �Ǿ��ִٸ� �����ڰ� ���� �������� ����� �ǵ��� �ִٴ� ��
	cMy.PrintAllValue();
	cMy2.PrintAllValue();

	CMyClass2 aa;

	CMyClass cMy3;
	cMy.a = 1000;
	cMy.PrintAllValue();
	cMy2.PrintAllValue();
	cMy3 = cMy + cMy2;
	cMy3.PrintAllValue();


} //�ı��� ȣ��