/*#include <iostream>
#include <vector>
#include <string>
using std::vector;
using namespace std;

/*int main()  //��ϰ3.17
{
	vector<string>text;
	string word;
	while (cin >> word)  //�������������
	{
		text.push_back(word);
	}
	for (auto &a : text) //һ�������ݣ���ȡ���е����ʣ����������ݣ���ȡÿ����ĸ
		for (auto &b : a)
			b = toupper(b);  //����Сд��ĸ����д��ĸ��ת��
	for (auto &a : text)   //�������дʣ��������
		cout << a << endl;
	return 0��
}*/
/*
int main()
{
	vector<int>text;
	int add = 0;
	while (cin >> add)
		text.push_back(add);
	cout << "�������ĺ�Ϊ";
	for (int a = 0; a < text.size() - 1; a++)  //����������ĺ�
	{
		int sum = 0;
		sum = text[a] + text[a + 1];
		cout << sum << " ";
	}
	cout << endl;
	int size = 0;
	cout << "ǰ���ĺ�Ϊ";
	for (int b = 0; b < text.size()/2; b++)  //���ǰ���ĺ�
	{
		int sum = 0;
		sum = text[b] + text[text.size() - b - 1];
		cout << sum << " ";
	}
	if (text.size() % 2 != 0)  //�ж����ݸ�����ȷ������ʱ�������
		cout << "��������" << text[text.size()/2] << " ";
	cout << endl;
	return 0;
}*/