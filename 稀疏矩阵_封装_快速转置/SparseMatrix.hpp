#include"SepList.hpp"
#include<iostream>
#include<iomanip>

using namespace std;


template<typename T>
struct Triplet{
    int row;
    int col;
    T e;
    Triplet(){} //必须提供默认构造函数,以便创造对象矩阵
    Triplet(int r,int c,T v){
        row = r;
        col = c;
        e = v;
    }

};
template<typename T>
struct SparseMatrix :SepList<Triplet<int> > { //为什么不能用<T>

    int rows,cols;
    SparseMatrix(int r,int c,int n = 10):SepList(n){
    rows = r;
    cols = c;
    }
    int getIndex(int r,int c){
        int left = 0;
        int right = length-1;
        int mid;
        while(left<=right){
            mid = (left + right)/2;
            Triplet<T> &t = (*this)[mid];
            if(r < t.row)
                right = mid -1;
            else if(r > t.row)
                left = mid+1;
            else{
                while((*this)[mid+1].row==r)mid++;
                if((*this)[mid+1].col>=c)return mid;
                else return mid+1;
            }
            }
        while((*this)[mid].row<r)mid++;
            return mid;

        }


};
