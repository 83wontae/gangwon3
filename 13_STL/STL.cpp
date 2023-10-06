#include <stdio.h>
#include <vector>

class CShop
{
public:
	int isOpen = false;
};

int main()
{
	// STL
	// 고정되지 않은 유동적인 배열
	// 배열 생성하면서 처음부터 공간을 점유하지 않고 필요할때 마다 늘리고 줄일수있는 배열
	
	/*
	* 백터(vector) - 스택(Stack) 구조
	* 연속적인 메모리를 확보한다.
	* 자신의 요소를 내부의 동적 배열(dynamic array)로 복사한다.
	* 임의 접근 연산자를 제공([])하기 때문에 어떠한 값에 접근하든 상수시간(고정된 시간)이 소요된다.
	* 동적 배열이기 때문에 배열의 중간에 새로 추가하거나 삭제하면 많은 값이 이동해야하기 때문에 오랜 시간이 걸린다.
	* 중간에 추가하는 것이 오버헤드가 크기 때문에 보통 뒷부분에 추가한다( push_back )
	* 동적 배열이기 때문에 크기의 확장과 축소가 자유롭지만 재할당 비용은 크다.
	* 
	* 장점
	* - 임의 접근을 상수시간(고정된 시간)에 가능하므로, 읽기 속도가 매우 빠르다.
	* 
	* 단점
	* - 중간에 값을 추가/제거하는 비용이 크다
	* - 재할당 비용이 크다
	*/

	//std::vector<int> : int형에 vector 배열
	//vecint : vector 배열에 이름
	//{ 0,1,2,3,4 } : vecint에 초기값 넣기
	//std::vector<int> vecint{ 0,1,2,3,4 };
	//int vectorSize = vecint.size();// 백터의 요소 갯수 반환
	//int vec0 = vecint[0];// [] 명확한 위치를 넣어서 접근 가능
	//int* pData = vecint.data();// 백터 배열 실재 데이터 메모리 공간에 주소(포인터)를 반환
	//int vCap = vecint.capacity();// 데이터 크기 측면에서에 저장 공간 크기를 반환
	//printf("vecint capacity=%d\n", vCap);
	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint)// 값 복사 방식으로 값을 변경하면은 원본 데이터는 수정 안됨
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//for (int& value : vecint)// 레퍼런스 참조 방식으로 값을 변경하면은 원본 데이터 변경
	//{
	//	value = 1;
	//	printf("Ref vecint=%d\n", value);
	//}

	//for (const int& value : vecint)// 레퍼런스 참조시 const 변수로 참조하면 값 변경 불가능
	//{
	//	// value = 0;
	//	printf("vecint=%d\n", value);
	//}

	std::vector<int> vecInt{ 0,1,2,3,4,5,6,7,8,9 };
	std::vector<int>::iterator vecIter = vecInt.begin();
	// vecIter++;// 오른쪽으로 다음 배열에 위치를 가리키겠다.
	vecIter += 2;// 오른쪽으로 2번 이동한 배열에 위치를 가리키겠다.
	vecIter--;
	// vecInt.end();// 배열 끝이라는 의미(마지막 배열은 아니다)
	vecInt.push_back(100);// 배열에 마지막에 100 요소를 추가하겠다
	for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	{
		printf("iter=%d\n", *iter);
	}

	vecInt.pop_back();// 마지막 배열에 요소를 제거하겠다.
	vecIter = vecInt.begin();
	while (vecIter != vecInt.end())
	{
		printf("while iter=%d\n", *vecIter);
		vecIter++;
	}
	printf("vecInt size=%d\n", int(vecInt.size()));

	vecIter = vecInt.begin();
	while (vecIter != vecInt.end())
	{
		if (*vecIter == 5)
		{
			vecIter = vecInt.erase(vecIter);//vecIter가 가리키고 있는 배열 요소 제거하겠다.
		}
		else
		{
			vecIter++;
		}
	}

	vecIter = vecInt.begin();
	while (vecIter != vecInt.end())
	{
		printf("while iter=%d\n", *vecIter);
		vecIter++;
	}
	 

	/*
	* 리스트(list)
	* 
	*/
}