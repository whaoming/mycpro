/**
 * 栈的应用：2.求解迷宫
 */

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

int mg[10][10] =
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
	int i;
	int j;
	int di;
}Box;

typedef struct{
	Box data[MaxSize];
	int top;
}StType;

int MgPath(int xi,int yi,int xe,int ye){
	StType * st = (StType *)malloc(sizeof(StType));
	int i,j,di,find,k;
	st->top = -1;
	st->top++;
	st->data[st->top].i = xi;
	st->data[st->top].j = yi;
	st->data[st->top].di = -1;
	mg[xi][yi]=-1;
	while(st->top>-1){
		i = st->data[st->top].i;
		j = st->data[st->top].j;
		di = st->data[st->top].di;
//		printf(" (%d,%d)",i,j);
		if(i==xe && j==ye){
			//找到的情况
			printf("迷宫的路径如下:\n");
			for(k=0;k<=st->top;k++){
				printf(" (%d,%d)",st->data[k].i,st->data[k].j);
				if(k%5==0){
					printf("\n");
				}
			}
			return 1;
		}else{
			//遍历4个方向
			//这一句非常重要
			find = 0;
			while(di<4 && find==0){
				di++;
				switch(di){
					case 0:
						i = st->data[st->top].i-1;
						j = st->data[st->top].j;
						break;
					case 1:
						i = st->data[st->top].i;
						j = st->data[st->top].j+1;
						break;
					case 2:
						i = st->data[st->top].i+1;
						j = st->data[st->top].j;
						break;
					case 3:
						i = st->data[st->top].i;
						j = st->data[st->top].j-1;
						break;
				}
				if(mg[i][j]==0){
					find = 1;
				}
			}

			if(find==1){
				mg[i][j]=-1;
				st->data[st->top].di = di;
				st->top++;
				st->data[st->top].i = i;
				st->data[st->top].j = j;
				st->data[st->top].di = -1;
			}else{
				//由于上面已经改变了i和j，所以这里不能再使用i和j来修改mg了
				mg[st->data[st->top].i][st->data[st->top].j] = 0;
				st->top--;
			}
		}

	}
	return 0;
}

void testMgPath(){
	if(MgPath(1,1,8,8)==0){
		printf("该迷宫没有解");
	}
}


int main(){
	testMgPath();
	return 0;
}
