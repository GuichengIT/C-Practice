#include<stdio.h>
#include "struct.h"
//////���������ֵ��������˫��������ʵû��Ҫ�����������Ǹ�ǰ��ָ�������//////
List *List_search(List *L, int key)
{
	struct List *x = L;
	while (x != NULL&&(*x).key != key)
		x = (*x).next;
	return(x);
}