#include"Queue.hpp"
#define N 10 //�Թ���С
#define M 4 //ͼ����ͨ��,��Ӧ��������
struct Point {
    int x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y): x(x), y(y) {}
    void output() {
        cout << "X:" << x << ' ';
        cout << "Y:" << y;
    }
    Point move(Point vector) {
        return Point(x + vector.x, y + vector.y);
    }


};

char map[N][N + 1] = {
    "XXXXXXXXXX",
    "X  X   X X",
    "X  X   X X",
    "X    XX  X",
    "X XXX    X",
    "X   X X  X",
    "X X   X  X",
    "X XXX XX X",
    "XX       X",
    "XXXXXXXXXX",

};
Point direction[M+4] = {
    Point{ -1, 0}, //��
    Point{1, 0}, //��
    Point{0, -1}, //��
    Point{0, 1}, //��
    Point{1, -1},
    Point{1, 1},
    Point{-1, -1},
    Point{-1, 1}

};

Point previous[N][N];
void printPath(Point c) {
    Point previous2[N*N];
    int count = N*N-1;
    char path[N][N + 1] = { //�ַ�����ʼ��char����Ĭ�Ͻ�β'\0'
        "XXXXXXXXXX",
        "X  X   X X",
        "X  X   X X",
        "X    XX  X",
        "X XXX    X",
        "X   X X  X",
        "X X   X  X",
        "X XXX XX X",
        "XX       X",
        "XXXXXXXXXX",

    };
    while(map[c.y][c.x] != 'A'){
        previous2[count] = c;
        c = previous[c.y][c.x];
        count--;
    }
     cout<<"˳�����:"<<endl;
    for(int i = count+1;i<N*N;i++){
        previous2[i].output();
        cout<<endl;

    }
    //�������
//    while(map[c.y][c.x] != 'A') {
//        c.output();
//        cout << endl;
//        path[c.y][c.x] = '*';
//        c = previous[c.y][c.x];
//
//    }
//    //���ͼ��
//    path[c.y][c.x] = 'A';
//    for(int i = 0; i < N; i ++) {
//        for(int j = 0; j < N; j ++)
//            cout << path[i][j];
//        cout << endl;
//    }

}


void findPath(Point src, Point dst) {
    map[src.y][src.x] = 'A';
    map[dst.y][dst.x] = 'B';

    Queue<Point> Q(5);
    Q.enqueue(src);
    while(Q.iSempty() == false) {
        Point pt = Q.dequeue();//ȡһ�㴦��

        for(int i = 0; i < M; i ++) {
            Point c = pt.move(direction[i]); //���c���ǰ����Ϊpt��
            char ch = map[c.y][c.x];
            if(ch == ' ') {
                previous[c.y][c.x] = pt;
                map[c.y][c.x] = 'X';
                Q.enqueue(c);
            }
            if(ch == 'B') {
                previous[c.y][c.x] = pt;
                cout << "�ҵ�����B����,·����:" << endl;
                printPath(c);
                return;
            }



        }


    }
    cout << "��A�㵽B��û��·��";

}



