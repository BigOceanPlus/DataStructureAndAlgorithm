#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
//#define MAX 100

typedef struct table{  // 线性表结构体 
	int* array;  // 存放数据的数组，索引值从0开始 
	int capacity;  // 线性表最大容量 
	int size;  // 当前元素个数
}Table;

Table Initialization(int capacity);  // 创建线性表 
void Insert(Table* tablep,int index,int element);  // 线性表元素插入 
int Find(Table table,int element);  // 线性表元素查找(根据元素值)
void DelElement(Table* tablep,int element);  // 线性表元素删除(根据元素值)
void DelIndex(Table* tablep,int element);  // 线性表元素删除(根据索引值)
int Length(Table table);  // 求线性表长度 
int Top(Table table);  // 求线性表最后一个元素 
void Print(Table table);  // 顺序输出线性表的元素 

/*
Output: 4 3 2 1 0
*/

int main(void){
    Table table;
    table = Initialization(50);
    
    int i;
    for(i = 0; i < 5; i ++)
    	Insert(&table,0,i);
	
	Print(table);
	printf("\n");

    return 0;
}

Table Initialization(int capacity){
	Table table;
	table.array = (int*)malloc(sizeof(int) * capacity);  // 分配空间 
	table.capacity = capacity;  // 线性表最大容量 
	table.size = 0;  // 线性表初始化为空 
	return table;
}

void Insert(Table* tablep,int index,int element){
	
	if(Length(*tablep) == tablep->capacity){  // 线性表已满 
		printf("Error for full of room\n");
		return;
	}
	
	if(index < 0 || index > Length(*tablep)){  // 索引值错误
		printf("Error for index value\n");
		return;
	}
	
	int i;
	for(i = Length(*tablep); i >= index + 1; i --)  // 从后往前移动元素 
		tablep->array[i] = tablep->array[i - 1];
	
	tablep->array[index] = element;  // 插入元素 
	tablep->size ++;  // 线性表元素个数加一 
}

int Find(Table table,int element){
	int i;
	for(i = 0; i < Length(table); i ++){  // 遍历线性表 
		if(element == table.array[i])  // 查找成功，返回索引值 
			return i;
	}
	
	printf("Error for not find\n");  // 查找失败 
	return ERROR;
}

void DelElement(Table* tablep,int element){
	int i;
	for(i = 0; i < Length(*tablep); i ++){  // 遍历线性表 
		if(element == tablep->array[i]){  // 删除成功 
			tablep->size --;  // 线性表元素个数减一 
			return;
		}
	}
	
	printf("Error for not find\n");  // 删除失败 
}

void DelIndex(Table* tablep,int index){
	if(Length(*tablep) == 0){  // 线性表为空 
		printf("Error for the linear table is empty\n");
		return;
	}
	
	if(index < 0 || index >= Length(*tablep)){  // 索引值错误
		printf("Error for index value\n");
		return;
	}
	
	int i;
	for(i = index; i < Length(*tablep) - 1; i ++)  // 从前往后移动元素 
		tablep->array[i] = tablep->array[i + 1];  // 删除元素 
	
	tablep->size --;  // 线性表元素个数减一
}

int Length(Table table){
	return table.size;  // 返回线性表长度 
}

int Top(Table table){
	if(!Length(table)){  // 线性表为空 
		printf("Error for the linear table is empty\n");
		return ERROR;
	}
	else
		return table.array[table.size - 1];  // 返回元素值 
}

void Print(Table table){
	int i;
	for(i = 0; i < Length(table); i ++)  // 遍历线性表输出 
		printf("%d ",table.array[i]);
}
