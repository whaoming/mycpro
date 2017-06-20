#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LiString;

/**
 * 将cstr赋给q
 */
void StrAssign(LiString *q,char cstr){
	int i = 0;
	LiString * m,*n = q;
	while(cstr[i]!='\0'){
		m = (LiString *)malloc(sizeof(LiString));
		m->data = cstr[i];
		n->next = m;
		n = m;
		i++;
	}
	n->next = NULL;
}

/**
 * 将串t复制给串s
 */
void StrCopy(LiString *s,LiString *t){
	LiString *p = s,*q = t->next,*m;
	while(q!=NULL){
		m = (LiString *)malloc(sizeof(LiString));
		m->data = q->data;
		p->next = m;
		p = m;
		q = q->next;
	}
	p->next = NULL;
}

/**
 * 判断串相等
 */
int StrEqual(LiString *s,LiString *t){
//	int flag = 1;
//	LiString *p = s->next,*q = t->next;
//	while(p!=NULL && q!=NULL){
//		if(p->data!=q->data){
//			flag = 0;
//			break;
//		}
//	}
//	if(p->next!=NULL){
//		flag = 0;
//	}
//	if(q->next!=NULL){
//		flag = 0;
//	}
//	return flag;
	LiString *p = s->next,*q = t->next;
	while(p!=NULL ** q!=NULL && p->data == q->data){
		p = p->next;
		q = q->next;
	}
	if(p->next==NULL && q->next==NULL){
		return 1;
	}else{
		return 0;
	}

}

/**
 * 判断串的长度
 */
int StrLength(LiString *s){
	int i;
	LiString *p = s->next;
	while(p!=NULL){
		i++;
	}
	return i;
}

/**
 * 串连接，尾插法
 */
LiString* Concat(LiString *s,LiString *t){
	LiString * q = (LiString *)malloc(sizeof(LiString));
	LiString *m = s->next,*n = t->next,*k,*g=q;
	while(m!=NULL){
		k = (LiString *)malloc(sizeof(LiString));
		k->data = m->data;
		g->next = k;
		g = k;
		m = m->next;
	}
	while(n!=NULL){
		k = (LiString *)malloc(sizeof(LiString));
		k->data = n->data;
		g->next = k;
		g = k;
		n = n->next;
	}
	g->next = NULL;
	return q;
}

/**
 * 返回串s中从第i个字符开始的，由连续j个字符组成的子串。返回新串
 */
LiString * SubStr(LiString *s,int i,int j){
	int k;
	LiString *p = s->next,*str = (LiString *)malloc(sizeof(LiString)),*q,*g = str;
	while(p!=NULL && k<i-1){
		k++;
		p = p->next;
	}
	if(p==NULL){
		return str;
	}
	k=0;
	while(p!=NULL && k<j){
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		g->next = q;
		g = q;
		p = p->next;
		k++;
	}
	g->next = NULL;
	return str;
}

/**
 * 将串s2插入串s1的第i个字符位置，返回新串
 */
LiString * InsStr(LiString *s,int i,LiString *t){

}

/**
 * 删除串s中第i个开始连续的j个字符，返回新串
 */
LiString * DelStr(LiString *s,int i,int j){

}

/**
 * 将s的第i个开始连续j个 替换成t，然后返回新串
 */
LiString * RepStr(LiString *s,int i,int j,LiString *t){

}

/**
 * 输出
 */
void DispStr(LiString *s){

}
