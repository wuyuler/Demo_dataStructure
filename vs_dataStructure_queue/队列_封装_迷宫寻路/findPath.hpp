#include"Queue.hpp"
#define N 10 //迷宫大小
#define M 4 //图的联通数,对应上下左右
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
    Point{ -1, 0}, //上
    Point{1, 0}, //下
    Point{0, -1}, //左
    Point{0, 1}, //右
    Point{1, -1},
    Point{1, 1},
    Point{-1, -1},
    Point{-1, 1}

};

Point previous[N][N];
void printPath(Point c) {
    Point previous2[N*N];
    int count = N*N-1;
    char path[N][N + 1] = { //字符串初始化char数组默认结尾'\0'
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
     cout<<"顺序输出:"<<endl;
    for(int i = count+1;i<N*N;i++){
        previous2[i].output();
        cout<<endl;

    }
    //逆序输出
//    while(map[c.y][c.x] != 'A') {
//        c.output();
//        cout << endl;
//        path[c.y][c.x] = '*';
//        c = previous[c.y][c.x];
//
//    }
//    //输出图形
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
        Point pt = Q.dequeue();//取一点处理

        for(int i = 0; i < M; i ++) {
            Point c = pt.move(direction[i]); //标记c点的前驱点为pt点
            char ch = map[c.y][c.x];
            if(ch == ' ') {
                previous[c.y][c.x] = pt;
                map[c.y][c.x] = 'X';
                Q.enqueue(c);
            }
            if(ch == 'B') {
                previous[c.y][c.x] = pt;
                cout << "找到出口B点了,路径是:" << endl;
                printPath(c);
                return;
            }



        }


    }
    cout << "从A点到B点没有路径";

}



