#include <stdio.h>

//c++의 컴파일
//c++에서 사람이 작성한 소스코드를 컴퓨터가 읽을 수 있는 코드로 변환하여 실행할 수 있는 파일로 변환하는 과정

//1. 전처리(Preprocessing) 단계 : #include와 #define과 같은 전처리기 매크로들을 처리하는 단계
//2. 컴파일(Compile) 단계: 각각의 소스 파일들을 어셈블리 명령어로 변환
//3. 어셈블(Assemble) 단계: 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
//4. 링킹(Linking) 단계: 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계


//메모리 영역
//1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
//2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될 때까지 메모리에 저장
//3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
//4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역. malloc() 또는 new 연산자로 할당, free() 또는 delete ㅇ녀산자로 해제
#include "money.h"
#include "calcFunc.h"

int g_money = 0; //전역 변수 모든 코드에서 하나만 있어야! (링킹 단계에서 오류)
static int s_money = 0; //Static은 Data 영역에 위치 money.cpp애 있는 것과 완전 별도 메모리에 위치

//---------------------------------------계산기
int Add(int a, int b)
{
	printf("int형 Add 사용\n");
	return a + b;
}

float Add(float a, float b)
{
	printf("float형 Add 사용\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double형 Add 사용\n");
	return a + b;
}

//---------------------------------------구조체
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
		printf("과일가게 가격 사과:%d, 망고:%d, 딸기:%d \n", appleA, mangoA, strawberryA);
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
		printf("폰가격 IPhone : % d, ZFlip : % d, , GalaxyS23 : % d, GalaxyFold : % d \n", 
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

		printf("어떤 연산을 하시겠습니까?(0:더하기, 1:빼기, 2:곱하기, 3:나누기, 4:나머지, 5:종료): ");
		scanf_s("%d", &nInput);
		switch (nInput)
		{
		case 0:
		{
			printf("숫자 2개를 입력하세요(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 합은 %d 입니다.\n", AddNum(num1, num2));
		} break;
		case 1:
		{
			printf("숫자 2개를 입력하세요(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 차는 %d 입니다.\n", MinusNum(num1, num2));
		} break;
		case 2:
		{
			printf("숫자 2개를 입력하세요(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 곱는 %d 입니다.\n", MultiplyNum(num1, num2));
		} break;
		case 3:
		{
			printf("숫자 2개를 입력하세요(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 나누기는 %f 입니다.\n", DivideNum(num1, num2));
		} break;
		case 4:
		{
			printf("숫자 2개를 입력하세요(num1 num2): ");
			scanf_s("%d %d", &num1, &num2);
			printf("두 수의 나머지는 %d 입니다.\n", RemainNum(num1, num2));
		} break;
		case 5:
		{
			printf("계산기를 종료하시겠습니까?(0:No, 1:Yes): ");
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
				printf("잘못된 숫자입니다. 다시 입력해주세요.\n");
			}break;
			}
		} break;
		default:
		{
			printf("잘못된 숫자입니다. 다시 입력해주세요.");
		} break;
		}
		
	}*/

	////함수 오버로딩
	//Add(1, 1);
	//Add(1.0f, 1.0f); //f를 붙이고 실수를 쓰면 float형
	//Add(1.0, 1.0);	//f를 붙이지 않고 실수를 쓰면 double형

	////배열
	////int arrInt[10] = { 0 };	//전부 0으로 초기화
	////int arrInt[10] = { 0, };	//전부 0으로 초기화
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//arrInt[0] = 10;	//배열 1번째에 값 넣기
	//arrInt[9] = 90;	//0번부터 배열이 시작 되므로 10번째가 아니라 9번째가 마지막 배열 번호

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d번째 배열 값은 %d입니다.\n", i, arrInt[i]); //2개 이상의 파라메타 출력 방법
	//}
	int number = 0;
	for (int value : arrInt)	//for each는 처음부터 배열의 크기까지의 for문 (암기!)
	{
		printf("for each %d번째 배열 값은 %d입니다.\n", number, value);
		number++;
	}

	//Struct 구조체 사용
	//fruitShop: 변수형
	//shop: 변수의 이름
	fruitShop shop[3];
	
	//shop[0].appleA = 1000;
	//shop[0].mangoA = 2000;
	//shop[0].strawberryA = 3000;
	//Struct 함수 사용법
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