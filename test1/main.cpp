#include <stdio.h>
#include <iostream>


int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	// 2�� ��� ����ϱ�(0~100)
	// 0 2 4 6 8 ~ 96 98 100

	// n�� ���� �ϳ��� �Է� �ޱ�
	// n�� ��� ����ϱ�(0~100)

	// (0~100) 2�� ����� ���� ���

	// abcdef�� ������ ����ϱ� fedcba
	wchar_t szWChar[20] = L"abcdef";


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
	wprintf(L"szWCharInput=%s", szWCharInput);

	// �Է� ���� ���ڿ����� 'a'���� ���� ���

}