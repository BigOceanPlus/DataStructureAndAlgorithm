#include <stdio.h>
#include <string.h>

int next[1000];  // next数组 
char str1[500];  // 主串 
char str2[100];  // 模式串 

void getnext(int len);  // 求next数组 

/*
Input:
12345
234
Output:
1
*/

int main(void){
	
	scanf("%s %s",str1,str2);  // 读取主串和模式串 
	
	int len1 = strlen(str1);  // 主串长度 
	int len2 = strlen(str2);  // 模式串长度 
	getnext(len2);  // 算出next数组 
	
	int i = 0;  // 初始化 
	int j = 0;
	
	while(i < len1 && j < len2){  // kmp模式匹配 
		if(j == -1 || str1[i] == str2[j]){  // 字符相同时i，j同时移动 
			i ++;
			j ++;
		}
		else
			j = next[j];  // j转到指定位置，i不需要回溯 
		
	}
	
	if(j == len2)  // 匹配成功 
		printf("%d",i - j);  // 返回模式串位置 
	else  // 匹配失败 
		printf("-1");
		
	return 0;
}

void getnext(int len){
	int j,k;
	next[0] = -1;  // 最左边j无法移动，所以有此初始化 
	
	j = 0;
	k = -1;
	
	while(j < len - 1){
		if(k == -1 || str2[k] == str2[j])  // 索引值j，k对应的字符相等或k = -1时 
			next[++ j] = ++ k;
		else  // k转到指定位置 
			k = next[k];
	}
} 
