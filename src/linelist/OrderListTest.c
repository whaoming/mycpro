///**
// * eg2.3
// * 假设一个线性表采用顺序表表示。设计一个算法，
// * 删除其中所有值等于x的元素
// * 要求时间复杂度为O(n),空间复杂度为O(1)
// */
//
///**
// * eg2.4
// * 有一个顺序表L，假设元素类型ElemType为整型。设计一个算法：
// * 以第一个元素为分界线，将所有小于它的元素移到该元素的前面
// * 将所有大于它的元素移到该元素的后面
// */
//
//#include <stdio.h>
//#include "common/linelist.h"
//
///**
// * eg2.3
//// * 注意"躲过"的那一个  就是不能以：
// * L->data[i] = L->data[i+k]这种形式，这种会让某一个元素躲过
// */
//#include <stdio.h>
//#include "common/linelist.h"
//
//
//#include <stdio.h>
//#include "common/linelist.h"
//void delete_eg2_3(SqList *L,ElemType e){
//	int i,k;
//	for(i=0,k=0;i<L->length;i++){
//		if(L->data[i]==e){
//			k++;
//		}else{
//			L->data[i-k] = L->data[i];
//		}
//	}
//	L->length = L->length-k;
//}
//
///**
// * eg2-3的测试
// */
//void delete_eg2_3_test(){
//	int s[] = {5,5,4,8,9,6,7,1,2,3,0,5,8,4,1,2,5,4};
//	SqList *L = (SqList *)malloc(sizeof(SqList));
//	CreateList(L,s,17);
//	DispList(L);
//	printf("删除元素5\n");
//	delete_eg2_3(L,5);
//	DispList(L);
//}
//
//void move_eg2_4(SqList *L){
////	int i=1,k=0;
////	int tmp = L->data[k];
////	for(i;i<L->length;i++){
////		if(L->data[i]<tmp){
////			L->data[k] = L->data[i];
////			k = i;
////		}
////	}
////	L->data[k] = tmp;
//
////	int i=0,j=L->length-1;
////	int tmp = L->data[i];
////	while(i<j){
////		if(tmp>L->data[j] && i<j){
////			L->data[i] = L->data[j];
////			i++;
////		}
////
////		if(L->data[i]>tmp &&i<j){
////			L->data[j] = L->data[i];
////			j--;
////		}else{
////			i++;
////		}
////	}
////	L->data[i] = tmp;
//
//	int i=0,j=L->length-1;
//	int tmp = L->data[i];
//	int t = 0;
//	i++;
//	while(i<j){
//		while(tmp<L->data[j] && i<j){
//			j--;
//		}
//		while(tmp>L->data[i] && i<j){
//			i++;
//		}
//		t = L->data[j];
//		L->data[j] = L->data[i];
//		L->data[i] = t;
//	}
//	t = L->data[j];
//	L->data[j] = L->data[0];
//	L->data[0] = t;
//	printf("i:%d\n",j);
//}
//
///**
// * eg2_4第二种解法
// */
//void move2_eg2_4(SqList *L){
//
//	int tmp = L->data[0];
//	int i=0,j=L->length-1;
//	while(i<j){
//		while(i<j && L->data[j]>tmp){
//			j--;
//		}
//		L->data[i] = L->data[j];
//		i++;
//		while(i<j && L->data[i]<tmp){
//			i++;
//		}
//		L->data[j] = L->data[i];
//		j--;
//	}
//	L->data[i] = tmp;
//}
//
//void move_eg2_4_test(){
//	int s[] = {4,5,6,8,1,2,3,7,9,0};
//	SqList *L = (SqList *)malloc(sizeof(SqList));
//	CreateList(L,s,10);
//	DispList(L);
////	move_eg2_4(L);
//	move2_eg2_4(L);
//	DispList(L);
//}
//
////int main(){
//////	move_eg2_4_test();
////	return 0;
////}
