#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct stTest
{
	string m_name;
	int m_math;
	int m_eng;
	int m_lang;

	stTest(string name = "", int math = 0, int eng = 0, int lang = 0) :
		m_name(name), m_math(math), m_eng(eng), m_lang(lang) { }

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}

	void SetData (string& str)
	{
		stringstream ssTest(str);
		string line;

		while (getline(ssTest, line, ','))
		{
			line.erase(remove(line.begin(), line.end(), ' '), line.end()); //remove는 포인트만 알려줌 (실제로 지우는 역할 아님)
			printf("line[%s]\n", line.c_str());

			int index = line.find('=');
			string leftStr = line.substr(0, index);
			string rightStr = line.substr(index + 1, line.length() - index);

			if (leftStr == "name")
			{
				m_name = rightStr;
			}
			else if (leftStr == "math")
			{
				m_math = stoi(rightStr);
			}
			else if (leftStr == "eng")
			{
				m_eng = stoi(rightStr);
			}
			else if (leftStr == "lang")
			{
				m_lang = stoi(rightStr);

			}
		}
	}
};


int main()
{
	/*//파일 쓰기
	std::ofstream writeFile;
	writeFile.open("test.txt");	// txt 파일을 연다. (파일이 없다면은 생성한다.)

	std::string strTest = "test 1234 abcd 입니다.\n";
	writeFile.write(strTest.c_str(), strTest.size());
	writeFile.write(strTest.c_str(), strTest.size());

	writeFile.close();	// 파일을 열었으면 반드시 닫기*/

	// 파일 읽기
	std::ifstream readFile;
	readFile.open("test.txt");

	//bool z = true;

	vector<stTest> vecTest;
	/*stTest aaa("aaa", 80, 60, 70);
	vecTest.push_back(aaa);
	stTest bbb("bbb", 90, 30, 40);
	vecTest.push_back(bbb);
	stTest ccc("ccc", 20, 90, 80);
	vecTest.push_back(ccc);*/

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::string str;

			std::getline(readFile, str);	// readFile에 텍스트를 한 줄 읽어서 str에 넣는다.
			//printf("str=%s\n", str.c_str());

			/*std::string strleft = str.substr(2, 3);
			int nresult = stoi(strleft, &index);

			while (z)
			{
				test.a = nresult;
				z = false;
			}

			test.b = nresult;
			printf("str=%s\n", str.c_str());*/

			/*size_t x = str.find('=') + 1;
			if (str.find('a') == 0)
			{
				std::string teatA = str.substr(x, str.length() - x);
				test.a = stoi(teatA);
			}
			else if (str.find('b') == 0)
			{
				std::string teatB = str.substr(x, str.length() - x);
				test.b = stoi(teatB);
			}
			else
			{	}*/

			stTest newData;
			newData.SetData(str);
			vecTest.push_back(newData);

		}
		readFile.close();
	}
	
	for (stTest& test : vecTest)
	{
		test.printTest();
	}

}