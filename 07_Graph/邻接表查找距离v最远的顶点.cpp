#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

#define MaxSize 100

// 邻接表的边结构体
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
} ArcNode;

// 邻接表的顶点结构体
typedef struct VNode {
	char data;
	ArcNode* firstarc;
} VNode;

// 邻接表
typedef struct AGraph {
	VNode adjlist[MaxSize];
	int vexnum, arcnum;
} AGraph;


// 队列结构体
typedef struct Queue {
	int data[MaxSize];
	int front, rear;
} Queue;

// 初始化队列
void InitQueue(Queue &Q) {
	Q.front = Q.rear = 0;
}

// 判断队列是否为空
bool IsEmpty(Queue &Q) {
	return Q.front == Q.rear;
}

// 入队列
void EnQueue(Queue &Q, int x) {
	Q.data[Q.rear++] = x;
}

// 出队列
void DeQueue(Queue &Q, int &x) {
	x = Q.data[Q.front++];
}

// 创建图的函数
void CreateAGraph(AGraph*& G) {
	G = (AGraph*)malloc(sizeof(AGraph));
	if (!G) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	
	printf("请输入顶点个数：");
	scanf("%d", &G->vexnum);
	G->arcnum = 0; // 初始化边数为0
	
	// 输入顶点信息
	printf("请输入每个结点的data（字符个数应为顶点个数）：\n");
	for (int i = 0; i < G->vexnum; i++) {
		scanf(" %c", &G->adjlist[i].data); // 注意空格用于吸收换行符
		G->adjlist[i].firstarc = NULL; // 初始化每个顶点的邻接表为空
	}
	
	// 输入边信息
	printf("请输入每个结点的相邻结点的adjlist下标，以-1结束每个结点的输入：\n");
	for (int i = 0; i < G->vexnum; i++) {
		int adjindex;
		ArcNode* tail = NULL;
		
		printf("正在输入 %c 的相邻结点：\n", G->adjlist[i].data);
		while (1) {
			scanf("%d", &adjindex);
			if (adjindex == -1)
				break;
			
			// 创建新的边节点
			ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
			if (!newNode) {
				printf("Memory allocation failed.\n");
				exit(1);
			}
			newNode->adjvex = adjindex;
			newNode->nextarc = NULL;
			
			// 将新节点插入到邻接表中
			if (G->adjlist[i].firstarc == NULL) {
				G->adjlist[i].firstarc = newNode;
			} else {
				tail->nextarc = newNode;
			}
			tail = newNode;
			
			G->arcnum++; // 每添加一条边，边数加1
		}
	}
}

int FindFarthest(AGraph *G,int v,int visited[]){
	Queue Q;
	InitQueue(Q);	
	visited[v] = 1;
	EnQueue(Q,v);
	ArcNode *p;
	while(!IsEmpty(Q)){
		DeQueue(Q,v);
		p = G->adjlist[v].firstarc;
		while(p){
			if(!visited[p->adjvex]){
				visited[p->adjvex] = 1;
				EnQueue(Q,p->adjvex);
			}
			p = p -> nextarc;
		}
	}
	return v;//广度优先遍历中最后一个被访问的点就是距离最远的点，也是最后一个出队的点
}


int main() {
	AGraph* G;
	CreateAGraph(G);
	// 打印邻接表内容（仅用于测试）
	printf("邻接表存储的图内容如下：\n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("%c -> ", G->adjlist[i].data);
		ArcNode* p = G->adjlist[i].firstarc;
		while (p) {
			printf("%c -> ", G->adjlist[p->adjvex].data);
			p = p->nextarc;
		}
		printf("NULL\n");
	}
	std::cout << "查找距离哪个顶点最远的点: " << std::endl;
	int v;
	std::cin >> v;
	int *visited = new int[G->vexnum];
	for(int i=0;i< G->vexnum;i++)
		visited[i] = 0;
	int i = FindFarthest(G,v,visited);
	std::cout << "距离它最远的点是: " << G->adjlist[i].data << std::endl;
	return 0;
}

