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

using namespace std;

int main1() //��ϰ11.3
{
	ifstream in("file2.txt");
	map<string, int> count;
	set<string> exclude{ "" };
	string word;
	while (in >> word)
		++count[word];
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time " )<< endl;
	return 0;
}

int main2()  //��ϰ11.4
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
		++count[word];
	}
	for (const auto &s : count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	return 0;
}*/