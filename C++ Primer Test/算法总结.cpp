#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <forward_list>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

/*���ֲ�����򵥲���*/
template<typename T> static int binarysearch(T *a, T const &f, int lo, int hi)  //aΪ������fΪ���ҵ�����lo��hiΪ������
{
	while (lo < hi)
	{
		int mi = (lo + hi) / 2;
		(f < a[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;  //���ص�ͬ��f������ȣ���ʹʧ���ˣ����ص�Ҳ��ʧ�ܵ�λ�ã���С��f�����ֵ������ȣ�
}

template<typename T> static int normalsearch(T *a, T const &f, int lo, int hi)
{
	while (lo < hi)
	{
		if (a[hi] == f)
			break;
		hi--;
	}
	if (lo == hi)
		return -1;
	else
		return hi;
}

template<typename T> static int sum(T *a, int n)
{
	/*�б������ֵ*/  //��������ֱ��ͳ�ƣ�ʱ�临�Ӷ�ΪO(n)������ö��ַ��ή����O(log n)
	T num2 = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > num2)
			num2 = a[i];
	return num2;

	/*�ݹ����Ԫ�ظ���*/
	if (n == 0)
		return 0;
	else
		return 1 + sum(a, --n);

	/*�ݹ�*/
	if (n == 0)
		return 0;
	else
		return a[--n] + sum(a, n);

	/*����*/
	T s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}

/*������������㷨*/  //����һ�����Լ������������û����â���ģ����������ַ�Ϊm��
bool person_is_seller(string &a)  //��ʾ���������ĺ���������ʱ����
{
	if (a.back() == 'm')
		return true;
	return false;
}

static bool breadth_first_search(map<string, vector<string>> &people)
{
	deque<string> search_deque;
	search_deque.push_back("you");
	vector<string> fn_people;
	while (search_deque.size())
	{
		string person = search_deque.front();
		search_deque.pop_front();
		bool flag = true;
		for (auto &s : fn_people)
			if (s == person)
				flag = false;
		if (flag)
		{
			if (person_is_seller(person))
			{
				cout << "find the seller " << person << endl;
				return true;
			}
			else
			{
				for (auto &s : people[person])
					search_deque.push_back(s);
				fn_people.push_back(person);
			}
		}
	}
	cout << "not find the seller" << endl;
	return false;
}

static int inf = numeric_limits<int>::max();
static vector<string> processed;  //�洢������Ľڵ�
/*�ҿ�˹�����㷨*/
static string find_lowest_cost_node(map<string, int> &costs)
{
	string lower_cost_node;
	int lower_cost = inf;
	for (auto &s : costs)
	{
		bool flag = true;
		for (auto &r : processed)
			if (r == s.first)
				flag = false;
		if (flag)
		{
			if (s.second < lower_cost)
			{
				lower_cost = s.second;
				lower_cost_node = s.first;
			}
		}
	}
	return lower_cost_node;
}

static void dijkstra(map<string, vector<pair<string, int>>> &save, map<string, int> &costs, map<string, string> &parents)
{
	string node = find_lowest_cost_node(costs);
	while (node.size())
	{
		int cost = costs[node];
		auto neighbors = save[node];
		for (auto &s : neighbors)
		{
			auto new_cost = cost + s.second;
			if (costs[s.first] > new_cost)
			{
				costs[s.first] = new_cost;
				parents[s.first] = node;
			}
		}
		processed.push_back(node);
		node = find_lowest_cost_node(costs);
	}
}

/*̰���㷨*/
static void bestst(map<string, set<string>> &stations, set<string> &states_need,set<string> &final_station)
{  //�������ݣ����踲�ǵ����򣬸����㲥̨���ּ����Ӧ������ѹ㲥̨ѡ��洢set
	set<string> states_needed(states_need);  //ʹ���½���set����ԭ���ݣ�����ʱ���ݽ��и��ı�֤���޸�ԭ����
	while (states_needed.size())   //ÿһ��ѭ��ѡ��ǰneed�����ܸ�����෶Χ�Ĺ㲥̨��ֱ��needΪ��
	{
		string best_station;
		set<string> states_covered;
		for (auto &s : stations)   //�������еĹ㲥̨���ڵ�ǰ��need��Χ��ѡȡ�ܸ�����������Ĺ㲥̨����ͬ��������
		{
			set<string> covered;
			vector<string> temp1(20);
			auto end1 = set_intersection(s.second.begin(), s.second.end(), states_needed.begin(), states_needed.end(), temp1.begin());
			temp1.resize(end1 - temp1.begin());  //���ÿ���㲥̨�������������踲������Ľ������洢��vector��
			for (auto &s2 : temp1)
				covered.insert(s2); //�����������ת��covered��
			if (covered.size() > states_covered.size())  //��ͬ������
			{
				best_station = s.first;
				states_covered = covered;
			}
		}
		vector<string> temp2(20);
		auto end2 = set_difference(states_needed.begin(), states_needed.end(), states_covered.begin(), states_covered.end(), temp2.begin());
		temp2.resize(end2 - temp2.begin());  //��ʱһ���㲥̨�Ѿ���ѡ�������Ѿ���ѡȡ�㲥̨�Ķ�Ӧ�����need��Ĩ��
		set<string> new_states_needed;
		for (auto &s2 : temp2)
			new_states_needed.insert(s2);
		states_needed = new_states_needed;   //���¸�ֵneed����ʱ�����Ѿ�û���˱�Ĩ��������
		final_station.insert(best_station);  //����ѡ�Ĺ㲥̨�������ѡ��
	}
}

int main_suanfazongjie()
{
	//int a[] = { 1,32,13,56,32,734,78,123,325,124 };
	//int n = sizeof(a) / sizeof(int);
	//auto temp1 = binarysearch(a, 13, 0, 10);
	//auto temp2 = normalsearch(a, 13, 0, 10);
	//cout << temp1 << temp2 << endl;
	//int s = sum(a, n);
	//cout << s << " " << n << endl;

	/*�����������*/
	//map<string, vector<string>> people;
	//set<string> fn_people;
	//vector<string> you({ "alice", "bob", "claire" });
	//vector<string> bob({ "anuj", "peegy" });
	//vector<string> alice({ "peggy" });
	//vector<string> claire({ "thom","jonny" });
	//vector<string> empty;
	//people.insert({ "you",you });
	//people.insert({ "bob",bob });
	//people.insert({ "alice",alice });
	//people.insert({ "claire",claire });
	//people.insert({ "anuj",empty });;
	//people.insert({ "peggy",empty });
	//people.insert({ "thom",empty });
	//people.insert({ "jonny",empty });

	//breadth_first_search(people);

	/*�ҿ�˹�����㷨*/
	//map<string, vector<pair<string, int>>> save;  //�洢�ھ��Լ�ǰ���ھӵĿ���
	//vector<pair<string, int>> start;
	//start.push_back({ "a",6 });
	//start.push_back({ "b",2 });
	//save.insert({ "start",start });
	//vector<pair<string, int>> a;
	//a.push_back({ "fin",1 });
	//save.insert({ "a", a });
	//vector<pair<string, int>> b;
	//b.push_back({ "a",3 });
	//b.push_back({ "fin",5 });
	//save.insert({ "b",b });
	//vector<pair<string, int>> fin;
	//save.insert({ "fin",fin });

	//map<string, int> costs;   //�洢����
	//costs.insert({ "a",6 });
	//costs.insert({ "b",2 });
	//costs.insert({ "fin",inf });

	//map<string, string> parents;   //�洢���ڵ㣬��Ϊǰ�ĸ��ڵ�
	//parents.insert({ "a","start" });
	//parents.insert({ "b","start" });
	//parents.insert({ "fin","" });

	//for (auto &s1 : save)
	//	for (auto &s2 : s1.second)
	//		cout << s1.first << " to " << s2.first << ":" << s2.second << endl;
	//for (auto &s : costs)
	//	cout << "start to "<<s.first << " cost " << s.second << endl;
	//for (auto &s : parents)
	//	cout << s.first << "'s parents is " << s.second << endl;
	//cout << endl;
	//dijkstra(save, costs, parents);

	//for (auto &s1 : save)
	//	for (auto &s2 : s1.second)
	//		cout << s1.first << " to " << s2.first << ":" << s2.second << endl;
	//for (auto &s : costs)
	//	cout << "start to " << s.first << " cost " << s.second << endl;
	//for (auto &s : parents)
	//	cout << s.first << "'s parents is " << s.second << endl;

	/*̰���㷨*/
	set<string> states_needed({ "mt","wa","or","id","nv","ut","ca","az" });//�������ݴ洢���洢������Ҫ���㲥̨���ǵ���
	map<string, set<string>> stations;      //�����㲥̨���ּ��䷶Χ�洢��ǰstring����㲥̨�����֣���set<string>���������ǵ���
	set<string> kone({ "id","nv","ut" });
	stations.insert({ "kone", kone });
	set<string> ktwo({ "wa","id","mt" });
	stations.insert({ "ktwo", ktwo });
	set<string> kthree({ "or","nv","ca" });
	stations.insert({ "kthree", kthree });
	set<string> kfour({ "nv","ut" });
	stations.insert({ "kfour", kfour });
	set<string> kfive({ "ca","az" });
	stations.insert({ "kfive", kfive });
	set<string> final_station;  //���ڴ�����ѵĹ㲥̨ѡ��

	bestst(stations, states_needed, final_station);
	for (auto &s : final_station)
		cout << "��ѹ㲥̨ѡ��Ϊ��" << s << " " << endl;

	return 0;
}