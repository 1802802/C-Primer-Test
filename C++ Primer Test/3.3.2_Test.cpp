/*#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

int main()  //��ϰ3.14 ����
{
	int word;
	vector<int>text;
	while (cin >> word)
		text.push_back(word);
	for (auto a : text)
		cout << a << " ";
	cout << endl;
}

/*int main()  //��ϰ3.15 �ַ���
{
	string word;
	vector<string>text;
	while (cin >> word)
	{
		text.push_back(word);
	}
	for (auto a : text)  //�������
	cout << a << " ";
	cout << endl;
}*/