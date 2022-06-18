#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{  // 结点的结构体 
	int value;  // 结点值 
	struct node* next;  // 指向下一个结点的指针 
}Node;

typedef struct queue{  // 队列的结构体 
	Node* begin;  // 指向队尾的指针 
	Node* end;  // 指向队头的指针
}Queue;

Queue QueueCreate();  // 创建一个空队列 
void EnQueue(Queue* q,int value);  // 元素入队 
int DeQueue(Queue* q);  // 元素出队 
bool IsEmpty(Queue* q);  // 判断队列是否为空 
 
/*
Output: 0 1 2 3 4 
*/

int main(void){
	Queue q = QueueCreate();
	
	int i;
	for(i = 0; i < 5; i ++)
		EnQueue(&q,i);
	
	for(i = 0; i < 5; i ++)
		printf("%d ",DeQueue(&q));
	return 0;
}

Queue QueueCreate(){
	Queue q;  // 初始化队列为空 
	q.begin = q.end = NULL;
	
	return q;
}

void EnQueue(Queue* q,int value){
	Node* temp;  // 创建新结点 
	temp = (Node*)malloc(sizeof(Node));  // 分配空间 
	temp->next = NULL;  // 初始化 
	temp->value = value;
	
	if(IsEmpty(q))  // 队列为空 
		q->begin = q->end = temp;
	else{  // 队列不为空 
		q->end->next = temp;  // 后接新结点 
		q->end = q->end->next;  // 移动队头end指针 
	}
}

int DeQueue(Queue* q){
	if(IsEmpty(q)){  // 队列为空 
		printf("Error for empty\n");
		exit(1);
	}
	else{
		Node* temp = q->begin;  // 保存删除结点的地址 
		
		q->begin = q->begin->next;  // 移动队尾begin指针 
		int value = temp->value;
		
		free(temp);  // 释放内存 
		
		return value;
	}
}

bool IsEmpty(Queue* q){
	return (q->begin == NULL);
}
