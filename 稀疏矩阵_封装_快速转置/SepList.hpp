#define SepList_INIT_SIZE 100//线性表存储空间的初始分配量
#define SepList_INCREMNT 2 //线性表存储空间的分配增量
#define SepList_SHRINK 2 //线性表收缩的量
#include<memory>
#include <iostream>
using namespace std;
template<typename T>
struct SepList
{
    T *elem;  //存储空间基址
    int length; //当前长度
    int SepListsize; //当前分配的存储容量

    SepList(int a = SepList_INIT_SIZE)
    {
        elem = new T [a];
        length = 0;
        SepListsize = a;
    }
    ~SepList()
    {
        delete[] elem;
    }
    bool SepListInsert(int i,T a);
    bool SepListDelete(int i);
    void outPut();
    void append(T e);
    void resize(int c);
    T& operator[](int index)const;
} ;

//顺序表插入
template<typename T>
bool SepList<T>::SepListInsert(int i,T a)        //在第i位置插入a
{
    if(i<0||i>length)
        return false;
    if(length == SepListsize)
    {
        T*p = new T[SepListsize + SepList_INCREMNT];
        for(int j = 0,k = 0; k < length ; j++,k++)      //j表示新的已经插入过线性表的元素,k表示原来的线性表的元素
        {
            if(j == i)
            {
                p[j] = a;
                j ++;
            }
            p[j] = elem[k];

        }
        delete[] elem;
        elem = p;
        SepListsize +=SepList_INCREMNT;
        return true;
    }
    for(int j = length; j > i; j --)
        elem[j] = elem[j - 1];
    elem[i] = a;
    length ++;
    return true;

}

//顺序表删除
template<typename T>
bool SepList<T>::SepListDelete(int i)
{
    if(i<0||i>length)
        return false;
    else
    {
        for(int j = i; j < length; j ++)
            elem[j] = elem[j+1];
        length--;
        if(length <= SepListsize - 2*SepList_INCREMNT)         //余量多于两倍的分配增量时收缩
        {
            T*p = new T[SepListsize -SepList_SHRINK];
            for(int i = 0; i < length ; i ++)
            {
                p[i] = elem[i];

            }
            delete[] elem;
            elem = p;
            SepListsize -= SepList_SHRINK;
        }

        return true;

    }

};
//调整空间
template<typename T>
void SepList<T>::resize(int c){
    SepListsize = c;
    T *newData = new T[SepListsize];
    if(elem != NULL){
        for(int i = 0;i < length;i ++){
            newData[i] = elem[i];

        }

        delete[] elem;

    }
    elem = newData;

}

//追加元素
template<typename T>
void SepList<T>::append(T e){
    if(length == SepListsize)
        resize(SepListsize + SepList_INCREMNT);
    elem[length++] = e;
}
//顺序表输出
template<typename T>
void SepList<T>::outPut()
{
//    cout<<"SepList:"<<endl;
    for(int i = 0; i <length; i ++)
        cout << elem[i];
//    cout<<endl;
//    cout<<"SepListSize:"<<SepListsize<<endl;
}

//实现a[i]索引数据
template<typename T>
T&SepList<T>::operator[](int index) const{
    return elem[index];

}
