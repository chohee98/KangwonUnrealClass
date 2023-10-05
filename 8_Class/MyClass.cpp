#include "MyClass.h"
#include <stdio.h>

//������
//Ŭ������ ������ �� ȣ��Ǵ� �Լ�
//���� ���� �ʾƵ� �⺻ �����ڰ� ����
//�����ڵ� private���� �ܺο� ȣ�� �Ұ�. �ݵ�� public���� ����
//�����ڵ� �Ķ������ ������ Ÿ�Կ� ���� Overload(Ÿ�Ժ� ������ �Լ��� ����)�� �� �ִ�.
//(int valueA = 0) �̷� ������� ������ �Ķ��Ÿ�� �־��� �� �ִ�.
//:a(valueA), m_b(valueB), c(0) �̷� ������� ���� �� ��������� �ʱⰪ�� ������ �� �ִ�.
// �Ķ��Ÿ ������ ���°� �Է� ��Ŀ� ���� ������ �Ұ����ϸ� ������ �߻��Ѵ�.

//�ı���
//Ŭ������ �ı��� �� ȣ��Ǵ� �Լ�
//�������� �ʾƵ� �⺻ �ı��ڰ� ����
//�ı��ڵ� public�� �ƴϸ� ȣ�� �Ұ���. �ݵ�� public���� ����

CMyClass2::CMyClass2(int valueA) : a(valueA), m_b(0), c(0)
{
	printf("CMyClass2 ������A�� ȣ���.\n");
}

CMyClass2::CMyClass2(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
{
	printf("CMyClass2 ������B�� ȣ���.\n");
}

CMyClass2::~CMyClass2()
{
	printf("CMyClass2 �ı��ڰ� ȣ���.\n");
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

