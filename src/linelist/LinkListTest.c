/**
 * 单链表的测试题
 */

/**
 * eg2_5
 *有一个带头结点的单链表L={a1,b1,a2,b2,a3,b3...}，设计
 *设计一个算法将其拆分成俩个带头结点的单链表L1和L2
 *L1={a1,a2,a3,...}
 *L2={bn,bn-1,bn-2....b1}
 *要求L1使用L的头节点
 */


/**
 * eg2_6
 * 设计一个算法，删除一个单链表L中元素值最大的节点
 */

/**
 * eg2_7
 * 有一个带头结点的单链表L(至少有一个数据节点)，设计一个算法使其元素有序递增
 *
 */

#include <stdio.h>

typedef int ElemType;

/**
 * 单链表结构
 */
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkList;

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
 * 输出线性表
 */
void DispList(LinkList *L){
	LinkList *p = L->next;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

void eg2_5(LinkList *L,LinkList *L1,LinkList *L2){
	LinkList *p,*q,*m;
	q = L1 = L;
	L2 = (LinkList *)malloc(sizeof(LinkList));
	m = L2;
	p = L->next;
	while(p!=NULL){
		//先采用尾插法操作L1
		q->next = p;
		q = p;
		p = p->next;
		//这里应该做的是记住p的下一个节点
		//而不能让m=p然后来操作m，这样其实也是在操作p，所以是不行的
		m = p->next;;
		p->next = L2->next;
		L2->next = p;
		p = m;
	}
	q->next = NULL;
}


/**
 * eg2-6:设计一个算法，删除一个单链表L中元素值最大的节点
 * 思路：也就是遍历这个链表。然后每次都记录前驱界面
 */
void eg2_6(LinkList *L){
	LinkList *pre =L ,*maxprior=L,*p=L->next,*q;
	while(p!=NULL){
		if(p->data > maxprior->next->data){
			maxprior = pre;
		}
		pre = p;
		p = p->next;
	}
	//删除maxprior的下一个节点
	q = maxprior->next;
	maxprior->next = q->next;
	free(q);
}

void test_eg2_6(){
	printf("test_eg2_6\n");
	LinkList * L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	InsertElem(L,1,7);
	InsertElem(L,2,2);
	InsertElem(L,3,3);
	InsertElem(L,4,9);
	InsertElem(L,5,6);
	InsertElem(L,6,1);
	InsertElem(L,6,0);
	DispList(L);
	eg2_6(L);
	DispList(L);
}

/**
 * eg2_7
 * 有一个带头结点的单链表L(至少有一个数据节点)，
 * 设计一个算法使其元素有序递增
 */

void eg2_7(LinkList *L){
//	LinkList *s = L,*p = L->next->next,*m,*n;
//	while(p!=NULL){
//		m = s->next;
//		while(m->next!=NULL && m->next->data < p->data){
//			m = m->next;
//		}
//		n = p->next;
//		p->next = m->next;
//		m->next = p;
//		p = n;
//	}
//	L = s;

//	LinkList *L1=L,*cur = L1->next,*pre = L1,*p = L->next->next,*q;
//	while(p!=NULL){
//		while(cur!=NULL && cur->data<p->data){
//			pre = cur;
//			cur = cur->next;
//		}
//		q = p->next;
//		p->next = pre->next;
//		pre->next = p;
//		p = q;
//	}
//	L = L1;

	LinkList *p,*q,*pre,*cur;
	p = L->next->next;
	L->next->next = NULL;
	while(p!=NULL){
		pre = L;
		cur = L->next;
		while(cur!=NULL && cur->data < p->data){
			pre = cur;
			cur = cur->next;
		}
		q = p->next;
		p->next = pre->next;
		pre->next = p;
		p = q;

	}
}

void test_eg2_7(){
	printf("test_eg2_7\n");
	LinkList * L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	InsertElem(L,1,7);
	InsertElem(L,2,2);
	InsertElem(L,3,3);
	InsertElem(L,4,9);
	InsertElem(L,5,6);
	InsertElem(L,6,1);
	InsertElem(L,6,0);
	DispList(L);
	eg2_7(L);
	DispList(L);

}



int main(){
	printf("main\n");
//	test_eg2_7();
//	return 1;
//
//	test_eg2_6();
	return 0;
}

