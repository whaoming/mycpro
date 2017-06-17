#include <stdio.h>
#include "common/linelist.h"

static void CreateList(SqList *L,ElemType a[],int n){
	int i;
	for(i=0;i<n;i++){
		L->data[i] = a[i];
	}
	L->length = n;
}

static void DispList(SqList *L){
	int i;
	for(i=0;i<L->length;i++){
		printf("%d",L->data[i]);
	}
	printf("\n");
}

static int ListLength(SqList *L){
	return L->length;
}

static int ListEmpty(SqList *L){
	return L->length==0;
}

/**
 * 插入
 */
static int ListInsert(SqList *L,int i,ElemType e){
	if(i>L->length || i<0){
		return 0;
	}
	i--;
	int k ;
	for(k=L->length;k>i;k--){
		L->data[k] = L->data[k-1];
	}
	L->data[i] = e;
	L->length++;
	return 1;
}

/**
 * 获取某个位置的元素
 */
static int getElem(SqList *L,int i,ElemType *e){
	if(i>L->length || i<1){
		return 0;
	}
	*e = L->data[i-1];
}

/**
 * 查看某个元素的位置
 */
static int locatElem(SqList *L,ElemType e){
	int i=0;
	while(i<L->length && e!=L->data[i])
		i++;
	if(i<L->length){
		return i+1;
	}else{
		return -1;
	}
}
/**
 * 删除第i个位置的
 */
static int ListDelete(SqList *L,int i,ElemType *e){
	if(i<1 || i>L->length){
		return 0;
	}
	*e = L->data[i-1];
	int k;
	for(k=i-1;k<L->length-1;k++){
		L->data[k] = L->data[k+1];
	}
	L->length--;

}

static void orderList(){
	int s[] = {5,4,8,9,6,7,1,2,3,0};
	SqList *L = (SqList *)malloc(sizeof(SqList));
	CreateList(L,s,10);
	DispList(L);
	printf("删除第10个位置的元素");
	int e = 0;
	ListDelete(L,10,&e);
	DispList(L);
	int locat = locatElem(L,3);
	printf("元素3的位置是:%d\n",locat);
	int elem = getElem(L,3,&e);
	printf("获取第3个位置的元素是:%d\n",e);
	printf("在第3个位置插入一个元素3\n");
	ListInsert(L,3,3);
	DispList(L);

}

/**
 * 求长度
 * 判断是否为空
 * 插入
 * 按元素值查找
 */
//int main(){
//	orderList();
//	return 1;
//}
