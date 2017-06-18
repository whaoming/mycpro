#include <stdio.h>
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


/**
 * eg2_8：
 * 有一个带头节点的双链表L，谁一个算法将其所有元素逆置，
 * 即第1个元素变为最后一个元素，第2个元素变为倒数第2个元素
 * 最后一个元素变为第一个元素
 *
 * eg2_9:
 * 有一个带头节点的双链表L(至少有一个数据节点)，设计一个算法使其元素递增有序排列
 *
 */

void ed2_8(DLinkList *L){
	DLinkList *p = L->next,*q;
	L->next=NULL;
	while(p!=NULL){
		q = p->next;
		p->prior = L;
		p->next = L->next;
		if(L->next!=NULL){
			L->next->prior = p;
		}
		L->next = p;
		p = q;
	}
}

void eg2_8_test(){
	DLinkList *L = (DLinkList *)malloc(sizeof(DLinkList));
	ElemType a[] = {5,8,1,7,6,2,4};
	int n = 7;
	ElemType e;
	printf("初始化线性表:\n");
	CreateDLinkListR(L,a,n);
	DispList(L);
	ed2_8(L);
	DispList(L);

}

/**
 * eg2_9:
 * 有一个带头节点的双链表L(至少有一个数据节点)，设计一个算法使其元素递增有序排列
 */
void eg2_9(DLinkList *L){
	DLinkList *p = L->next->next,*q,*m;
	L->next->next = NULL;
	while(p!=NULL){
		q = L;
		while(q->next!=NULL && q->next->data < p->data){
			q = q->next;
		}
		m = p->next;
		p->next = q->next;
		p->prior = q;
		if(q->next!=NULL){
			q->next->prior = p;
		}
		q->next = p;
		p = m;
	}
}

void eg2_9_test(){
	DLinkList *L = (DLinkList *)malloc(sizeof(DLinkList));
	ElemType a[] = {5,8,1,7,6,2,4};
	int n = 7;
	ElemType e;
	printf("初始化线性表:\n");
	CreateDLinkListR(L,a,n);
	DispList(L);
	eg2_9(L);
	DispList(L);
}

//int main(){
//	eg2_9_test();
//	return 0;
//}
