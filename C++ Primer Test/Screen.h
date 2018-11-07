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
	//构造函数
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(ht*wd, c) {}
	//构造函数
	char get() const { return contents[cursor]; }   //函数get的声明，返回光标当前位置
	inline char get(pos ht, pos wd)const;   //函数get的重载声明，返回由行号和列号确定位置的字符
	Screen &move(pos r, pos c);      //函数move的声明，用于移动光标位置
	void some_member() const;  //函数some_member的声明，用于记录成员函数调用的次数
	Screen &set(char);  //函数set的声明，用于设置当前光标所在位置的新值
	Screen &set(pos, pos, char);  //函数set的重载声明，用于设置给定光标位置的新值
	Screen &display(ostream &os) { do_display(os); return *this; }  //函数display的声明与定义，用于显示非常量版本的screen对象
	const Screen &display(ostream &os)const { do_display(os); return *this; }  //函数display的重载声明与定义，用于显示常量版本的screen对象
private:
	pos cursor = 0;  //光标的位置
	pos height = 0, width = 0;  //屏幕的高与宽
	string contents;  //用于保存Screen的内容
	mutable size_t access_ctr;   //定义一个可变量用于计数
	//void do_display(ostream &os)const { os << contents; }  //函数do_display的声明与定义，用于执行display函数中的输出操作
	void do_display(ostream &os)const   //函数do_display的声明与定义，用于执行display函数中的输出操作
	{
		for (pos i = 0; i != height; ++i)
		{
			for (pos j = 0; j != width; ++j)
				os << (contents[i*width + j]);
			os << endl;
		}
	}
};

class Window_mgr  //默认情况下，该类中包含了一个标准尺寸的空白Screen
{
public:
	using ScrennIndex = vector<Screen>::size_type;
	void clear(ScrennIndex);  //函数clear的声明，用于清除屏幕中的所有数据
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
	pos row = r*width;   //计算行的位置
	cursor = row + c;    //在行内将光标移动到指定的列
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