/*#include <vector>
#include <string>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <exception>
#include<iostream>  
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

using namespace std;

int main()
{
	string s;
	allocator<string> alloc;
	auto p = alloc.allocate(10);//�õ���()��ֻ�����ڴ�
	auto q = p;
	while (cin >> s && q != p + 10)
	{
		alloc.construct(q++, s);//�������󲢷�ֵ
	}
	const size_t size = q - p;
	while (q != p)
	{
		alloc.destroy(--q);//������ٶ���destory����һ��ָ��
	}
	alloc.deallocate(p, 10);//��������ڴ棬�ͷŶ���
	cout << size << endl;
	return 0;
}*/