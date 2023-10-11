#include "Card.h"
#include <stdio.h>

CCard::CCard(CardMark mark, int number) :m_mark(mark), m_number(number)
{

}

std::string CCard::GetMarkStr()
{
	switch (m_mark)
	{
	case Clover:
		return "Clover";
		break;
	case Heart:
		return "Heart";
		break;
	case Dia:
		return "Dia";
		break;
	case Spade:
		return "Spade";
		break;
	}

	return "None";
}

void CCard::printCard()
{
	printf("%s[%d]\n", GetMarkStr().c_str(), m_number);
}