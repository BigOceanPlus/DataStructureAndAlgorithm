#include <stdio.h>
#include <stdbool.h>
#define MAX 50  // 队列的最大容量
#define ERROR -1

typedef struct queue{  // 队列的结构体（用循环队列表示）
	int array[MAX];  // 存放数值的数组（索引值从0开始）
	int begin;  // 队尾的索引值
	int end;  // 队头的索引值
}Queue;

Queue QueueCreate();  // 创建一个空队列
bool IsEmpty(Queue* q);  // 判断队列是否为空 
bool IsFull(Queue* q);  // 判断队列是否为满
void EnQueue(Queue* q,int value);  // 元素入队 
int DeQueue(Queue* q);  // 元素出队 

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
	q.begin = q.end = -1;

    return q;
}

void EnQueue(Queue* q,int value){
	if(IsFull(q)){  // 队列为满
		printf("Error for full\n");
		return;
	}
	else{
		q->end = (q->end + 1) % MAX;  // 元素入队
		q->array[q->end] = value;
	}
}

int DeQueue(Queue* q){
	if(IsEmpty(q)){  // 队列为空
		printf("Error\n");
		return ERROR;
	}
	else{
		q->begin = (q->begin + 1) % MAX;  // 元素出队
		return q->array[q->begin];
	}
}

bool IsEmpty(Queue* q){
	return (q->begin == q->end);
}

bool IsFull(Queue* q){
	return (q->end + 1) % MAX == q->begin;
}
