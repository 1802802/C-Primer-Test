/*#include<iostream>  
#include<string>  
#include<vector>  
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

int main1()  //��ϰ11.20
{
	ifstream in("file2.txt");
	map<string, int> count;
	string word;
	while (in >> word)
	{
		for (auto beg = word.begin(); beg != word.end();)
		{
			if (ispunct(*beg))  //ɾ��string�еı�����
				beg = word.erase(beg); //�����erase���õ���������ɾ�����壬��ɾ����Ӧ������λ�õ�ֵ������ָ���һ������������word��Ϊstring�ַ���Ҳ���Զ���erase����
			else
			{
				*beg = tolower(*beg);  //��дȫ�����Сд
				++beg;
			}
		}
		auto ret = count.insert({ word, 1 });  //insert�ķ�ʽ��¼�����Լ����������Ը�Ϊ����
		if (!ret.second)
			++ret.first->second;
	}
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	return 0;
}

int main2()  //��ϰ11.23
{
	multimap<string, vector<string>> family;
	string word1, word2;
	while ([&]()->bool { cout << "�����ͥ����" << endl; return (cin >> word1) && (word1 != "end"); }())  //�������ģ���ʵ�ڲ�����������ɾ
	{
		cout << "�����Ӧ��ͥ���ӵ�����" << endl;
		vector<string> temp;
		while (cin >> word2 && word2 != "end")
			temp.push_back(word2);
		family.insert({ word1,temp });  //�������������ۺ��壬ʡȥ�ܶ���
	}
	for (const auto &s : family)
		for (const auto &s2 : s.second)
			cout << s.first << " " << s2 << endl;
	return 0;
}*/