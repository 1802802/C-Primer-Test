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

int main1()  //��ϰ11.7
{
	map<string, vector<string>> family;
	string word1,word2;
	while ([&]()->bool { cout << "�����ͥ����" << endl;return (cin >> word1) && (word1 != "end"); }())  //�������ģ���ʵ�ڲ�����������ɾ
	{
		family[word1];
		cout << "�����Ӧ��ͥ���ӵ�����" << endl;
		while (cin >> word2 && word2 != "end")
				family[word1].push_back(word2);
	}
	for (const auto &s : family)
		for (const auto &s2 : s.second)
			cout << s.first << " " << s2 << endl;
	return 0;
}

int main() //��ϰ11.8
{
	ifstream in("file2.txt");
	map<string, int>word_count;
	vector<string> exclude{ "I" ,"and","me"};
	string word;
	int temp = 0;
	while (in >> word)
	{
		if (find(exclude.begin(), exclude.end(), word) == exclude.end())  //find������Ӧ����set�������÷���̫һ��
			++word_count[word];
	}
	for (const auto &s : word_count)
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
}*/