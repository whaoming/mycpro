/**
 * 队列的应用：求解迷宫
 */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

static int mg[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

typedef struct{
	int i,j;//当前坐标
	int pre;//上一个点在队列中的值
}Box1;

typedef struct{
	Box1 data[MaxSize];
	int front,rear;
}QuType;

void print1(QuType *qu,int front){

//	Box1 *box = &(qu->data[front]),*b;
//	while(box!=NULL){
//		b = &(qu->data[box->pre]);
//		box->pre = -1;
//		box = b;
//	}
//	int n = 0;
//	while(n<qu->rear){
//		if(qu->data[n].pre==-1){
//			printf("(%d,%d) ",qu->data[n].i,qu->data[n].j);
//		}
//		if(n%5==0){
//			printf("\n");
//		}
//	}

	int k = qu->data[qu->front].pre,m;
	qu->data[qu->front].pre = -1;
	while(k!=-1){
		m = qu->data[k].pre;
		qu->data[k].pre = -1;
		k = m;
	}

	int n = 0;
	k=0;
	while(n<qu->rear){
		if(qu->data[n].pre==-1){
			k++;
			printf("(%d,%d) ",qu->data[n].i,qu->data[n].j);
		}
		if(k%5==0){
			printf("\n");
		}
		n++;
	}
}

int mgpath1(int xi,int yi,int xe,int ye){
	QuType *qu = (QuType *)malloc(sizeof(QuType));
	int i,j,m,n,di,find;
	qu->front = qu->rear = -1;
	qu->rear++;
	qu->data[qu->rear].i = xi;
	qu->data[qu->rear].j = yi;
	qu->data[qu->rear].pre = -1;
	while(qu->rear!=qu->front && !find){
		qu->front++;
		i = qu->data[qu->front].i;
		j = qu->data[qu->front].j;
		if(i==xe && j == ye){
			find=1;
			print1(qu,qu->front);
			return 1;
		}
		di = 0;
		while(di<4){
			switch(di){
			case 0:
				m = i-1;
				n = j;
				break;
			case 1:
				m=i;
				n=j+1;
				break;
			case 2:
				m=i+1;
				n=j;
				break;
			case 3:
				m=i;
				n=j-1;
				break;
			}
			if(mg[m][n]==0){
				//加入到队列中
				mg[m][n]=-1;
				qu->rear++;
				qu->data[qu->rear].i = m;
				qu->data[qu->rear].j = n;
				qu->data[qu->rear].pre = qu->front;
			}
			di++;
		}
	}
	return 0;
}

static void testAll(){
	if(mgpath1(1,1,8,8)==0){
		printf("该迷宫没有解");
	}else{
		printf("此迷宫有解");
	}
}

int main(){
	testAll();
	return 0;
}
