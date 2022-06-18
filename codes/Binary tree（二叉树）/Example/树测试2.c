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
void ExchangeLeftRightSubtree(Node* rootNode);  // 交换左右子树 
void LevelTraversal(Node* rootNode);  // 层次遍历

/*
Input:
2
1 0 2 0 3 0 0 -1
1 2 3 4 0 5 6 0 0 0 0 0 0 -1
Output:
1 2 0 3 0 0 0 
1 3 2 6 5 0 4 0 0 0 0 0 0 
*/

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // 处理n组数据 
		Node* rootNode = TreeCreate();
		ExchangeLeftRightSubtree(rootNode);
		LevelTraversal(rootNode); 
		printf("\n");
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

void ExchangeLeftRightSubtree(Node* rootNode){
	if(rootNode != NULL){  // 非空结点 
		if(rootNode->left || rootNode->right){  // 左右结点不都是空结点 
			Node* temp;  // 交换结点 
			temp = rootNode->left;
			rootNode->left = rootNode->right;
			rootNode->right = temp;
		}
		ExchangeLeftRightSubtree(rootNode->left);
		ExchangeLeftRightSubtree(rootNode->right);
	}
}

void LevelTraversal(Node* rootNode){
	Node* temp;
	
	Node* queue[1000];  // 创建空队列 
	int begin = -1;
	int end = -1;

	queue[++ end] = rootNode;  // 根结点入队 
	
	while(begin != end){  // 队列不为空 
		temp = queue[++ begin];  // 出队 
		printf("%d ",temp->value);
		
		if(temp->value == 0)  // 空结点 
			continue;
		
		if(temp->left)  // 左结点不为空 
			queue[++ end] = temp->left;  // 入队 
		else{
			temp->value = 0;  // 空结点入队 
			queue[++ end] = temp;
		}
		if(temp->right)  // 右结点不为空 
			queue[++ end] = temp->right;  // 入队 
		else{
			temp->value = 0;  // 空结点入队
			queue[++ end] = temp;
		}
		
	}
}

