#include <stdio.h>

void BuyItem(int* Money, int price)
{
	//int* Money�� �޸� ������ �Ͼ�� �ʴ´�.
	//�޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	*Money -= price;
}

enum ePhoneType {	iphone, Galaxys23, GalaxyFold, GalaxyZ	};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;

	void printPhoneCnt()
	{
		printf("iPhone=%d,Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d\n",
			iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};


void BuyPhone(int phoneType, stPhoneShop* pPS)
{
	switch (phoneType)
	{
	case ePhoneType::iphone:
		pPS->iPhoneCnt--; //����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case ePhoneType::Galaxys23:
		pPS->Galaxys23--;
		break;
	case ePhoneType::GalaxyFold:
		pPS->GalaxyFold--;
		break;
	case ePhoneType::GalaxyZ:
		pPS->GalaxyZ--;
		break;
	default:
		break;
	}
}

//Num�� �޾Ƽ� ȭ�鿡 ����Ѵ�.
void printNumber(const int* num)
{
	//num = nullptr; //������ �ּ� ���� ������ �� �ִ�.
	printf("print number=%d\n", *num);
}

void printNumber2(const int& num) //���⼭ &�� ���� ���۷���!
{
	//*num = 10 //�Ұ�. num�� ������ �޾Ƽ�
	printf("print number2=%d\n", num);
}

void printPhoneShop(const stPhoneShop* ps)
{
	printf("print iPhoneCnt=%d\n", ps->iPhoneCnt); //������ ������ ȭ��ǥ
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("print iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0; //4byte
	int b = 0;
	//�����͸� ����ϴ� ����
	// �޸𸮿� ȿ������ ����, ������ ������ ��
	// ���� ��� ����ü�� x64 �÷������� 8����Ʈ�� ��� �޸𸮸� �����ϴµ� (�޸𸮸� �ȿ��� 12����Ʈ�� �ᵵ 16����Ʈ�� �����)
	// �̷� ����ü�� �Ű������� �ҷ��ͼ� ������ �Ϸ��� �޸𸮿� ���� ũ��� ���縦 ���༭ �޸��� ���� ����.
	// �׷��� ���°��� ������. �����ʹ� x64 �÷������� 8byte��ŭ�� �����ϰ� ����Ű�� ������ �ϱ� ������ 
	// ���� ���� �޸𸮷� ����ü ���� ���������� ���� ����.
	//int* pA : ������ ������ ����(pA�� �� �ִ� �ּҿ� int���� ũ�� ��ŭ �����ϰڴ�.)
	//nullptr: ������ ������ �ʱ�ȭ ��(�ּҰ��� �������)
	//�������� NULL�� ����ߴµ� NULL=0�� �ǹ� �׷��� 0�̶� �ǹ̰� �����ؼ� ���� �߻�
	//�ּҰ��� ��������̶�� ��Ȯ�� �ǹ̸� ���� nullptr ���
	//������ ũ�� (x32 �÷��������� 4byte, x64������ 8byte)
	int* pA = nullptr;
	pA = &a;	//a�ּҰ��� pA�� �ִ´�.
	// *: ���۷��� �����Ѵ�.(�ּҰ� ����Ű�� �ִ� ���� �����Ѵ�.)
	b = *pA;	//b�� pA�� ����Ű�� �ִ� �ּҿ� ���� �ִ´�.
	*pA = 10;	//pA�� ����Ű�� �ִ� �ּҿ� ���� 10���� �����Ѵ�.
	printf("%d", *(&a));

	int Money = 10000;
	BuyItem(&Money, 1000);
	printf("Money=%d\n", Money);

	stPhoneShop stPS;
	stPS.iPhoneCnt = 100;
	stPS.Galaxys23 = 100;
	stPS.GalaxyFold = 100;
	stPS.GalaxyZ = 100;

	BuyPhone(GalaxyFold, &stPS);
	stPS.printPhoneCnt();

	//--------------------------------------------------------------------------
	//�迭�� ������
	int arrInt[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pInt = nullptr;
	pInt = arrInt;
	printf("pInt=%d\n", *pInt);
	pInt += 1; //���� �迭 �����Ϳ� �ּҸ� ����Ų��.
	printf("pInt=%d\n", *pInt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pInt = (int*) arrS; //(int*)�� ����ؼ� int*�� ������ ����ȯ(Cast)�Ѵ�.
	pInt += 1;	//pInt�� int*�̹Ƿ� int(4byte)��ŭ ���� �ּ� ���� �����Ѵ�.
	short* pS = (short*)pInt; //int(4byte)��ŭ �̵��� �ּ� ���� Short(2byte) 2�� �̵��� ��
	printf("pS=%d\n", *pS);

	//�Ʒ� �迭�� ���� ���� ������� ���
	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				int num = arr[i];
				arr[i] = arr[j];
				arr[j] = num;
			}
		}
	}*/

	for (int i = 0; i < 10; i++)
	{
		int lowestIndex = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[lowestIndex] > arr[j])
			{
				//lowestIndex�� j�� ������� ��
				//j index�� ���� ������ jsms ���ο� lowestIndex
				lowestIndex = j;
			}
			//for���� ����Ǹ� lowestindex���� ���� ���� ���� index ���� ����
			//i�� ���������� ���鼭 ���� ���� ���� ���ߵ�
			//lowestindex ���� index�� ���� ��ü�Ѵ�.
			int temp = arr[i];
			arr[i] = arr[lowestIndex];
			arr[lowestIndex] = temp;
		}
	}

	for (int a : arr)
	{
		printf("%d ", a);
	}
	printf("\n");

	//const ���ȭ
	//�Ǽ��� ���� �� �־ ����� Ƚ���� ���� �� �ִ�. (�����: ���׸� ã�ų� �����ϴ� ��� ����)
	const int cint = 100; //���

	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	//const int* pValue = &value;		//�����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	//int const* pValue = &value;		//�����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� ����, ���� ����
	//int* const pValue = &value;		//�����Ͱ� ����Ű�� ���� ���� ����, ������ �� ���� �Ұ�, ���� ����
	//const int* const pValue = &value; //�����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����
	//int const* const pValue = &value; //�����Ͱ� ����Ű�� ���� ���� �Ұ�, ������ �� ���� �Ұ�, ���� ����

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);

	printNumber(&value);
	printNumber2(value);

}