#include <iostream>
#include <cstdlib>

#define MaxSize 100

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack; // 将结构体名Stack改为SqStack

void InitStack(SqStack& S) {
	S.top = -1;
}

bool IsEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

struct ArcNode {
	int adjvex;
	ArcNode* nextarc;
};

struct VNode {
	char data;
	ArcNode* firstarc;
};

struct AGraph {
	VNode adjlist[MaxSize];
	int vexnum, arcnum;
};

void CreateAGraph(AGraph*& G) {
	G = (AGraph*)malloc(sizeof(AGraph));
	if (!G) {
		std::cerr << "Memory allocation failed." << std::endl;
		exit(1);
	}
	
	std::cout << "请输入顶点个数：";
	std::cin >> G->vexnum;
	G->arcnum = 0;
	
	std::cout << "请输入每个结点的data（字符个数应为顶点个数）：" << std::endl;
	for (int i = 0; i < G->vexnum; i++) {
		std::cin >> G->adjlist[i].data;
		G->adjlist[i].firstarc = NULL;
	}
	
	std::cout << "请输入每个结点的相邻结点的adjlist下标，以-1结束每个结点的输入：" << std::endl;
	for (int i = 0; i < G->vexnum; i++) {
		int adjindex;
		ArcNode* tail = NULL;
		
		std::cout << "正在输入 " << G->adjlist[i].data << " 的相邻结点：" << std::endl;
		while (1) {
			std::cin >> adjindex;
			if (adjindex == -1)
				break;
			
			ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
			if (!newNode) {
				std::cerr << "Memory allocation failed." << std::endl;
				exit(1);
			}
			newNode->adjvex = adjindex;
			newNode->nextarc = NULL;
			
			if (G->adjlist[i].firstarc == NULL) {
				G->adjlist[i].firstarc = newNode;
			}
			else {
				tail->nextarc = newNode;
			}
			tail = newNode;
			
			G->arcnum++;
		}
	}
}

void DFS(AGraph* G, int v, int visited[]) {
	SqStack S;
	InitStack(S);
	std::cout << G->adjlist[v].data;
	visited[v] = 1;
	Push(S,v);
	ArcNode* p ;
	while (!IsEmpty(S)) {
		GetTop(S,v);
		p = G->adjlist[v].firstarc;
		while(p && visited[p->adjvex])
			p = p->nextarc;
		if(p){
			std::cout << G->adjlist[p->adjvex].data;
			visited[p->adjvex] = 1;
			Push(S,p->adjvex);
		}else{
			Pop(S,v);
		}
	}
}

void DFSAll(AGraph* G, int v) {
	int* visited = new int[G->vexnum];
	for (int i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	DFS(G, v, visited);
	for (int i = 0; i < G->vexnum; i++)
		if (!visited[i])
			DFS(G, i, visited);
	delete[] visited;
}

int main() {
	AGraph* G;
	CreateAGraph(G);
	
	std::cout << "邻接表存储的图内容如下：" << std::endl;
	for (int i = 0; i < G->vexnum; i++) {
		std::cout << G->adjlist[i].data << " -> ";
		ArcNode* p = G->adjlist[i].firstarc;
		while (p) {
			std::cout << G->adjlist[p->adjvex].data << " -> ";
			p = p->nextarc;
		}
		std::cout << "NULL" << std::endl;
	}
	
	std::cout << "从哪个顶点开始深度优先遍历（输入对应的下标）: ";
	int start;
	std::cin >> start;
	std::cout << "DFS遍历顺序: ";
	DFSAll(G, start);
	
	free(G); // 释放动态分配的内存
	return 0;
}

