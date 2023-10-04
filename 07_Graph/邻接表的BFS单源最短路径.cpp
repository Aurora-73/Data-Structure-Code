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

typedef struct {
	int data[MaxSize];
	int top;
} SqStack; // 将结构体名Stack改为SqStack

void InitStack(SqStack& S) {
	S.top = -1;
}

bool IsEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

bool Push(SqStack& S, int x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack& S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
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

void ShortestPath(AGraph *G,int v,int visited[],int d[],int path[]){
	Queue Q;
	InitQueue(Q);
	visited[v] = 1;
	d[v] = 0;
	path[v] = -1;
	EnQueue(Q,v);
	ArcNode *p;
	while(!IsEmpty(Q)){
		DeQueue(Q,v);
		p = G->adjlist[v].firstarc;
		while(p){
			if(!visited[p->adjvex]){
				visited[p->adjvex] = 1;
				d[p->adjvex] = d[v] + 1;
				path[p->adjvex] = v;
				EnQueue(Q,p->adjvex);
			}
			p = p -> nextarc;
		}
	}
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
	std::cout << "源头是哪个顶点？";
	int start;
	std::cin >> start;
	std::cout << "最短距离是\n";
	int *visited = new int[G->vexnum];
	int *d = new int[G->vexnum];
	int *path = new int[G->vexnum];
	for(int i=0;i< G->vexnum;i++){
		visited[i] = 0;
		d[i] = INT_MAX;
		path[i] = -1;
	}
    ShortestPath(G,start,visited,d,path);
	for(int i=0;i< G->vexnum;i++){
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	SqStack S;
	InitStack(S);
	std::cout << "最短路径为" << std::endl;
	for(int i=0;i< G->vexnum;i++){
		int j = path[i];
		while(j != -1){
			Push(S,j);
			j = path[j];
		}
		while(!IsEmpty(S)){
			Pop(S,j);
			std::cout << G->adjlist[j].data << "->" ;
		}
		std::cout << G->adjlist[i].data << std::endl;
	}
	return 0;
}

