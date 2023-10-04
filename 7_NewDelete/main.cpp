#include <stdio.h>
#include <iostream>

// c++ 의 컴파일
// c++에서 사람이 작성한 소스코드를 컴퓨터가 읽을수 있는 코드로 변환하여 실행할수 있는 파일로 변환하는 과정

// 1. 전처리(Preprocessing) 단계 : #include 와 #define 과 같은 전처리기 매크로들을 처리하는 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계


// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// 2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// 3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자로 할당, free() 또는 delete 연사자로 해제

int main()
{
	/*
	// 정적 메모리 할당
	// 정적으로 메모리를 할당하면 컴파일 시 Stack 영역에 할당되며, 함수를 빠져나갈때 소멸된다.
	// 프로그램 컴파일 시 Stack에 얼마만큼의 크기로 할당을 해야하는지 결정되기 때문에, 컴파일 이후 크기를 변경할 수 없다.
	// 따라서 정적 배열 선언시 크기를 가변적으로 명시하면 문제가 될 수 있다.

	int a = 0;
	int arr[10];

	// 동적 메모리 할당
	// 동적으로 메모리를 할당하는 경우 데이터가 heap 영역에 할당이 된다.
	// heap은 프로그래머에 의해 할당(new) 소멸(delete)된다.
	// 프로그래머가ㅏ 원할 때 원하는 크기로 할당할 수 있다.
	// 참고로 포인터 변수는 stack에 할당된다.

	int* pM = (int*)malloc(4);// C에서 동적 할당하는 기능
	free(pM);

	// new & delete
	// new 연산자로 생성지 반드시 delete 연산자로 해제 해주어야 한다.
	// new 연산자로 배열 생성시 delete[] 연산자로 배열임을 명시 해주어야 한다.
	int* pA = new int(0);// C++ 에서 동적 할당하는 기능이 추가됨
	int* pArr = new int[10];

	delete pA;
	delete[] pArr;
	*/

	int* pArr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", pArr[i]);
	}

	delete[] pArr;

	// 깊은 복사 & 얕은 복사
	int* a;
	a = new int(10);
	//int* a = new int(10);
	int* b = new int(20);

	a = b;// 얕은 복사 : a에 주소값에 b에 주소값을 넣는다, b가 가리키고 있는걸 a도 가리키게 하겠다.
	*a = *b;// 깊은 복사 : a가 가리키고 있는 값을 b가 가리키고 있는 값으로 수정한다.

	delete a;
	delete b;
}