#include<stdio.h>
#include"struct.h"

/**使用邻接矩阵的构建图**/
//下面这种方式只是其中一种，比如那些arc[][]的值都是由实参传递过来的，这才是比较实用的方式。
MGraph* CreateMGraph(MGraph *G)
{
	int i, j;
	G->edgeNum = 7;//边的数量和结点的数量其实由实参传递过来比较好
	G->verNum = 9;
	// 输入顶点的结点，注意图顶点的内容不一定就是0，1，2，3....这些，很多情况下是A,B,C...这种情况，所以要按下面那样写
	G->vex[0] = 0;
	G->vex[1] = 1;
	G->vex[2] = 2;
	G->vex[3] = 3;
	G->vex[4] = 4;
	G->vex[5] = 5;
	G->vex[6] = 6;
	G->vex[7] = 7;
	G->vex[8] = 8;
	// 邻接矩阵初始化
	for (i = 0; i < G->verNum; i++){
		for (j = 0; j < G->verNum; j++) {
			G->arc[i][j] = 0;
		}
	}
	// 随机生成图
	G->arc[0][2] = 1;
	G->arc[1][0] = 1;
	G->arc[1][3] = 1;
	G->arc[1][4] = 1;
	G->arc[2][5] = 1;
	G->arc[6][3] = 1;
	G->arc[4][7] = 1;
	G->arc[8][5] = 1;
	//G->arc[7][8] = 1;
	/*G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;
	G->arc[5][6] = 1;
	G->arc[6][7] = 1;*/
	//因为构建的是无向图，所以是对称的
	//for (i = 0; i < G->verNum; i++){
	//	for (j = i; j < G->verNum; j++)
	//		G->arc[j][i] = G->arc[i][j];
	//}
	return G;
}
