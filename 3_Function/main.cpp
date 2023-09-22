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

// 곱하기 함수 만들기
// CalculatorMultiply

// 나누기 함수 만들기
// CalculatorDivide

// 나머지 함수 만들기
// CalculatorRemain

void CallFunction();

int main()
{
	unsigned int nResult = 0;
	nResult = CalculatorSum(1, 1);
	printf("함수 실행 결과 = %d\n", nResult);
	CallFunction();
}

void CallFunction()
{
	printf("함수 호출됬다!");
}
