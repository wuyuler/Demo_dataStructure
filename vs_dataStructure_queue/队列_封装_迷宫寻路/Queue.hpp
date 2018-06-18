#include <stdexcept>
template <typename T>
struct Queue{
    T *items; //����Ԫ�ػ���ַ
    int capacity; //��������
    int head,tail; //��β,����ָ��(���﷨�����ָ��)
    int length; //��ǰ���������
    Queue(int c = 100){
        head = tail = 0;
        length = 0;
        capacity = c;
        items = new T[capacity];

    }
    ~Queue(){
        delete[] items;
    }

    void enqueue(T e){
    //���
    if(length == capacity)
        throw runtime_error("������,�޷������");

        items[tail] = e;
        tail = (tail + 1)%capacity;
        length++;

    }
    T dequeue(){
        if(length == 0)
            throw runtime_error("���ѿ�");
        T e = items[head];
        head = (head + 1)%capacity;
        length--;
        return e;
    }

    void output(){
        cout<<"���е�ǰ���е�Ԫ��:";
        for(int i=0;i < length;i ++){
            cout<<items[(head+i)%capacity];  //ע�����Ҫѭ��
        }
        cout<<endl;

    }

    bool iSempty(){
        return length== 0;

    }


};
