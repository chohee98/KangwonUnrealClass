#include <stdio.h>

void BuyItem(int* Money, int price)
{
	//int* Money는 메모리 복제가 일어나지 않는다.
	//메모리에 효율적인 관리, 데이터 참조가 편리하다.
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
		pPS->iPhoneCnt--; //포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
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

//Num을 받아서 화면에 출력한다.
void printNumber(const int* num)
{
	//num = nullptr; //포인터 주소 값을 변경할 수 있다.
	printf("print number=%d\n", *num);
}

void printNumber2(const int& num) //여기서 &는 참조 레퍼런스!
{
	//*num = 10 //불가. num을 변수로 받아서
	printf("print number2=%d\n", num);
}

void printPhoneShop(const stPhoneShop* ps)
{
	printf("print iPhoneCnt=%d\n", ps->iPhoneCnt); //포인터 참조는 화살표
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("print iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0; //4byte
	int b = 0;
	//포인터를 사용하는 이유
	// 메모리에 효율적인 관리, 데이터 참조의 편리
	// 예를 들어 구조체는 x64 플랫폼에서 8바이트씩 끊어서 메모리를 차지하는데 (메모리를 안에서 12바이트를 써도 16바이트를 쥐어줌)
	// 이런 구조체를 매개변수로 불러와서 수정을 하려면 메모리에 같은 크기로 복사를 해줘서 메모리의 낭비가 심함.
	// 그래서 나온것이 포인터. 포인터는 x64 플렛폼에서 8byte만큼만 차지하고 가리키는 역할을 하기 때문에 
	// 적은 양의 메모리로 구조체 값을 직접적으로 수정 가능.
	//int* pA : 포인터 변수의 선언(pA에 들어가 있는 주소에 int형의 크기 만큼 참조하겠다.)
	//nullptr: 포인터 변수의 초기화 값(주소값이 비어있음)
	//이전에는 NULL을 사용했는데 NULL=0을 의미 그래서 0이랑 의미가 동일해서 문제 발생
	//주소값이 비어있음이라는 명확한 의미를 가진 nullptr 사용
	//포인터 크기 (x32 플렛폼에서는 4byte, x64에서는 8byte)
	int* pA = nullptr;
	pA = &a;	//a주소값을 pA에 넣는다.
	// *: 레퍼런스 참조한다.(주소가 가르키고 있는 값을 참조한다.)
	b = *pA;	//b에 pA가 가르키고 있는 주소에 값을 넣는다.
	*pA = 10;	//pA가 가르키고 있는 주소에 값을 10으로 변경한다.
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
	//배열과 포인터
	int arrInt[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pInt = nullptr;
	pInt = arrInt;
	printf("pInt=%d\n", *pInt);
	pInt += 1; //다음 배열 포인터에 주소를 가리킨다.
	printf("pInt=%d\n", *pInt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pInt = (int*) arrS; //(int*)를 사용해서 int*로 강제로 형변환(Cast)한다.
	pInt += 1;	//pInt가 int*이므로 int(4byte)만큼 다음 주소 값을 참조한다.
	short* pS = (short*)pInt; //int(4byte)만큼 이동한 주소 값은 Short(2byte) 2번 이동한 값
	printf("pS=%d\n", *pS);

	//아래 배열을 낮은 숫자 순서대로 출력
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
				//lowestIndex와 j를 순서대로 비교
				//j index에 값이 낮으면 jsms 새로운 lowestIndex
				lowestIndex = j;
			}
			//for문지 종료되면 lowestindex에는 가장 낮은 수의 index 값이 저장
			//i는 순차적으로 돌면서 가장 낮은 수가 들어가야됨
			//lowestindex 값과 index에 값을 교체한다.
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

	//const 상수화
	//실수를 줄일 수 있어서 디버깅 횟수를 줄일 수 있다. (디버깅: 버그를 찾거나 수정하는 모든 행위)
	const int cint = 100; //상수

	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	//const int* pValue = &value;		//포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	//int const* pValue = &value;		//포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	//int* const pValue = &value;		//포인터가 가르키는 내용 수정 가능, 포인터 값 수정 불가, 참조 가능
	//const int* const pValue = &value; //포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
	//int const* const pValue = &value; //포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);

	printNumber(&value);
	printNumber2(value);

}