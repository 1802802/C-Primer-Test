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

class Screen
{
	friend class Window_mgr;
public:
	//���캯��
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(ht*wd, c) {}
	//���캯��
	char get() const { return contents[cursor]; }   //����get�����������ع�굱ǰλ��
	inline char get(pos ht, pos wd)const;   //����get�������������������кź��к�ȷ��λ�õ��ַ�
	Screen &move(pos r, pos c);      //����move�������������ƶ����λ��
	void some_member() const;  //����some_member�����������ڼ�¼��Ա�������õĴ���
	Screen &set(char);  //����set���������������õ�ǰ�������λ�õ���ֵ
	Screen &set(pos, pos, char);  //����set�������������������ø������λ�õ���ֵ
	Screen &display(ostream &os) { do_display(os); return *this; }  //����display�������붨�壬������ʾ�ǳ����汾��screen����
	const Screen &display(ostream &os)const { do_display(os); return *this; }  //����display�����������붨�壬������ʾ�����汾��screen����
private:
	pos cursor = 0;  //����λ��
	pos height = 0, width = 0;  //��Ļ�ĸ����
	string contents;  //���ڱ���Screen������
	mutable size_t access_ctr;   //����һ���ɱ������ڼ���
	//void do_display(ostream &os)const { os << contents; }  //����do_display�������붨�壬����ִ��display�����е��������
	void do_display(ostream &os)const   //����do_display�������붨�壬����ִ��display�����е��������
	{
		for (pos i = 0; i != height; ++i)
		{
			for (pos j = 0; j != width; ++j)
				os << (contents[i*width + j]);
			os << endl;
		}
	}
};

class Window_mgr  //Ĭ������£������а�����һ����׼�ߴ�Ŀհ�Screen
{
public:
	using ScrennIndex = vector<Screen>::size_type;
	void clear(ScrennIndex);  //����clear�����������������Ļ�е���������
private:
	vector<Screen> screens{ Screen(24,80,' ') };
};

void Window_mgr::clear(ScrennIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r*width;   //�����е�λ��
	cursor = row + c;    //�����ڽ�����ƶ���ָ������
	return *this;
}

inline char Screen::get(pos r, pos c)const
{
	pos row = r*width;
	return contents[row + c];
}

void Screen::some_member() const
{
	++access_ctr;
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}