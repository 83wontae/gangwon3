#include <stdio.h>
#include <iostream>
#include <assert.h>

//_pString="abcdefg";
unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i);//�������� �ּҰ��� ���ڸ� ����

		//if (c == 0)
		if (c == '\0')
		{
			break;
		}

		++i;
	}

	return i;
}

// _Dest : "abcde"
// _pSource : "fghij\0"
void StringCat(wchar_t* _Dest, unsigned int size, const wchar_t* _pSource)
{
	int destLen = GetStringLength(_Dest);
	int sourceLen = GetStringLength(_pSource);
	if (size < destLen + sourceLen + 1)// \0 ���� 1���� �� �ʿ�
	{
		assert(nullptr);
	}

	for (int i = 0; i < sourceLen + 1; i++)
	{
		*(_Dest + destLen + i) = *(_pSource + i);
		//_Dest[destLen + i] = _pSource[i];
	}
}

int StringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	int LeftLen = GetStringLength(_pLeft);
	int RightLen = GetStringLength(_pRight);

	// ���� �� ������ ���� ��ŭ�� ���Ѵ�.
	// ���忡 ������ \0�� ���ϱ� ������
	int nLoop = (LeftLen > RightLen) ? LeftLen : RightLen;

	for (int i = 0; i < nLoop; i++)
	{
		if (_pLeft[i] == _pRight[i])// ���� ������ ũ��� ����� �������� �ʰ� �ٽ� for���� ����
			continue;

		return (_pLeft[i] > _pRight[i]) ? 1 : -1;// ũ��� ����� ��ȯ
	}

	//if(LeftLen != RightLen)
	//{
	//	// left�� ��� 1, right ��� -1
	//	return (LeftLen > RightLen) ? 1 : -1;// ũ��� ����� ��ȯ
	//}

	return 0;//��� ���ڰ� ���� ���̵� ����
}

int main()
{
	// ���� ó��
	// �ƽ�Ű �ڵ� ��ũ : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
	// multi-byte
	// 127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
	// �������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
	// �Ϻ��� �ؽ�Ʈ ������ �ѱ� �����쿡�� ������ �� ���� ������ ������ ����
	// ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�. �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ������
	char c1 = 'a';//1Byte(0~255), �ѱ��� �϶��� ' '���
	printf("c1=%c\n", c1);// �ѱ��� char ��½� %c ���

	setlocale(LC_ALL, "korean");// multi-byte ��� ����

	char arrC1[10] = "abc�ѱ�";//����� 1Byte, �ѱ��� 2Byte ���, ���ڿ� �϶��� " "���
	printf("arrC1=%s\n", arrC1);// ���ڿ� char ��½� %s ���

	// ���̵� ����(wide character)
	// multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	// ������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	// ���� ���� ����ϴ� ����� UTF-8�� �ִ�
	// 2Byte(0~65535)���� �տ� ������ 1bit�� �����ϸ� 32767�� ǥ������
	// wchar_t���� ���ڸ� ������ �տ� L�� ���δ�.

	wchar_t wc1 = L'a';
	wprintf(L"wc1=%c\n", wc1);// wchar_t���� ����Ҷ��� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.

	_wsetlocale(LC_ALL, L"korean");// ���̵� ���� ��� ����

	wchar_t arrWC1[10] = L"abc�ѱ�";// wchar_t�迭�� ���ڿ��� ������ �տ� L�� ���δ�.
	wprintf(L"arrWC1=%s\n", arrWC1);// wchar_t���� ����Ҷ��� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.

	wchar_t szWChar[10] = L"abcdefghi";//�������� ���ڿ� �������̶�� ǥ��� '\0'���ڰ� ����.
	wprintf(L"szWChar=%s\n", szWChar);

	wchar_t szWCharLen[20] = L"abcdefg";
	int size = wcslen(szWCharLen);// ���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	size = GetStringLength(szWCharLen);// ���ڿ� ���� ���ϱ�
	printf("szWCharLen size=%d\n", size);

	//wcscat_s(szWCharLen, 20, L"hij");// ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	StringCat(szWCharLen, 20, L"hij");// ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	wcscpy_s(szWCharLen, L"abcdef");// ���� ���ڿ��� �ڿ� ���ڿ� �����ؼ� �ִ´�.

	int nResult = wcscmp(L"abcdef", L"abidef");//������ 0, �տ� ���ڼ����� ������ 1, �ڿ� ���ڼ����� ������ -1
	nResult = StringCmp(L"abcdef", L"abidef");//������ 0, �տ� ���ڼ����� ������ 1, �ڿ� ���ڼ����� ������ -1
	printf("nResult=%d\n", nResult);
}