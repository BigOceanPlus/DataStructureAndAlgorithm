#include <stdio.h>

char string[120];  // 存放表达式的数组 
char stack[5];  // 创建栈 
int prior[50];  // 用运算符的ASCII来表示优先级 

int main(){
	prior[43] = prior[45] = 1;  // +，-的优先级 
	prior[42] = prior[47] = 2;  // /，*的优先级 
	int n,m,i,j;
	int count = -1;  // 初始化栈为空 
	char ch;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // 处理n组表达式 
		scanf("%d",&m);  // 读取表达式长度 
		scanf("%s",string);  // 读取表达式 
		
		for(j = 0; j < m; j ++){
			if('A' <= string[j] && string[j] <= 'Z')  // 大写字母直接输出 
				printf("%c",string[j]);
			else{  // 运算符需先判断 
				ch = string[j];  // 保存本次运算符 
				while(count >= 0 && prior[ch] <= prior[stack[count]])  // 如果本次运算符不是优先级最高的 
					printf("%c",stack[count --]);  // 先从栈顶中弹出运算符以满足条件 
				stack[++ count] = ch;  // 否则运算符直接入栈 
			}
			
		}
		
		while(count >= 0)  // 输出栈中的所有内容 
			printf("%c",stack[count --]);
		printf("\n");
		
	}
	
	return 0;
}
