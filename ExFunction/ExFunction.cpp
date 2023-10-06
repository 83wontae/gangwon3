#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"

//�Լ��̸� Average
//�Ķ��Ÿ int &Sum, int a, int b, int c
//��ȯ�� ����
//���۷��� ���� Sum���� a, b, c�� ��� ���� ��ȯ
void Average(int& Sum, int a, int b, int c)
{
	Sum = a + b + c / 3;
}

//�Լ��̸� ArraySum
//�Ķ��Ÿ int* arr, int length
//��ȯ �� : int
//�迭 "arr" �� �迭�� ���� "length"�� �Ķ��Ÿ�� �޾Ƽ� ��� �迭�� ���� ��ȯ
int ArraySum(int* arr, int length)
{
	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += arr[i];
	}

	return sum;
}

// Ŭ���� �̸� : CShop
// �ɹ� ���� : m_value(�⺻��:0)
// �ɹ� �Լ� �߰� : printValue
// printValue �Լ� ��� : "Value=%d"�� m_value ���
class CShop
{
public:
	int m_value;

	void printValue()
	{
		printf("Value=%d\n", m_value);
	}
};

// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
// �ɹ� ���� : int m_PhoneCnt
// �ɹ� ���� : int m_PhonePrice
// ������ �Ķ��Ÿ : int PhoneCnt ( m_PhoneCnt�� �� ���� )
// ������ �Ķ��Ÿ : int PhonePrice ( m_PhonePrice�� �� ���� )
// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���
class CPhoneShop : public CShop
{
public:

	CPhoneShop(int PhoneCnt, int PhonePrice):m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{

	}

	void printValue()
	{
		printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
	}

	int m_PhoneCnt;
	int m_PhonePrice;
};

// Ŭ���� �̸� : CFruitShop
// �θ� Ŭ���� : CShop
// �ɹ� ���� : int m_FruitCnt
// �ɹ� ���� : int m_FruitPrice
// ������ �Ķ��Ÿ : int FruitCnt ( m_FruitCnt�� �� ���� )
// ������ �Ķ��Ÿ : int FruitPrice ( m_FruitPrice�� �� ���� )
// printValue �Լ� ��� : "Value=%d"�� m_FruitCnt * m_FruitPrice���
class CFruitShop : public CShop
{
public:
	CFruitShop(int FruitCnt, int FruitPrice):m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{

	}

	void printValue()
	{
		printf("Value=%d", m_FruitCnt * m_FruitPrice);
	}

	int m_FruitCnt;
	int m_FruitPrice;
};



int main()
{
	// printf�� "Sum=%d\n"�� Sum�Լ� ��� ���
	// printf�� "Minus=%d\n"�� Minus�Լ� ��� ���
	// printf�� "Multi=%d\n"�� Multi�Լ� ��� ���
	// printf�� "Divid=%d\n"�� Divid�Լ� ��� ���

	int sum = Sum(1, 1);
	//Minus();
	//Multi();
	//Divid();

	// CPhoneShop(10, 100) ���� �� ��ü�� printValue ���
	CPhoneShop PhoneShop(10, 100);
	PhoneShop.printValue();

	// CFruitShop(10, 100) ���� �� ��ü�� printValue ���
	CFruitShop FruitShop(10, 100);
	FruitShop.printValue();
}