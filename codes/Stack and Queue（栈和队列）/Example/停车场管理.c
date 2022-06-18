#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 由于题目没有给收费标准，默认为1时间单位一元，这样的话经过的时间就是对应的停车费，因此调试结果中输出时间差就是对应的停车费

typedef struct car Car;  // 汽车的结构体 
typedef struct car{
	int id;  // 车牌 
	int time;  // 入场时刻
	Car* next;  // 只在便道中有意义，表示后一辆车
}Car; 

int n;  // 停车场大小 

Car parking[200];  // 用栈模拟停车场 
int count1 = -1;  // count = -1表示停车场为空 
Car stack[200];  // stack栈用来临时停放因让路离去的汽车 
int count2 = -1;  // count2 = -1表示stack栈为空 

Car* begin = NULL;  // begin = end = NULL 表示模拟便道的队列 
Car* end = NULL;
int count3 = -1;  // count3 = -1表示便道为空 

void LineEnter(int id,int time);  // 元素进入队列 
Car LineLeave();  // 元素离开队列 

/*
Input:
2
A 4 25
A 5 30
A 1 35
D 2 40
D 1 45
D 4 50
E 0 0
Output:
ID: 4 Parking: 0
ID: 5 Parking: 1
ID: 1 Line: 0
Not find
Not find
ID: 4 Time: 25
ID: 1 Parking: 1
*/

int main(){
	int i,j;
	scanf("%d",&n);   
	getchar();  // 排除\n的干扰 
	
	char ch;
	int id,time;
	bool flag;
	while(true){
		flag = true; // flag = true表示在ch == 'D'的情况找到元素 
		scanf("%c %d %d",&ch,&id,&time);
		getchar();  // 排除\n的干扰
		
		if(ch == 'A'){  // 汽车准备进入
			if(n - 1 > count1){  // 停车场有位置 
				++ count1;
				parking[count1].id = id;
				parking[count1].time = time;
				printf("ID: %d Parking: %d\n",id,count1);
			}
			else{  // 停车场没位置
				LineEnter(id,time);  // 进入便道 
				printf("ID: %d Line: %d\n",id,count3);
			}
		}
		else if(ch == 'D'){  // 汽车准备离开
			while(parking[count1].id != id && count1 >= 0)  // 查到符合ID的汽车 
				stack[++ count2] = parking[count1 --];
				
			if(count1 >= 0){  // 查找成功 
				printf("ID: %d Time: %d\n",id,time - parking[count1].time);
				count1 --;
			}
			else{  // 查找失败
				printf("Not find\n");
				flag = false;
			}
			
			while(count2 >= 0)  // 通过stack恢复原来汽车的先后顺序 
				parking[++ count1] = stack[count2 --];
			
			if(begin && flag){  // 便道不为空且停车场不满 
				parking[++ count1] = LineLeave();  // 汽车离开便道进入停车场
				parking[count1].time = time;  // 更新汽车进入停车场的时间 
				printf("ID: %d Parking: %d\n",parking[count1].id,count1); 
			}
		}
		else
			break;
	}
	return 0;
}

void LineEnter(int id,int time){
	Car* temp = (Car*)malloc(sizeof(Car));  // 汽车进入便道
	temp->next = NULL;
	temp->id = id;
	temp->time = time;
	
	if(!begin)  // 便道为空 
		begin = end = temp;
	else{  // 便道不为空
		end->next = temp;
		end = end->next;
	}
	count3 ++;
}

Car LineLeave(){
	Car temp;  // 汽车离开便道
	temp.id = begin->id;
	temp.time = begin->time;	

	Car* out = begin;
	
	begin = begin->next;  // 后面的汽车前进
    count3 --;

	free(out);
	
	return temp;
}

