#include <vector>
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

class StrBlob  //��ϰ13.26 ��Ҫ�Ǽ��˿������캯���Ϳ�����ֵ�����
{
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
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
	string &operator[](size_t n) { check(n, "out_of_range"); return data->at(n); }    //��ͨ����
	const string &operator[](size_t n) const { check(n, "out_of_range"); return data->at(n); }   //��ĳ�����Ա�ĳ�������

	//����Ϊ�������ܺ����Ķ���
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void push_back(string &&t) { data->push_back(t); }
	void pop_back();
	string& front() const;
	string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

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
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	string &operator[](size_t n) { auto temp = check(n, "out of range"); return (*temp).at(n); }     //[]��ͨ����
	const string &operator[](size_t n) const { auto temp = check(n, "out of range"); return (*temp).at(n); }    //[]��������
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();   //ǰ�������
	StrBlobPtr& operator++(int);
	StrBlobPtr& operator--(int);  //�����������int��Ϊһ����־������������
private:
	shared_ptr<vector<string>>check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

StrBlobPtr &StrBlobPtr::operator++()
{
	check(curr, "incrment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr &StrBlobPtr::operator--()  //ǰ�������
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr &StrBlobPtr::operator++(int)
{

}
StrBlobPtr &StrBlobPtr::operator--(int) //�����������int��Ϊһ����־������������
{

}


bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return rhs < lhs;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

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