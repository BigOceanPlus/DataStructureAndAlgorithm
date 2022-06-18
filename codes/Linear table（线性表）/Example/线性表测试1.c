#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;  // 定义节点的结构体 
typedef struct node{
	int val;
	Node* next;
}Node;
// 链表为带头结点的链表

void Add(Node* head,int val);  // 链表的插入 
void ListReverse(Node* head);  // 反转链表 
void Print(Node* head);  // 链表遍历输出 
void ListMerge(Node* ahead,Node* bhead,Node* chead);  // 两个链表归并为一个链表 

/*
Input:
2
5 5
1 2 3 4 5
1 2 3 4 5
3 3
2 4 8
3 6 9
Output:
5 5 4 4 3 3 2 2 1 1
9 8 6 4 3 2
*/

int main(void){
	int n,i,j,val;
    int len1,len2;  // 链表A,B的长度

	scanf("%d",&n);
	Node ahead,bhead,chead;  // 定义链表A,B,C的头结点 
	
	for(i = 0; i < n; i ++){
		
		//  初始化 
		ahead.next = NULL;
		bhead.next = NULL;
		chead.next = NULL;
		scanf("%d %d",&len1,&len2);
		
		for(j = 0; j < len1; j ++){  // 创建A链表
			scanf("%d",&val);
			Add(&ahead,val);
		}
		
		for(j = 0; j < len2; j ++){  // 创建B链表
			scanf("%d",&val);
			Add(&bhead,val);
		}
		
		// 反转A，B链表，使得他们按递减有序排列
		ListReverse(&ahead);
		ListReverse(&bhead);
		
		// 归并A，B链表，归并后的链表C按递减有序排列
		ListMerge(&ahead,&bhead,&chead);
		
		Print(&chead);
		
		//  释放内存，接受下一轮的输入 
		Node* scan = chead.next;
		while(scan){
			Node* temp = scan;
			scan = scan->next;
			free(temp);
		}
		
	}
	return 0;
}

void Add(Node* head,int val){
	Node* scan = head;
	while(scan->next)
		scan = scan->next;
		
	Node* node = (Node*)malloc(sizeof(Node));  // 建立新节点 
	node->next = NULL;
	node->val = val;
	
	scan->next = node;  // 将节点插入链表 
}

void ListReverse(Node* head){  // 反转链表至少需3个临时节点来存放 
	Node* a = head;
	Node* b = head->next;
	Node* c = head->next->next;
	
	b->next = NULL;  // 反转链表的最后一个结点next指针设为NULL

	while(c){
		a = b;
		b = c;
		c = c->next;
		b->next = a;  // 构建新的next指针
	}
	
	head->next = b;  // 头结点指向反转链表的第一个结点
}

void Print(Node* head){  // 遍历链表 
	Node* scan = head->next;

	while(scan){
		printf("%d ",scan->val);
		scan = scan->next;
	}
    
	printf("\n");
}

void ListMerge(Node* ahead,Node* bhead,Node* chead){
	Node* scan1 = ahead->next;
	Node* scan2 = bhead->next;
	Node* scan = chead;
		
	while(scan1 && scan2){  // A,B链表都没有归并完
			
		if(scan1->val >= scan2->val){
			scan->next = scan1;
			scan1 = scan1->next;
			scan = scan->next;
		}
		else{
			scan->next = scan2;
			scan2 = scan2->next;
			scan = scan->next;
		}
	}
		
	while(scan1){  // B链表已全部归并到C链表 
		scan->next = scan1;
		scan1 = scan1->next;
		scan = scan->next;
	}
	while(scan2){  // A链表已全部归并到C链表 
		scan->next = scan2;
		scan2 = scan2->next;
		scan = scan->next;
	}
}
