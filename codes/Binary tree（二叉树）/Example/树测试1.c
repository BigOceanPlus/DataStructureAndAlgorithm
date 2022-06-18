#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // 树节点的结构体 
typedef struct node{
	Node* left;
	Node* right;
	int value;
}Node; 

int count;
Node* TreeCreate();  // 创建树（层次）
void CountLeafNode(Node* rootNode);  // 计算树的叶结点

/*
Input:
3
1 2 3 0 0 0 0 -1
1 0 2 0 3 4 0 0 0 -1
1 2 3 4 5 6 7 0 0 8 9 10 11 12 13 0 0 0 0 0 0 0 0 0 0 0 0 -1
Output:
2
1
7
*/ 

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // 处理n组数据 
		Node* rootNode = TreeCreate();
		count = 0;  // count清0，重新计数 
		CountLeafNode(rootNode);
		printf("%d\n",count);
	}
	
	return 0;
}

Node* TreeCreate(){
	Node* rootNode;  // 根节点 
	Node* temp;
	
	Node* queue[1000];  // 创建空队列 
	int begin = -1;
	int end = -1;

	int num;
	scanf("%d",&num);
	if(num == 0)  // 空结点 
		return NULL;
	else{  // 非空结点 
		rootNode = (Node*)malloc(sizeof(Node));
		rootNode->value = num;
		queue[++ end] = rootNode;
	}
	
	while(begin != end){  // 队列不为空 
		temp = queue[++ begin];  // 出队 
		
		scanf("%d",&num);  // 左孩子结点处理
		if(num == 0)   
			temp->left = NULL;
		else{
			temp->left = (Node*)malloc(sizeof(Node));
			temp->left->value = num;
			queue[++ end] = temp->left;  // 入队 
		}
		
		scanf("%d",&num);  // 右孩子结点处理
		if(num == 0)  
			temp->right = NULL;
		else{
			temp->right = (Node*)malloc(sizeof(Node));
			temp->right->value = num;
			queue[++ end] = temp->right;  // 入队 
		}
	}
	
	scanf("%d",&num);  // 处理多余的-1 
	return rootNode;
}

void CountLeafNode(Node* rootNode){
	if(rootNode != NULL){  // 非空结点 
		if(rootNode->left == NULL && rootNode->right == NULL)  // 结点为叶结点 
			count ++;
		CountLeafNode(rootNode->left);
		CountLeafNode(rootNode->right);
	}
}

