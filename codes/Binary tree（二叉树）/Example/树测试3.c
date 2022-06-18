#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

typedef struct node Node;  // 树节点的结构体 
typedef struct node{
	Node* left;
	bool isLeftThread;
	Node* right;
	bool isRightThread;
	int value;
}Node; 

Node* currentNode;  // 在中序线索化二叉树过程中表示当前结点 

Node* TreeCreate();  // 创建树(层次)
void InorderInthreadTree(Node* node);  // 中序线索化二叉树 
Node* PrecursorNode(Node* node);  // 求前驱结点 
Node* ReardriveNode(Node* node);  // 求后驱结点 
void LevelTraversal(Node* rootNode);  // 层次遍历结点的前驱结点和后驱结点 

/*
Input:
3
1 0 0  -1
1 2 3 0 0 0 0  -1
1 2 3 4 0 0 5 6 7 8 9 0 0 0 0 0 0 0 0  -1
Output:
0 0
2 3 0 1 1 0
2 3 7 1 1 8 6 7 8 9 0 4 4 2 3 5 5 0
*/

int main(){
	int i,n;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // 处理n组数据 
		currentNode = NULL; 
		Node* rootNode = TreeCreate();
		
		InorderInthreadTree(rootNode);  // 线索化 
		
		if(currentNode){  // 最后一个结点的后续结点为空 
			currentNode->isRightThread = true;
			currentNode->right = NULL;
		}
		
		LevelTraversal(rootNode);  // 遍历 
		printf("\n");
	}
	
	return 0;
}

Node* TreeCreate(){
	Node* rootNode;  // 根节点 
	Node* temp;
	
	Node* queue[1000];  // 创建空队列 
	int begin,end;

	begin = end = -1;
	int num;
	scanf("%d",&num);
	if(num == 0)  // 空结点 
		return NULL;
	else{  // 非空结点 
		rootNode = (Node*)malloc(sizeof(Node));
		rootNode->value = num;
		rootNode->isLeftThread = rootNode->isRightThread = false;
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
			temp->left->isLeftThread = temp->left->isRightThread = false;
			
			queue[++ end] = temp->left;  // 入队 
		}
		
		scanf("%d",&num);  // 右孩子结点处理
		if(num == 0)  
			temp->right = NULL;
		else{
			temp->right = (Node*)malloc(sizeof(Node));
			temp->right->value = num;
			temp->right->isLeftThread = temp->right->isRightThread = false;
			
			queue[++ end] = temp->right;  // 入队 
		}
	}
	
	scanf("%d",&num);  // 处理多余的-1 
	return rootNode;
}

void InorderInthreadTree(Node* node){
	if(node){
		InorderInthreadTree(node->left);
		
		if(!node->left){  // 添加前驱结点 
			node->isLeftThread = true;
			node->left = currentNode; 
		}
		if(currentNode && !currentNode->right){  // 添加后驱结点 
			currentNode->isRightThread = true;
			currentNode->right = node;
		}
		currentNode = node;  // 更新结点 
		
		InorderInthreadTree(node->right);
	}
}

Node* PrecursorNode(Node* node){
	if(!node)
		return NULL;
	
	if(node->isLeftThread)  // 有左线索 
		return node->left;
		
	Node* temp = node->left;  // 左子树的最右结点 
	while(!temp->isRightThread)  
		temp = temp->right;
		
	return temp;
}

Node* ReardriveNode(Node* node){
	if(!node)
		return NULL;
	
	if(node->isRightThread)  // 有右线索 
		return node->right;
		
	Node* temp = node->right;  // 右子树的最左结点
	while(!temp->isLeftThread)
		temp = temp->left;
		
	return temp;
}

void LevelTraversal(Node* rootNode){
	Node* temp;
	
	Node* queue[1000];  // 创建空队列 
	int begin = -1;
	int end = -1;

	queue[++ end] = rootNode;  // 根结点入队 
	
	while(begin != end){  // 队列不为空 
		temp = queue[++ begin];  // 出队 
		printf("%d ",PrecursorNode(temp) ? PrecursorNode(temp)->value : 0);  // 输出前驱结点 
		printf("%d ",ReardriveNode(temp) ? ReardriveNode(temp)->value : 0);  // 输出后驱结点 
		
		if(!temp->isLeftThread)  // 左结点不为空 
			queue[++ end] = temp->left;  // 入队 
		if(!temp->isRightThread)  // 右结点不为空 
			queue[++ end] = temp->right;  // 入队 
		
	}
}
