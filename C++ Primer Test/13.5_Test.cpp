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

class StrVec
{
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}  //Ĭ�Ϲ��캯��
	StrVec(initializer_list<string> &temp)   //initializer_list<string>�Ĺ��캯��
	{
		auto newdata = alloc_n_copy(temp.begin(), temp.end());
		elements = newdata.first;
		first_free = cap = newdata.second;   //�����=cap�ǳ���Ҫ������cap���¸�ֵ����Ȼ�ᱨ��
	}
	StrVec(const StrVec&);  //�������캯��������
	StrVec &operator=(const StrVec&);  //������ֵ�����������
	~StrVec();  //��������������
	void push_back(const string&);  //����Ԫ�صĺ�������
	size_t size() const { return first_free - elements; }  //���ô�С�ĺ�������
	size_t capacity() const { return cap - elements; }  //�ڴ�ռ��С�ĺ�������
	string *begin() const { return elements; }   //ָ����Ԫ�ص�ָ�룬����vector��begin
	string *end() const { return first_free; }	 //ָ�����һλԪ����һλ��ָ�룬����vector��end
//private:
	allocator<string> alloc;  //���string��δ�����ڴ棬���ڷ���Ԫ��
	void chk_n_alloc()	//���������Ԫ��ǰ�������ڴ�λ�ü��ĺ���
	{
		if (size() == capacity())reallocate();  //�������ڴ��������ڴ�ʱ���Զ������µĿռ�
	}
	pair<string*, string*>alloc_n_copy(const string*, const string*); //�����㹻���ڴ������������Χ�ڵ�Ԫ�أ������������ЩԪ�ر��浽�µ��ڴ���
	void free();			//��������Ԫ�ز��ͷ��ڴ�ĺ���
	void reallocate();		//���ڻ�ø����ڴ沢��������Ԫ��
	void reserve(size_t &);
	void resize(size_t &);
	string *elements;		//ָ��������Ԫ�ص�ָ��
	string *first_free;		//ָ�������һ������Ԫ�ص�ָ��
	string *cap;			//ָ������β��λ�õ�ָ��
};

StrVec::StrVec(const StrVec &s)   //�������캯��
{
	auto newdata = alloc_n_copy(s.begin(), s.end());   //newdata����ֵ����Ϊһ���µ��ڴ���ָ�����һ��Ԫ�غ����ָ�룬��end��ͬʱ�������ڴ��д洢��s������
	elements = newdata.first;     //begin����
	first_free = newdata.second;  //end����
}

StrVec &StrVec::operator=(const StrVec &rhs)  //������ֵ�����
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());  //�����µ��ڴ棬data�������ڴ�Ԫ�ص�begin��end
	free();  //��ս�Ҫ�������Ԫ��
	elements = data.first;  //ʹ�����ڴ��ָ������ʼ��
	first_free = data.second;
	return *this;  //����rhs�е�string�ַ���
}

StrVec::~StrVec()  //��������
{
	free();
}

void StrVec::reserve(size_t &sz)
{
	auto newcapacity = sz;  //�Զ����ڴ��С
	auto newdata = alloc.allocate(newcapacity);  //����������ڴ���䵽���ڴ��У�����newdataָ�����ڴ��beginλ��
	auto dest = newdata;  //dest�����ڴ��begin
	auto elem = elements; //elemΪ���ڴ��begin
	if (sz >= size())  //sz��size��С�Ƚϣ�������ڻ����ʱ������ֵ������С��ʱ��ֻ����sz�������Ĳ���
	{
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));  //�����ڴ�ĵ�һλ��ʼ������������Ӿ��ڴ��Ԫ��
	}
	else
	{
		for (size_t i = 0; i != sz; ++i)
			alloc.construct(dest++, std::move(*elem++));  //�����ڴ�ĵ�һλ��ʼ������������Ӿ��ڴ��Ԫ��
	}
	free(); //�ͷž��ڴ�ռ�
	elements = newdata;
	first_free = dest;  //���������dest��Ϊ�����ڴ��end
	cap = elements + newcapacity;  //�ڴ����λ�õ�ָ�룬�ɿ�ͷָ�����������
}

void StrVec::resize(size_t &sz)
{
	if (sz >= size())
	{
		cap = first_free + sz;
		auto temp = first_free + (sz - size());
		first_free = temp;
	}
	else
	{
		auto temp = first_free - (size() - sz);
		first_free = temp;
	}
	chk_n_alloc();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);  //alloc�Ĺ��죬�൱����first_freeָ����ָ��λ��������ַ���s
}

pair<string*, string*>StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);   //b��string��endָ�룬e��string��beginָ�룬��Ϊalloc�ķ��䣬dataָ���������ڴ��begin
	return{ data,uninitialized_copy(b,e,data) };  //����ָ����������ڴ��begin��ָ��data���������佫b��e�е����ݿ�����data��ָ���ڴ���,������ָ�����ڴ����һ��Ԫ��֮��λ�õ�ָ�룬��end
}

void StrVec::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)   //���������ٵ�string����������Ԫ��
			//alloc.destroy(--p);
		for_each(elements, first_free, [this](string &rhs) { alloc.destroy(&rhs); });//this��ָ��ǰ���ָ�룬�Ӿ��ڴ�Ŀ�ͷ����β������alloc��destroyָ��ǰλ�������Ԫ�أ�rhsΪһ��ָ��
		alloc.deallocate(elements, cap - elements); //�ͷ�string��ʹ�õ��ڴ棨��Ȼ��ʱɾ����Ԫ�أ����ڴ滹�ڣ�����Ϊ�գ�
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //��������ڴ�
	auto newdata = alloc.allocate(newcapacity);  //����������ڴ���䵽���ڴ��У�����newdataָ�����ڴ��beginλ��
	auto dest = newdata;  //dest�����ڴ��begin
	auto elem = elements; //elemΪ���ڴ��begin
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));  //�����ڴ�ĵ�һλ��ʼ������������Ӿ��ڴ��Ԫ��
	free(); //�ͷž��ڴ�ռ�
	elements = newdata;
	first_free = dest;  //���������dest��Ϊ�����ڴ��end
	cap = elements + newcapacity;  //�ڴ����λ�õ�ָ�룬�ɿ�ͷָ�����������
}

using line_no = vector<string>::size_type;

class QueryResult  //�ַ���ӡ��
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<StrVec> f) :sought(s), lines(p), file(f) {}  //���캯��
private:
	string sought;  //�����ѯ�ĵ���
	shared_ptr<set<line_no>> lines;  //ָ�򵥴ʳ��ֵ��к�set��
	shared_ptr<StrVec> file; //ָ�򱣴�ÿ�������ļ���vector
};

class TextQuery  //�ַ������࣬ͨ�������ļ����õ��洢��ÿ�����ݣ��Լ���ͬ���ʳ��ִ��������ݡ�
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	TextQuery(ifstream&);//���캯�������������嶨���ⲿ
	QueryResult query(const string&) const;
private:
	shared_ptr<StrVec> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) :file(new StrVec)
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
	initializer_list<string> temp{ "i","can","fly" };
	StrVec a(temp);
	a.push_back("me");
	a.push_back("and");
	a.push_back("you");
	size_t sz = 10;
	a.reserve(sz);
	//a.resize(sz);
	for (auto &s : a)
		cout << s << a.capacity() << a.size() << endl;
	//runQueries(ifstream("input_line.txt"));
}*/

//�����е�resize��reserve��д���Բ��Ͻ�����Ҫ��ѧϰ�ƶ����캯������иĽ�