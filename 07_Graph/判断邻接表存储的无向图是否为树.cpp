#include <iostream>
#include <cstdlib>

#define MaxSize 100

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
	visited[v] = 1;
	ArcNode* p = G->adjlist[v].firstarc;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(G, p->adjvex, visited);
		}
		p = p->nextarc;
	}
}

bool IsTree(AGraph* G) {
	if(G->vexnum != G->arcnum + 1) return false;
	int* visited = new int[G->vexnum],count = 0;
	for (int i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	for (int i = 0; i < G->vexnum; i++)
		if (!visited[i]){
			DFS(G, i, visited);
			count++;
		}
	delete[] visited;
	return count == 1;
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
	
	std::cout << (IsTree(G) ? "是树" : "不是树");
	free(G); // 释放动态分配的内存
	return 0;
}

