/*#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
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
#include <utility>
#include <memory>
using namespace std;

class HasPtr  //ģ����    ��ϰ13.23
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}   //����һ���ַ�����Ĭ�Ϲ��캯��
	HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) {}  //�������캯�� 
	HasPtr& operator=(const HasPtr &rhs)  //������ֵ�����=�Ĺ��캯��  
	{
		string *p = new string(*rhs.ps);
		delete ps;
		ps = p;
		i = rhs.i;
		return *this;
	}
	~HasPtr()  //��ϰ13.10  //��������
	{
		delete ps; //����delete����ps����Ϊ����new�Ķ�̬�ڴ棬��Ҫ�ֶ��ͷ�
	}
	string *ps;
	int i;
}; 

class StrBlob  //��ϰ13.26 ��Ҫ�Ǽ��˿������캯���Ϳ�����ֵ�����
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {} //Ĭ�ϵĿչ��캯��
	StrBlob(initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}  //Ĭ�Ϲ��캯��������һ��list<string>������

	StrBlob(const StrBlob &temp) :data(make_shared<vector<string>>(*temp.data)) { cout << "�������캯��" << endl; }  //�������캯��
	StrBlob &operator=(const StrBlob &temp) //������ֵ�����
	{
		data = make_shared<vector<string>>(*temp.data);
		cout << "������ֵ�����" << endl;
		return *this;
	}

	//����Ϊ�������ܺ����Ķ���
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string& front() const;
	string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
	shared_ptr<vector<string>>check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

string& StrBlobPtr::deref() const  //������
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()  //����
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();  //����wptr�Ƿ񻹴���
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this, 0);
}


StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

int main(int argc, char**argv)
{
	ifstream in("input_line.txt");
	string word;
	StrBlob a,b;
	while (getline(in, word))
		b.push_back(word);
	a = b;
	StrBlob c(a);
	for (StrBlobPtr pbeg(a.begin()), pend(a.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
	return 0;
}*/