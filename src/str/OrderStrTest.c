#include "OrderStr.h"

/**
 * 以顺序串作为串的存储结构，
 * 设计一个算法求串s中出现的第一个最长的连续相同字符构成的平台
 */
void LongestSqString(SqString s,int *i,int *m){
	int index=0,max=0,q=0,length=0,start=0;
	while(q<s.length-1){
		if(s.data[q]==s.data[q+1]){
			q++;
			length++;
		}else{
			if(max<length){
				max = length;
				index = start;
			}
			q++;
			start = q;
			length = 1;
		}
	}
	*i = index;
	*m = max;
}

/**
 * 思路：
 * 总是把当前这一个和下一个相比
 * 总共有几个值：
 * 1.记录当前连续最多的值是从哪里开始的 ：index
 * 2.记录当前连续最多的位数：max
 * 3.从哪里开始不相等的 ：start
 * 4.自从遇到第一个相等之后已经有多少个相等了：length
 */
