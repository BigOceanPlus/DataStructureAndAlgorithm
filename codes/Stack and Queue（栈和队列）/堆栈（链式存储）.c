#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define ERROR -1 

typedef struct node{  // 结点的结构体 
	int value;  // 结点值 
	struct node* next;  // 指向下一个结点的指针 
}Node;

Node* StackCreate();  // 创建一个空栈 
int Pop(Node* head);  // 弹出栈顶元素 
void Push(Node* head,int value);  // 往栈顶压入元素 
bool IsEmpty(Node* head);  // 判断栈顶是否为空 

/*
Output: 15 25 10
*/

int main(void){
	int i;
	Node* head = StackCreate();
	
	Push(head,10);
	Push(head,25); 
	Push(head,15);
	
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	printf("%d ",Pop(head));
	
	return 0;
}

Node* StackCreate(){
	Node* head;  // 头结点，头结点不存放数值，指针始终指向栈顶元素
	
	head = (Node *)malloc(sizeof(Node));  // 初始化 
	head->next = NULL;
	
	return head;
}

void Push(Node* head,int value){
	Node* temp;
	temp = (Node *)malloc(sizeof(Node));  // 分配新结点 
	temp->value = value;
	
	temp->next = head->next;  // 压入元素 
	head->next = temp;
}

int Pop(Node* head){
	if(IsEmpty(head)){  // 栈为空 
		printf("Stack is empty\n");
		return ERROR;
	}
	else{
		Node* temp = head->next;  // 保存删除结点的地址 
		head->next = temp->next;  // 移动头结点指针 
		
		int value = temp->value;
		
		free(temp);  // 释放内存 
		
		return value;  // 返回栈顶元素的数值 
	}
}

bool IsEmpty(Node* head){
	return (head->next == NULL);
}

