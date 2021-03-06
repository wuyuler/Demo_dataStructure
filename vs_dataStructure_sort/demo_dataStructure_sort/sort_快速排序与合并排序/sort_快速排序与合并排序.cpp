// sort_快速排序与合并排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h> 
#include <time.h>
#include<iostream>
using namespace std;
#define max_sort 10000
#define max_times 10


void merge(int a[], int b[], int i, int s, int t) {
	int a_right = s;
	int b_point = i;
	while (i < s&&a_right < t) {
		if (a[i] < a[a_right]) 
			b[b_point++]= a[i++];
		else 
			b[b_point++] = a[a_right++];
	}
	while (i < s) 
		b[b_point++] = a[i++];
	while (a_right < t) 
		b[b_point++] = a[a_right++];
}

void mergeSort(int a[], int left, int right) {
	//合并排序主控
	int n = right - left;
	int *b = new int[right];
	for (int m = 1;m <= n;m *= 2) {
		for (int i = left;i < right;i += m * 2) {
			int s = i + m;if (s > right)s = right;
			int t = s + m;if (t > right)t = right;
			merge(a, b, i, s, t);
			

		}
		memcpy(a + left, b + left, n * sizeof(int));
	}
	delete[]b;

}

int partition(int a[], int left, int right) {//1以a[left]为中枢,将a[left..right]划分为左中右三部分
	int pivotkey = a[left];
	right--;
	while (left < right) {
		while (left<right&&a[right] >= pivotkey) right--;
		a[left] = a[right];
		//a[right] = pivotkey;
		while (left < right&&a[left] <= pivotkey)left++;
		a[right] = a[left];
		//a[left] = pivotkey;

	}
	a[left] = pivotkey;
	return left;

}

void quickSort(int a[], int left, int right) {//递归
	if (right <= left)return;
	int p = partition(a, left, right);
	quickSort(a, left, p);
	quickSort(a, p + 1, right);

}

void show(int a[],int s,int n) {
	for (int i = s;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{	
	
	int a[] = { 43, 68, 45, 63, 47, 78, 49, 63, 59, 75 };
	int n = sizeof(a) / sizeof(int);
	cout << "未排序数:";show(a, 0, n);
	mergeSort(a, 0, n);
	cout << "合并排序:";show(a, 0, n);

	int a2[] = { 43, 68, 45, 63, 47, 78, 49, 63, 59, 75 };
	int n2 = sizeof(a2) / sizeof(int);
	quickSort(a2, 0, n);
	cout << "快速排序:";show(a2, 0, n);

	//int b[max_times][max_sort] ;
	//int b2[max_times][max_sort];
	//srand((unsigned int)time(NULL));
	//for (int i = 0; i < max_times;i++) {
	//	for (int j = 0;j < max_sort;j++) {
	//		b[i][j] = rand();
	//		b2[i][j] = b[i][j];
	//		//cout << b[i][j];
	//	}
	//	
	//}
	//double dur;
	//clock_t start, end;

	//start = clock();
	//for(int i=0;i<max_times;i++)
	//mergeSort(b[i], 0, max_sort);
	////show(b[0], 0, max_sort);
	//end = clock();
	//dur = (double)(end - start);
	//cout << "合并排序的时间:" << dur / CLOCKS_PER_SEC<<endl;

	//start = clock();
	////for(int i=0;i<max_times;i++)
	////quickSort(b2[i], 0, max_sort);
	////show(b2[0], 0, max_sort);
	//end = clock();
	//dur = (double)(end - start);
	//cout << "快速排序的时间:" << dur / CLOCKS_PER_SEC<<endl;

		
	
	
    return 0;
}

