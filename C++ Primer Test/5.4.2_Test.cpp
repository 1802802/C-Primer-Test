/*#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()  //��ϰ5.17
{
	int ic;
	vector<int> a{0,1,1,2};
	vector<int> b{0,1,2,2,3,5,8};
	if (sizeof(a) > sizeof(b))
		ic = b.size();
	else 
		ic = a.size();
	cout << ic << endl;
	for (int i = 0; i != ic; ++i)
	{
		if (a[i] != b[i])
		{
			cout << "�����鲻�ǳ������ͷ" << endl;
			return 0;
		}
	}
	cout << "�������ǳ������ͷ" << endl;
	return 0;
}*/