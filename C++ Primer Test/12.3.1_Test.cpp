/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main()  //��ϰ12.28
{
	ifstream in1("input_line.txt");
	ifstream in2("input_line.txt");
	string word1, word2;
	vector<string> save;
	set<string> line;
	map<string, int> place;
	while (getline(in1, word1))
		save.push_back(word1);
	while (in2 >> word2)
		++place[word2]; 


	cout << "������Ҫ���ҵ��ַ�" << endl;
	string temp;
	cin >> temp;
	auto ct = place.find(temp);  //����ʵ���ַ������˶��ٴ�
	if (ct != place.end())  //�����ַ������Ƿ���ڸ��ַ�
		cout << "word " << temp << " occurs " << ct->second << ((ct->second > 1) ? " times " : " time ") << endl;
	else
	{
		cout << "word not in!" << endl;
		return 0;
	}

	int n = 1;
	for (auto &s : save)  //ʵ�ֽ����ֹ����ַ���ĳһ��ö�ٲ���ӡ����
	{
		auto pl = s.find(temp);
		if (pl != string::npos)
			cout << "    " << "(line" << n << ")" << " " << s << endl;
		n++;
	}
}*/