#include <stdio.h>

// �Լ���
// unsigned int : ��ȯ �ڷ���<-Output
// CalculatorSum : �Լ� �̸�
// (int x, int y) : �Ű� ����(�Ķ��Ÿ)<-Input
unsigned int CalculatorSum(int x, int y)
{//->�Լ� ����
	printf("�Լ� �����ߴ�.\n");

	return x + y;//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��

// ���� �Լ� �����
// CalculatorMinus

// ���ϱ� �Լ� �����
// CalculatorMultiply

// ������ �Լ� �����
// CalculatorDivide

// ������ �Լ� �����
// CalculatorRemain

void CallFunction();

int main()
{
	unsigned int nResult = 0;
	nResult = CalculatorSum(1, 1);
	printf("�Լ� ���� ��� = %d\n", nResult);
	CallFunction();
}

void CallFunction()
{
	printf("�Լ� ȣ����!");
}
