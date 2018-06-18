#include <iostream>
using namespace std;
#include"findPath.hpp"

int main()
{
    //测试队列
    try{
    Queue<char> Q(5);
    cout<<Q.items[0];
    //测试入队
    Q.enqueue('A');
    Q.enqueue('B');
    Q.enqueue('C');
    Q.enqueue('D');
    Q.output();
    //测试出队
    cout<<"出队:"<<Q.dequeue()<<endl;
    cout<<"出队:"<<Q.dequeue()<<endl;
    //测试循环功能
    Q.enqueue('E');
    Q.enqueue('F');
    Q.enqueue('G');
    Q.output();
    //测试异常
    Q.enqueue('H');
    }catch(runtime_error err) {
        cout << err.what() << endl;
    }
    //测试迷宫
    findPath(Point(1,1),Point(8,8));


    return 0;
}
