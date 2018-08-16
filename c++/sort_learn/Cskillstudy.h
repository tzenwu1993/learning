#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#define maxsize 100

class Cskillstudy
{
public:
	int  data[maxsize];
	int  length;
public:
	Cskillstudy();
	~Cskillstudy(){};
	void input();
	void output(); 
	void bubble_sort();  //冒泡法排序
	void shell_sort();    //希尔排序
	void insert_sort();  //插入排序
	void HeapSort(int size);   //堆排序
	void MergeSort(int n);   //归并排序
	void fast_sort(int low, int high);    //快速排序

	int BinarySearch(int array[], int T);    //二分查找方法
	void MinHeapify(int size, int element);    //建小堆函数
	void Merge(int a, int b, int a_end, int b_end);   //合并函数
};