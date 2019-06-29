#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
int  EnQueue(Queue * Q, int e);
int DeQueue(Queue *q, int *e);
void InitQueue(Queue * q);
int  QueueEmpty(Queue q);
// 邻接表的广度遍历算法

/** 过程：1. 依次从顶点表开始遍历 防止非连通图的出现
2. 判断结点有没有被访问
3. 没有被访问则进入队列
4. 判断队列是否为空，如果不为空，出队列，并且将与顶点直接相连的所有临近点按照顺序入队列
5. 重复 1 - 4 的过程
**/
void BFSTraverse(LGraphAdjListLink GL, int startcross){

	int i, j = 0;
	int visited[MAXSIZE];//用来记录当前节点是否已被遍历到
	//EdgeNodeT T;
	EdgeNode *p;
	Queue Q;
	for (i = 0; i < GL->numNodes; i++)
		visited[i] = FALSE;//初始化，FALSE表明当前第i个节点还未被遍历到
	InitQueue(&Q);//队列初始化，空队列

	for (i = 0; i < GL->numNodes; i++){
		if (j == 0) {
			i = startcross - 1;//由于文件中的结点是从1开始的所以，实际中结点为1的话对应数组中为0，要根据实际情况如果实际节点从36开始，那么这里应该是startcross-36
			j++;
		}//这个if的主要作用是让遍历点从sartcross开始，而且只能进入一次，否则for循环就没有意义了
		if (!visited[i]){//当visited[i]等于true时说明已找到不进入if语句，此条语句还有一个重要作用就是当队列为空时，
			//也就是那个节点没有出度时，再通过for循环找到一个未经过遍历的节点为源节点再进行下述的遍历过程
			visited[i] = TRUE;//将当前节点变为已遍历过的节点

			//cout << GL->adjList[i].data << endl;
			printf("%d\n", GL->adjList[i].data);//输出当前头结点的值，这是一个链表的开头元素，所以要通过
			EnQueue(&Q, i);                    //GL->adjList[i].data这条语句输出
			int a;//加这一句的主要作用是防止i的值变化，之前DeQueue(&Q, &a)是这样写的DeQueue(&Q, &i);由于传递
			if (j == 1)
			{
				i = i - startcross;
				j++;
			}//让i重新从-1开始，注意for循环有一个i++故i重新从零开始
			while (!QueueEmpty(Q)) {//过去的是i的地址，所以i的值也变了。故for循环中i有的值并没有进行，导致有的节点不能遍历到

				DeQueue(&Q, &a);//出队

				p = GL->adjList[a].firstedge;//p是指向以i节点为头节点链表的最后一个元素，这也就是为什么同一层遍历输出数据
				//总是从右向左的原因
				while (p) {//当p是NULL时说明遇到了头节点，头节点在上面已经输出

					if (!visited[p->adjvex]){//检查当前节点是否已被遍历过，如果没有进入if

						visited[p->adjvex] = TRUE;

						//cout << GL->adjList[p->adjvex].data << endl;
						printf("%d\n", GL->adjList[p->adjvex].data);//这里要输出的是下标为p->adjvex的数据，而各个链表头节点
						EnQueue(&Q, p->adjvex);//的data正是保存的当前下标的data数据
					}//将当前节点入队将来会以它为头节点进行遍历

					p = p->next;//实际上是向着当前链表的头节点靠近，因为LGraph生成的是一个由逆邻接表生成的图
				}

			}
		}
	}

}