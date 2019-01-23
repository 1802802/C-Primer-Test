#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

struct queen
{
	int x, y;
	queen(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	bool operator==(queen const &q) const
	{
		return (x == q.x) || (y == q.y) || (x + y == q.x + q.y) || (x - y == q.x - q.y);
	}
	bool operator!=(queen const &q) const { return !(*this == q); }
};

int checkout(stack<queen> &solu, queen &q)
{
	int num = 0;
	stack<queen> temp(solu);
	while (temp.size())
	{
		auto tm = temp.top(); temp.pop();
		if (q == tm)
			num++;
	}
	return num;
}

tuple<int,int> placequeens(int n)
{
	int ncheck = 0 , nsolution = 0;
	queen q(0, 0);  //��ʼλ��Ϊ0,0�����
	stack<queen> solu;
	do
	{
		if (n <= solu.size() || n <= q.y) //Խ�磬����ǰ��û���ҵ���Ӧ�ĵ㣬�ʻ�����һ�������ҵ�
		{
			auto tm = solu.top(); solu.pop();
			q = tm;
			q.y++;  //Ϊ��ֹ�����ظ���һ�е�ѡ�㣬ֱ���ڴ������ʱ����������1
		}
		else
		{
			while ((q.y < n) && (checkout(solu, q)))  //����ǰqueen��ջ�ڵ����ݱȽϣ��Ƿ��и�����������
			{
				q.y++;   //���ָ��漴����һ�м���ȶ�
				ncheck++;
			}
			if (n > q.y)  //������һ�����������ʱ��λ���Ƿ���Ҫ��ģ�ֻ��Ҫ�жϴ�ʱ�Ƿ�Խ�缴��
			{
				solu.push(q);  //δԽ����ڵ���ջ
				if (n <= solu.size()) nsolution++;  //��ջ��Ԫ����Ŀ�ﵽ�˽����Ŀ����solution++��ʾȫ�ֽ��Ѿ��ҵ�
				q.x++; q.y = 0;  //������һ�в��������������н�һ������
			}
		}
	} while ((0 < q.x) || (q.y < n));  //���з�֧���Ի���ٻ��֦��  //���е��������Ե���󣬿϶��͵�����q.x=0��q.y=n�ĵط���������
	tuple<int, int> tmm({ ncheck,nsolution });
	return tmm;
}

int main_shitanhuisufa()
{
	int n;
	while (cin >> n)
	{
		auto temp = placequeens(n);
		cout << get<1>(temp) << " solution(s) found after "<< get<0>(temp) << " check(s) for "<< n << " queen(s)\n"; //����������
	}
	return 0;
}