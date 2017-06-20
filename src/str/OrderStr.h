/**
 * 顺序串
 */
#include <stdio.h>
#define MaxSize 50

typedef struct{
	char data[MaxSize];
	int length;
}SqString;

/**
 * 串复制
 */
void StrAssign(SqString *s,char cstr[]){
	int i;
	for(i=0;cstr[i]!='\0';i++){
		s->data[i] = cstr[i];
	}
	s->length = i;
}

/**
 * 将t复制给s
 */
void strCopy(SqString *s,SqString t){
	int i;
	for(i=0;i<t.length;i++){
		s->data[i] = t.data[i];
	}
	s->length = t.length;
}

/**
 * 串的比较
 */
int StrEqual(SqString s,SqString t){
	int i,j = 1;
	if(s.length!=t.length){
		return 0;
	}
	else{
		for(i=0;i<s.length;i++){
			if(s.data[i]!=t.data[j]){
				j=0;
				break;
			}
		}
	}
	return j;
}

int StrLength(SqString s){
	return s.length;
}

/**
 * 字符串连接
 */
SqString Concat(SqString s,SqString t){
	SqString str;
	int i;
	for(i=0;i<s.length;i++){
		str[i] = s.data[i];
	}
	i=0;
	for(i=0;i<t.length;i++){
		str[i+s.length] = t.data[i];
	}
	str.length = s.length+t.length;
	return str;
}

/**
 * 第i个开始，连续j个字符，返回新的
 */
SqString SubStr(SqString s,int i,int j){
	SqString str;
	int k;
	if(i<=0 || j<=0 || i>s.length || i+j-1>s.length){
		return str;
	}
	for(k=i-1;k<i+j-1;k++){
		str.data[k-i+1] = s.data[k];
	}
	str.length = k;
	return str;
}

/**
 * 将串s2插入到串s1的第i个字符中，即将s2的第一个字符作为s1的第i个字符，返回新串
 */
SqString InsStr(SqString s1,int i,SqString s2){
	SqString str;
	int k;
	if(i<1 || i>s1.length){
		return str;
	}
	for(k=0;k<s1.length;k++){
		str[k] = s1.data[k];
	}
	for(k=0;k<s2.length;k++){
		str[k+s2.length] = s2.data[k];
	}
	for(k=i+s2.length;k>s1.length+i;k++){
		str[k] = s1.data[k-s2.length];
	}
	str.length = s1.length + s2.length;
	return str;

}

/**
 * 删除s的从第i个开始连续j个字符
 * 返回新的字符
 */
SqString DelStr(SqString s,int i,int j){
	SqString str;
	if(i<1 || i+j-1>s.length){
		return str;
	}
	int k;
	for(k=0;k<i-1;k++){
		str[k] = s.data[i];
	}
	for(k=i+j-1;k<s.length;k++){
		//这里为什么是k-j呢，因为上面那个循环贷i-1开始就进不去了
		str[k-j] = s.data[k];
	}
	str.length = s.length - j;
	return str;
}

/**
 * 字符串替换
 */
SqString RepStr(SqString s,int i,int j,SqString t){
	SqString str;
	if(i<1 || i>s.length || i+j-1 >s.length){
		return str;
	}
	int k;
	for(k=0;k<i-1;k++){
		str[k] = s.data[k];
	}
	for(k=0;k<t.length;t++){
		str[k+i-1] = t.data[k];
	}
	for(k=i+j-1;k<s.length;k++){
		str[i+t.length-1] = t.data[k];
	}
	str.length = s.length+t.length-j;
	return str;
}

void DispStr(SqString s){
	int i;
	if(s.length>0){
		for(i=0;i<s.length;i++){
			printf("%c",s.data[i]);
		}
		printf("\n");
	}
}
