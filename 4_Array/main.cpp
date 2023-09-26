#include <stdio.h>

// c++ �� ������
// c++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ������ �ִ� �ڵ�� ��ȯ�Ͽ� �����Ҽ� �ִ� ���Ϸ� ��ȯ�ϴ� ����

// 1. ��ó��(Preprocessing) �ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking) �ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�

// �޸� ����
// 1. Code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// 2. Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
// 3. Stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
// 4. Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int g_money = 0;//���� ����

static int s_money = 0;

#include "money.h"
#include "calcFunc.h"

struct fruitShop
{
	// ����ü ���� ������ ������ ����ü ������� ������ �� �������.
	int index;
	int appleA;
	int mangoA;
	int strawberryA;

	// ����ü ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�.
	fruitShop() : index(0), appleA(1000), mangoA(1000), strawberryA(1000)
	{

	}

	// ����ü�� �Լ� ����
	void SetFruitValue(int apple, int mange, int strawberry)
	{
		int appleB = apple;// SetFruitValue �Լ��� ����Ǹ� �������.
		appleA = apple;
		mangoA = mange;
		strawberryA = strawberry;
	}

	void printShopValue()
	{
		printf("%d��° ���ϰ��� ���� ���:%d, ����:%d, ����:%d\n", index, appleA, mangoA, strawberryA);
	}
};

struct PhoneShop
{
	int iPhone;
	int zFlip;
	int GalaxyS23;
	int GalaxyFold;

	PhoneShop()
	{
		iPhone = 0;
		zFlip = 0;
		GalaxyS23 = 0;
		GalaxyFold = 0;
	}
	
	void setPhoneValue(int niPhone, int nzFlip, int nGalaxyS23, int nGalaxyFold)
	{
		iPhone = niPhone;
		zFlip = nzFlip;
		GalaxyS23 = nGalaxyS23;
		GalaxyFold = nGalaxyFold;
	}

	void printShopValue()
	{
		printf("�ڵ������� ���� ������:%d, �ø�:%d, �ַ���:%d, ����:%d\n"
			, iPhone, zFlip, GalaxyS23, GalaxyFold);
	}
};

// 1 + 1 = 2
int Add(int a, int b)
{
	printf("int�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}

// 1.2 + 1.3 = 1.5
float Add(float a, float b)
{
	printf("float�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}

int main()
{
	int t_money = 0;//���� ����
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);

	printf("main t_money=%d\n", t_money);
	printf("main g_money=%d\n", g_money);
	printf("1+1 Sum=%d\n", AddNum(1, 1));

	Add(1, 1);
	Add(1.0f, 1.0f);//f�� ���̰� �Ǽ��� ���� float��
	Add(1.0, 1.0);//f�� ������ �ʰ� �Ǽ��� ���� double��

	// �迭
	// int arrInt[10] = { 0 };// �迭 ���� �� ���� 0���� �ʱ�ȭ
	// int arrInt[10] = { 0, };// �迭 ���� �� ���� 0���� �ʱ�ȭ
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };// �迭 ���� �� ������ �迭�� �ʱⰪ �ִ� ���
	arrInt[0] = 10;// �迭 0��°�� �� �ֱ�
	arrInt[4] = 40;// �迭 4��°�� �� �ֱ�
	arrInt[9] = 90;// 0�� ���� �迭�� ���� �ǹǷ� ������ �迭�� 9��°

	for (int i = 0; i < 10; i++)
	{
		printf("%d��° �迭 ���� %d�Դϴ�.\n", i, arrInt[i]);// 2�� �̻��� �Ķ��Ÿ ��� ���
	}

	int number = 0;
	for (int value : arrInt)
	{
		printf("for each %d��° �迭 ���� %d�Դϴ�.\n", number, value);
		number++;
	}

	// Struct�� ���
	// fruitShop : ������
	// shop : ������ �̸�
	fruitShop shop[3];

	// Struct �Լ� ����
	shop[0].index = 0;
	shop[0].SetFruitValue(1000, 2000, 3000);
	shop[1].index = 1;
	shop[1].SetFruitValue(1100, 2100, 3100);
	shop[2].index = 2;
	shop[2].SetFruitValue(900, 1900, 2900);

	for (fruitShop stValue : shop)
	{
		stValue.printShopValue();
	}

	// Struct PhoneShop
	// int iPhone;
	// int zFlip;
	// int GalaxyS23;
	// int GalaxyFold;
	// PhoneShop[0] iPhone=100, zFlip=90, GalaxyS23=80, GalaxyFold=150
	// PhoneShop[1] iPhone=110, zFlip=100, GalaxyS23=90, GalaxyFold=160
	// PhoneShop[2] iPhone=90, zFlip=80, GalaxyS23=70, GalaxyFold=140
	// PhoneShop[0], PhoneShop[1], PhoneShop[2]�� ������ ���

	PhoneShop stPhoneShop[3];
	stPhoneShop[0].setPhoneValue(100, 90, 80, 150);
	stPhoneShop[1].setPhoneValue(110, 100, 90, 160);
	stPhoneShop[2].setPhoneValue(90, 80, 70, 140);

	for (PhoneShop value : stPhoneShop)
	{
		value.printShopValue();
	}
}