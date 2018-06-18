// 图_单源最短路径and所有点对最短路径.cpp: 定义控制台应用程序的入口点。
//

/*
author:唐永金

*/
#include "stdafx.h"
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#define MAX_VERTEX_NUM 8
#define INFINITY 100000
#include"Graph.hpp"

void ShortestPath_Dijkstra(Graph&G, int v0) {
	int D[MAX_VERTEX_NUM];
	int P[MAX_VERTEX_NUM];
	bool S[MAX_VERTEX_NUM];
	memset(S, 0, sizeof(S));
	S[v0] = true;
	for (int i = 0;i < G.vexnum;i++) {
		if (G.arcs[v0][i] < INFINITY) {
			D[i] = G.arcs[v0][i];
			P[i] = v0;
		} 
		else {
			D[i] = INFINITY;
			P[i] = -1;//-1表示前驱结点未确定
		}
	}
	cout << "算法开始 选择了:";
	int previous_v=v0, v;
	for (int i = 1;i < G.vexnum;i++) {
		int min = INFINITY;
		
		for (int j = 0;j < G.vexnum;j++) {
			if (!S[j]) {
				if (D[j] < min) {
					min = D[j];
					v = j;
				}
					
			}
		}
		if (S[v])break;
		S[v] = true;
		if (P[v]==-1||G.arcs[P[v]][v] > G.arcs[previous_v][v]) //前驱结点未确定OR新的前驱结点距离更近,则更新P
		P[v] = previous_v;
		
		previous_v = v;
		cout << "v" << v << " ";
		for (int k = 0;k < G.vexnum;k++) {
			if (D[v] + G.arcs[v][k] < D[k]) {
				D[k] = D[v] + G.arcs[v][k];
			}
		}


	}
	for (int i = 0;i < G.vexnum;i++) {
		cout << endl;
		if (D[i]!=INFINITY) {
			cout << "v" << i << "的前驱结点是" << P[i]<<endl;
		}
		else cout << "v" << i<< "的前驱结点是" << "无"<<endl;
	}
		
	

}
int main()
{
	Graph G("012345");
	G.addArc(0, 2, 10);G.addArc(0, 4, 30);G.addArc(0, 5, 100);
	G.addArc(1, 2,5);G.addArc(2, 3, 50);G.addArc(3, 5, 10);
	G.addArc(4, 3, 20);G.addArc(4, 6, 60);
	//cout << G.arcs[0][2];
	ShortestPath_Dijkstra(G, 0);
	return 0;
}

