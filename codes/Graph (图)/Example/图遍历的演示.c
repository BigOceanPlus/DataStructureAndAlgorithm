#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arc Arc;  // 邻接表中边的结构
typedef struct arc{
    int id;  // 结点名称(结果为图中对应索引 + 1)
    Arc* next;  // 对应结点的下一个邻居
}Arc;

typedef struct node Node;  // 结点的结构
typedef struct node{
    int id;  // 结点名称(结果为图中对应索引 + 1)
    Arc* first;  // 该结点的第一个邻居
}Node;

typedef struct graph Graph;  // 图的结构(用邻接表表示)
typedef struct graph{
    int edge;  // 边的数量
    int point;  // 结点的数量
    Node array[30];  // 结点的具体数据
}Graph;

bool visit[30] = {0};  // 表示在DFS和BFS中图相应的结点是否被访问

Graph DirectedGraphCreate();  // 有向图的创建
Graph UndirectedGraphCreate();  // 无向图的创建
void DFS(Graph g,int index);  // 深度优先搜索(递归)
void BFS(Graph g,int index);  // 广度优先搜索(递归)
void DFSNoRecursion(Graph g,int index);  // 深度优先搜索(非递归)

/*
5 4
0 1 0 2 0 3 1 2 2 3
7 8
0 1 1 2 1 3 2 4 5 3 0 6 7 6
10 9
0 1 1 2 1 4 2 3 3 0 4 5 5 6 6 7 7 8 8 5
*/

int main(){
    Graph g1 = UndirectedGraphCreate();  // 无向图的初始化

    memset(visit,0,sizeof(visit));  // 深度优先
    printf("无向图DFS:");
    DFSNoRecursion(g1,0);
    printf("\n");

    memset(visit,0,sizeof(visit));  // 广度优先
    printf("无向图BFS:");
    BFS(g1,0);
    printf("\n");

    Graph g2 = DirectedGraphCreate();  // 有向图的初始化

    memset(visit,0,sizeof(visit));  // 深度优先
    printf("有向图DFS:");
    DFSNoRecursion(g2,0);
    printf("\n");

    return 0;
}

Graph UndirectedGraphCreate(){
    Graph g;
    int i,j,k;
    scanf("%d %d",&g.edge,&g.point);  // 读取边和结点数

    for(i = 0; i < g.point; i ++){  // 初始化图的结点
        g.array[i].id = i + 1;
        g.array[i].first = NULL;
    }

    for(k = 0; k < g.edge; k ++){  // 读取图的边的数据

        scanf("%d %d",&i,&j);  // 读取相应的两个结点

        Arc* scan1;
        Arc* scan2;
        Arc* temp;

        // 由于图为无向图,所以一次需创建两条边,且邻接表中按结点id的大小进行升序排序

        temp = (Arc*)malloc(sizeof(Arc));
        temp->id = j + 1;
        for(scan1 = NULL, scan2 = g.array[i].first;\
            scan2 && temp->id > scan2->id; scan1 = scan2, scan2 = scan2->next);
        temp->next = scan2;
        if(scan1)  // 结点不是第一个邻居
            scan1->next = temp;
        else  // 结点是第一个邻居
            g.array[i].first = temp;


        temp = (Arc*)malloc(sizeof(Arc));
        temp->id = i + 1;
        for(scan1 = NULL, scan2 = g.array[j].first;\
            scan2 && temp->id > scan2->id; scan1 = scan2, scan2 = scan2->next);
        temp->next = scan2;
        if(scan1)  // 结点不是第一个邻居
            scan1->next = temp;
        else  // 结点是第一个邻居
            g.array[j].first = temp;

    }

    return g;
}

Graph DirectedGraphCreate(){
    Graph g;
    int i,j,k;
    scanf("%d %d",&g.edge,&g.point);  // 读取边和结点数

    for(i = 0; i < g.point; i ++){  // 初始化图的结点
        g.array[i].id = i + 1;
        g.array[i].first = NULL;
    }

    for(k = 0; k < g.edge; k ++){  // 读取图的边的数据

        scanf("%d %d",&i,&j);  // 读取相应的两个结点

        Arc* scan1;
        Arc* scan2;
        Arc* temp;

        // 由于图为有向图,所以一次只需创建一条边,且邻接表中按结点id的大小进行升序排序

        temp = (Arc*)malloc(sizeof(Arc));
        temp->id = j + 1;
        for(scan1 = NULL, scan2 = g.array[i].first;\
            scan2 && temp->id > scan2->id; scan1 = scan2, scan2 = scan2->next);
        temp->next = scan2;
        if(scan1)  // 结点不是第一个邻居
            scan1->next = temp;
        else  // 结点是第一个邻居
            g.array[i].first = temp;
    }

    return g;
}

void DFS(Graph g,int index){
    if(!visit[index]){
        // 结点被访问
        visit[index] = true;
        printf("%d ",g.array[index].id);

        for(Arc* scan = g.array[index].first; scan; scan = scan->next){  // 遍历结点的邻居
            if(!visit[scan->id - 1])  // 邻居未被访问
                DFS(g,scan->id - 1);  // 递归调用
        }
    }
}

void DFSNoRecursion(Graph g,int index){
    // 创建空栈
    Node stack[30];
    int top = -1;

    // 第一个结点入栈
    printf("%d ",g.array[index].id);
    stack[++ top] = g.array[index];
    visit[index] = true;

    while(top != -1){  // 栈不为空
        Node temp = stack[top --];  // 结点出栈
        for(Arc* scan = temp.first; scan; scan = scan->next){  // 遍历结点的邻居
            if(!visit[scan->id - 1]){  // 该结点有邻居未被访问
                // 该结点和邻居入栈
                stack[++ top] = temp;
                stack[++ top] = g.array[scan->id - 1];

                // 标记邻居已被访问
                printf("%d ",scan->id);
                visit[scan->id - 1] = true;

                break;  // 退出循环
            }
        }
    }
}

void BFS(Graph g,int index){
    // 创建空队列
    Node queue[30];
    int begin,end;
    begin = end = -1;

    // 第一个结点入队
    queue[++ end] = g.array[index];
    visit[index] = true; 

    while(begin != end){
        // 结点出队
        Node temp = queue[++ begin];
        printf("%d ",temp.id);

        for(Arc* scan = g.array[temp.id - 1].first; scan; scan = scan->next){  // 遍历结点的邻居
            if(!visit[scan->id - 1]){  // 邻居未被访问
                // 邻居入队
                queue[++ end] = g.array[scan->id - 1];  
                visit[scan->id - 1] = true;
            }
        }
    }
}