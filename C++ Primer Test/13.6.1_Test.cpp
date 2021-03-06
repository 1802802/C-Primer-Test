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
	String() { cout << "默认构造函数调用" << endl; }  //默认构造函数
	String(const char*s)//接受c风格字符串参数的构造函数，s为指向字符串的指针(首位置)
	{
		auto s1 = const_cast<char*>(s);//转化为非常量的指针
		while (*s1)
			++s1;//使其指向最后一个位置的尾部
		auto newdata = alloc_n_copy(s, s1);//进行拷贝
		elements = newdata.first;
		first_free = newdata.second;
		cout << "c风格字符串默认构造函数调用" << endl;
	}
	String(const String&);  //拷贝构造函数的声明
	String &operator=(const String&);  //拷贝赋值运算符的声明
	~String() { free(); };  //析构函数的声明

	size_t size() const { return first_free - elements; }  //已用大小的函数声明
	char *begin() const { return elements; }   //指向首元素的指针，类似vector的begin
	char *end() const { return first_free; }	 //指向最后一位元素下一位的指针，类似vector的end
private:
	allocator<char> alloc;  //存放char的未构造内存，用于分配元素
	pair<char*, char*>alloc_n_copy(const char*, const char*); //分配足够的内存来保存给定范围内的元素，并将输入的这些元素保存到新的内存中
	void range_initializer(const char*, const char*);
	void free();			//用于销毁元素并释放内存的函数
	char *elements;		//指向数组首元素的指针
	char *first_free;		//指向数组第一个空闲元素的指针
};

String::String(const String&s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cout << "拷贝构造函数调用" << endl;
}

String &String::operator=(const String&s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	cout << "拷贝赋值运算符调用" << endl;
	return *this;
}

pair<char*, char*>String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);   //b是string的end指针，e是string的begin指针，其为alloc的分配，data指向分配的新内存的begin
	return{ data,uninitialized_copy(b,e,data) };  //返回指向所分配的内存的begin的指针data，后面的语句将b到e中的数据拷贝到data所指的内存中,并返回指向新内存最后一个元素之后位置的指针，即end
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
		//for (auto p = first_free; p != elements;)   //先逆序销毁掉string中所包含的元素
		//alloc.destroy(--p);
		for_each(elements, first_free, [this](char &rhs) { alloc.destroy(&rhs); });//this是指向当前类的指针，从旧内存的开头到结尾，捕获alloc后，destroy指向当前位置所存的元素，rhs为一个指针
		alloc.deallocate(elements, first_free - elements); //释放string所使用的内存（虽然此时删除了元素，但内存还在，其内为空）
	}
}

void foo(String x)  //这里没有用引用，所以会直接赋值
{
	for (auto &s : x)
		cout << s;
	cout << endl;
}

void bar(const String& x)  //这里调用了一次拷贝构造函数
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

int main() //练习13.47与13.48
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
	baz();//baz()初始化一次C风格，然后函数的形参实参转换一次拷贝构造函数

	cout << endl;

	std::vector<String> svec;   
	cout << svec.capacity() << endl;
	svec.push_back(s0);  //新数据读入，调用正常的拷贝构造函数
	cout << svec.capacity() << endl;
	svec.push_back(s1);  //svec内存扩大，旧内存的元素到新内存的拷贝构造一次；新数据读入，调用正常的拷贝构造函数一次
	cout << svec.capacity() << endl; 
	svec.push_back(baz()); //svec内存扩大，旧内存的元素到新内存的拷贝构造两次；新数据读入，调用正常的拷贝构造函数一次；baz()函数调用一次C一次拷贝构造
	cout << svec.capacity() << endl;
	svec.push_back("good job");  //svec内存扩大，旧内存的元素到新内存的拷贝构造三次；新数据读入，调用正常的拷贝构造函数一次；good job作为C字符串一次C
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec内存扩大，旧内存的元素到新内存的拷贝构造四次；新数据读入，调用正常的拷贝构造函数一次；
	cout << svec.capacity() << endl;
	svec.push_back(s1);//新数据读入，调用正常的拷贝构造函数一次//因为此时的cap已经变成了6，此数据插入时不需要调整内存大小；
	cout << svec.capacity() << endl;
	svec.push_back(s1);//svec内存扩大，旧内存的元素到新内存的拷贝构造六次；新数据读入，调用正常的拷贝构造函数一次；
	cout << svec.capacity() << endl;

	for (auto &s : svec)
	{
		for (auto &ss : s)
			cout << ss;
		cout << " " << s.size() << " ";
	}
	cout << endl;
}*/