#include <iostream>


using namespace std;
#define N  9 //��Ҫ��ɫ��������
bool anyConflict(bool R[][N], int i, int color[]) {
    for(int j = 1; j < i; j ++) {
        if((color[j] == color[i]) && (R[i - 1][j - 1] == 1))
            return true;
    }
    return false;
}

bool testColor(bool R[][N], int m) {
    int color[N + 2]; //��ɫջ
    color[N + 1] = 0;

    int i = 1;
    color[1] = 1;

    while(i > 0 && i <= N) {

        while(color[i] <= m) {
            if(anyConflict(R, i, color)) {
                color[i]++;    //��ͻ,ʹ����һ����ɫ
                cout << i << "������" << color[i] - 1 << "����" << color[i] << endl;
            } else {
                cout << i << "������" << color[i] << endl;
                i++;
                if(i <= N) {
                    cout << "����" << i << "����" << endl;
                    color[i] = 1;
                }
                break;     //
            }
        }

        if(color[i] > m) {
            cout << "��Ϊcolor[i]Ϊ" << color[i];
            i--;
            cout << "����" << i << endl;
            color[i]++;
        }



    }
    if(i > N) {
        for(int j = 1; j <= m; j ++) {
            cout << j << "�Ӽ�" << endl;
            for(int k = 1; k <= N; k++ ) {
                if(color[k] == j)cout << k << endl;
            }
            cout << endl;
        }
        return true;
        cout << "�ҵ���ɫ����\n";
    } else {
        return false;
        cout << "�õ�ͼ�����ڽ���" << m << "����ɫ����ɫ����";
    }


}
int findmin(bool R[][N]) {
    for(int i = 1; i <= N; i ++) {
        if(testColor(R, i)) {
            cout << "��С����" << i;
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
