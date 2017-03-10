#include"Cskillstudy.h"
using namespace std;
Cskillstudy::Cskillstudy()    //���캯����Ҫ��ʼ��
{
	data[maxsize] = { 0 };
	length = 0;
}
void  Cskillstudy::input()
{
	cout << "���������ݵĳ��ȣ�" << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "�����" << i + 1 << "������" << endl;
		cin >> data[i];
	}
	output();
}

void  Cskillstudy::output()
{
	for (int i = 0; i < length; i++)
	{
		cout<<data[i]<<" "<<endl;
	}
}


void Cskillstudy::bubble_sort()   //ð�ݷ�����
{
	int temp;
	for (int i = 0; i < length;i++)
	   for (int j = i; j < length;j++)
	   if (data[i]>data[j])
	   {
		   temp = data[i];
		   data[i] = data[j];
		   data[j] = temp;
	   }
	   output();
}

void Cskillstudy::insert_sort()   //��������
{
	int key,j;
	for (int i = 1; i < length; i++)
	{
		key = data[i];
		j = i - 1;
		while (j>=0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = key;
	}
	output();
}

void Cskillstudy::shell_sort()     //ϣ������
{
	int gap = length;
	int key,j;
	do{
		gap = gap / 3 + 1;      //���¼��ֵ
		for (int i = gap; i < length; i++)
		{
			key = data[i];
			j = i - gap;
			while (j >= 0 && data[j] > key)
			{
				data[j + gap] = data[j];
				j = j - gap;
			}
			data[j + gap] = key;
		}
	} 
	while (gap>1);
	output();
}

//sizeΪ���鳤��
//elementΪ����Ԫ�ص�λ��
void Cskillstudy::MinHeapify(int size, int element)
{
	int lchild = element * 2 + 1, rchild = lchild + 1;//��������
	while (rchild<size)//�������ڷ�Χ��
	{
		if (data[element] <= data[lchild] && data[element] <= data[rchild])//���������������С���������
		{
			return;
		}
		if (data[lchild] <= data[rchild])//��������С
		{
			swap(data[element], data[lchild]);//��������ᵽ����  ������swap����
			element = lchild;//ѭ��ʱ��������
		}
		else//����������С
		{
			swap(data[element], data[rchild]);//ͬ��
			element = rchild;
		}
		lchild = element * 2 + 1;
		rchild = lchild + 1;//���¼�������λ��
	}
	if (lchild<size&&data[lchild]<data[element])//ֻ��������������С���Լ�
	{
		swap(data[lchild], data[element]);
	}
	return;
}
//������time:O(nlgn)

void Cskillstudy::HeapSort(int size)      //������
{
	int i;
	for (i = size - 1; i >= 0; i--)//��������ʼ������
	{
		MinHeapify( size, i);
	}
	while (size>0)//�����
	{
		swap(data[size - 1], data[0]);//��������С����������ĩ����
		size--;//����С��С
		MinHeapify(size, 0);//������
	}
	return;
}

//����a��ͷ����Ϊlength��b��ͷ����Ϊright��������ϲ�Ϊ��Ϊb_end
void Cskillstudy::Merge(int a,int b,int a_end,int b_end)     //�鲢
{
	int right;
	if (b + a_end - 1 >= b_end- 1)
		right =b_end-b;
	else
		right = a_end;
	int *temp = new int[a_end+ right];
	int i = 0, j = 0;
	while (i <= a_end - 1 && j <= right - 1)
	{
		if (data[a + i] <= data[b + j])
		{
			temp[i + j] = data[a + i]; i++;
		}
		else
		{ temp[i + j] = data[b + j]; j++; }
	}
	if (j == right)
	{//a�л���Ԫ�أ���ȫ����b�еĴ�,a[i]��δʹ��
		memcpy(data + a + i + j, data + a + i, (a_end - i)*sizeof(int));
	}
	memcpy(data + a, temp, (i + j)*sizeof(int));
	delete temp;
}

void Cskillstudy::MergeSort(int n)     //�鲢����
{
	int step = 1;
	while (step<n)
	{
		for (int i = 0; i <= n - step - 1; i += 2 * step)
			Merge(i, i + step, step, n);
		//��i��i+step�������������н��кϲ�
		//���г���Ϊstep
		//��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
		step *= 2;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
	}
}















void Cskillstudy::fast_sort(int low,int high)   //�����������
{
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = data[first];      /*���ֱ�ĵ�һ����¼��Ϊ����*/

	while (first < last)
	{
		while (first < last && data[last] >= key)
		{
			--last;
		}

		data[first] = data[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/

		while (first < last && data[first] <= key)
		{
			++first;
		}

		data[last] = data[first];
		/*���ȵ�һ������Ƶ��߶�*/
	}
	data[first] = key;          /*�����¼��λ*/
	fast_sort(low, first - 1);
	fast_sort(first + 1, high);     //������������
}

int Cskillstudy::BinarySearch(int array[], int T)
{
	int low, high, mid;
	low = 0; 
	high = length - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] < T)
		{
			low = mid + 1;
		}
		else if (array[mid]>T)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}






