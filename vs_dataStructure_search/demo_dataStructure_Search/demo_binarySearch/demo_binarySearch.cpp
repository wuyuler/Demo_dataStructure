// demo_binarySearch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<typename T>
int binarySearch(T array[], int left, int right, T key);//实现在左闭右开的顺序数组array中查找元素e

int main()
{	
	//测试用例
	int a[] = { 3,3,4,5,6,8,9 };
	cout << binarySearch<int>(a, 0, 6, 4)<<endl;
	cout << binarySearch<int>(a, 0, 7, 9) << endl;
	cout << binarySearch<int>(a, 1, 6, 7)<<endl;
    return 0;
}


//template<typename T>
//int binarySearch(T array[], int left, int right, T key) {//实现在左闭右开的顺序数组array中查找元素e
////递归实现
//	if (left == right)return -1;
//	int mid = (left + right) / 2;
//	if (array[mid] == key)return mid;
//	else if (array[mid] > key)return binarySearch(array, left, mid, key);
//	else  return binarySearch(array, mid + 1, right, key);
//	
//
//}

template<typename T>
int binarySearch(T array[], int left, int right, T key) {//实现在左闭右开的顺序数组array中查找元素e
	 //循环实现
	while (left < right) {//注意因为right是开的,所以没有等于号
		int mid = (right + left) / 2;
		if (array[mid] == key)return mid;
		else if (array[mid] > key)right = mid;
		else left = mid + 1;

	}

	return -1;

}
	
	
