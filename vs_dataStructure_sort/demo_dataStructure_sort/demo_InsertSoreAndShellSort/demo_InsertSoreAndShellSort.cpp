// demo_InsertSoreAndShellSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void InsertSort(int a[], int left, int right, int step = 1) {
	//实现直接插入排序,间隔步长为step,注意不含a[right]
	for (int i = left; i < right; i += step) {
		if (a[i] < a[i - step]) {
			int temp = a[i];
			int j;
			for ( j = i - step; j >= left && a[j] > temp; j -= step) 
				a[j + step] = a[j];
			a[j+step] = temp;
		}
	}
}

void show(int a[],int left,int right) {
	for (int i = left; i < right; i++) {
		cout << " " << a[i];
	}
}

void ShellSort(int a[], int left, int right) {
	int steps[] = { 5,3,1 };
	int t = sizeof(steps) / sizeof(int);
	for (int i = 0; i < t; i++) {
		for(int j=left;j+steps[i]<right;j++)
		InsertSort(a,j , right, steps[i]);


		cout << "第" << i+1 << "趟shell排序:";
		show(a,left,right);
		cout << endl;
	}
}

int main()
{	
	int a[] = { 36,42,65,98,76,14,57,36 };
	int n = sizeof(a) / sizeof(int);
	//InsertSort(a, 0, n, 1);
	//show(a,0,n);
	ShellSort(a, 0, n);
	
    return 0;
}

