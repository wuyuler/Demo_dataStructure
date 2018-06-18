#include <stdexcept>
template <typename T>
struct Queue{
    T *items; //队列元素基地址
    int capacity; //队列容量
    int head,tail; //队尾,队首指针(非语法意义非指针)
    int length; //当前储存的容量
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
    //入队
    if(length == capacity)
        throw runtime_error("队已满,无法再入队");

        items[tail] = e;
        tail = (tail + 1)%capacity;
        length++;

    }
    T dequeue(){
        if(length == 0)
            throw runtime_error("队已空");
        T e = items[head];
        head = (head + 1)%capacity;
        length--;
        return e;
    }

    void output(){
        cout<<"队列当前保有的元素:";
        for(int i=0;i < length;i ++){
            cout<<items[(head+i)%capacity];  //注意输出要循环
        }
        cout<<endl;

    }

    bool iSempty(){
        return length== 0;

    }


};
