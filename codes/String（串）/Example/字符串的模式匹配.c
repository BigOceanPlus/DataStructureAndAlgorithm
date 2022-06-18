#include <stdio.h>
#include <string.h>

char s[501], t[501];  // s为主串，t为模式串
// 字符串索引从1开始 

/*
Input:
12345
234
Output:
2
*/

int Func(char* s,char* t){
	t[0] = strlen(t + 1);  // 记录字符串t的长度 
	
	int i = 1,j = 1;  // 字符串索引初始化 
	while(s[i]){
		while(s[i] == t[j] && t[j]){  // 字符相等时 
			i ++;
			j ++;
		}
		if(!t[j])  // 匹配成功 
			return i - t[0];  // 返回模式串在主串的索引值 
		else{  // 单次匹配失败 
			i = i - j + 2;  // 主串返回到本次匹配开始的下一个字符 
			j = 1;  // 模式串回到开头 
		}
	}
	
	return 0;  // 最终匹配失败
}

int main(){
	scanf("%s %s",s + 1,t + 1);  // 读取字符串 
	
	int num = Func(s,t);
	if(num)  // 匹配成功 
		printf("%d\n",num);
	else  // 匹配失败 
		printf("匹配失败\n"); 
	return 0;
}

