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

using namespace std;

int main()  //��ϰ10.42
{
	list<string> words{ "my","name","is","amazing","name" };
	for (auto &s : words)
		cout << s << endl;
	for (auto beg = words.begin(); beg != words.end(); beg++)
		cout << "ԭ��Ϊ��" << *beg << endl;
	words.sort();
	words.unique();
	//doit(words);
	for (auto beg = words.begin(); beg != words.end(); beg++)
		cout << "�޸�Ϊ��" << *beg << endl;
}*/