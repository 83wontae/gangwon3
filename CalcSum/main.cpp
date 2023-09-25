#include <stdio.h>

int Sum(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

int main()
{
	bool bRun = true;
	while (bRun)
	{
		int nInput = 0;
		int num1, num2;

		printf("어떤 연산을 하시겠습니까?(0:더하기, 1:빼기, 2:곱하기, 3:나누기, 4:나머지):");
		scanf_s("%d", &nInput);
		switch (nInput)
		{
			case 0:
			{
				printf("숫자 2개를 입력하세요(num1 num2):");
				scanf_s("%d %d", &num1, &num2);
				printf("두수의 합은 %d입니다.\n", Sum(num1, num2));
			}
			break;

			case 1:
			{
				printf("숫자 2개를 입력하세요(num1 num2):");
				scanf_s("%d %d", &num1, &num2);
				printf("두수의 뺄셈은 %d입니다.\n", Minus(num1, num2));
			}
			break;

		default:
			break;
		}

		printf("계산기를 종료하시겠습니까?(0:No 1:Yes):");
		scanf_s("%d", &nInput);
		
		switch (nInput)
		{
		case 1:
			bRun = false;
			break;
		}
	}

	return 0;
}