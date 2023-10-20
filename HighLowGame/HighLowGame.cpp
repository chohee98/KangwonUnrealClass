#include <stdio.h>
#include <vector>
#include <string>
#include <random>
#include "Card.h"

/*
1. 52���� ī������ ������ �մϴ�.
2. 52���� ī�带 �������� �����ϴ�.
3. ������ ���۵Ǹ� ī�� �ϳ��� ���� �մϴ�.
4. �÷��̾�� ����ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���� ������ �մϴ�.
5. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
6. ī�带 1�� ���� ���� K�� ���� �����ϴ�. ���� ���ڶ�� ���� ������ ī�尡 �¸��մϴ�.
7. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ �����ϴ�.
*/


void Shuffle(std::vector<CCard>& Cards)
{
	std::random_device rd;
	// 1234�� �õ�(seed)���̶�� �ؼ� �ʱ⿡ �־����� Ű��
	// ���� �õ���� ���� ���ڰ� ���ϰ� ���´�.
	// std::mt19937 mt(1234); 
	std::mt19937 mt(rd.entropy());// �õ� ���� �������� �ο��ؼ� ���� ���� ����� ������ �ʴ´�. mt19937:���� ����(��û ū ��)
	std::uniform_int_distribution<int> dist(0, Cards.size() - 1); // 0���� ī���-1���� ������ ���� �� ���� 


	for (int i = 0; i < 200; i++)	//����(100��)���� ī�� 2���� ��ġ�� �ٲ��ֱ�
	{
		int firstIndex = dist(mt);	
		int secondIndex = dist(mt); //�ð� ���� �ٸ� ���� ��.

		CCard temp = Cards[firstIndex];
		Cards[firstIndex] = Cards[secondIndex];
		Cards[secondIndex] = temp;
	}
}

// �Լ� �̸�: CompareCard
// �Ķ��Ÿ : const CCard& CardA, const CCard& CardB
// ��ȯ�� : bool
// �Լ���� : CardA�� CardB�� ���Ͽ� CardA�� ũ�ٸ� true, CardB�� ũ�ٸ� false ��ȯ
bool CompareCard(const CCard& CardA, const CCard& CardB)
{
	int ScoreA = CardA.m_number * 10 + CardA.m_mark;
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;

	return ScoreA > ScoreB;
	
}

int main()
{
	std::vector<CCard> Cards;

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)
		{
			CCard card;
			card.m_mark = (CardMark)i;	//enum�� �����ϴ� ��� (ĳ����)
			card.m_number = j;
			Cards.push_back(card);
		}
	}

	Shuffle(Cards);
	int i = 0;
	bool bRun = true;
	while (bRun)
	{
		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str());

		int input = 0;//input = 1 �̸� Cards[0] ����.
		printf("�ι�° ī�尡 ������ 0, ������ 1�� �Է����ּ��� : ");
		scanf_s("%d", &input);
		system("cls");

		//c���� ���ڿ��� ���� �ٷ�� �ڷ����� ���� ������ c_str�� ���� string->char*�� �ٲ��༭ ǥ��
		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str());
		printf("�ι�° ī��� %s �Դϴ�.\n", Cards[i + 1].GetCardStr().c_str());
		// IsFirstHigh = 1 �̸� Cards[0] ����.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);

		if (IsFirstHigh == input) //IsFirstHigh = 1
		{
			printf("�����.\n");
		}
		else //IsFirstHigh = 0
		{
			printf("Ʋ�ȴ�.\n");
		}
		i += 2;
	}

	
	/*for (CCard& card : Cards)
	{
		card.printCard();
	}*/

	
}