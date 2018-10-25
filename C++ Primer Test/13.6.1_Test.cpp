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

class String
{
public:
	String() { cout << "Ĭ�Ϲ��캯������" << endl; }  //Ĭ�Ϲ��캯��
	String(const char*s)//����c����ַ��������Ĺ��캯����sΪָ���ַ�����ָ��(��λ��)
	{
		auto s1 = const_cast<char*>(s);//ת��Ϊ�ǳ�����ָ��
		while (*s1)
			++s1;//ʹ��ָ�����һ��λ�õ�β��
		auto newdata = alloc_n_copy(s, s1);//���п���
		elements = newdata.first;
		first_free = newdata.second;
		cout << "c����ַ���Ĭ�Ϲ��캯������" << endl;
	}
	String(const String&);  //�������캯��������
	String &operator=(const String&);  //������ֵ�����������
	~String() { free(); };  //��������������

	size_t size() const { return first_free - elements; }  //���ô�С�ĺ�������
	char *begin() const { return elements; }   //ָ����Ԫ�ص�ָ�룬����vector��begin
	char *end() const { return first_free; }	 //ָ�����һλԪ����һλ��ָ�룬����vector��end
private:
	allocator<char> alloc;  //���char��δ�����ڴ棬���ڷ���Ԫ��
	pair<char*, char*>alloc_n_copy(const char*, const char*); //�����㹻���ڴ������������Χ�ڵ�Ԫ�أ������������ЩԪ�ر��浽�µ��ڴ���
	void range_initializer(const char*, const char*);
	void free();			//��������Ԫ�ز��ͷ��ڴ�ĺ���
	char *elements;		//ָ��������Ԫ�ص�ָ��
	char *first_free;		//ָ�������һ������Ԫ�ص�ָ��
};

String::String(const String&s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cout << "�������캯������" << endl;
}

String &String::operator=(const String&s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	cout << "������ֵ���������" << endl;
	return *this;
}

pair<char*, char*>String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);   //b��string��endָ�룬e��string��beginָ�룬��Ϊalloc�ķ��䣬dataָ���������ڴ��begin
	return{ data,uninitialized_copy(b,e,data) };  //����ָ����������ڴ��begin��ָ��data���������佫b��e�е����ݿ�����data��ָ���ڴ���,������ָ�����ڴ����һ��Ԫ��֮��λ�õ�ָ�룬��end
}

void String::range_initializer(const char*a, const char*b)
{
	auto newdata = alloc_n_copy(a, b);
	elements = newdata.first;
	first_free = newdata.second;
}

void String::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)   //���������ٵ�string����������Ԫ��
		//alloc.destroy(--p);
		for_each(elements, first_free, [this](char &rhs) { alloc.destroy(&rhs); });//this��ָ��ǰ���ָ�룬�Ӿ��ڴ�Ŀ�ͷ����β������alloc��destroyָ��ǰλ�������Ԫ�أ�rhsΪһ��ָ��
		alloc.deallocate(elements, first_free - elements); //�ͷ�string��ʹ�õ��ڴ棨��Ȼ��ʱɾ����Ԫ�أ����ڴ滹�ڣ�����Ϊ�գ�
	}
}

void foo(String x)  //����û�������ã����Ի�ֱ�Ӹ�ֵ
{
	for (auto &s : x)
		cout << s;
	cout << endl;
}

void bar(const String& x)  //���������һ�ο������캯��
{
	for (auto &s : x)
		cout << s;
	cout << endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main() //��ϰ13.47��13.48
{
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;
	for (auto &s : s1)
		cout << s;
	cout << s1.size() << endl;

	cout << endl;

	foo(s1);
	bar(s1);

	cout << endl;

	foo("temporary");
	bar("temporary");
	String s4 = baz();
	String &s5 = baz();
	baz();//baz()��ʼ��һ��C���Ȼ�������β�ʵ��ת��һ�ο������캯��

	cout << endl;

	std::vector<String> svec;   
	cout << svec.capacity() << endl;
	svec.push_back(s0);  //�����ݶ��룬���������Ŀ������캯��
	cout << svec.capacity() << endl;
	svec.push_back(s1);  //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ�������һ�Σ������ݶ��룬���������Ŀ������캯��һ��
	cout << svec.capacity() << endl; 
	svec.push_back(baz()); //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ����������Σ������ݶ��룬���������Ŀ������캯��һ�Σ�baz()��������һ��Cһ�ο�������
	cout << svec.capacity() << endl;
	svec.push_back("good job");  //svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ����������Σ������ݶ��룬���������Ŀ������캯��һ�Σ�good job��ΪC�ַ���һ��Cһ�ο�������
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ��������ĴΣ������ݶ��룬���������Ŀ������캯��һ�Σ�
	cout << svec.capacity() << endl;
	svec.push_back(s1);//�����ݶ��룬���������Ŀ������캯��һ��//��Ϊ��ʱ��cap�Ѿ������6�������ݲ���ʱ����Ҫ�����ڴ��С��
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec�ڴ����󣬾��ڴ��Ԫ�ص����ڴ�Ŀ����������Σ������ݶ��룬���������Ŀ������캯��һ�Σ�
	cout << svec.capacity() << endl;

	for (auto &s : svec)
	{
		for (auto &ss : s)
			cout << ss;
		cout << " " << s.size() << " ";
	}
	cout << endl;
}*/