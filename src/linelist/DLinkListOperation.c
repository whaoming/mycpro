/**
 * 双连表的一些基本操作
 */
#include <stdio.h>
#include "common/linklist.h"

/**
 * 头插法建立双链表
 */
static void CreateDLinkListF(DLinkList *L,ElemType a[],int n){
	DLinkList *p,*q;
	int i = 0;
	while(i<n){
		q = (DLinkList *)malloc(sizeof(LinkList));
		q->data = a[i];
		q->next = L->next;
		if(L->next != NULL){

		}
		q->prior = L;
		L->next = q;
	}
}

/**
 * 尾插法建立双链表
 */
static void CreateDLinkListR(DLinkList *L,ElemType a[],int n){

}

/**
 * 在第i个位置上插入值为e的节点
 */
static void ListInsert(DLinkList *L,int i,ElemType e){

}
