/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>  
#include <algorithm>  
#include <numeric>  
#include <functional>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>

using namespace std;
using line_no = vector<string>::size_type;

class QueryResult  //�ַ���ӡ��
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}  //���캯��
private:
	string sought;  //�����ѯ�ĵ���
	shared_ptr<set<line_no>> lines;  //ָ�򵥴ʳ��ֵ��к�set��
	shared_ptr<vector<string>> file; //ָ�򱣴�ÿ�������ļ���vector
};

class TextQuery  //�ַ������࣬ͨ�������ļ����õ��洢��ÿ�����ݣ��Լ���ͬ���ʳ��ִ��������ݡ�
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	TextQuery(ifstream&);//���캯�������������嶨���ⲿ
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);  //��vector�н�Դ�ļ�ÿ�б���
		int n = file->size();  //��¼�к�
		istringstream line(text);  //�ֽ�ÿ�У�ʹ֮��Ϊ�������ʣ��ٴ��γ�������
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];  //������ĵ��ʴ���map�У��Լ�������ͬʱ�ٴ���һ�������͵�ָ��lines��ָ��map��Ԫ��set
			if (!lines)
				lines.reset(new set<line_no>);  //��wm����word���������Ӧ��Ԫ�أ���ִ�д���䣻
			//û��word��������룬��ʱ��word��Ԫ��Ϊ�գ�ִ�д���䣬Ϊ�����һ���µ�set��Ϊ��Ԫ��
			lines->insert(n);//�ڶ�Ӧ��wordԪ��set�в������֣���������
		}
	}
}

QueryResult TextQuery::query(const string &sought)const  //���Һ��������ڽ�����ĵ��ʽ��в�ѯ�����洢����
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);  //һ���յ�setָ��
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); //û�ҵ�����������ʣ������ݣ������ļ�
	else
		return QueryResult(sought, loc->second, file); //�ҵ��ˣ���������ʣ����ִ����������ļ�
}

ostream &print(ostream &os, const QueryResult &qr)  //���ڴ�ӡ����
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num << ") " << *(qr.file->begin() + num - 1) << endl;
	return os;
}

void runQueries(ifstream &infile)  //ͳ�ﺯ���������������ݣ��Լ�ʹ�����Ӵ�ӡ
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter a word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	runQueries(ifstream ("input_line.txt"));
}*/