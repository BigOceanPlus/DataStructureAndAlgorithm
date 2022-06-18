#include <stdio.h>
#include <stdbool.h>
#define MAX 100  // 堆栈最大容量 
#define ERROR -1

typedef struct stack{  // 堆栈的结构体 
	int array[MAX];  // 存放数值的数组（索引值从0开始） 
	int top;  // 栈顶元素的索引值 
}Stack;

Stack StackCreate();  // 创建一个空栈 
void Push(Stack* sp,int value);  // 弹出栈顶元素 
int Pop(Stack* sp);  // 往栈顶压入元素
bool IsEmpty(Stack* sp);  // 判断栈顶是否为空 
bool IsFull(Stack* sp);  // 判断栈顶是否为满

/*
Output: 15 25 10
*/

int main(void){
    Stack s = StackCreate();
	
    Push(&s,10);
	Push(&s,25); 
	Push(&s,15);
	
	printf("%d ",Pop(&s));
	printf("%d ",Pop(&s));
	printf("%d ",Pop(&s));

	return 0;
} 

Stack StackCreate(){
    Stack s;  // 创建空堆栈
	s.top = -1;

    return s;
}

void Push(Stack* sp,int value){
	if(IsFull(sp)){  // 栈为满
		printf("Stack is full\n");
		return;
	}
	else
		sp->array[++ sp->top] = value;  // 压入元素
	
}

int Pop(Stack* sp){
	if(IsEmpty(sp)){  // 栈为空
		printf("Stack is empty\n");
		return -1;
	}
	else
		return sp->array[sp->top --];  // 弹出元素
} 

bool IsEmpty(Stack* sp){
	return (sp->top == -1);
}

bool IsFull(Stack* sp){
	return (sp->top + 1 == MAX);
}