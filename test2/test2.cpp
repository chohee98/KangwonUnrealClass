#include <stdio.h>
#include <cmath>

float standardWeight(float height)
{
	return (height - 100) * 0.9;
}

float GetBMI(float weight, float standardWeight)
{
	return  (weight - standardWeight) * 100 / standardWeight;
}


int main()
{
	/*int num1 = 0, num2 = 0, result = 0;
	printf("���ڸ� �ϳ� �Է��ϼ���: ");
	scanf_s("%d", &num1);
	printf("���ڸ� �ϳ� �� �Է��ϼ���: ");
	scanf_s("%d", &num2);

	for (int i = num1; i <= num2; i++)
	{
		result += i;
	}

	printf("������ ��� ���� ���� result = %d", result);*/


	/*int num;
	int arrnum[6] = {0, };
	bool bRun = true;

	printf("�ֹι�ȣ�� �Է��Ͻÿ�. ");
	scanf_s("%d", &num); //980320


	int j = 2;
	for (int i = 3; i < 2; i++)
	{
		arrnum[i] = num % (int)pow(10,j);
		j-=2;
		printf("%d", arrnum[i]);
	}

	while (bRun)
	{

	}
	return 0;*/



	/*while (1)
	{
		int type = 0, money = 0, per = 0;
		printf("�ҵ漼�� ����Ͻðڽ��ϱ�? 0)NO 1)Yes ");
		scanf_s("%d", &type);

		if (type == 0)	break;

		printf("���� �� �ҵ��� �Է��ϼ���(�� ����) : ");
		scanf_s("%d", &money);

		if (money > 100000)
			per = 45;
		else if (money > 50000)
			per = 42;
		else if (money > 30000)
			per = 40;
		else if (money > 15000)
			per = 38;
		else if (money > 8800)
			per = 35;
		else if (money > 4600)
			per = 24;
		else if (money > 1200)
			per = 15;
		else
			per = 6;
		printf("����� �ҵ漼�� %d �Դϴ�.\n", per);
	}*/


	bool bRun = true;

	while (bRun)
	{
		int type = 0;
		float weight = 0, height = 0, bmi = 0;
		printf("BMI�� ����Ͻðڽ��ϱ�? 0)NO 1)Yes ");
		scanf_s("%d", &type);

		switch (type)
		{
		case 0:
			bRun = false;
			break;
		case 1:
			printf("�����Ը� �Է����ּ���: ");
			scanf_s("%f", &weight);
			printf("Ű�� �Է����ּ���: ");
			scanf_s("%f", &height);

			bmi = GetBMI(weight, standardWeight(height));
			printf("bmi = %f\n", bmi);

			if (bmi > 20)
				printf("��\n");
			else if (bmi > 10)
				printf("��ü��\n");
			else
				printf("����\n");
			break;
		default:
			break;
		}

	}
}