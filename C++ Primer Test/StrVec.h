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

class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}  //默认构造函数
	StrVec(initializer_list<string> &temp)   //initializer_list<string>的构造函数
	{
		auto newdata = alloc_n_copy(temp.begin(), temp.end());
		elements = newdata.first;
		first_free = cap = newdata.second;   //这里的=cap非常重要，即对cap重新赋值，不然会报错
	}
	StrVec(const StrVec&);  //拷贝构造函数的声明
	StrVec(StrVec &&) noexcept;  //移动构造函数的声明
	StrVec &operator=(const StrVec&);  //拷贝赋值运算符的声明
	StrVec &operator=(StrVec &&) noexcept;  //移动赋值运算符的声明
	StrVec &operator=(initializer_list<string> il);
	~StrVec();  //析构函数的声明
	void push_back(const string&);  //拷贝元素的函数声明
	size_t size() const { return first_free - elements; }  //已用大小的函数声明
	size_t capacity() const { return cap - elements; }  //内存空间大小的函数声明
	string *begin() const { return elements; }   //指向首元素的指针，类似vector的begin
	string *end() const { return first_free; }	 //指向最后一位元素下一位的指针，类似vector的end
												 //private:
	allocator<string> alloc;  //存放string的未构造内存，用于分配元素
	void chk_n_alloc()	//用于在添加元素前，进行内存位置检查的函数
	{
		if (size() == capacity())reallocate();  //当所用内存大于最大内存时，自动分配新的空间
	}
	pair<string*, string*>alloc_n_copy(const string*, const string*); //分配足够的内存来保存给定范围内的元素，并将输入的这些元素保存到新的内存中
	void free();			//用于销毁元素并释放内存的函数
	void reallocate();		//用于获得更多内存并拷贝已有元素
	void reserve(size_t &);
	void resize(size_t &);
	string *elements;		//指向数组首元素的指针
	string *first_free;		//指向数组第一个空闲元素的指针
	string *cap;			//指向数组尾后位置的指针
};

StrVec &StrVec::operator=(initializer_list<string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	return rhs < lhs;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

StrVec::StrVec(const StrVec &s)   //拷贝构造函数
{
	auto newdata = alloc_n_copy(s.begin(), s.end());   //newdata被赋值，其为一个新的内存中指向最后一个元素后面的指针，即end。同时，该新内存中存储了s的数据
	elements = newdata.first;     //begin定义
	first_free = newdata.second;  //end定义
}

StrVec::StrVec(StrVec &&s) noexcept  //移动构造函数
{
	elements = s.elements;
	first_free = s.first_free;
	cap = s.cap;
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs)  //拷贝赋值运算符
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());  //分配新的内存，data保存了内存元素的begin和end
	free();  //清空将要定义的类元素
	elements = data.first;  //使用新内存的指针来初始化
	first_free = data.second;
	return *this;  //返回rhs中的string字符串
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept  //移动赋值运算符
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec()  //析构函数
{
	free();
}

void StrVec::reserve(size_t &sz)
{
	auto newcapacity = sz;  //自定义内存大小
	auto newdata = alloc.allocate(newcapacity);  //将两倍大的内存分配到新内存中，其中newdata指向新内存的begin位置
	auto dest = newdata;  //dest即新内存的begin
	auto elem = elements; //elem为旧内存的begin
	if (sz >= size())  //sz与size大小比较，当其大于或等于时正常赋值，当其小于时则只拷贝sz所包含的部分
	{
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	}
	else
	{
		for (size_t i = 0; i != sz; ++i)
			alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	}
	free(); //释放旧内存空间
	elements = newdata;
	first_free = dest;  //递增到最后，dest成为了新内存的end
	cap = elements + newcapacity;  //内存最大位置的指针，由开头指针加整体容量
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
	alloc.construct(first_free++, s);  //alloc的构造，相当于向first_free指针所指的位置中添加字符串s
}

pair<string*, string*>StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);   //b是string的end指针，e是string的begin指针，其为alloc的分配，data指向分配的新内存的begin
	return{ data,uninitialized_copy(b,e,data) };  //返回指向所分配的内存的begin的指针data，后面的语句将b到e中的数据拷贝到data所指的内存中,并返回指向新内存最后一个元素之后位置的指针，即end
}

void StrVec::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)   //先逆序销毁掉string中所包含的元素
		//alloc.destroy(--p);
		for_each(elements, first_free, [this](string &rhs) { alloc.destroy(&rhs); });//this是指向当前类的指针，从旧内存的开头到结尾，捕获alloc后，destroy指向当前位置所存的元素，rhs为一个指针
		alloc.deallocate(elements, cap - elements); //释放string所使用的内存（虽然此时删除了元素，但内存还在，其内为空）
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //两倍大的内存
	auto newdata = alloc.allocate(newcapacity);  //将两倍大的内存分配到新内存中，其中newdata指向新内存的begin位置
	auto dest = newdata;  //dest即新内存的begin
	auto elem = elements; //elem为旧内存的begin
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));  //从新内存的第一位开始，往内依次添加旧内存的元素
	free(); //释放旧内存空间
	elements = newdata;
	first_free = dest;  //递增到最后，dest成为了新内存的end
	cap = elements + newcapacity;  //内存最大位置的指针，由开头指针加整体容量
}
