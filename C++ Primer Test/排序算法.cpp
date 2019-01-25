#include <iostream>
#include <queue>
#include <time.h>
using namespace std;

/*��������*/
/*ʱ�临�Ӷ�ƽ��O(n2)�����O(n)�����O(n2)���ռ临�Ӷ�O(1)���͵ء��ȶ�������*/
/*˼·Ϊ���ӵ�һ��ڶ���Ԫ�ؿ�ʼ�����Ͽ��Ǻ�׺��Ԫ�أ�������뵽ǰ׺�к������λ�ã����Ų��룬��������λ�ö���Ҫ�ı�
�����ڴ��˿�ʱ�ĳ��ƣ��������������ȫ��֪���ġ�*/
template<typename T> void insertionsort(T data[], int n)
{
	for (int i = 1, j; i < n; i++)
	{
		T tmp = data[i];
		for (j = i; j > 0 && tmp < data[j - 1]; j--)  //ע��ֻ��<�Ż��ƶ���=������
			data[j] = data[j - 1];   //���������Ҳ����ÿ�κ�׺�ĵ�һ��������������ǰ������ֱȽϣ���������ǰ������ֱ������С������ͷ
		data[j] = tmp;  //����˳����Ǹ�λ�ñ�tmp��ֵ��ȥ���伴��
	}
}

/*ѡ������*/  //��������˲��ҵķ���
/*ʱ�临�Ӷ�ƽ��O(n2)�����O(n2)�����O(n2)���ռ临�Ӷ�O(1)���͵ء����ȶ�������*/
/*˼·Ϊ��������ǰ���飬������������С���󣩵�Ԫ�أ���������Ԫ�أ�ĩԪ�أ����н�����Ȼ�󽵵����������뽻������*/
template<typename T> void selectionsort(T data[], int n)
{
	for (int i = 0, j, least; i < n - 1; i++)   //i�����ֵ��Ϊn-1����Ϊ�˱�֤��j��nʱֹͣѭ����ֹԽ��
	{
		for (j = i + 1, least = i; j < n; j++)  //ÿ����ѭ��������Сֵλ��i����ƶ�һλ
			if (data[j] < data[least])			//���������Сֵλ��֮���Ԫ�ر�jС����һֱ��λ�ô��ݸ�least
				least = j;
		if (i != least)							//��������ʾ��ǰ��������Сʱ����Ҫ����������n-1�������Ƚϣ�����ĳЩ����Ľ�������
			swap(data[i], data[least]);			//���ֱ�ӽ���i��least��Ԫ�ؼ��ɣ�����ǰ���ѭ������ʱ��least��Ȼ�Ǻ�׺����СԪ�ض�Ӧ��λ��
												//����ͳ��ֲ��ȶ���ԭ�򣬵������д��ڶ����ͬ����aʱ��������ǰ���a�ᱻ�����������λ��ȥ��С����������ƫ��ĵط���
	}
}

/*ð������*/  
/*ʱ�临�Ӷ�ƽ��O(n2)�����O(n)�����O(n2)���ռ临�Ӷ�O(1)���͵ء��ȶ�������*/
/*˼·Ϊ����ͷ��ʼ��β������������������ǰ�����С���󣩣��ͽ�����һֱ��������ټ�С�����������*/
template<typename T> void bubblesort(T data[], int n)
{
	bool flag = false;
	while (!flag)
	{
		flag = true;    //��Ϊ��ʶ����������֮����Ϊtrue����ʾ��ǰ�����Ѿ�����ֱ����������
		for (int i = 0; i < n - 1; i++)
		{
			if (data[i] > data[i + 1])  //����ʽ���������յ�ǰ��������һ������Ȼ�������ڵ������
			{
				swap(data[i], data[i + 1]);  //��������û�г��ֽ��棬�������ȶ���
				flag = false;
			}
		}
		n--; //n�ݼ�����Ϊÿ��һ��ѭ������ǰ��������һ�������Ѿ�������ɣ�����ͨ��������С����
	}
}

/*ϣ������*/
/*ʱ�临�Ӷ�ƽ��O(n1.3)�����O(n)�����O(n2)���ռ临�Ӷ�O(1)���͵ء����ȶ�������*/
/*˼·Ϊ�������������н������������仮��Ϊ���h�����У�֮����������������εݼ����»����������������һ������������ʵ��*/
/*�㷨���ģ��������У���shell���е�ѡȡ��ȷ��*/
template<typename T> void shellsort(T data[], int n)
{
	int k = 0, m = 1, increments[20];
	while (m < n / 3)						// ��̬���������У����������shell�������У��⼸ʮ��Դ˵��о��������и��õĴ��ڣ�    
	{
		increments[k++] = m;
		m = m * 3 + 1;						// {1,4,13,40,121,....��ͨ��shell����
	}
	for (m = k-1; m >= 0; m--)              //�ظ�ʹ��m���˴������Ǳ���increment���У��Ӵ�С��
	{
		int h = increments[m];              //h����ǰ�ķָ���������������е�������ȡ

		/*�����￪ʼ��ʵ�ֶ���������ķָ�������*/
		for (int i = h; i < 2 * h; i++)     //�˴���ʼ���ݲ���h��������ָ�����ʼh=4��n=17����ô�����i��ȡֵ4567�ĸ�����ʵ��������Ķηָ�
		{

			/*�����￪ʼ��ʵ�ֶ��ڱ��ָ��������������*/  //�����Ƕ���ÿ���ָ������ĵ��������㷨����ѡ�ò�ͬ��
			for (int j = i; j < n;)   //jΪ����ĳ�ʼֵ��j+hΪ��һλ�ã�j<nΪ�̶���������
			{
				T temp = data[j];     //�ӵ�ǰ���������࿪ʼ
				k = j;				  //����j����ֵ��ʹ��k������j���в�����������
				while (k - h > 0 && temp < data[k - h])   //�˴�ѡ�õ��ǲ�������
				{
					data[k] = data[k - h];
					k -= h;			  //ע�ⲻ��k--������Ϊh
				}
				data[k] = temp;		  //����˳����Ǹ�λ�ñ�temp��ֵ��ȥ���伴��
				j += h;
			}

			/*�����Ƕ���ѡ������ĳ��Թ��̣���ϧʧ����*/
			//for (int j = i-h, k, least; j < n - h; j += h)
			//{
			//	for (k = j , least = j; k < n; k += h)		//ÿ����ѭ��������Сֵλ��i����ƶ�һλ
			//	{
			//		cout << "k: " << k << endl;
			//		if (data[k] < data[least])			//���������Сֵλ��֮���Ԫ�ر�jС����һֱ��λ�ô��ݸ�least
			//			least = k;
			//	}
			//	if (k != least)							//��������ʾ��ǰ��������Сʱ����Ҫ����������һ���������Ƚϣ�����ĳЩ����Ľ�������
			//		swap(data[k], data[least]);			//���ֱ�ӽ���i��least��Ԫ�ؼ��ɣ�����ǰ���ѭ������ʱ��least��Ȼ�Ǻ�׺����СԪ�ض�Ӧ��λ��
			//}


		}
	}
}

/*������*/
/*ʱ�临�Ӷ�ƽ��O(nlog2n)�����O(nlog2n)�����O(nlog2n)���ռ临�Ӷ�O(1)���͵ء����ȶ�������*/
/*˼·Ϊ������������������½��ѣ����ϵؽ��ѵĶ��������������β�����������������˲���С���䣬��֤�ѵ����ֵһֱ�ڶ�����*/
/*�㷨���ģ����ѣ�ȡ���ֵ*/
template<typename T> void moveDown(T data[], int first, int last)  //�ѵ������㷨��firstΪ�Ѷ�������ĵ�һλ����lastΪ��β����������һλ��
{													   //�Ӷѵ���ײ㿪ʼ������α�����˳�����ÿ���к��ӵĽڵ㣨���¶��ϣ���ǳ��������ӱ��Լ���ͽ������������ź���ԭ����λ������
	int largest = 2 * first + 1;                       //�����largest�������first�ڵ��Ӧ������λ��
	while (largest <= last)							   //�ж����ĺ����Ƿ���������
	{
		if (largest < last && data[largest] < data[largest + 1])   //�˴��ж�largest�Ƿ�պ�Ϊĩ�ڵ㣬���߲鿴first�������Һ����ıߴ�largestȡ���
			largest++;
		if (data[first] < data[largest])               //first��Ϊ���ڵ㣬�������ĺ��ӱȽϣ�������Ӵ�ͻ�������������ǣ�����ýڵ��Ƚ�������
		{
			swap(data[first], data[largest]);          //����ӽڵ�largest�͸��ڵ�first�����������ж�first��������������Ĵ�С��ϵ
			first = largest;
			largest = 2 * first + 1;
		}
		else
			//largest = last + 1;
			break;
	}
}

template<typename T> void heapsort(T data[], int size)
{	
	for (int i = size / 2 - 1; i >= 0; --i)    //���ѣ�floyid���ѷ��������¶��ϵ�����ÿ���ڵ㡣��size���в�ѡֵ��������ȡֵ�����к��ӵĽڵ㣬�����޹ؼ���
		moveDown(data, i, size - 1);

	cout << "���Ѻ�����Ϊ��   ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;

	for (int i = size - 1; i >= 1; --i)        //��ʼʵ�ʵĶ����򣬼����ϵؽ�data[0]����ǰ������������������������ĩβ
	{
		swap(data[0], data[i]);
		moveDown(data, 0, i - 1);			   //ͨ��ÿ�ν���֮������ˣ���֤�������Ԫ��һֱ�������ֵ
	}
}

/*��������*/
/*ʱ�临�Ӷ�ƽ��O(nlog2n)�����O(nlog2n)�����O(n2)���ռ临�Ӷ�O(nlog2n)�����͵ء����ȶ�������*/
/*˼·Ϊ�����������鲻�ϵķֶ���֮���������ֻ��һ��Ԫ�ص����飨1��Ԫ����Ȼ����Ҫ���򣩣�������������������Ĳ��ϵĻ��ֹ�����*/
/*�㷨���ģ��ݹ黮��*/
int partition(int save[], int lo, int hi)      //����Ļ��ֺ��������ĵ�Ϊpivot���ڻ���֮�������������������С���Ҳ�������������ֵ����ֻʣһ��Ԫ�أ�����Ҳ���������
{
	int p = save[lo];
	int l = lo, h = hi;
	while (lo < hi)                            //����save[lo]����ֵ����lo��ʼ���Ͻ���ȶԣ���lo=hiʱ���ҵ���λ��
	{
		while ((lo < hi) && (p <= save[hi]))
			hi--;
		save[lo] = save[hi];
		while ((lo < hi) && (p >= save[lo]))
			lo++;
		save[hi] = save[lo];
	}
	save[lo] = p;
	return lo;
}

void quicksort(int save[], int lo, int hi)
{
	if (hi - lo < 2)return;
	int mi = partition(save, lo, hi - 1);      //ȷ����λ�㣨�����е㣬����λ��pivot��
	quicksort(save, lo, mi);				   //ͨ���ڻ��ֺ����������ڲ��ϵݹ黮�֣������ֻʣ����һ��Ԫ�أ���hi-lo=1��ʱ��������ϵ�ͬʱҲ�������
	quicksort(save, mi + 1, hi);
}

/*�鲢����*/
/*ʱ�临�Ӷ�ƽ��O(nlog2n)�����O(nlog2n)�����O(nlog2n)���ռ临�Ӷ�O(n)�����͵ء��ȶ�������*/
/*˼·Ϊ�����������鲻�ϵķֶ���֮���������ֻ��һ��/����Ԫ�ص����飬Ȼ�󽫸������������鲢��һ���������ڹ鲢�����У����鲢�꼴�������*/
/*�㷨���ģ�����Ԫ�صĹ鲢*/

template<typename T> void merge(T data[], int lo, int mi, int hi)//����һ����ѭ����Сѭ���ٵ���ѭ���Ĺ��̣�����Сѭ������ֻ������Ԫ�ػ�ֻ��һ��Ԫ�أ������������ֱ��return����Ȼ�������鲢����һ�����Ĵ�ѭ����
{
	cout << "lo: " << lo << " mi: " << mi << " hi: " << hi << endl;
	int i1 = 0, i2 = lo, i3 = mi;								 //�˴���i1��Ϊtemp���±꣬i2��Ϊ����data[lo,mi-1]���±꣬i3��Ϊ����data[mi,hi-1]���±�
	T *temp = new T[hi - lo];                                    //ÿ��ѭ������һ����ʱ����temp�������洢��ǰ����������Ԫ��
	while ((i2 < mi) || (i3 < hi))								 //��data�ָ��ǰ���������鲻�ϵ��໥�Ƚϣ���Сֵ����temp��Ȼ���Ӧ�������±�++������ﵽĳ������ȫ���Ƚ��꣨�±굽���Ͻ磩������һ�������Ԫ�ذ�˳���temp
	{
		if ((i2 < mi) && (!(i3 < hi) || (data[i2] <= data[i3])))
			temp[i1++] = data[i2++];
		cout << "i2: " << i2 << endl;
		if ((i3 < hi) && (!(i2 < mi) || (data[i3] < data[i2])))
			temp[i1++] = data[i3++];
		cout << "i3: " << i3 << endl;
		cout << "i1: " << i1 << endl;
		cout << endl;
	}

	for (int i = 0; i < hi-lo; i++)				//����ĸ�ֵ�ǽ���ʱ����temp�洢������ֵ���ݽ�data��ԭ��Ӧ�ö�Ӧ�������ڣ�temp�ڵ���ֵ��С�㶨Ϊhi-lo
	{
		data[i + lo] = temp[i];					//������������Ϊ[lo,hi]���䣬����data[i+lo]Ϊtemp���������ÿ����ֵ��Ӧ����ʵ��ֵ
		cout << "temp" << "[" << i << "]:" << temp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < hi - lo; i++)			//�˴����ڲ鿴��ǰdata������������
		cout << "data" << "[" << i + lo << "]:" << data[i] << " ";
	cout << endl;
	delete[] temp;
}

template<typename T> void mergesort(T data[], int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = (lo + hi) / 2;
	mergesort(data, lo, mi); mergesort(data, mi, hi);
	merge(data, lo, mi, hi);
}

/*��������*/
/*ʱ�临�Ӷ�ƽ��O(n*k)�����O(n*k)�����O(n*k)���ռ临�Ӷ�O(n+k)�����͵ء��ȶ�������*/
/*˼·Ϊ���Ӹ������Ļ�������λ��ʮλ����λ���Դ����ƣ���ʼ�Ƚ�����һֱ�������λ�Ļ���*/
/*�㷨���ģ�������Ϊ10������λ����ѡ��ֵ��ѡ�������������λ��*/
template<typename T> void radixsort(T data[], int n)
{
	int i, j, k, factor;
	const int radix = 10;
	const int digits = 10;
	queue<T> queues[radix];                                        //һ����У����ڴ洢��ͬ���������ݣ�ÿһ�����������Ҷ�Ӧ9������
	for (i = 0, factor = 1; i < digits; factor *= radix, i++)      //digits��ʾ���λ����Ĭ��Ϊ10λ���˴�����10�顣Ҳ�����Ż��㷨Ϊ��ǰ����������������һλ
	{
		for (j = 0; j < n; j++)
			queues[(data[j] / factor) % radix].push(data[j]);	   //ÿ�����ݣ����ݵ�ǰλ��ȡ��õ�������������Ӧ�Ķ����У����к㶨Ϊ0-9��
		for (j = k = 0; j < radix; j++)
			while (!queues[j].empty())							   //������˳�����ÿ�����У����½����ݸ���ԭ����data��ͬʱ��������ж���
			{
				data[k++] = queues[j].front();
				queues[j].pop();
			}
	}
	cout << "��������" << endl;
}

/*��������*/
/*ʱ�临�Ӷ�ƽ��O(n+k)�����O(n+k)�����O(n+k)���ռ临�Ӷ�O(n+k)�����͵ء��ȶ�������*/
/*˼·Ϊ��ʹ��һ�����ݽṹ��Ϊ�������洢ÿ�����ֵĳ��ִ�����Ȼ�������ֵĴ�С�ʹ洢����Ŀ�������*/
/*�㷨���ģ�����ֵ��Ҫ̫��������С��Χ�����ݵ�����*/
template<typename T> void countingsort(T data[], const int n)
{
	long i;
	long largest = data[0];
	long *temp = new long[n];       //����������������temp
	for (int i = 1; i < n; i++)
		if ((largest < data[i]))
			largest = data[i];      //ѡ�������е����ֵ
	unsigned long *count = new unsigned long[largest + 1];   //�����������
	for (i = 0; i <= largest; i++)  //��ʼ����������
		count[i] = 0;
	for (i = 0; i < n; i++)         //����data�������е����ݣ�����һ�Σ���Ӧ����ֵ+1
		count[data[i]]++;

	/*��������ͳ�ļ����������*/
	//for (i = 1; i <= largest; i++)  //�Ѽ�������count�ڵĵ���������ֵ�����������ε��ӵ�
	//	count[i] = count[i - 1] + count[i];
	//for (i = n - 1; i >= 0; i--)    //�����������data��������ݼ��������е�λ�ÿ�ʼ���η���
	//{
	//	temp[count[data[i]] - 1] = data[i];
	//	count[data[i]]--;           //�������ж�Ӧ��Ԫ�ؿ�ʼ�ݼ������ѭ�������ʼ��������ÿ��Ԫ�ص�����������һ�¡�
	//}
	//for (i = 0; i < n; i++)         //temp�е������Ѿ�������ɣ��������¸�ֵ��data��
	//	data[i] = temp[i];
	
	/*����ΪͰ�����һ��������ʽ����ֱ�ӽ�����������˳�����Ӧ��ÿ��Ԫ��ֱ�Ӹ�ֵ*/
	int num = 0;
	for (i = 0; i <= largest; i++)
	{
		while (count[i] != 0)
		{
			data[num] = i;
			num++; count[i]--;
		}
	}

}

int main()
{
	int a[] = { 21,1,32,13,56,32,89,54,31,456,324,734,78,123,325,3,7,124 };
	int n = sizeof(a) / sizeof(int);
	cout << "ԭ����Ϊ��       ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//insertionsort(a, n);
	//selectionsort(a, n);
	//bubblesort(a, n);
	//shellsort(a, n);
	//heapsort(a, n);
	//quicksort(a, 0, n);
	//mergesort(a, 0, n);
	//radixsort(a, n);
	countingsort(a, n);

	cout << "����������Ϊ�� ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
