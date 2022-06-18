#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;  // 定义节点的结构体 
typedef struct node{
	int val;
	Node* next;
}Node;
// 链表为带头结点的链表

void Add(Node* head,int val);  // 链表的插入 
void Print(Node* head);  // 链表遍历输出 
void ListMerge(Node* ahead,Node* bhead,Node* chead);  // 两个链表归并为一个链表 

/*
Input:
2
3 4
1 2 3
1 2 3 4
5 2
1 1 1 1 1
2 2
Output:
1 1 2 2 3 3 4
1 2 1 2 1 1 1
*/

int main(void){
	int n,i,j,val;
    int len1,len2;  // 定义链表A,B的长度
	scanf("%d",&n);
	Node ahead,bhead,chead;  // 定义链表A,B,C的头结点 
	
	for(i = 0; i < n; i ++){
	
		//  初始化 
		ahead.next = NULL;
		bhead.next = NULL;
		chead.next = NULL;
		scanf("%d %d",&len1,&len2);
		
		for(j = 0; j < len1; j ++){
			scanf("%d",&val);
			Add(&ahead,val);
		}
		
		for(j = 0; j < len2; j ++){
			scanf("%d",&val);
			Add(&bhead,val);
		}
		
		// 归并A，B链表
		ListMerge(&ahead,&bhead,&chead);
		
		Print(&chead);
		
		//  释放内存，接受下一轮的输入 
		Node* scan = chead.next;
		while(scan){
			Node* temp = scan;
			scan = scan->next;
			free(temp);
			temp = NULL;
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
		
	while(scan1 && scan2){  //   A，B链表都未全部归并时，C链表轮流接受A，B链表的元素
			
		scan->next = scan1;
		scan1 = scan1->next;
		scan = scan->next;

		scan->next = scan2;
		scan2 = scan2->next;
		scan = scan->next;
		
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
