#include<iostream>
using namespace std;
bool anyConflict(bool R[][N-1],int i,int color[]){
    for(int j = 1;j<i;j ++){
        if(color[j] == color[i]){
            if(R[i-1][j-1] == 1)
                return true;

        }
        return false;
    }
}
bool testColor(bool R[][N-1],int m){
    int color[10]; //��ɫջ

    int i = 1;
    color[1] = 1;
    while(i > 0&&i <= N){
        while(color[i] <=m){
            if(anyConflict(R,i,color)) color[i]++;
            else {
                if(i <= N) {
                    i++;
                    color[i] = 1;
                };
                if(i > N)break;
            }
            if(color[i] > m){
                i--;
                color[i]++;
            }
        }


    }
    if(i > N){
        cout<<"�ҵ���ɫ����\n";
    }
    else
        cout<<"�õ�ͼ�����ڽ���"<<m<<"����ɫ����ɫ����";


}
