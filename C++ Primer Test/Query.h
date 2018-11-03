#include <vector>
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
	//friend ostream& print_qr(ostream &a, const Query &b, ifstream &c);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}  //���캯��
	auto begin() { return (*lines).begin(); }
	auto end() { return (*lines).end(); }
	auto get_file() { return file; }
//private:
	string sought;  //�����ѯ�ĵ���
	shared_ptr<set<line_no>> lines;  //ָ�򵥴ʳ��ֵ��к�set��
	shared_ptr<vector<string>> file; //ָ�򱣴�ÿ�������ļ���vector
};

class TextQuery  //�ַ������࣬ͨ�������ļ����õ��洢��ÿ�����ݣ��Լ���ͬ���ʳ��ִ��������ݡ�
{
	friend ostream& print(ostream&, const QueryResult&);
	//friend ostream& print_qr(ostream&, const Query &, ifstream &);
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

class history
{
public:
	friend void runQueries(ifstream &, history &);
	static int num;
	map<int, QueryResult> his;
};
int history::num = 1;

void runQueries(ifstream &infile,history &h)  //ͳ�ﺯ���������������ݣ��Լ�ʹ�����Ӵ�ӡ
{
	cin.clear();
	TextQuery tq(infile);
	while (true)
	{
		cin.clear();
		cout << "enter a word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
		h.his.insert({ h.num,tq.query(s) });
		++(h.num);
	}
}

void check_history(history &h)
{
	cin.clear();
	cout << "do you want to check the history? : (yes/no) ";
	string s;
	if (!(cin >> s) || s == "no") return;
	while (true)
	{
		cin.clear();
		cout << "enter a number of history or other to quit: ";
		int number;
		if (!(cin >> number) || number == 0) break;
		auto temp = (h.his).find(number);
		auto limit = (h.his).size();
		if (number > limit)
		{
			cout << "out of range!" << endl;
			cin.clear();
		}
		else
		{
			cout << temp->first << " # ";
			print(cout, temp->second);
			cin.clear();
		}
	}
}

class Query_base
{
	friend class Query;
protected:
	//using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &) const = 0;  //����eval�����������뵱ǰQueryƥ���QueryResult
	virtual string rep() const = 0;  //rep��ʾ��ѯ��string
};

class Query
{
	//������Ԫ
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string &);   //����һ���µ�WordQuery
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }   //�����뵱ǰQueryƥ���QueryResult
	string rep() const { cout << "Query��rep()" << endl; return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) :q(query){ cout << "Query����Ĭ�Ϲ��캯��" << endl; }  //����Ĭ�Ϲ��캯��
	shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query)
{
	return os << query.rep();
}

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const string &s) :query_word(s) { cout << "WordQuery����Ĭ�Ϲ��캯��" << endl; }   //����Ĭ�Ϲ��캯��
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }  //�����麯��
	string rep() const { cout << "WordQuery��rep()" << endl; return query_word;}   //�����麯��
	string query_word; 
};
inline Query::Query(const string &s):q(new WordQuery(s)){}  //��ӦQuote�н�����Ӧ�ĺ���������һ���µ�word_query

class NotQuery : public Query_base
{
	friend Query operator~ (const Query &);
	NotQuery(const Query &q) :query(q){ cout << "NotQuery����Ĭ�Ϲ��캯��" << endl; }  //����Ĭ�Ϲ��캯��
	QueryResult eval(const TextQuery &) const;
	string rep() const { cout << "NotQuery��rep()" << endl; return "~(" + query.rep() + ")";}
	Query query;
};
inline Query operator~(const Query &operand) { return shared_ptr<Query_base>(new NotQuery(operand)); }
QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text);  //ͨ��Query��������eval��������ã����result��QueryResult�Ķ���
	auto ret_lines = make_shared<set<line_no>>();  //����һ���յ�set
	auto beg = result.begin(), end = result.end();  //beg��ָ���鵥�ʵĳ����к�begin��������end��end������
	auto sz = result.get_file()->size();  //�õ������ļ���size��С
	for (size_t n = 0; n != sz; n++)   //һ�����ָ��в���result�У�������ӵ�ret_lines��
	{
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else
			if (beg != end)
				++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) { cout << "BinaryQuery����Ĭ�Ϲ��캯��" << endl; }
	//�����ࣺBinaryQuote������eval
	string rep() const { cout << "BinaryQuery��rep()" << endl; return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator &(const Query&, const Query &);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&"){ cout << "AndQuery����Ĭ�Ϲ��캯��" << endl; }
	//������ࣺAndQuery�̳���rep���Ҷ����������麯��
	QueryResult eval(const TextQuery &) const;
};
inline Query operator&(const Query &lhs, const Query &rhs) { return shared_ptr<Query_base>(new AndQuery(lhs, rhs)); }
QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	//ʹ�ñ�׼���㷨���ϲ�����left��right�д��������set
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query &);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") { cout << "OrQuery����Ĭ�Ϲ��캯��" << endl; }
	//������ࣺAndQuery�̳���rep���Ҷ����������麯��
	QueryResult eval(const TextQuery &) const;
};
inline Query operator|(const Query &lhs, const Query &rhs) { return shared_ptr<Query_base>(new OrQuery(lhs, rhs)); }
QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());   //����������һ��
	return QueryResult(rep(), ret_lines, left.get_file());
}

ostream &print_qr(ostream &os, const Query &q, ifstream &infile)  //���ڴ�ӡ����
{
	auto qr = q.eval(TextQuery(infile));
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num << ") " << *(qr.file->begin() + num - 1) << endl;
	return os;
}

//void runQueries(ifstream &infile)  //ͳ�ﺯ���������������ݣ��Լ�ʹ�����Ӵ�ӡ
//{
//	TextQuery tq(infile);
//	while (true)
//	{
//		cout << "enter a word to look for,or q to quit: ";
//		string s;
//		if (!(cin >> s) || s == "q") break;
//		print(cout, tq.query(s)) << endl;
//	}
//}