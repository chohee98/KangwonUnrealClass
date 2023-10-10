#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// ���ӽ����̽��� ���� �ĺ��ڷ� �������� ���̺귯���� ����� �� �̸� ���� �浹�� �����ϱ� ���ؼ� ���
using namespace std;	//std �̸� ������ �������ڴ�. std ���̺귯�� �Լ� �տ� std�� ������ �ʾƵ� �ȴ�.

int main()
{
	/*
	* String �̶�?
	* - C++ STL���� ����ϴ� Ŭ������ ���ڿ��� �ٷ�� Ŭ����
	* C������ char* �Ǵ� char[]�� ���·� ���ڿ��� �ٷ���ٸ�, C++������ ���ڿ��� �ϳ��� ���� typeó�� ���
	* ���ڿ��� �پ��ϰ� ���� �ٷ� �� �ְ� �� �ش�.
	* char* char[]�� �ٸ��� ���ڿ��� ���� \0 ���ڰ� ���� ������, ���ڿ��� ���̸� �������� ���� �����ϴ�.
	*/

	wchar_t chars[20] = L"abcdef";
	char result = wcscmp(chars, L"abcdef");
	wcscpy_s(chars, 20, L"ghjkl");

	// ������ : std::string
	// ���� �̸� : strA
	// �⺻�� : ("abcdef")
	std::string strA("abcdef");
	printf("strA = %s\n", strA.c_str()); //���ڿ� ����� c_str()�� ����Ͽ� ���
	size_t size = strA.size();	//���ڿ��� ũ�� ���ϱ�(�޸𸮰���)
	size_t len = strA.length();	//���ڿ��� ���� ���ϱ�(���ڿ� ����)

	std::string A("12");
	std::string B("34");
	A += B;
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	A = B;
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	if (A == B)	//���ڿ� �� ������ ����
	{
		printf("A�� B�� ����.\n");
	}

	std::wstring wstr; // wchar_t�� string
	//auto : ������ ���� ���¿� ���� �ڵ����� �������� ���� �ȴ�.
	auto stringS = "abcdef"s; // string �������� ����

	double d = 3.14;
	string strD = to_string(d); // ���� -> ���� ��ȯ
	printf("strD = %s\n", strD.c_str());

	string toParse = "123USD456";
	size_t index = 0;
	// stoi(int), stof(float), stod(double), stol(long)
	int nresult = stoi(toParse, &index);	// ���� -> ���ڷ� ��ȯ
	printf("stoi result=%d\n", nresult);	// nresult : ��ȯ�� ���� = 123
	printf("toParses index Character=%c\n", toParse[index]); // Parse�� �Ұ����� ���� ����Ʈ

	string findStr = "123SABC456SORRY";
	int nPointL = findStr.find('S');	// ���ʿ��� ���� ���� ã��
	printf("Find Point[%d] Character = %c\n", nPointL, findStr[nPointL]);	// nPointL : ã�� ���ڿ� ��ġ
	int nPointR = findStr.rfind('S');	// �����ʿ��� ���� ���� ã��
	printf("Find Point[%d] Character = %c\n", nPointR, findStr[nPointR]);	// nPointR : ã�� ���ڿ� ��ġ

	string strleft = findStr.substr(0, nPointL);	// ���ڿ� �߶����. 0�� �������̰� nPointL ���� ��ŭ. // 123
	string strcenter = findStr.substr(nPointL, nPointR - nPointL);
	string strright = findStr.substr(nPointR, findStr.length() - nPointR);
	printf("strleft=%s\nstrcenter=%s\nstrright=%s\n", strleft.c_str(), strcenter.c_str(), strright.c_str());



	string testStr = "1,2,3,4,5,6,7,8,9";

	stringstream ssTest(testStr);	// string ���ڿ��� stringstream ���� ���·� �����.
	string line;	// �о�� string ��� �� ����

	// setTest�� ���ʺ��� ','�� �������� ���ڸ� �о line�� �ִ´�.
	// getline ����� false(���̻� ���� ���ڿ��� ����)�� ����
	while (getline(ssTest, line, ','))	
	{
		printf("line=%s\n", line.c_str());
	}

	//��Ʈ������ Ư�� ���� ����
	testStr.erase(remove(testStr.begin(), testStr.end(), ' '), testStr.end());
	printf("testStr[%s]\n", testStr.c_str());

}