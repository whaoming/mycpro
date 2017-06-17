#include <stdio.h>
#include "common/linklist.h"
/**
 * 建立单链表：1.头插法  2.尾插法
 */

/**
 * 头插法建立单链表
 */
static void CreateListF(LinkList *L,ElemType a[],int n){
	LinkList *m;
	L = (LinkList *)malloc(sizeof(LinkList));
	int i;
	for(i=0;i<n;i++){
		m = (LinkList *)malloc(sizeof(LinkList));
		m->data = a[i];
		m->next=L->next;
		L->next = m;
	}
}

/**
 * 尾插法建立单链表
 */
static void CreateListW(LinkList *L,ElemType a[],int n){
	LinkList *m,*q;
	L = (LinkList *)malloc(sizeof(LinkList));
	q = (LinkList *)malloc(sizeof(LinkList));
	q = L;
	int i;
	for(i=0;i<n;i++){
		m = (LinkList *)malloc(sizeof(LinkList));
		m->data = a[i];
		q->next = m;
		q = m;
	}
}

/**
 * 初始化线性表InitList(L)
 * 销毁线性表
 * 判断线性表是否为空表
 * 求线性表的长度
 * 输出线性表
 * 求线性表中某个数据元素值(第i个位置的数据值)
 * 按元素值查找
 * 在某个位置插入数据元素
 * 删除第i个元素
 */

/**
 * 初始化链表
 */
static void InitList(LinkList *L){
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
}

/**
 * 销毁线性表
 */
static void destoryList(LinkList *L){
	LinkList *pre = L,*p=L->next;
	while(p!=NULL){
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

/**
 * 判断线性表是否为空
 */
static int isListEmpty(LinkList *L){
	return L->next==NULL;
}

/**
 * 求线性表的长度
 */
static int ListLength(LinkList *L){
	int i=0;
	LinkList *p = L;
	while(p->next!=NULL){
		i++;
		p = p->next;
	}
	return i;
}

/**
 * 输出线性表
 */
static void DispList(LinkList *L){
	LinkList *p = L->next;
	while(p!=NULL){
		printf("%c",p->data);
		p = p->next;
	}
	printf("\n");
}

/**
 * 求线性表中某个数据元素值(第i个位置的数据值)
 */
static int getElem(LinkList *L,int i,ElemType *e){
	int m = 0;
	LinkList * p = L->next;

//	while(p!=NULL){
//		if(m==i){
//			*e = p->data;
//		}
//		m++;
//		p = p->next;
//		return 1;
//	}
//	return 0;

	while(m<i-1 && p!=NULL){
		m++;
		p = p->next;
	}
	if(p==NULL){
		return 0;
	}else{
		*e = p->data;
		return 1;
	}
}

/**
 * 按元素值查找
 */
static int LocatElem(LinkList *L,ElemType e){
	int i=0;
	LinkList *p = L->next;
	while(p!=NULL && p->data != e){
		i++;
	}
	if(p==NULL){
		return -1;
	}else{
		return i+1;
	}
}

/**
 * 在某个位置插入数据元素
 */
static int InsertElem(LinkList *L,int i,ElemType e){

	LinkList *m,*p = L;
	int k = 0;
	while(p!=NULL && k<i-1){
		k++;
		p = p->next;
	}
	if(p==NULL){
		return 0;
	}
	else{
	m = (LinkList *)malloc(sizeof(LinkList));
	m->data = e;
	m->next = p->next;
	p->next = m;
	return 1;
	}
}

/**
 * 删除第i个位置的数据元素
 */

static int ListDelete(LinkList *L,int i,ElemType *e){
	LinkList *p = L->next,*q;
	int k = 0;
	while(k<i-1 && p!=NULL){
		k++;
		q = p;
		p = p->next;
	}
	if(p==NULL){
		return 0;
	}else{
		q->next = p->next;

		free(p);
	}
}

static void test(){
	LinkList * h;
	ElemType e;
	printf("单链表的基本运算如下：\n");
	printf("(1)初始化单链表h\n");
	InitList(h);
	h = (LinkList *)malloc(sizeof(LinkList));
	h->next = NULL;
	printf("(2)依次采用尾插法插入a，b，c，d，e元素\n");
	int a = InsertElem(h,1,'a');
	//printf("插入第一个位置是否成功:%d",a);
	InsertElem(h,2,'b');
	InsertElem(h,3,'c');
	InsertElem(h,4,'d');
	InsertElem(h,5,'e');
	printf("(3)输出单链表h:");
	DispList(h);
	printf("(4)单链表h的长度=%d\n",ListLength(h));
	printf("(5)单链表是否为空%d\n",isListEmpty(h));
	getElem(h,3,&e);
	printf("(6)单链表h的第3个元素=%c\n",e);
	printf("(7)元素a的位置=%d\n",LocatElem(h,'a'));
	printf("(8)在第4个元素位置上插入f元素\n");
	InsertElem(h,4,'f');
	printf("(9)输出单链表h:");
	DispList(h);
	printf("(10)删除h的第3个元素\n");
	ListDelete(h,3,e);
	printf("(11)输出单链表h：");
	DispList(h);
	printf("(12)释放单链表h\n");
	destoryList(h);
}

//int main(){
//	test();
//	return 0;
//}
