/**
 * 栈的应用:表达式求值
 */
#include <stdio.h>
#define MaxOp 7
#define MaxSize 50
typedef struct{
	char ch;
	//优先级
	int pri;
}PRI;
PRI lpri[]={{'=',0},{'(',1},{'+',3},{'-',3},{'*',5},{'/',5},{')',6}};
PRI rpri[]={{'=',0},{'(',6},{'+',2},{'-',2},{'*',4},{'/',4},{')',1}};


/**
 * 求左运算符的优先级
 */
int LeftPri(char c){
	int i;
	for(i=0;i<MaxOp;i++){
		if(lpri[i].ch==c){
			return lpri[i].pri;
		}
	}
	return -1;
}

/**
 * 求右运算符的优先级
 */
int RightPri(char c){
	int i;
	for(i=0;i<MaxOp;i++){
		if(rpri[i].ch==c){
			return rpri[i].pri;
		}
	}
	return -1;
}

/**
 * 判断是否是运算符
 */
int InOp(char c){
	if(c=='(' || c==')' || c=='+' || c=='-' || c=='*' || c=='/'){
		return 1;
	}else{
		return 0;
	}
}

/**
 * 求俩个符号的优先级
 */
int Precede(char l,char r){
	int left = LeftPri(l),right=RightPri(r);
//	printf("%c:%d,%c:%d\n",l,left,r,right);
	if( left>right){
		return 1;
	}else if(left==right){
		return 0;
	}else{
		return -1;
	}
}

static void trans(char *exp,char postexp[]){
	struct{
		char data[MaxSize];
		int top;
	}op;
	int i = 0;
	op.top = -1;
	op.top++;
	op.data[op.top] = '=';
	while(*exp!='\0'){
		if(InOp(*exp)!=1){
			while(*exp>='0' && *exp<='9'){
//				printf("此时要进postexp的是:%c\n",*exp);
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';
		}else{
			switch(Precede(op.data[op.top],*exp)){
				case 1:
					postexp[i++] = op.data[op.top];
					op.top--;
					break;
				case 0:
					op.top--;
					exp++;
					break;
				case -1:
					op.top++;
					op.data[op.top] = *exp;
					exp++;
					break;
			}
		}
	}
	//检查栈底是不是=符号
	while(op.data[op.top]!='='){
		postexp[i++] = op.data[op.top];
		op.top--;
	}
	postexp[i] = '\0';
}

void testTrans(){
	char *exp="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("%s",postexp);
}

float compvalue(char *postexp){
struct{
	char data[MaxSize];
	int top;
}st;
	float a,b,c,d;
	st.top = -1;
	while(*postexp!='\0'){
		switch(*postexp){
			case '+':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = a+b;
				st.top++;
				st.data[st.top] = c;
				break;
			case '-':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = b-a;
				st.top++;
				st.data[st.top] = c;
				break;
			case '*':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = a*b;
				st.top++;
				st.data[st.top] = c;
				break;
			case '/':
				a = st.data[st.top];
				st.top--;
				b = st.data[st.top];
				st.top--;
				c = b/a;
				st.top++;
				st.data[st.top] = c;
				break;
			default:
				d = 0;
				while(*postexp >='0' && *postexp <='9'){
					d = d*10 +*postexp-'0';
					//这里就是去掉#的意思
					postexp++;
//					printf("%c",*postexp);
				}
				st.top++;
				st.data[st.top] = d;
//				postexp++;
				break;
		}
		postexp++;
	}
	return st.data[st.top];
}

void testAll(){
	char *exp="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("中缀表达式：%s\n",exp);
	printf("后缀表达式：%s\n",postexp);
	printf("表达式的结果是:%g",compvalue(postexp));
}

//int main(){
////	testTrans();
//	testAll();
//	return 0;
//}
