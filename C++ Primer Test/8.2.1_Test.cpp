#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*void fun(const string &file, vector<string> &word)     //���н��һֱ�����޷����ļ�����Ϊѹ����û��mfile����ļ�����
{
	ifstream in(file);
	if (in)
	{
		string temp;
		while (getline(cin, temp))
			word.push_back(temp);
	}
	else
		cerr << "�޷����ļ���" << endl;
	for (auto &s : word)
		cout << s << endl;
}

int main()           //��ϰ8.4
{
	string mfile{ "1.txt" };
	vector<string> mword;
	fun(mfile,mword);
}*/

/*void fun(const string &file, vector<string> &word)
{
	ifstream in(file);
	if (in)
	{
		string temp;
		while (cin >> temp)   //������������   //������ĸ����Ӧ����char temp�����߰ѵ��ʵı���ѭ�������ĸ��
			word.push_back(temp);
	}
	else
		cerr << "�޷����ļ���" << endl;
	for (auto &s : word)
		cout << s << endl;
}

int main()           //��ϰ8.5
{
	string mfile{ "1.txt" };
	vector<string> mword;
	fun(mfile, mword);
}*/

/*struct Sales_data  //��ϰ8.6
{
	friend istream &read(istream&is, Sales_data&item);              //��Ԫ����������������ʹ��غ�������private����
	friend ostream &print(ostream&os, const Sales_data&item);
	friend Sales_data add(const Sales_data&lhs, const Sales_data&rhs);
public:
	//���캯��
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &);
	string isbn() const { return bookNo; }   //����isbn�����е������붨�壬�䷵�ض�Ӧ��bookNo
	Sales_data& combine(const Sales_data&);  //����combine�����е����������ڽ������е��������������ֵ���
	double avg_price() const;                //����avg_price�����е����������ڼ���ĳ���е���Ʒ�۸�ƽ��ֵ
    //���캯��������
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)  //�����Ա����add�Ķ��壬���ڽ������е����ݼ���һ���У�Ȼ�󷵻�һ���ֵ
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream&os, const Sales_data&item)  //�����Ա����print�Ķ��壬�������ĳ���е�isbn�ţ�bookNo��,���ۣ��ܼ��Լ�ƽ���۸�
{
	os << "��һ����ı��Ϊ��" << item.isbn() << " ����Ϊ��" << item.units_sold << " �ܼ�Ϊ��" << item.revenue << " ƽ���۸�Ϊ��" << item.avg_price() << endl;
	return os;
}

istream &read(istream&is, Sales_data&item)  //�����Ա����read�Ķ��壬���ڽ��������еı�ţ����������ۣ���������ܼۣ�Ȼ�󷵻����ݵ�����
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

Sales_data::Sales_data(istream &is)  //istreamΪ�����Ĺ��캯��
{
	read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs) //���Ա����combine�Ķ��壬������ΪSales_data��������
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const  //��Ա����avg_price�Ķ��壬������Ϊdouble���������ͣ�����ֱֵ��Ϊ��Ʒ����
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main(int argc, char** argv)
{
	Sales_data total;
	string file1 = "book.txt";  //�ڵ�ǰ�ļ����������ļ�����������ݼ����������ļ��У�����ᱻ��ӡ������ļ���
	string file2 = "out.txt";
	ifstream input(file1);
	//ofstream output(file2);
	ofstream output;
	output.open("file2", ofstream::app);
	if (read(input, total))
	{
		Sales_data add;
		while (read(input, add))
		{
			if (add.isbn() == total.isbn())
			{
				total.combine(add);      //����total��ĺ����е�combine����������ֵthis���ش�total�ĳ�Ա������
			}
			else
			{
				print(output, total);
				total = add;
			}
		}
		print(output, total);
	}
	else {
		cerr << "No Data" << endl;
		return -1;
	}
	return 0;
}*/