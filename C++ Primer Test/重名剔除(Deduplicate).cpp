#include<cstdio>
#include<cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#define HASHSIZE 600001
using namespace std;

const int SZ = 1 << 20;  //����io ������������ٶ�
static struct fastio
{
	char inbuf[SZ];
	char outbuf[SZ];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, SZ);
		setvbuf(stdout, outbuf, _IOFBF, SZ);
	}
}io;

int main_cplusplus()   //�Լ�д��Ч��ȷʵ��ܶ࣬����һ�������
{
	int n; vector<string> save; 
	cin >> n;
	while (n--)
	{
		string input;
		cin >> input;
		save.push_back(input);
	}
	vector<string> same(save);
	stable_sort(same.begin(), same.end());
	auto iter = unique(same.begin(), same.end());
	same.erase(iter, same.end());
	vector<string> output(600000, "");
	for (int i = 0; i < same.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < save.size(); j++)
		{
			if (same[i] == save[j])
				flag++;
			if (flag == 2)
			{
				output[j] = same[i];
				break;
			}
		}
	}
	for (auto &s : output)
		if (s != "")
			cout << s << endl;
	return 0;
}

struct Slot 
{//ÿ��Ͱ��Ӧ�Ĳ�λ���洢��ͻ����ӳ�䵽ͬһ��ַ�Ҳ��ظ����ַ�����ʵ���ַ�ָ�룩 
	char* data;//������洢�ַ�ָ�� 
	bool repeat;//��־���б��ַ����Ƿ��ظ�
	Slot* succ;//��� 
}buckets[HASHSIZE];//Ͱ���飨ɢ�б� 

char name[HASHSIZE][41];//�ַ���ά���飨���뿪ͷ���壩���洢�����ַ�����ע���ά����Ϊ40+1��������=41 

void Insert(int addr, char* s)  //����Ĳ��붼��ǰ���룬��ÿ����Ԫ�ض����뵽��ͷ����Ϊ�˱�֤�ȶ��ԣ�����Ǻ��
{//����Ӧ��ַ�в����ͻ���ַ�����ʵ���ַ�ָ�룩 
	Slot* t = new Slot;
	t->data = s; t->repeat = false;//��ʼ����ǰ�ַ�����δ�ظ� 
	t->succ = buckets[addr].succ;//����ͷ�巨 
	buckets[addr].succ = t;
}
int HashCode(char* s) 
{//ɢ����ת�����ַ���ת���֣� 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//����ʽ��� 
		sum += (i + 1)*(s[i] - 'a' + 1);
	return sum;
}

int main_csanliebiao() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%s", name[i]);
		int addr = HashCode(name[i]) % HASHSIZE;//���ӳ�䵽�ĵ�ַ 
		Slot* p = buckets[addr].succ;//�ӵ�ǰͰ�ĵ�1����λ��ʼ ,�洢�ĵط����ǵ�ǰ��buckets[]��succ��̣�����൱��һ������ṹ���ڶ�Ӧ��ÿ��Ͱ��Ԫ����һ������Ȼ����ͬ�ľ����ﴮ����
		while (p)//�������в�λ����������е�Ԫ����ͻ�ĵ�Ԫ�� 
		{
			if (!strcmp(p->data, name[i]))
			{//����ǰ��λ���ַ����ظ� 
				if (!p->repeat)
				{//��鵱ǰ��λ���ַ����Ƿ��ظ�
					p->repeat = true;//��δ�ظ������־Ϊ���ظ��� 
					puts(name[i]);//����ظ��ַ���
					//Ҳ����˵�������ﲢû�н���ͻ���ַ�������ɢ�б��У�����ͨ���ڵڶ��β������ظ�ʱ���޸ĵ�ǰ��λ��״̬���������ʵ�ֹ��̡�
				}break;//���ظ���������ԣ������Ƿ��ظ���������ֹ���� 
			}
			else p = p->succ;  //ͨ���˾���ɱ���
		}
		if (!p)Insert(addr, name[i]);//����ǰ��λ�գ�����в��� 
	}
	return 0;
}

/*c++��ʽ��ɢ�б�*/
map<int, list<string>> save;   //map��intΪͰ��Ԫ�ı�ţ������listΪÿ��Ͱ�е�����

int hashcode(string &s)
{//ɢ����ת�����ַ���ת���֣� 
	int sum = 0, len = s.size();
	for (int i = 0; i < len; i++)//����ʽ��� 
		sum += (i + 1)*(s[i] - 'a' + 1);
	return sum;
}

int main_cplussanliebiao()
{
	vector<string> same;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		int flag = 0;
		for (auto &s : save[hashcode(input)])
		{
			if (s == input)
			{
				flag++;
				same.push_back(s);
				break;
			}
		}
		if (flag == 0)
			save[hashcode(input)].push_back(input);
	}
	for (auto &s : same)
		cout << s << endl;
	return 0;
}


/*
20
brioche
camembert
cappelletti
savarin
cheddar
cappelletti
tortellni
croissant
brioche
lpc
mapotoufu
yzt
lpc
wzz
zw
brioche
qy
qy
zw
tortellni
*/