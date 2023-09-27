#include <stdio.h>
#include <iostream>
#include <assert.h>

unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;
	while (1)
	{
		wchar_t c = *(_pString + i);	//���������� �ּҰ��� ���� �� ����
		if (c == '\0')
			break;
		++i;
	}
	return i;
}


void StringCat(wchar_t* _Dest, unsigned int size, const wchar_t* _pSource)
{
	int destLen = GetStringLength(_Dest);
	int sourceLen = GetStringLength(_pSource);

	if (size < destLen + sourceLen + 1)
	{
		assert(nullptr);
	}

	for (int i = 0; i < sourceLen + 1; i++)
	{
		*(_Dest + destLen + i) = *(_pSource + i);
		//_Dest[destLen + i] = _pSource[i]; ������ ����
	}
}

int StringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	int LeftLen = GetStringLength(_pLeft);
	int RightLen = GetStringLength(_pRight);

	bool nLoop = (_pLeft < _pRight) ? LeftLen : RightLen; //���� ª�� ������ ���� ��ŭ�� ��

	for (int i = 0; i < nLoop; i++)
	{
		if (_pLeft[i] == _pRight[i]) //���ڰ� ������ ũ�� �� ����� �������� �ʰ� �ٽ� for���� ����
			continue;

		return (_pLeft[i] > _pRight[i]) ? 1 : -1; //ũ�� �� ����� ��ȯ
	}

	////left�� ��� 1, right ��� -1
	//if (LeftLen != RightLen)
	//{
	//	return (LeftLen > RightLen) ? 1 : -1;
	//}

	return 0; //��� ���ڰ� ���� ���̵� ����.
}

int main()
{
	//���� ó��
	//�ƽ�Ű �ڵ� ��ũ : 
	//multi-byte
	//127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
	//�������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
	//�Ϻ��� �ؽ�Ʈ ������ �ѱ� ������ ���� ������ �� ���� ������ ������ ����
	//ö���� �ڱ��� ǥ�⸸�� ���� �ΰ��. �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ����
	char c1 = 'a'; //1byte(0~255)
	printf("c1=%c\n", c1);

	setlocale(LC_ALL, "korean"); //multi-byte ��� ����

	char arrC1[10] = "abc�ѱ�"; //����� 1byte, �ѱ��� 2byte ���
	printf("arrC1=%s\n", arrC1);

	//���̵� ����(wide character)
	//multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	//������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	//���� ���� ����ϴ� ����� UTF-8�� �ִ�.
	//2byte(0~65535)���� �տ� ������ 1bit�� �����ϸ� 32,767�� ǥ�� ����
	//wchar_t���� ���ڸ� ���� �� �տ� L�� ���δ�.

	wchar_t wc1 = L'a'; 
	wprintf(L"wc1=%d\n", wc1);	//wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�. 
	
	_wsetlocale(LC_ALL, L"korean"); //���ϵ� ���� ��� ����
	
	wchar_t arrWC1[10] = L"abc�ѱ�"; //wchar_t���� ���ڸ� ���� �� �տ� L�� ���δ�.
	wprintf(L"arrWC1=%s\n", arrWC1); //wchar_t���� ����� ���� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.

	wchar_t szWChar[10] = L"abcdefghi"; //�������� ���ڿ� �������̶�� ǥ��� '\0'���ڰ� ����.
	wprintf(L"szWChar=%s\n", szWChar);

	wchar_t szWCharLen[20] = L"abcdefg";
	int size = wcslen(szWCharLen);	//���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
	size= GetStringLength(szWCharLen);	//���ڿ� ���� ���ϱ�
	wprintf(L"szCharLen size = %d\n", size);

	wcscat_s(szWCharLen, 20, L"hij");	//���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	StringCat(szWCharLen, 20, L"hijkl");
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	wcscpy_s(szWCharLen, L"abcdef");

	int nResult = wcscmp(L"abcdef", L"abcdef"); //������ 0, �տ� ���� ������ ������ 1, �ڿ� ���� ������ ������ -1
	nResult = StringCmp(L"abcdef", L"abcdef");
	printf("nResult=%d\n", nResult);

}