#include "common/Stack.h"

/**
 * eg3_4:
 * 编写一个算法利用顺序栈判断一个字符串是否是对称串
 */
int eg3_4(ELemType str[]){
	SqStack *s = (SqStack *)malloc(sizeof(SqStack));
	int i=0,e;
	while(str[i]!='\0'){
		PushSqStack(s,str[i]);
	}
	i=0;
	while(str[i]!='\0'){
		PopSqStack(s,&e);
		if(str[i]!=e){
			DestorySqStack(s);
			return 0;
		}
	}
	DestorySqStack(s);
	return 1;
}

/**
 * 判断输入的表达式中括号是否匹配
 */
int Match(char exp[],int n){
	LiStack * s = (LiStack *)malloc(sizeof(LiStack));;
	InitLiStack(s);
	int i=0,flag=1;
	char e;
	while(i<n && flag){
//		printf("i:%d,str:%c\n",i,exp[i]);
		if(exp[i]=='('){
//			printf("存入");
			PushLiStack(s,exp[i]);
		}else if(exp[i]==')'){
//			printf("i:%d,GetLiTop(s,&e):%d\n",i,GetLiTop(s,&e));
			if(GetLiTop(s,&e)==1){
//				printf("e:%c\n",e);
				if(e=='('){
					Pop(s,&e);
				}else{
//					printf("flag = 0;");
					flag = 0;
				}
			}else{
//				printf("flag = 0;");
				flag = 0;
			}
		}
		i++;
	}
//	printf("GetLiTop(s,&e):%d\n",GetLiTop(s,&e));
	if(!LiStackEmpty(s))
//	{
//		flag = 1;
//	}else
		flag = 0;
	DestoryLiStack(s);
	return flag;
}

void Match_test(){
	char exp[] = {'3','(','(',')',')','w',')','('};
	int n=8;
	printf("匹配的结果是：%d\n",Match(exp,n));
}

//int main(){
//	Match_test();
//	return 0;
//}
