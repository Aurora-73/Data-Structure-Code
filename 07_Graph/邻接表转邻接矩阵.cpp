#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MaxSize = 100;

// 邻接矩阵表示的图结构体
typedef struct MGraph {
    char Vex[MaxSize];
    int Edge[MaxSize][MaxSize];
    int vexnum, arcnum;
} MGraph;

//邻接表的边结构体
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

//邻接表的顶点结构体
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode;

//邻接表
typedef struct AGraph{
	VNode adjlist[MaxSize];
	int vexnum , arcnum;
}AGraph;

// 创建图的函数
void CreateGraph(AGraph*& G) {
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

void Transform_A_M(MGraph &G1, AGraph *G2){
	G1.arcnum = G2->arcnum;
	G1.vexnum = G2->vexnum;
	for(int i=0;i< G1.vexnum ;i++)
		G1.Vex[i] = G2->adjlist[i].data;
	for(int i=0;i< G1.vexnum ;i++)
		for(int j=0;j< G1.vexnum ;j++)
			G1.Edge[i][j] = 0;
	ArcNode *p;
	for(int i=0;i< G1.vexnum ;i++){
		p = G2->adjlist[i].firstarc;
		while(p){
			G1.Edge[i][p -> adjvex] =1;
			p = p -> nextarc ;
		}
	}
}


// 输出邻接表存储的图
void PrintMGraph(MGraph G) {
	cout << "邻接矩阵存储的图内容如下：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << G.Vex[i] << " -> ";
		for (int j = 0; j < G.vexnum; j++) {
			if (G.Edge[i][j] == 1) {
				cout << G.Vex[j] << " -> ";
			}
		}
		cout << "NULL" << endl;
	}
}

void PrintAGraph(AGraph *G) {
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
}

int main() {	
	MGraph G1;
	AGraph *G2;
	CreateGraph(G2);
	PrintAGraph(G2);
	Transform_A_M(G1,G2);
	PrintMGraph(G1);
    return 0;
}
