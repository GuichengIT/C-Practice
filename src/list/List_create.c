#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
////˼���̷��ǿc�������P313////
List *List_create(int *a,int n)//a����Ҫ���ݸ������ֵ����Ȼ�п����ж�����绹��b���飬�����n����������鴫�ݹ���Ԫ�صĸ���
{ 
	List *p1, *p2, *head;//
	p1 = (List *)malloc(sizeof(List));
	head = p1;
	for (int i = 0; i < n; i++)
	{
		(*p1).key = a[i];
		p2 = p1;
		p1 = (List *)malloc(sizeof(List));
		(*p2).next = p1;
		(*p1).prev = p2;
	}
	return (head);//����������Ԫ�صĵ�ַ
}