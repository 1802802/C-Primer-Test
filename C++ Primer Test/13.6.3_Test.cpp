/*#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
	Foo sorted() &&
	{
		sort(data.begin(), data.end());
		cout << "��ֵsort" << endl;
		return *this;
	}
	Foo sorted() const &
	{
		return Foo(*this).sorted();   //������ֵsort


		//Foo ret(*this);
		//return ret.sorted();  //ʲô��û��


		//Foo ret(*this);
		//sort(ret.data.begin(), ret.data.end());   //��ͳ����ֵsort����
		//cout << "��ֵsort" << endl;
		//return ret;
	}
private:
	vector<int> data;
};

int main()
{
	Foo().sorted();
	Foo f;
	f.sorted(); // call "const &"
}*/