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

class Folder
{
	friend class Message;
public:
	void addMsg(Message *temp)
	{
		mes.insert(temp);
	}
	void remMsg(Message *temp)
	{
		mes.erase(temp);
	}
	//private:
	set<Message*> mes;
};

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string &str = "") :contents(str) {}   //默认构造函数
	Message(const Message&);  //拷贝构造函数的声明
	Message(Message &&);  //移动构造函数的声明
	Message& operator=(const Message&);  //拷贝赋值运算符的声明
	Message& operator=(Message &&);  //移动赋值运算符的声明
	~Message();  //析构函数的声明
				 //面对所针对的Folder进行单个的删除与存储
	void save(Folder&);
	void remove(Folder&);
	//private:
	string contents;   //保存消息文本的string
	set<Folder*> folders;   //内含指向保存了本Message的Folder的指针
	void add_to_Folders(const Message&);  //本Message添加到别的Folder集合里的函数声明
	void remove_from_Folders();  //本Message从所有Folder中删除的函数声明
	void move_Folders(Message *);
};

Message::Message(const Message &m) :contents(m.contents), folders(m.folders) { add_to_Folders(m); }   //拷贝构造函数的定义

Message::Message(Message &&m)   //移动构造函数
{
	contents = std::move(m.contents);
	move_Folders(&m);   //m的值转移到了类成员中，同时其指向folders的指针也只有类成员的了
}

Message& Message::operator=(const Message &rhs)  //拷贝赋值运算符
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message &&rhs)  //移动赋值运算符
{
	if (this != &rhs)  //这里的&rhs代表rhs的地址
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);  //重置值内容
		move_Folders(&rhs);   //重置Folder指针
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);  //this是指向当前输入对象的指针
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m) //删除输入的m所指向folders的所有指针，加入一个现有的类成员的指针
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	//每个msg从原有的fold中删除掉
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);  //交换两者的set
	swap(lhs.contents, rhs.contents);  //交换两者的string
									   //将每个MSG的指针插入到对应的新的fold中去
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}
