#pragma once
#include <string>

enum CardMark
{
	None = 0,
	Clover,
	Heart,
	Dia,
	Spade,
	MaxMark
};

class CCard
{
public:
	CardMark m_mark;
	int m_number;
public:
	CCard(CardMark mark = CardMark::None, int number = 0);

	std::string GetMarkStr();

	std::string GetCardStr();

	void printCard();
};
