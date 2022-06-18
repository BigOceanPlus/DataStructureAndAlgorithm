#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;  // 定义人的结构体 
typedef struct node{
	int code;  // 密码 
	bool exist;  // exist = false时表示人出列 
}Node;
Node array[30];  // 数组的索引值等于人的编号 - 1 

/*
Input:
20 7 3 1 7 2 4 8 4
Output:
6 1 4 7 2 3 5
*/

int main(void){
	int i,n,m;
	scanf("%d %d",&m,&n);  // 初始化m和n 
	
	for(i = 0; i < n; i ++){  // 读取数据 
		scanf("%d",&array[i].code);
		array[i].exist = true;
	}
	
	int scan = 0;
	for(i = 0; i < n; i ++){  // 用数组模拟循环链表 
		
		while(!array[scan].exist)  // 按规则找到本次第一个报数的人
			scan = (scan + 1) % n;
		
		while(-- m){  // 模拟报数
			scan = (scan + 1) % n;
			while(!array[scan].exist)  // 按规则找到下一个队列中的人
				scan = (scan + 1) % n;
		}
		
		array[scan].exist = false;  // 模拟人的出列 
		printf("%d ",scan + 1);  // 输出出列的人的编号 
		m = array[scan].code;
		
	}
	return 0;
}

