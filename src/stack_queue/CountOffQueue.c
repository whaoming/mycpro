/**
 * 队列的应用：求解报数
 */

#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int rear,front;
}SqQueue;

void number(int n){
	int e;
	SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
	int i;
	for(i=1;i<=n;i++){
		q->rear++;
		q->data[q->rear] = i;
	}

	while(q->rear != q->front){
		q->front = (q->front+1)%MaxSize;
		e = q->data[q->front];
		printf("-%d-",e);
		if(q->rear != q->front){
			q->front = (q->front+1)%MaxSize;
			e = q->data[q->front];
			q->rear = (q->rear+1)%MaxSize;
			q->data[q->rear] = e;
		}
	}
}

//int main(){
//	number(15);
//	return 0;
//}
