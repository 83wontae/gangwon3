#include <stdio.h>

// 함수형
// unsigned int : 반환 자료형<-Output
// CalculatorSum : 함수 이름
// (int x, int y) : 매개 변수(파라메타)<-Input
unsigned int CalculatorSum(int x, int y)
{//->함수 시작
	printf("함수 시작했다.\n");

	return x + y;//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝

// 빼기 함수 만들기
// CalculatorMinus
int CalculatorMinus(int x, int y)
{
	return x - y;
}
// 곱하기 함수 만들기
// CalculatorMultiply
int CalculatorMultiply(int x, int y)
{
	return x * y;
}

// 나누기 함수 만들기
// CalculatorDivide
float CalculatorDivide(float x, float y)
{
	return x / y;
}

// 나머지 함수 만들기
// CalculatorRemain
float CalculatorRemain(int x, int y)
{
	return x % y;
}

// Factorial 함수
int Factorial(int Num)
{
	int FacResult = 1;
	for (int i = Num; i > 0; --i)
	{
		FacResult *= i;
	}

	return FacResult;
}

int Factorial2(int Num)
{
	int FacResult = 1;

	for (int i = 1; i <= Num; ++i)
	{
		FacResult *= i;
	}

	return FacResult;
}

int ReFactorial(int Num)
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1);
}

// SumToN 함수
int SumToN(int Num)
{
	int FacResult = 0;
	for (int i = Num; i > 0; --i)
	{
		FacResult += i;
	}

	return FacResult;
}

void CallFunction();

int main()
{
	//unsigned int nResult = 0;
	//nResult = CalculatorSum(1, 1);
	//printf("더하기 함수 실행 결과 = %d\n", nResult);
	//nResult = CalculatorMinus(1, 1);
	//printf("빼기 함수 실행 결과 = %d\n", nResult);
	//nResult = CalculatorMultiply(2, 2);
	//printf("곱하기 함수 실행 결과 = %d\n", nResult);
	//float fResult = 0.0f;
	//fResult = CalculatorDivide(10, 3);
	//printf("나누기 함수 실행 결과 = %f\n", fResult);
	//fResult = CalculatorRemain(10, 4);
	//printf("나머지 함수 실행 결과 = %f\n", fResult);
	//CallFunction();

	//// 반복문
	//// for문
	//for (/*초기 설정*/int i = 0;/*반복 조건 채크*/i < 10;/*반복 후 처리*/++i)
	//{// <-반복 처리할 코드 시작
	//	
	//	printf("%d Hello\n", i);
	//}// <-반복 처리할 코드 끝

	//int a = 0;
	//for (; a < 5; ++a)
	//{
	//	printf("HelloA\n");
	//}

	//for (int b = 0;b < 10;b+=2)
	//{
	//	printf("HelloB\n");
	//}
	
	// 1. int i = 0;
	// 2. i = 0이고, i < 10 채크 결과는 true(1)
	// 3. 반복 처리할 코드 실행
	// 4. 반복 후 처리 ++i(i를 1증가 시킨다.) i = 1;
	//~~~~~~~~~~~~~
	// 1. int i = 9;
	// 2. i = 9이고, i < 10 채크 결과는 true(1)
	// 3. 반복 처리할 코드 실행
	// 4. 반복 후 처리 ++i(i를 1증가 시킨다.) i = 10;
	// 1. int i = 10;
	// 2. i = 10이고, i < 10 채크 결과는 false(0)


	//for (int i = 0;i < 10;++i)
	//{
	//	printf("Hello\n");
	//}


	// Factorial
	// 5 Factorial 구해라
	// 5 * 4 * 3 * 2 * 1 = 15; 

	printf("Factorial FacResult = %d\n", Factorial(5));
	printf("Factorial2 FacResult = %d\n", Factorial2(5));
	printf("ReFactorial FacResult = %d\n", ReFactorial(5));
	printf("SumToN Result = %d\n", SumToN(10));

	//1~n까지 합 구하는 함수
	//int SumToN(int Num)
}

void CallFunction()
{
	printf("함수 호출됬다!");
}
