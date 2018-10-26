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
	explicit Message(const string &str = "") :contents(str) {}   //Ĭ�Ϲ��캯��
	Message(const Message&);  //�������캯��������
	Message(Message &&);  //�ƶ����캯��������
	Message& operator=(const Message&);  //������ֵ�����������
	Message& operator=(Message &&);  //�ƶ���ֵ�����������
	~Message();  //��������������
				 //�������Ե�Folder���е�����ɾ����洢
	void save(Folder&);
	void remove(Folder&);
	//private:
	string contents;   //������Ϣ�ı���string
	set<Folder*> folders;   //�ں�ָ�򱣴��˱�Message��Folder��ָ��
	void add_to_Folders(const Message&);  //��Message��ӵ����Folder������ĺ�������
	void remove_from_Folders();  //��Message������Folder��ɾ���ĺ�������
	void move_Folders(Message *);
};

Message::Message(const Message &m) :contents(m.contents), folders(m.folders) { add_to_Folders(m); }   //�������캯���Ķ���

Message::Message(Message &&m)   //�ƶ����캯��
{
	contents = std::move(m.contents);
	move_Folders(&m);   //m��ֵת�Ƶ������Ա�У�ͬʱ��ָ��folders��ָ��Ҳֻ�����Ա����
}

Message& Message::operator=(const Message &rhs)  //������ֵ�����
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message &&rhs)  //�ƶ���ֵ�����
{
	if (this != &rhs)  //�����&rhs����rhs�ĵ�ַ
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);  //����ֵ����
		move_Folders(&rhs);   //����Folderָ��
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
	f.remMsg(this);  //this��ָ��ǰ��������ָ��
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

void Message::move_Folders(Message *m) //ɾ�������m��ָ��folders������ָ�룬����һ�����е����Ա��ָ��
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
	//ÿ��msg��ԭ�е�fold��ɾ����
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);  //�������ߵ�set
	swap(lhs.contents, rhs.contents);  //�������ߵ�string
									   //��ÿ��MSG��ָ����뵽��Ӧ���µ�fold��ȥ
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}
