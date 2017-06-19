#include <stdio.h>
#define MaxSize 5
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;

/**
 * 1.初始化队列InitQueue(q)
 */

void InitQueue(SqQueue *q){
	q->front = q->rear = -1;
}

/**
 * 销毁队列
 */
void DestorySqQueue(SqQueue *q){
	free(q);
}

/**
 * 判断队列是否为空
 */
int SqQueueEmpty(SqQueue *q){
	return q->front == q->rear;
}

/**
 * 进队列
 */
int enSqQueue(SqQueue *q,ElemType e){
	if(q->rear == MaxSize -1){
		//队列满了 上溢
		return 0;
	}
	q->rear ++;
	q->data[q->rear] = e;
	return 1;
}

/**
 * 出队列
 */
int deSqQueue(SqQueue *q,ElemType *e){
	if(q->rear == q->front)
		return 0;
	q->front++;
	*e = q->data[q->front];
	return 1;
}

/**
 * ******************环形队列***********************
 * 环形队列其实只要把结构想象成存储的地方是环形的，那么你当进队一个元素是怎么样的呢
 * 假如内存结构是0，1，2，3，4，那么当rear处于4的时候，这时候要在进队一个元素，就是：
 * rear= rear+1，但是rear不能等于5呀，所以必须rear=(rear+1)%MaxSize
 */

void InitQueueH(SqQueue *q){
	q->front = q->rear ;
}

/**
 * 一个元素进环形队列
 */
int enSqQueueH(SqQueue *q,ElemType e){
	if((q->rear+1)%MaxSize == q->front){
		return 0;
	}
	q->rear = (q->rear+1)%MaxSize;
	q->data[q->rear] = e;
	return 1;
}

/**
 * 一个元素从环形队列出来
 */
int deSqQueueH(SqQueue *q,ElemType *e){
	if(q->rear==q->front){
		return 0;
	}
	q->front = (q->front+1)%MaxSize;
	e = q->data[q->front];
	return 1;
}

/**
 * eg3_7:
 * 对环形队列来说，如果知道队头指针和队列中元素个数，就可以计算出队尾指针。
 * 也就是说,可以用队列中元素个数代替队尾指针。
 * 如下：
 */

typedef struct{
	ElemType data[MaxSize];
	int front;
	int count;//元素个数
}QuType;

void InitTypeQueue(QuType *q){
	q->front = q->count = 0;
}

int enTypeQueue(QuType *q,ElemType e){
	if(q->count == MaxSize){
		return 0;
	}else{
		int rear;
		rear = (q->front + q->count)%MaxSize;
		rear = (rear+1)%MaxSize;
		q->data[rear] = e;
		q->count ++;
		return 1;
	}
}

int deTypeQueue(QuType *q,ElemType *e){
	if(q->count == 0){
		return 0;
	}else{
		q->front  = (q->front+1)%MaxSize;
		e = q->data[q->front];
		q->count--;
		return 1;
	}
}

int TypeQueueEmpty(QuType *q){
	return q->count == 0;
}

/**
 * *****************队列的链式存储***********************
 */
typedef struct qnode{
	ElemType data;
	struct qnode *next;
}QNode;

typedef struct{
	QNode *rear;
	QNode *front;
}LiQueue;

/**
 * 链式队列的初始化
 */
void InitLiQueue(LiQueue *q){
	q->front = q->rear = NULL;
}

/**
 * 链式队列的销毁
 */
void DestoryLiQueue(LiQueue *q){
	QNode *p = q->front,*r;
	if(p!=NULL){
		r = p->next;
		while(r!=NULL){
			free(p);
			p = r;
			r = r->next;
		}
	}
	free(p);
	free(q);
}

/**
 * 链式队列判空
 */
int LiQueueEmpty(LiQueue *q){
	return q->rear==NULL;
}

/**
 * 进链式队列
 */
void enLiQueue(LiQueue *q,ElemType e){
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	if(q->rear==NULL){
		q->rear = q->front = p;
	}else{
		q->rear->next = p;
		q->rear = p;
	}
}

/**
 * 出链式队列
 */
int DeLiQueue(LiQueue *q,ElemType *e){
	if(q->rear == NULL){
		return 0;
	}
	QNode *t;
	t = q->front;
	if(q->front == q->rear){
		q->front = q->rear = NULL;
	}else{
		q->front = q->front->next;
	}
	*e = t->data;
	free(t);
}

/**
 * eg3_8:
 * 采用一个不带头结点只有一个为节点指针rear的循环单链表存储队列
 * 设计队列的初始化，进队和出队算法
 */

typedef struct node{
	ElemType data;
	struct node *next;
}LinkList;

void InitEgLiQueue(LinkList *rear){
	rear = NULL;
}

void enEgLiQueue(LinkList *rear,ElemType e){
	LinkList *p = (LinkList *)malloc(sizeof(LinkList));
	p->data = e;
	if(rear==NULL){
		//当本来没有节点的时候，插入一个节点，必须让自己指向自己
		p = p->next;
		rear = p;
	}else{
		p->next = rear->next;
		rear->next =p;
		rear = p;
	}
}

int deEgLiQueue(LinkList *rear,ElemType *e){
	/**
	 * 1.检查是否有节点
	 * 2.检查是否只有一个节点
	 * 3.当有一个以上的节点的时候
	 */
	LinkList *p;
	if(rear==NULL){
		return 0;
	}else if(rear->next == rear){
		*e = rear ->data;
		free(rear);
		rear = NULL;
	}else{
		//记住rear是指向队尾，所以rear->next才是队头
		p = rear->next;
		*e = p->data;
		rear->next = p->next;
		free(p);
	}
	return 1;
}



