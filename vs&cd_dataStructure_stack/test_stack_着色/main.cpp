#include <iostream>


using namespace std;
#define N  9 //需要着色的区域数
bool anyConflict(bool R[][N], int i, int color[]) {
    for(int j = 1; j < i; j ++) {
        if((color[j] == color[i]) && (R[i - 1][j - 1] == 1))
            return true;
    }
    return false;
}

bool testColor(bool R[][N], int m) {
    int color[N + 2]; //着色栈
    color[N + 1] = 0;

    int i = 1;
    color[1] = 1;

    while(i > 0 && i <= N) {

        while(color[i] <= m) {
            if(anyConflict(R, i, color)) {
                color[i]++;    //冲突,使用下一种颜色
                cout << i << "不能用" << color[i] - 1 << "换成" << color[i] << endl;
            } else {
                cout << i << "可以用" << color[i] << endl;
                i++;
                if(i <= N) {
                    cout << "换成" << i << "区域" << endl;
                    color[i] = 1;
                }
                break;     //
            }
        }

        if(color[i] > m) {
            cout << "因为color[i]为" << color[i];
            i--;
            cout << "换回" << i << endl;
            color[i]++;
        }



    }
    if(i > N) {
        for(int j = 1; j <= m; j ++) {
            cout << j << "子集" << endl;
            for(int k = 1; k <= N; k++ ) {
                if(color[k] == j)cout << k << endl;
            }
            cout << endl;
        }
        return true;
        cout << "找到着色方案\n";
    } else {
        return false;
        cout << "该地图不存在仅用" << m << "中颜色的着色方案";
    }


}
int findmin(bool R[][N]) {
    for(int i = 1; i <= N; i ++) {
        if(testColor(R, i)) {
            cout << "最小划分" << i;
            return i;
        }

    }

}

bool R[][9] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0}
};
int main() {
    findmin(R);
    cout << "Hello world!" << endl;
    return 0;
}
