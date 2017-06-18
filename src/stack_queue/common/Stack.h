#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef char ELemType;

typedef struct{
	ELemType data[MaxSize];
	int top;
}SqStack;

/**
 * 初始化顺序栈
 */
void InitSqStack(SqStack *s){
	s->top = -1;
}

/**
 * 销毁顺序栈
 */
void DestorySqStack(SqStack *s){
	free(s);
}

/**
 * 判断顺序栈是否为空
 */
int SqStackEmpty(SqStack *s){
	return s->top == -1;
}

/**
 * push元素到顺序栈中
 */
int PushSqStack(SqStack *s,ELemType e){
	if(s->top==MaxSize-1){
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

int PopSqStack(SqStack *s,ELemType *e){
	if(s->top == -1){
		return 0;
	}
	e = s->data[s->top];
	s->top--;
	return 1;
}

int GetTop(SqStack *s,ELemType *e){
	if(s->top == -1){
		return 0;
	}
	e = s->data[s->top];
	return 1;
}

typedef struct linknode{
	ELemType data;
	struct linknode *next;
}LiStack;

void InitLiStack(LiStack *s){
	s->next = NULL;
}

void DestoryLiStack(LiStack *s){
	LiStack *p = s,*q=p->next;
	while(q!=NULL){
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
}

int LiStackEmpty(LiStack *s){
	return (s->next==NULL);
}

void PushLiStack(LiStack *s,ELemType e){
	LiStack * p = (LiStack *)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

int Pop(LiStack *s,ELemType *e){
	if(s->next==NULL){
		return 0;
	}
	LiStack *p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 1;

}

int GetLiTop(LiStack *s,ELemType *e){
	if(s->next==NULL){
			return 0;
		}
	*e = s->next->data;
	return 1;
}
