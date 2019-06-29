#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
int  EnQueue(Queue * Q, int e);
int DeQueue(Queue *q, int *e);
void InitQueue(Queue * q);
int  QueueEmpty(Queue q);
// �ڽӱ�Ĺ�ȱ����㷨

/** ���̣�1. ���δӶ����ʼ���� ��ֹ����ͨͼ�ĳ���
2. �жϽ����û�б�����
3. û�б�������������
4. �ж϶����Ƿ�Ϊ�գ������Ϊ�գ������У����ҽ��붥��ֱ�������������ٽ��㰴��˳�������
5. �ظ� 1 - 4 �Ĺ���
**/
void BFSTraverse(LGraphAdjListLink GL, int startcross){

	int i, j = 0;
	int visited[MAXSIZE];//������¼��ǰ�ڵ��Ƿ��ѱ�������
	//EdgeNodeT T;
	EdgeNode *p;
	Queue Q;
	for (i = 0; i < GL->numNodes; i++)
		visited[i] = FALSE;//��ʼ����FALSE������ǰ��i���ڵ㻹δ��������
	InitQueue(&Q);//���г�ʼ�����ն���

	for (i = 0; i < GL->numNodes; i++){
		if (j == 0) {
			i = startcross - 1;//�����ļ��еĽ���Ǵ�1��ʼ�����ԣ�ʵ���н��Ϊ1�Ļ���Ӧ������Ϊ0��Ҫ����ʵ��������ʵ�ʽڵ��36��ʼ����ô����Ӧ����startcross-36
			j++;
		}//���if����Ҫ�������ñ������sartcross��ʼ������ֻ�ܽ���һ�Σ�����forѭ����û��������
		if (!visited[i]){//��visited[i]����trueʱ˵�����ҵ�������if��䣬������仹��һ����Ҫ���þ��ǵ�����Ϊ��ʱ��
			//Ҳ�����Ǹ��ڵ�û�г���ʱ����ͨ��forѭ���ҵ�һ��δ���������Ľڵ�ΪԴ�ڵ��ٽ��������ı�������
			visited[i] = TRUE;//����ǰ�ڵ��Ϊ�ѱ������Ľڵ�

			//cout << GL->adjList[i].data << endl;
			printf("%d\n", GL->adjList[i].data);//�����ǰͷ����ֵ������һ������Ŀ�ͷԪ�أ�����Ҫͨ��
			EnQueue(&Q, i);                    //GL->adjList[i].data����������
			int a;//����һ�����Ҫ�����Ƿ�ֹi��ֵ�仯��֮ǰDeQueue(&Q, &a)������д��DeQueue(&Q, &i);���ڴ���
			if (j == 1)
			{
				i = i - startcross;
				j++;
			}//��i���´�-1��ʼ��ע��forѭ����һ��i++��i���´��㿪ʼ
			while (!QueueEmpty(Q)) {//��ȥ����i�ĵ�ַ������i��ֵҲ���ˡ���forѭ����i�е�ֵ��û�н��У������еĽڵ㲻�ܱ�����

				DeQueue(&Q, &a);//����

				p = GL->adjList[a].firstedge;//p��ָ����i�ڵ�Ϊͷ�ڵ���������һ��Ԫ�أ���Ҳ����Ϊʲôͬһ������������
				//���Ǵ��������ԭ��
				while (p) {//��p��NULLʱ˵��������ͷ�ڵ㣬ͷ�ڵ��������Ѿ����

					if (!visited[p->adjvex]){//��鵱ǰ�ڵ��Ƿ��ѱ������������û�н���if

						visited[p->adjvex] = TRUE;

						//cout << GL->adjList[p->adjvex].data << endl;
						printf("%d\n", GL->adjList[p->adjvex].data);//����Ҫ��������±�Ϊp->adjvex�����ݣ�����������ͷ�ڵ�
						EnQueue(&Q, p->adjvex);//��data���Ǳ���ĵ�ǰ�±��data����
					}//����ǰ�ڵ���ӽ���������Ϊͷ�ڵ���б���

					p = p->next;//ʵ���������ŵ�ǰ�����ͷ�ڵ㿿������ΪLGraph���ɵ���һ�������ڽӱ����ɵ�ͼ
				}

			}
		}
	}

}