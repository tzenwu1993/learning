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
	void bubble_sort();  //ð�ݷ�����
	void shell_sort();    //ϣ������
	void insert_sort();  //��������
	void HeapSort(int size);   //������
	void MergeSort(int n);   //�鲢����
	void fast_sort(int low, int high);    //��������

	int BinarySearch(int array[], int T);    //���ֲ��ҷ���
	void MinHeapify(int size, int element);    //��С�Ѻ���
	void Merge(int a, int b, int a_end, int b_end);   //�ϲ�����
};