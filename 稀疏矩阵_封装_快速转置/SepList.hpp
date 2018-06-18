#define SepList_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define SepList_INCREMNT 2 //���Ա�洢�ռ�ķ�������
#define SepList_SHRINK 2 //���Ա���������
#include<memory>
#include <iostream>
using namespace std;
template<typename T>
struct SepList
{
    T *elem;  //�洢�ռ��ַ
    int length; //��ǰ����
    int SepListsize; //��ǰ����Ĵ洢����

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

//˳������
template<typename T>
bool SepList<T>::SepListInsert(int i,T a)        //�ڵ�iλ�ò���a
{
    if(i<0||i>length)
        return false;
    if(length == SepListsize)
    {
        T*p = new T[SepListsize + SepList_INCREMNT];
        for(int j = 0,k = 0; k < length ; j++,k++)      //j��ʾ�µ��Ѿ���������Ա��Ԫ��,k��ʾԭ�������Ա��Ԫ��
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

//˳���ɾ��
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
        if(length <= SepListsize - 2*SepList_INCREMNT)         //�������������ķ�������ʱ����
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
//�����ռ�
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

//׷��Ԫ��
template<typename T>
void SepList<T>::append(T e){
    if(length == SepListsize)
        resize(SepListsize + SepList_INCREMNT);
    elem[length++] = e;
}
//˳������
template<typename T>
void SepList<T>::outPut()
{
//    cout<<"SepList:"<<endl;
    for(int i = 0; i <length; i ++)
        cout << elem[i];
//    cout<<endl;
//    cout<<"SepListSize:"<<SepListsize<<endl;
}

//ʵ��a[i]��������
template<typename T>
T&SepList<T>::operator[](int index) const{
    return elem[index];

}
