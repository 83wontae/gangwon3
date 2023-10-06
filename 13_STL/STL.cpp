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
	// �������� ���� �������� �迭
	// �迭 �����ϸ鼭 ó������ ������ �������� �ʰ� �ʿ��Ҷ� ���� �ø��� ���ϼ��ִ� �迭
	
	/*
	* ����(vector) - ����(Stack) ����
	* �������� �޸𸮸� Ȯ���Ѵ�.
	* �ڽ��� ��Ҹ� ������ ���� �迭(dynamic array)�� �����Ѵ�.
	* ���� ���� �����ڸ� ����([])�ϱ� ������ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ�ȴ�.
	* ���� �迭�̱� ������ �迭�� �߰��� ���� �߰��ϰų� �����ϸ� ���� ���� �̵��ؾ��ϱ� ������ ���� �ð��� �ɸ���.
	* �߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �޺κп� �߰��Ѵ�( push_back )
	* ���� �迭�̱� ������ ũ���� Ȯ��� ��Ұ� ���������� ���Ҵ� ����� ũ��.
	* 
	* ����
	* - ���� ������ ����ð�(������ �ð�)�� �����ϹǷ�, �б� �ӵ��� �ſ� ������.
	* 
	* ����
	* - �߰��� ���� �߰�/�����ϴ� ����� ũ��
	* - ���Ҵ� ����� ũ��
	*/

	//std::vector<int> : int���� vector �迭
	//vecint : vector �迭�� �̸�
	//{ 0,1,2,3,4 } : vecint�� �ʱⰪ �ֱ�
	//std::vector<int> vecint{ 0,1,2,3,4 };
	//int vectorSize = vecint.size();// ������ ��� ���� ��ȯ
	//int vec0 = vecint[0];// [] ��Ȯ�� ��ġ�� �־ ���� ����
	//int* pData = vecint.data();// ���� �迭 ���� ������ �޸� ������ �ּ�(������)�� ��ȯ
	//int vCap = vecint.capacity();// ������ ũ�� ���鿡���� ���� ���� ũ�⸦ ��ȯ
	//printf("vecint capacity=%d\n", vCap);
	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint)// �� ���� ������� ���� �����ϸ��� ���� �����ʹ� ���� �ȵ�
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//for (int& value : vecint)// ���۷��� ���� ������� ���� �����ϸ��� ���� ������ ����
	//{
	//	value = 1;
	//	printf("Ref vecint=%d\n", value);
	//}

	//for (const int& value : vecint)// ���۷��� ������ const ������ �����ϸ� �� ���� �Ұ���
	//{
	//	// value = 0;
	//	printf("vecint=%d\n", value);
	//}

	std::vector<int> vecInt{ 0,1,2,3,4,5,6,7,8,9 };
	std::vector<int>::iterator vecIter = vecInt.begin();
	// vecIter++;// ���������� ���� �迭�� ��ġ�� ����Ű�ڴ�.
	vecIter += 2;// ���������� 2�� �̵��� �迭�� ��ġ�� ����Ű�ڴ�.
	vecIter--;
	// vecInt.end();// �迭 ���̶�� �ǹ�(������ �迭�� �ƴϴ�)
	vecInt.push_back(100);// �迭�� �������� 100 ��Ҹ� �߰��ϰڴ�
	for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	{
		printf("iter=%d\n", *iter);
	}

	vecInt.pop_back();// ������ �迭�� ��Ҹ� �����ϰڴ�.
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
			vecIter = vecInt.erase(vecIter);//vecIter�� ����Ű�� �ִ� �迭 ��� �����ϰڴ�.
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
	* ����Ʈ(list)
	* 
	*/
}