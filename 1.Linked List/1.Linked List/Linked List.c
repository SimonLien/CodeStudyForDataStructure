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


TSeqList *SeqList_Create(int capacity)	//Create the sequence list
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
	tmp->capacity=capacity;
	tmp->length=0;
	return tmp;
}

void Seqlist_Destroy(TSeqList *list)
{
	TSeqList *tList=NULL;
	if(list==NULL)	//If the list is empty,then return.
	{
		return;
	}
	tList=(TSeqList *)list;
	if (tList->node!=NULL)
	{
		free(tList->node);
	}
	return;
}

void SeqList_Clear(TSeqList *list)	//clear the list to return to the initialization state.
{
	TSeqList *tList=NULL;
	if(list==NULL)	//If the list is empty,then return.
	{
		return;
	}
	tList=(TSeqList *)list;
	tList->length=0;
	return;
}

int SeqList_Length(TSeqList *list)
{
	TSeqList *tList=NULL;
	if(list==NULL)	//If the list is empty,then return.
	{
		return -1;
	}
	tList=(TSeqList *)list;
	return tList->length;
}

int SeqList_Capacity(TSeqList *list)
{
	TSeqList *tList=NULL;
	if(list==NULL)	//If the list is empty,then return.
	{
		return -1;
	}
	tList=(TSeqList *)list;
	return tList->capacity;
}

int main()
{
	system("pause");
	return 0;
}