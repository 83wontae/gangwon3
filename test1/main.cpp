#include <stdio.h>
#include <iostream>


int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	// 2�� ��� ����ϱ�(0~100)
	// 0 2 4 6 8 ~ 96 98 100
	//for (int i = 0; i <= 50; i += 2)
	//{
	//	printf("%d ", i);
	//}

	// n�� ���� �ϳ��� �Է� �ޱ�
	// n�� ��� ����ϱ�(0~100)
	//int n = 2;
	//printf("\n�����ϳ��� �Է��� �ּ���! : ");
	//scanf_s("%d", &n);
	//for (int i = 0; i <= 50; i += n)
	//{
	//	printf("%d ", i);
	//}

	// (0~100) 2�� ����� ���� ���
	//int cnt = 0;
	//for (int i = 0; i <= 50; i += 2)
	//{
	//	if (i == 0)
	//	{
	//		continue;
	//	}
	//	// cnt = cnt + 1;
	//	// cnt += 1;
	//	cnt++;
	//}
	//printf("cnt=%d ", cnt);


	// abcdef�� ������ ����ϱ� fedcba
	wchar_t szwchar[20] = L"abcdef";
	int size = wcslen(szwchar);// ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	printf("size=%d\n", size);
	for (int i = 1; i <= size; ++i)
	{
		printf("%c", szwchar[size - i]);
	}
	
	for (int i = size; i >= 0; --i)
	{
		printf("%c", szwchar[i - 1]);
	}


	// wchar_t ������ ���� �Է� �ޱ�
	// "szWCharInput"�̸��� ����
	// "wchar_t" �������� 
	// [20]�� ũ��� �����ϰ� 
	// L"" ���� �ʱⰪ���� �ִ´�.
	wchar_t szWCharInput[20] = L"";
	// wscanf_s�� �Է��� �޴� ����� ����ϰڴ�.
	// L"%ls" �������·� �Է��� �ްڴ�.
	// "szWCharInput"������ �Է��� ���� �־��ְڴ�.
	// "(unsigned)_countof(szWCharInput)"�� ���� ���� ������ ũ��
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	// wprintf�� ����� �ϴ� ��� ����ϰڴ�.
	// L"szWCharInput=%s"���� ���·� ����ϰڴ�.
	// %s��ġ�� szWCharInput ���� ����ϰڴ�.
	wprintf(L"szWCharInput=%s\n", szWCharInput);

	// �Է� ���� ���ڿ����� 'a'���� ���� ���
	int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i] == 'a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);
}