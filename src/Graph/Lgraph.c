#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

LGraph* CreateALGraph(MGraph G, LGraph*  GL){

	int i, j;

	EdgeNode * e;
	//GL = (LGraphAdjListLink)malloc(sizeof(LGraph));


	 GL = (LGraph*)malloc(sizeof(LGraph));
	(GL)->numEdges = G.edgeNum; 
	(GL)->numNodes = G.verNum;

	// 生成顶点表
	for (i = 0; i <G.verNum; i++) /* 读入顶点信息,建立顶点表 */
	{
		(GL)->adjList[i].in = 0;
		(GL)->adjList[i].data = G.vex[i];
		(GL)->adjList[i].firstedge = NULL;   /* 将边表置为空表 */
	}


	// 生成邻接表,这个过程生成的应该是一个逆邻接表，分析草稿见有道云笔记《手写笔记》
	for (i = 0; i < G.verNum; i++){
		for (j = 0; j < G.verNum; j++) {
			if (G.arc[i][j] == 1){

				e = (EdgeNode *)malloc(sizeof(EdgeNode));

				e->adjvex = j;

				e->next = (GL)->adjList[i].firstedge;


				(GL)->adjList[i].firstedge = e;
				(GL)->adjList[j].in++; // 顶点入度加1

			}
		}
	}
	return GL;
}
