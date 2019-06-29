#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
////思想见谭浩强c程序设计P313////
List *List_create(int *a,int n)//a代表要传递给链表的值，当然有可能有多个比如还有b数组，这里的n代表各个数组传递过来元素的个数
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
	return (head);//返回链表首元素的地址
}