#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;  
typedef struct node{  // 结点的结构体
    int value;  // 结点值
    Node* left;  // 左结点
    Node* right;  // 右结点
}Node;

int length;  // 查找长度

Node* Insert(Node* node,int value);  // 二叉查找树结点插入
Node* Delete(Node* node,int value);  // 二叉查找树结点删除
Node* Find(Node* rootNode,int value);   // 二叉查找树结点查找
Node* FindMin(Node* rootNode);  // 查找树的最小结点
void PreorderTraversal(Node* rootNode);  // 前序遍历
void PrintTreeGroup(Node* node,int deep);  // 打印凹入表

/*
  Input: 10 5 15 3 7 12 18 -1
*/

int main(int argc, char const *argv[]){
    Node* rootNode = NULL;  // 创建空的根节点

    {
        int num;
        while(scanf("%d",&num) && num != -1) rootNode = Insert(rootNode,num);  // 创建二叉查找树
    }

    // 结点查找
    if(Find(rootNode,7))
        printf("Find success, the find length is %d\n",length);
    else
        printf("Find faliure, the find length is %d\n",length);
    if(Find(rootNode,20))
        printf("Find success, the find length is %d\n",length);
    else
        printf("Find faliure, the find length is %d\n",length);

    // 遍历
    printf("Traversal: ");
    PreorderTraversal(rootNode);
    printf("\n");
    
    // 格式化输出
    PrintTreeGroup(rootNode,1);

    return 0;
}

Node* Insert(Node* node,int value){
    if(!node){  // 创建新结点
        node = (Node*)malloc(sizeof(Node));
        node->left = node->right = NULL;
        node->value = value;
    }
    else if(value > node->value)  // 结点值比根节点的值大
        node->right = Insert(node->right,value);
    else if(value < node->value)  // 结点值比根节点的值小
        node->left = Insert(node->left,value);
    return node;
}

Node* Find(Node* rootNode,int value){
    Node* scan = rootNode;
    length = 1;  // 查找长度
    while(scan){
        if(value == scan->value)  // 查找成功
            return scan;
        else if(value < scan->value)  // 结点值比根节点的值小
            scan = scan->left;
        else  // 结点值比根节点的值大
            scan = scan->right;
        length ++;
    }
    return NULL;  // 查找失败
}

Node* FindMin(Node* rootNode){
    Node* scan = rootNode;
    while(scan->left)
        scan = scan->left;
    return scan;
}

Node* Delete(Node* node,int value){
    if(value > node->value)  // 结点值比根节点的值小
        node->right = Delete(node->right,value);
    else if(value < node->value)  // 结点值比根节点的值大
        node->left = Delete(node->left,value);
    else{
        if(node->right && node->left){  // 删除的结点有2个结点
            Node* minNode = FindMin(node->right);
            node->value = minNode->value;
            node->right = Delete(node->right,minNode->value);
        }
        else{
            Node* temp = node;
            if(node->right)  // 删除的结点只有右结点
                node = node->right;
            else  // 删除的结点只有左结点或没有子结点
                node = node->left;
            free(temp);
        }
    }
    return node;
}

void PreorderTraversal(Node* rootNode){
    if(rootNode){
        printf("%d ",rootNode->value);
        PreorderTraversal(rootNode->left);
        PreorderTraversal(rootNode->right);
    }
}

void PrintTreeGroup(Node* node,int deep){
    if(node != NULL){  // RDL遍历方法
		PrintTreeGroup(node->right,deep + 1);
		
		int i;
		for(i = 1; i < deep; i ++)  // 格式化输出 
			printf("\t");
		printf("%d\n",node->value);
		
		PrintTreeGroup(node->left,deep + 1);
	}
}