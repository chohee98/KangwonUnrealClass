#include <stdio.h>

//c++�� ������
//c++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ���� �� �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����

//1. ��ó��(Preprocessing) �ܰ� : #include�� #define�� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
//2. ������(Compile) �ܰ�: ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
//3. �����(Assemble) �ܰ�: ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
//4. ��ŷ(Linking) �ܰ�: ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�


//�޸� ����
//1. Code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
//2. Data ���� : ��������, Static �������� ����, ���μ����� ����� ������ �޸𸮿� ����
//3. Stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
//4. Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����. malloc() �Ǵ� new �����ڷ� �Ҵ�, free() �Ǵ� delete ������ڷ� ����
#include "money.h"
#include "calcFunc.h"

int g_money = 0; //���� ���� ��� �ڵ忡�� �ϳ��� �־��! (��ŷ �ܰ迡�� ����)
static int s_money = 0; //Static�� Data ������ ��ġ money.cpp�� �ִ� �Ͱ� ���� ���� �޸𸮿� ��ġ

//---------------------------------------����
int Add(int a, int b)
{
	printf("int�� Add ���\n");
	return a + b;
}

float Add(float a, float b)
{
	printf("float�� Add ���\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double�� Add ���\n");
	return a + b;
}

//---------------------------------------����ü
struct fruitShop
{
	int appleA;
	int mangoA;
	int strawberryA;

	fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
	{	}

	void SetFruitValue(int apple, int mango, int strawberry)
	{
		appleA = apple;
		mangoA = mango;
		strawberryA = strawberry;
	}

	void ShowShopValue()
	{
		printf("���ϰ��� ���� ���:%d, ����:%d, ����:%d \n", appleA, mangoA, strawberryA);
	}

};

struct PhoneShop
{
	int IPhone;
	int ZFlip;
	int GalaxyS23;
	int GalaxyFold;

	PhoneShop() : IPhone(0), ZFlip(0), GalaxyS23(0), GalaxyFold(0)
	{	}

	void SetPhonePrice(int mIPhone, int mZFlip, int mGalaxyS23, int mGalaxyFold)
	{
		IPhone = mIPhone;
		ZFlip = mZFlip;
		GalaxyS23 = mGalaxyS23;
		GalaxyFold = mGalaxyFold;
	}

	void ShowPhonePrice()
	{
		printf("������ IPhone : % d, ZFlip : % d, , GalaxyS23 : % d, GalaxyFold : % d \n", 
			IPhone, ZFlip, GalaxyS23, GalaxyFold);
	}

};

int main()
{
	/*addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	printf("main g_money=%d\n", g_money);
	printf("main s_money=%d\n", s_money);*/

	/*bool bRun = true;
	while (bRun)
	{
		int nInput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1:����, 2:���ϱ�, 3:������, 4:������, 5:����): ");
		scanf_s("%d", &nInput);
		switch (nInput)
		{
		case 0:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ���� %d �Դϴ�.\n", AddNum(num1, num2));
		} break;
		case 1:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ���� %d �Դϴ�.\n", MinusNum(num1, num2));
		} break;
		case 2:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ���� %d �Դϴ�.\n", MultiplyNum(num1, num2));
		} break;
		case 3:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������� %f �Դϴ�.\n", DivideNum(num1, num2));
		} break;
		case 4:
		{
			printf("���� 2���� �Է��ϼ���(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� �������� %d �Դϴ�.\n", RemainNum(num1, num2));
		} break;
		case 5:
		{
			printf("���⸦ �����Ͻðڽ��ϱ�?(0:No, 1:Yes): ");
			scanf_s("%d", &nInput);

			switch (nInput)
			{
			case 1:
				bRun = false;
				break;
			case 0:
				continue;
			default:
			{
				printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
			}break;
			}
		} break;
		default:
		{
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.");
		} break;
		}
		
	}*/

	////�Լ� �����ε�
	//Add(1, 1);
	//Add(1.0f, 1.0f); //f�� ���̰� �Ǽ��� ���� float��
	//Add(1.0, 1.0);	//f�� ������ �ʰ� �Ǽ��� ���� double��

	////�迭
	////int arrInt[10] = { 0 };	//���� 0���� �ʱ�ȭ
	////int arrInt[10] = { 0, };	//���� 0���� �ʱ�ȭ
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//arrInt[0] = 10;	//�迭 1��°�� �� �ֱ�
	//arrInt[9] = 90;	//0������ �迭�� ���� �ǹǷ� 10��°�� �ƴ϶� 9��°�� ������ �迭 ��ȣ

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d��° �迭 ���� %d�Դϴ�.\n", i, arrInt[i]); //2�� �̻��� �Ķ��Ÿ ��� ���
	//}
	int number = 0;
	for (int value : arrInt)	//for each�� ó������ �迭�� ũ������� for�� (�ϱ�!)
	{
		printf("for each %d��° �迭 ���� %d�Դϴ�.\n", number, value);
		number++;
	}

	//Struct ����ü ���
	//fruitShop: ������
	//shop: ������ �̸�
	fruitShop shop[3];
	
	//shop[0].appleA = 1000;
	//shop[0].mangoA = 2000;
	//shop[0].strawberryA = 3000;
	//Struct �Լ� ����
	shop[0].SetFruitValue(1000, 2000, 3000);
	shop[1].SetFruitValue(1100, 2100, 3100);
	shop[2].SetFruitValue(900, 1900, 2900);

	for (fruitShop stValue : shop)
	{
		stValue.ShowShopValue();
	}
	
	//Struct PhoneShop
	//int iPhone;
	//int zFlip;
	//int GalaxyS23;
	//int GalaxyFold;
	PhoneShop phone[3];
	phone[0].SetPhonePrice(100, 90, 80, 150);
	phone[1].SetPhonePrice(110, 100, 90, 160);
	phone[2].SetPhonePrice(90, 80, 70, 140);

	for (PhoneShop phValue : phone)
	{
		phValue.ShowPhonePrice();
	}
	

	return 0;
}