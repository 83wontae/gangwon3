#include <stdio.h>
#include <vector>
#include <string>
#include "Card.h"

/*
1. 52���� ī������ ������ �մϴ�.
2. 52���� ī�带 �������� �����ϴ�.
3. ������ ���۵Ǹ� ī�� �ϳ��� ���� �մϴ�.
4. �÷��̾�� ����ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���� ������ �մϴ�.
5. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
6. ī�带 1�� ���� ���� K�� ���� �����ϴ�.
7. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ �����ϴ�.
*/

int main()
{
	std::vector<CCard> Cards;

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)
		{
			CCard card;
			card.m_mark = (CardMark)i;
			card.m_number = j;
			Cards.push_back(card);
		}
	}

	for (CCard& card : Cards)
	{
		card.printCard();
	}
}