#include <stdio.h>
#include <iostream>


int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	// 2에 배수 출력하기(0~100)
	// 0 2 4 6 8 ~ 96 98 100

	// n은 숫자 하나를 입력 받기
	// n에 배수 출력하기(0~100)

	// (0~100) 2에 배수에 갯수 출력

	// abcdef를 역으로 출력하기 fedcba
	wchar_t szWChar[20] = L"abcdef";


	// wchar_t 형으로 문자 입력 받기
	// "szWCharInput"이름을 가진
	// "wchar_t" 변수형을 
	// [20]의 크기로 생성하고 
	// L"" 값을 초기값으로 넣는다.
	wchar_t szWCharInput[20] = L"";
	// wscanf_s는 입력을 받는 기능을 사용하겠다.
	// L"%ls" 변수형태로 입력을 받겠다.
	// "szWCharInput"변수에 입력한 값을 넣어주겠다.
	// "(unsigned)_countof(szWCharInput)"는 값을 넣을 변수에 크기
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	// wprintf는 출력을 하는 기능 사용하겠다.
	// L"szWCharInput=%s"문자 형태로 출력하겠다.
	// %s위치에 szWCharInput 값을 출력하겠다.
	wprintf(L"szWCharInput=%s", szWCharInput);

	// 입력 받은 문자열에서 'a'문자 갯수 출력

}