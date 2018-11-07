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
typedef string::size_type pos;

template <pos, pos> class Screen;   //�������������Ҫʹ�õ�
template <pos H, pos W> istream& operator>>(istream&, Screen<H, W>&);
template <pos H, pos W> ostream& operator<<(ostream&, const Screen<H, W>&);

template<pos H, pos W> class Screen
{
	friend istream& operator>><H, W>(istream&, Screen<H, W>&);
	friend ostream& operator<<<H, W>(ostream&, const Screen<H, W>&);
public:
	//���캯��
	Screen() = default;
	Screen(char c) : contents(H*W, c) {}
	//���캯��
	char get() const { return contents[cursor]; }   //����get�����������ع�굱ǰλ��
	inline char get(pos r, pos c)const { pos row = r*W; return contents[row + c]; }   //����get�������������������кź��к�ȷ��λ�õ��ַ�
	inline Screen &move(pos r, pos c);      //����move�������������ƶ����λ��
	void some_member() const;  //����some_member�����������ڼ�¼��Ա�������õĴ���
	inline Screen &set(char);  //����set���������������õ�ǰ�������λ�õ���ֵ
	inline Screen &set(pos, pos, char);  //����set�������������������ø������λ�õ���ֵ
	inline Screen &display(ostream &os) { do_display(os); return *this; }  //����display�������붨�壬������ʾ�ǳ����汾��screen����
	const Screen &display(ostream &os)const { do_display(os); return *this; }  //����display�����������붨�壬������ʾ�����汾��screen����
private:
	pos cursor = 0;  //����λ��
	pos height = H, width = W;  //��Ļ�ĸ����
	string contents;  //���ڱ���Screen������
	mutable size_t access_ctr;   //����һ���ɱ������ڼ���
								 //void do_display(ostream &os)const { os << contents; }  //����do_display�������붨�壬����ִ��display�����е��������
	void do_display(ostream &os)const   //����do_display�������붨�壬����ִ��display�����е��������
	{
		for (pos i = 0; i != H; ++i)
		{
			for (pos j = 0; j != W; ++j)
				//os << (contents[i*W + j]);
				os << get(i, j);
			os << endl;
		}
	}
};

template <pos H, pos W> istream& operator>>(istream&is, Screen<H, W>&s)
{
	string input;
	is >> input;
	for (char ch : input)
		s.set(ch);
	return is;
}
template <pos H, pos W> ostream& operator<<(ostream&os, const Screen<H, W>&s)
{
	for (pos i = 0; i != H; ++i)
	{
		for (pos j = 0; j != W; ++j)
			//os << (contents[i*W + j]);
			os << s.get(i, j);
		os << endl;
	}
	return os;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
	pos row = r*W;   //�����е�λ��
	cursor = row + c;    //�����ڽ�����ƶ���ָ������
	return *this;
}

template<pos H, pos W> void Screen<H, W>::some_member() const
{
	++access_ctr;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H,W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<pos H, pos W> inline Screen<H, W> &Screen<H, W>::set(pos r, pos col, char ch)
{
	contents[r*W + col] = ch;
	return *this;
}
