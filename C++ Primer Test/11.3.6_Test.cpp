//#include<iostream>  
//#include<string>  
//#include<vector>  
//#include<algorithm>  
//#include<numeric>  
//#include<functional>
//#include<iterator>
//#include<list>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <set>
//#include <utility>
//
//using namespace std;
//
//map<string, string> bulidMap(ifstream &map_file)
//{
//	map<string, string> trans_map;
//	string key;
//	string value;
//	while (map_file >> key && getline(map_file, value))
//		if (value.size() > 1)
//			trans_map[key] = value.substr(1);   //ȥ���ո�ͬʱ��map�Ĺؼ�����Ϊÿһ�еĵ�һ���ʣ���Ԫ�ر�Ϊÿһ�к���Ĵ�
//			//trans_map.insert({ key,value.substr(1) });  //ʹ���±�ʱ��һ��map��������ͬ�Ĺؼ��ʣ���ʹ�����һ������insertʱ��һֱ�õ�һ��
//		else
//			throw runtime_error("no rule for " + key);
//	return trans_map;
//}
//
//const string &transform(const string &s, const map<string, string> &m)
//{
//	auto map_it = m.find(s);
//	if (map_it != m.cend())  //�ҵ��ͻ�
//		return map_it->second;
//	else
//		return s;
//}
//
//void word_transform(ifstream &map_file, ifstream &input)
//{
//	auto trans_map = bulidMap(map_file);
//	string text;
//	while (getline(input, text))
//	{
//		istringstream stream(text);
//		string word;
//		bool firstword = true;   //��������������ÿ������֮���ӡһ���ո��
//		while (stream >> word)
//		{
//			if (firstword)
//				firstword = false;
//			else
//				cout << " ";
//			cout << transform(word, trans_map);
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	ifstream mapfile("map_file.txt");
//	ifstream input("input.txt");
//	word_transform(mapfile, input);
//}
