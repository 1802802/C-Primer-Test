/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	vector<string>text;
	string word1, word2, wordm;
	int sum, maxsum = 0;
	while (cin >> word1)
	{
		if (word1 == word2)  //word1ΪĿǰ���뵥�ʣ�word2Ϊ��һ������ĵ���
			++sum;  //sum���ڱ�ʾĿǰ���ظ�����
		else
		{
			sum = 1;
			word2 = word1;
		}
		if (maxsum < sum)  //����µĴʵ��ظ����������ֵ�����滻���ֵ���ظ���
		{
			maxsum = sum;
			wordm = word1;
		}
	}
	if (maxsum <= 1)
		cout << "û�е����ظ����ֹ�" << endl;
	else
		cout << "����" << wordm << "�ظ�������" << maxsum << endl;
	return 0;
}*/
