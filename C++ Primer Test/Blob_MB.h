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

//ǰ����������Blob��������Ԫ����Ҫ��
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T>&a, const Blob<T>&b) { return a.data == b.data; }

template <typename T> class Blob
{
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//���캯��
	Blob() :data(make_shared<vector<T>>()) {}
	Blob(initializer_list<T> il) :data(make_shared<vector<T>>(il)) {}
	//Blob�е�Ԫ����Ŀ
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//��Ӻ�ɾ��Ԫ��
	void push_back(const T &t) { return data->push_back(t); }
	//�ƶ��汾
	void push_back(T &t) { data->push_back(std::move(t)); }
	void pop_back();
	//Ԫ�ط���
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	//��data[i]��Ч�����׳�msg
	void check(size_type i, const string &msg) const;
};

template<typename T> void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T> T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T> T& Blob<T>::operator[](size_type i)
{
	//���i̫��check���׳��쳣����ֹ����һ�������ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T> void Blob<T>::pop_back()
{
	check(0,"pop_back on empty Blob");
	data->pop_back();
}

template<typename T> class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	T& operator*() const
	{
		auto p = check(curr, "deference past end");
		return (*p)[curr];   //(*p)Ϊ������ָ���vector
	}
	//�����͵ݼ�
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr& operator++(int);
	BlobPtr& operator--(int);  //�����������int��Ϊһ����־������������
private:
	//�����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<T>> check(size_t, const string&) const;
	//����һ��weak_ptr����ʾ�ײ�vector���ܱ�����
	weak_ptr<vector<T>> wptr;
	size_t curr;  //�����е�ǰλ��
};

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of Blob<T>Ptr");
	++curr;
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(-1, "decrement past begin of Blob<T>Ptr");
	return *this;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template <typename T> inline BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}

template <typename T> inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();  //����wptr�Ƿ񻹴���
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}