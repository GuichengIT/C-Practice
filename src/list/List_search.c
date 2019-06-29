#include<stdio.h>
#include "struct.h"
//////本来想区分单向链表和双向链表，其实没必要单向链表不用那个前趋指针就是了//////
List *List_search(List *L, int key)
{
	struct List *x = L;
	while (x != NULL&&(*x).key != key)
		x = (*x).next;
	return(x);
}