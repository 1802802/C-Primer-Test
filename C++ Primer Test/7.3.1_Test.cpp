/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Screen
{
public:
	//���캯��
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
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
	void do_display(ostream &os)const { os << contents; }  //����do_display�������붨�壬����ִ��display�����е��������
};

class Windows_mgr  //Ĭ������£������а�����һ����׼�ߴ�Ŀհ�Screen
{
private:
	vector<Screen> screens{ Screen(24,80,' ') };
};

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

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
}
*/