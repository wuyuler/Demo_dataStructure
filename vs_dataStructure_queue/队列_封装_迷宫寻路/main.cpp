#include <iostream>
using namespace std;
#include"findPath.hpp"

int main()
{
    //���Զ���
    try{
    Queue<char> Q(5);
    cout<<Q.items[0];
    //�������
    Q.enqueue('A');
    Q.enqueue('B');
    Q.enqueue('C');
    Q.enqueue('D');
    Q.output();
    //���Գ���
    cout<<"����:"<<Q.dequeue()<<endl;
    cout<<"����:"<<Q.dequeue()<<endl;
    //����ѭ������
    Q.enqueue('E');
    Q.enqueue('F');
    Q.enqueue('G');
    Q.output();
    //�����쳣
    Q.enqueue('H');
    }catch(runtime_error err) {
        cout << err.what() << endl;
    }
    //�����Թ�
    findPath(Point(1,1),Point(8,8));


    return 0;
}
