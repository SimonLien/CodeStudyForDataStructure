/*
@Author :Simon Lien
@Date:2020.04.19
@File: Linked List.c
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;
}TSeqList;


TSeqList *SeqList_Create(int capacity)
{
	int ret=0;
	TSeqList *tmp=NULL;
	tmp=(TSeqList *)malloc(sizeof(TSeqList));
	if (tmp==NULL)
	{
		ret=-1;
		printf("Fun SeqList_Create() err:%d\n",ret);
		return NULL;
	}
	memset(tmp,0,sizeof(TSeqList));	//clear all value
	//base on the capacity of Node to align the space of Node
	tmp->node=(unsigned int *)malloc(sizeof(unsigned int)*capacity);
	if (tmp->node==NULL)
	{
		ret=-2;
		printf("Fun SeqList_Create() err:%d\n",ret);
		return NULL;
	}
	return tmp;
}

int main()
{
	system("pause");
	return 0;
}