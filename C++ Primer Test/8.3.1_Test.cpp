/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/*istream &fun(istringstream& is)
{
	string word;
	while (is >> word)
	{
		cout << word << endl;
	}
	is.clear();
	return is;
}

int main()  //��ϰ8.9
{
	string file = "8.3.1.txt";
	vector<string> text;
	ifstream in(file);
	istringstream word("hello world!");
	fun(word);
}*/


/*int main()   //��ϰ8.10
{
	string file = "8.3.1.txt";
	vector<string> text;
	ifstream in(file);

	if (in)  //����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		while (in >> buf)  //ÿ�����ʵĶ������룬�Զ��Կո�Ϊ���
		{
			text.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << file << endl;
	}
	for (auto &s : text)
	{
		istringstream record(s);
		string temp;
		while(record >> temp)
			cout << temp << endl;
	}
	return 0;
}*/

/*struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string file1 = "8.3.1.txt";
	string file2 = "8.3.1_out.txt";
	ifstream in(file1);
	ofstream out(file2);
	string line, word;
	vector<PersonInfo> people;
	istringstream record;  //�ⲿ�����ַ����Ķ�ȡ

	if (in)
	{
		while (getline(in, line))  //���ļ�file1����������;in>>lineЧ��Ϊȫ�����У�getline����Ч��Ϊ��������Ļ��з��Ż���
		{
			PersonInfo info;
			record.clear(); //ѭ���ڲ���λ
			record.str(line);//��line��record
			record >> info.name;  //ֻ��ȡһ�Σ��Ӷ���ȡ��һλ����
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}
	for (const auto &s : people)
	{
		out << "�û���Ϊ��" << s.name;   //����ofstreamҲ��IO��������ֱ�ӽ������cout����ĳɶ�Ӧ��of����out���������ʵ���ļ����
		for (const auto &s2 : s.phones)
			out << "  �绰����Ϊ��" << s2;
		out << endl;
	}
	return 0;
}*/