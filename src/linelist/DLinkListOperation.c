/**
 * 双连表的一些基本操作
 */
#include <stdio.h>
//#include "common/linklist.h"

typedef int ElemType ;
/**
 * 双链表结构
 */
typedef struct DNode{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DLinkList;


/**
 * 头插法建立双链表
 */
static void CreateDLinkListF(DLinkList *L,ElemType a[],int n){
	DLinkList *p,*q;
	int i = 0;
	while(i<n){
		q = (DLinkList *)malloc(sizeof(DLinkList));
		q->data = a[i];
		q->next = L->next;
		if(L->next != NULL){
			L->next->prior = q;
		}
		q->prior = L;
		L->next = q;
		i++;
	}
}

/**
 * 尾插法建立双链表
 */
static void CreateDLinkListR(DLinkList *L,ElemType a[],int n){
	DLinkList *c = L,*q;
	int i;
	for(i=0;i<n;i++){
		q = (DLinkList *)malloc(sizeof(DLinkList));
		q->data = a[i];
		q->prior = c;
		c->next = q;
		c = q;
	}
	c->next = NULL;
}

/**
 * 在第i个位置上插入值为e的节点
 */
static int ListInsert(DLinkList *L,int i,ElemType e){
	int m=0;
	DLinkList *p = L,*q;
	//以下公式就是拿到第i-1个节点，也就是i的前驱节点
	while(m<i-1 && p!=NULL){
		m++;
		p = p->next;
	}
	if(p==NULL){
		return 0;
	}else{
	q = (DLinkList *)malloc(sizeof(DLinkList));
	q->data = e;
	q->next = p->next;
	if(p->next!=NULL){
		p->next->prior = q;
	}
	p->next = q;
	q->prior = p;
	return 1;
	}
}

/**
 * 删除双链表中第i个节点
 */
static int ListDelete(DLinkList *L,int i,ElemType *e){
	int m=0;
	DLinkList *p = L,*q;
	while(m<i && p!=NULL){
		p = p->next;
		m++;
	}
	if(p==NULL){
		return 0;
	}else{
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
	}
}


/**
 * 输出线性表
 */
static void DispList(DLinkList *L){
	DLinkList *p = L->next;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}


void testThis(){
	DLinkList *L = (DLinkList *)malloc(sizeof(DLinkList));
	ElemType a[] = {5,8,1,7,6,2,4};
	int n = 7;
	ElemType e;
	printf("初始化线性表:\n");
	CreateDLinkListR(L,a,n);
	DispList(L);
	printf("在第3个位置插入元素9\n");
	ListInsert(L,3,9);
	DispList(L);
	printf("删除第4个位置的元素：\n");
	ListDelete(L,4,&e);
	DispList(L);
}

//int main(){
//	testThis();
//	return 0;
//}
