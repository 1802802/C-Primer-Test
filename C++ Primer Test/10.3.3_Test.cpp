//#include <iostream>
//#include <numeric>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <iterator>
//#include <list>
//#include <algorithm>
//using namespace std;

/*int main()  //��ϰ10.20
{
	vector<string> word{ "i","can","fly!!!!!!","fly","on","the","sky" };
	auto temp = count_if(word.begin(), word.end(), [](const string &a) { return a.size() > 6; });
	cout << temp << endl;
}*/

/*int main()
{
	int a = 5;
	auto temp = [&a]()->bool
	{
		if (a == 0)
			return true;
		else
		{
			for (; a > 0; a--);
			return false;
		}
	};
	int j = temp();
	cout << j << endl; //0ʱ��ʾ������Ϊ0����0ʱ��ʾ����Ϊ0  //cout���ǲ���ֵ
	cout << a << endl; //a�ս�Ϊ0���жϵ������ʼֵ�Ƿ�Ϊ0
}*/