/**
 * 有序表
 */
#include <stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkList;



static void CreateSqList(SqList *L,ElemType a[],int n){
	int i;
	for(i=0;i<n;i++){
		L->data[i] = a[i];
	}
	L->length = n;
}
static void DispSqList(SqList *L){
	int i;
	for(i=0;i<L->length;i++){
		printf("%d",L->data[i]);
	}
	printf("\n");
}
/**
 * 尾插法建立单链表
 */
static void CreateListW(LinkList *L,ElemType a[],int n){
	LinkList *m,*q = L;
	int i;
	for(i=0;i<n;i++){
		m = (LinkList *)malloc(sizeof(LinkList));
		m->data = a[i];
		q->next = m;
		q = m;
	}
	q->next = NULL;
}
/**
 * 输出线性表
 */
static void DispLinkList(LinkList *L){
	LinkList *p = L->next;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

/**
 * 以顺序表存储有序表，插入算法
 */
void SqListInsert(SqList *L,ElemType e){
	int i=0,k;
	while(i<L->length-1 && L->data[i] < e){
		i++;
	}
	for(k=L->length;k>i;k--){
		L->data[k] = L->data[k-1];
	}
	L->data[i] = e;
	L->length ++;
}

/**
 * 以链表存储有序表，插入算法
 */
void LinkListInsert(LinkList *L,ElemType e){
	LinkList *pre = L,*q;
	while(pre->next!=NULL && pre->next->data < e){
		pre = pre->next;
	}
	q = (LinkList *)malloc(sizeof(LinkList));
	q->data = e;
	q->next = pre->next;
	pre->next = q;
}

/**
 * 顺序表的二路归并算法
 * 出错的地方：判断的条件是L->length,而不是L->length-1
 */
void UnionSqList(SqList *LA,SqList *LB,SqList *LC){
	int i=0,j=0,k=0;
	while(i<LA->length && j<LB->length){
		if(LA->data[i] < LB->data[j]){
			LC->data[k] = LA->data[i];
			i++;
		}else{
			LC->data[k] = LB->data[j];
			j++;
		}
		k++;
	}
	while(i<LA->length){
		LC->data[k] = LA->data[i];
		k++;
		i++;
	}
	while(j<LB->length){
		LC->data[k] = LB->data[j];
		j++;
		k++;
	}
	LC->length = k;
}

/**
 * 链表的二路归并算法
 */
void UnionLinkList(LinkList *LA,LinkList *LB,LinkList *LC){
	LinkList *a = LA->next,*b = LB->next,*c = LC,*q;
	while(a!=NULL && b!=NULL){
		q = (LinkList *)malloc(sizeof(LinkList));
		if(a->data<b->data){
			q->data = a->data;
			q->next = c->next;
			c->next = q;
			c = q;
			a = a->next;
		}else{
			q->data = b->data;
			q->next = c->next;
			c->next = q;
			c = q;
			b = b->next;
		}

	}
	while(a!=NULL){
		q = (LinkList *)malloc(sizeof(LinkList));
		q->data = a->data;
		q->next = c->next;
		c->next = q;
		c = q;
		a = a->next;
	}
	while(b!=NULL){
		q = (LinkList *)malloc(sizeof(LinkList));
		q->data = b->data;
		q->next = c->next;
		c->next = q;
		c = q;
		b = b->next;
	}
	c->next = NULL;
}

/**
 * 顺序表的二路归并算法测试
 */
void UnionSqList_test(){
	SqList *LA = (SqList *)malloc(sizeof(SqList));
	SqList *LB = (SqList *)malloc(sizeof(SqList));
	SqList *LC = (SqList *)malloc(sizeof(SqList));
	ElemType a[] = {1,3,5,7,9};
	ElemType b[] = {2,4,6,8};
	printf("初始化LA:\n");
	CreateSqList(LA,a,5);
	DispSqList(LA);
	printf("初始化LB\n");
	CreateSqList(LB,b,4);
	DispSqList(LB);
	printf("执行二路归并算法:\n");
	UnionSqList(LA,LB,LC);
	DispSqList(LC);

}

/**
 * 链表的二路归并算法测试
 */
void UnionLinkList_test(){
	LinkList *LA = (LinkList *)malloc(sizeof(LinkList));
	LinkList *LB = (LinkList *)malloc(sizeof(LinkList));
	LinkList *LC = (LinkList *)malloc(sizeof(LinkList));
	ElemType a[] = {1,3,5,7,9};
		ElemType b[] = {2,4,6,8};
		printf("初始化LA:\n");
		CreateListW(LA,a,5);
		DispLinkList(LA);
		printf("初始化LB\n");
		CreateListW(LB,b,4);
		DispLinkList(LB);
		printf("执行二路归并算法:\n");
		UnionLinkList(LA,LB,LC);
		DispLinkList(LC);
}

//int main(){
////	UnionSqList_test();
//	UnionLinkList_test();
//	return 0;
//}


