#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
#include<list>

using namespace std;

/*int main()   //��ϰ10.27
{
	vector<string> word{ "i","can","fly","fly","on","the","sky" };
	list<string> s;
	unique_copy(word.begin(), word.end(), back_inserter(s));  //ȥ���ظ��󿽱�
	for (auto &a : word)
		cout << a << endl;
	for (auto &a : s)
		cout << a << endl;
	return 0;
}*/

/*int main()
{
	list<int> a1{ 1,2,3,4,5,6,7,8,9 };
	list<int> a2;   //inserter�����ǵ����������ڲ�����
	list<int> a3;
	list<int> a4;
	copy(a1.cbegin(), a1.cend(), inserter(a2, a2.begin()));
	copy(a1.cbegin(), a1.cend(), back_inserter(a3));   //vector��֧��push_front
	copy(a1.cbegin(), a1.cend(), front_inserter(a4));
	for (auto &s : a1)
		cout << s;
	cout << endl;
	for (auto &s : a2)
		cout << s;
	cout << endl;
	for (auto &s : a3)
		cout << s;
	cout << endl;
	for (auto &s : a4)
		cout << s;
	cout << endl;
	return 0;
}*/