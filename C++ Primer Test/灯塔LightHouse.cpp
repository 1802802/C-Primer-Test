#include <iostream>
using namespace std;

long a = 0; long save_ltx[4000008][2], save_lty[4000008], temp[4000008]; long sum = 0;

//const int SZ = 1 << 20;  //����io ������������ٶ�
//struct fastio
//{
//	char inbuf[SZ];
//	char outbuf[SZ];
//	fastio()
//	{
//		setvbuf(stdin, inbuf, _IOFBF, SZ);
//		setvbuf(stdout, outbuf, _IOFBF, SZ);
//	}
//}io;

int partition_ltx(long save[4000008][2], int lo, int hi)   //�������򷨣����x
{
	int pivotx = save[lo][0]; int pivoty = save[lo][1];
	while (lo < hi)
	{
		while ((lo < hi) && (pivotx <= save[hi][0]))
			hi--;
		save[lo][0] = save[hi][0];
		save[lo][1] = save[hi][1];
		while ((lo < hi) && (save[lo][0] <= pivotx))
			lo++;
		save[hi][0] = save[lo][0];
		save[hi][1] = save[lo][1];
	}
	save[lo][0] = pivotx;
	save[lo][1] = pivoty;
	return lo;
}

void quicksort_lt(long save[4000008][2], int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = partition_ltx(save, lo, hi - 1);
	quicksort_lt(save, lo, mi);
	quicksort_lt(save, mi + 1, hi);
}

void merge(long *src, long *des, int start, int mid, int end)  //�鲢����
{
	int i = start, j = mid + 1;
	int k = start;

	while (i != mid + 1 && j != end + 1)
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
			sum += end - j + 1;  // ͳ�ơ�˳��ԡ�����
		}
		else
		{
			des[k++] = src[j++];
			//inversion_count += mid - i + 1;  // ͳ�ơ�����ԡ�����
		}
	}
	while (i != mid + 1) des[k++] = src[i++];
	while (j != end + 1) des[k++] = src[j++];
	for (i = start; i != end + 1; ++i)
		src[i] = des[i];
}

void mergeSort(long *src, long *des, int start, int end)  //�鲢����ԭ��Ϊ���ϵص����������ɢֱ��������£������˳��ȽϺ�ѡ���Ƿ����λ�ã�֮��������Χ��չ�Ƚϣ�����ͳ��˳���
{
	int mid;
	if (start < end)
	{
		mid = (start + end) >> 1;
		mergeSort(src, des, start, mid);
		mergeSort(src, des, mid + 1, end);
		merge(src, des, start, mid, end);
	}
}

int main_lighthouse()
{
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
		scanf("%ld %ld", &save_ltx[i][0], &save_ltx[i][1]);  //�˴���scanf������Ա����٣��Ӷ�����С��2s�����ơ�cin�Ļ��ᳬʱ
		//cin >> save_ltx[i][0] >> save_ltx[i][1];
	quicksort_lt(save_ltx, 0, a);   //����XԪ��
	for (int i = 0; i < a; i++)
		save_lty[i] = save_ltx[i][1];
	sum = 0;
	mergeSort(save_lty, temp, 0, a - 1);
	//for (int ix = 0; ix < a; ix++)   //�Լ���д�������ζԱ�Y���겢��������������Ч��Զ����鲢����
	//{
	//	for (int i = ix; i < a; i++)
	//	{
	//		if (save_ltx[ix][1] < save_ltx[i][1])
	//			sum++;
	//	}
	//}
	cout << sum << endl;
	return 0;
}