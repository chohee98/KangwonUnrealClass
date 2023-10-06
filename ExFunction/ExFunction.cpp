#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divid.h"

//�Լ� �̸� : Sum
//�Ű� ���� (�Ķ��Ÿ) : int a, int b
//��ȯ�� : int
//a�� b�� ���� ����� ��ȯ�Ͻÿ�

//�Լ� �̸� : Minus
//�Ű� ���� (�Ķ��Ÿ) : int a, int b
//��ȯ�� : int
//a�� b�� ������ ����� ��ȯ�Ͻÿ�

//�Լ� �̸� : Multi
//�Ű� ���� (�Ķ��Ÿ) : int a, int b
//��ȯ�� : int
//a�� b�� ���ϱ��� ����� ��ȯ�Ͻÿ�

//�Լ� �̸� : Divid
//�Ű� ���� (�Ķ��Ÿ) : int a, int b
//��ȯ�� : float
//a�� b�� �������� ����� ��ȯ�Ͻÿ�

//�Լ��̸� Average
//�Ķ��Ÿ int &Sum, int a, int b, int c
//��ȯ�� ����
//���۷��� ���� Sum���� a, b, c�� ��� ���� ��ȯ

//�Լ��̸� ArraySum
//�Ķ��Ÿ int* arr, int length
//��ȯ�� : int
//�迭 "arr"�� �迭�� ���� "length"�� �Ķ���ͷ� �޾Ƽ� ��� �迭�� �� ��ȯ

// Ŭ���� �̸� : CShop
// �ɹ� ���� : m_value(�⺻��:0)
// �ɹ� �Լ� �߰� : printValue
// printValue �Լ� ��� : "Value=%d"�� m_value ���

// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
// ������ �Ķ��Ÿ : int PhoneCnt ( m_PhoneCnt�� �� ���� )
// ������ �Ķ��Ÿ : int PhonePrice ( m_PhonePrice�� �� ���� )
// �ɹ� ���� : m_PhoneCnt
// �ɹ� ���� : m_PhonePrice
// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���

// Ŭ���� �̸� : CFruitShop
// ������ �Ķ��Ÿ : int FruitCnt ( m_FruitCnt�� �� ���� )
// ������ �Ķ��Ÿ : int FruitPrice ( m_FruitPrice�� �� ���� )
// �θ� Ŭ���� : CShop
// �ɹ� ���� : m_FruitCnt
// �ɹ� ���� : m_FruitPrice
// printValue �Լ� ��� : "Value=%d"�� m_FruitCnt * m_FruitPrice���



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