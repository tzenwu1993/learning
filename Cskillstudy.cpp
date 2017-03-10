#include"Cskillstudy.h"
using namespace std;
Cskillstudy::Cskillstudy()    //构造函数需要初始化
{
	data[maxsize] = { 0 };
	length = 0;
}
void  Cskillstudy::input()
{
	cout << "请输入数据的长度：" << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "输入第" << i + 1 << "个数据" << endl;
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


void Cskillstudy::bubble_sort()   //冒泡法排序
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

void Cskillstudy::insert_sort()   //插入排序
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

void Cskillstudy::shell_sort()     //希尔排序
{
	int gap = length;
	int key,j;
	do{
		gap = gap / 3 + 1;      //更新间隔值
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

//size为数组长度
//element为数组元素的位置
void Cskillstudy::MinHeapify(int size, int element)
{
	int lchild = element * 2 + 1, rchild = lchild + 1;//左右子树
	while (rchild<size)//子树均在范围内
	{
		if (data[element] <= data[lchild] && data[element] <= data[rchild])//如果比左右子树都小，完成整理
		{
			return;
		}
		if (data[lchild] <= data[rchild])//如果左边最小
		{
			swap(data[element], data[lchild]);//把左面的提到上面  重载了swap函数
			element = lchild;//循环时整理子树
		}
		else//否则右面最小
		{
			swap(data[element], data[rchild]);//同理
			element = rchild;
		}
		lchild = element * 2 + 1;
		rchild = lchild + 1;//重新计算子树位置
	}
	if (lchild<size&&data[lchild]<data[element])//只有左子树且子树小于自己
	{
		swap(data[lchild], data[element]);
	}
	return;
}
//堆排序time:O(nlgn)

void Cskillstudy::HeapSort(int size)      //堆排序
{
	int i;
	for (i = size - 1; i >= 0; i--)//从子树开始整理树
	{
		MinHeapify( size, i);
	}
	while (size>0)//拆除树
	{
		swap(data[size - 1], data[0]);//将根（最小）与数组最末交换
		size--;//树大小减小
		MinHeapify(size, 0);//整理树
	}
	return;
}

//对以a开头长度为length和b开头长度为right两个数组合并为长为b_end
void Cskillstudy::Merge(int a,int b,int a_end,int b_end)     //归并
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
	{//a中还有元素，且全都比b中的大,a[i]还未使用
		memcpy(data + a + i + j, data + a + i, (a_end - i)*sizeof(int));
	}
	memcpy(data + a, temp, (i + j)*sizeof(int));
	delete temp;
}

void Cskillstudy::MergeSort(int n)     //归并排序
{
	int step = 1;
	while (step<n)
	{
		for (int i = 0; i <= n - step - 1; i += 2 * step)
			Merge(i, i + step, step, n);
		//将i和i+step这两个有序序列进行合并
		//序列长度为step
		//当i以后的长度小于或者等于step时，退出
		step *= 2;//在按某一步长归并序列之后，步长加倍
	}
}















void Cskillstudy::fast_sort(int low,int high)   //随机快速排序法
{
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = data[first];      /*用字表的第一个记录作为枢轴*/

	while (first < last)
	{
		while (first < last && data[last] >= key)
		{
			--last;
		}

		data[first] = data[last];/*将比第一个小的移到低端*/

		while (first < last && data[first] <= key)
		{
			++first;
		}

		data[last] = data[first];
		/*将比第一个大的移到高端*/
	}
	data[first] = key;          /*枢轴记录到位*/
	fast_sort(low, first - 1);
	fast_sort(first + 1, high);     //迭代快速排序
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






