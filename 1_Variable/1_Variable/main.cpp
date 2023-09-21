﻿#include <iostream>
#include <stdlib.h>

int main()
{
	//컴퓨터는 0, 1 표현할수있는 1개를 bit라고 한다.
	//2진법 8개 bit일때는 0~255 256개 숫자를 표현
	//0000 0000 = 0
	//0000 0001 = 1
	//0000 0010 = 2
	//0000 0100 = 4
	//0000 1000 = 8
	//0001 0000 = 16
	//0010 0000 = 32
	//0100 0000 = 64
	//1000 0000 = 128
	//1111 1111 = 255
	//1000 0000 : 맨 앞에 부호가 1이면(-), 0이면(+)

	//0111 1111 = 127
	//0000 0001
	//1000 0000 = 128(-128)
	//1 + 1 = 2
	//1 + -1 = 0;
	//0000 0001(1) + 1111 1111(-1) = 0000 0000(0)
	//0110 0100(100) + 1001 1100(-100) = 0000 0000(0)

	signed char c;// -128~127//1Byte
	unsigned char uc;// 0~255//1Byte
	c = 128;


	//short int = short : 작은 정수
	short s;// –32,768 ~ 32,767//0000 0000 0000 0000// 2Byte

	//long int = long : 큰 정수
	long l;// 4byte;

	//int 자료형
	//최초 16bit 아키텍쳐 일때는 16bit
	//32bit 아키텍처 일때는 32bit
	//64bit 아키텍처 일때는 32bit
	//int64 = 64bit
	int A;//숫자, 음수, 양수, 정수(0, 1, 2, 3, 4)
	unsigned int uA;//숫자, 양수, 정수(0, 1, 2, 3, 4)


	float f = 0.1f;//4Byte
	f = 2.0f;
	f = 2.f;

	// 부동소수점
	// 0001 0000 = 1 이라면,
	// 0000 1000 = 0.5
	// 0000 0100 = 0.25
	// 0000 0010 = 0.125
	// 0000 0001 = 0.0625
	// 0000 1101 = 0.5 + 0.25 + 0.0625 = 0.8125
	// 0(부호부) / 000 0000 0(지수부) / 000 0000 0000 0000 0000 0000(가수부)
	// 21.8125 = 21(10101).8125(0.1101)
	// 21.8125->10101.1101(218125)->0.101011101 * 2^5->5승을 2진법으로 바꾸면(101)
	// 0(부호부) / 000 0010 1(지수부) / 101 0111 0100 0000 0000 0000(가수부)
	// 명확하게 0.1을 표기하려고 한다면 0000 0001 1011 1001
	// float a = 1.0;
	// int n = 1;
	// n == a ? 1 == 0.99999999999999999999999999999998

	double d = 0.1;//8Byte float 보다 더 정밀하다

	// int 1 = 0000 0001
	// float 1 = 0001 0001 101010
	int i2 = 0;
	float f2 = 1.0f;
	i2 = (int)f2;
	f2 = (float)i2;
	f2 = float(i2);
	f2 = (float)(i2 + 1);
	i2 = int(f2) + 1;

	// 대입연산자(=)
	// 오른쪽에 값을 왼쪽에 대입한다.

	// 연산자
	// +, -, *, /, %, ++, --
	i2 = 1 + 1;
	i2 = i2 + 1;
	i2 += 1;//i2 = i2 + 1; 과 동일하다.

	i2 = 1 * 1;
	i2 = i2 * 1;
	i2 *= 1;//i2 = i2 * 1; 과 동일하다.
	float divide = 10 / 2.0f;// 10 * 0.5f;
	// 실수 끼리 나머지 연산 불가능(몇번째 소수점 자리를 기준으로 연산을 해야하는지 알수 없음)
	// 즉, 둘다 정수 일때만 나머지 연산 가능
	float remain = 10 % 3;

	int add = 0, minus = 10;// 변수를 선언하면 초기화 값을 넣어준다.
	
	int addR = 0, addL = 0;
	addL = ++add;// 전치 연산
	addR = add++;// 후치 연산은 대입연산자(=)보다 더 뒤에 실행

	minus--;
	--minus;

	// 논리 연산자
	// &&(AND), ||(OR), !(NOT)
	// AND : 둘다 참이면 참, 그렇치 않으면 거짓
	// OR : 둘중에 하나라도 참이면 참, 그렇치 않으면 거짓
	// NOT : 참이면 거짓, 거짓이면 참
	// Yes : 0이 아닌 값, true(1)
	// No : 0이면, false(0)
	// bool bResult = true;
	// bool bResult = false;
	// bool bResult = 1;// true 넣은 것과 같다.
	bool bResult = 0;// false 넣은 것과 같다.

	bResult = 0 && 20;
	bResult = 0 || 20;
	bResult = !true;
	bResult = !0;

	// 주석 : 컴파일에 포함되지 않는 문자로 코드로 인식하지 않는다.
	/* 주석 : 컴파일에 포함되지 않는 문자로 코드로 인식하지 않는다. */

	// 자주쓰는 단축키
	// 지정한 구문 주석 : Ctrl + k -> Ctrl + c
	// 지정한 구문 주석 해제 : Ctrl + k -> Ctrl + u
	// Alt Drag : 부분 영역 지정

	// 디버깅 단축키
	// F5 : 디버깅 시작, 디버깅 개속 진행
	// F9 : 중단점 생성 및 해제
	// F10 : 디버깅 중 다음 구문 진행
	// F11 : 디버깅 중 함수 내부 구문 진행
	// Shift + F5 : 디버깅 종료

	// 비교 연산자
	// == : 같으면 true, 아니면 false
	// != : 같으면 false, 아니면 true
	// > : 왼쪽이 오른쪽보다 크면은 true, 아니면 false
	// >= : 왼쪽이 오른쪽보다 크거나 같으면 true, 아니면 false
	// < : 왼쪽이 오른쪽보다 작으면은 true, 아니면 false
	// <= : 왼쪽이 오른쪽보다 작거나 같으면 true, 아니면 false
	bResult = (10 == 11);
	bResult = (10 != 11);
	bResult = (10 > 11);
	bResult = (10 < 11);

	int nResult = (10 == 11) ? 100 : 50;


	// 문제 아래 time 들었는 초 값에 분과 시간 일수를 구해라
	unsigned int sec = 987654321;//초

	unsigned int day = 0, hour = 0, min = 0, sec = 0;
	day = 0;
	hour = 0;
	min = 0;
	sec = 0;

	printf("%d", i2);
	system("pause");
}