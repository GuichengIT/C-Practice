#include <stdio.h>
#include "struct.h"

/** 深度优先相关 遍历所有结点**/
/** 过程:
1. 依次遍历顶点表的每个顶点，防止非连通图的出现
2. 如果该顶点没有访问，则访问该顶点，
3. 找到与该顶点相连的第一个临界点，进行递归，结束条件是 p 的临界点为空
4. 继续从第一个顶点的第二个邻接点进行遍历
**/

//bool visited[MAXSIZE];
int visited[MAXSIZE];

void DFS(LGraphAdjListLink GL, int pos){

	EdgeNode *p;

	visited[pos] = TRUE;

	//cout << GL->adjList[pos].data << endl;
	printf("%d\n", GL->adjList[pos].data);
	p = GL->adjList[pos].firstedge;

	while (p) {

		if (!visited[p->adjvex])
			DFS(GL, p->adjvex);

		p = p->next;
	}
}

void DFSTraverse(LGraphAdjListLink GL){
	int i;
	for (i = 0; i < (GL)->numEdges; i++)
		visited[i] = FALSE;
	for (i = 0; i < GL->numNodes; i++) {
		if (visited[i] == FALSE){
			DFS(GL, i);
		}
	}

}
