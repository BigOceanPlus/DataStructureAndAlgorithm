#include <stdio.h>
#include <string.h>

char string[201];  // 建立数据字符串 
char stack[201];  // 建立栈 
int top = -1;  // top = -1表示栈为空 

/*
Input:
[ ([] []) ]
Output:
匹配 
*/

void Func(int len){
	int i;
	char ch;
	for(i = 0; i < len; i ++){
		ch = string[i];  // 获取新字符时先进行判断 
		if(ch == ' ')  // 排除空格干扰 
			continue;
		else if(top >= 0 && ( (stack[top] == '(' && ch == ')') || (stack[top] == '[' && ch == ']') ) )  // 栈和新字符的左右括号匹配 
			top --;  // 从栈中弹出左括号 
		else if(ch == ']' || ch == ')'){  // 栈和新字符左右括号不匹配或者为单独的右括号 
			printf("此串括号匹配不合法\n");
			return;
		}
		else  // 将右括号入栈 
			stack[++ top] = ch;
		
	}
	printf("匹配\n");  // 匹配成功 
}

int main(){
	gets(string);  // 将输入数据转为字符串 
	int len = strlen(string);  // 获取数据字符串的长度 
	
	Func(len);  // 判断括号匹配的函数 
	return 0;
}

