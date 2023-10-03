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
void CreateMGraph(MGraph &G) {
	cout << "请输入顶点信息（字符序列）: ";
	cin >> G.Vex;
	G.vexnum = strlen(G.Vex);
	G.arcnum = 0;
	
	cout << "请逐行输入邻接矩阵，每行只包含0和1，无空格：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < G.vexnum; j++) {
			G.Edge[i][j] = row[j] - '0';
			if(G.Edge[i][j])
				G.arcnum++;
		}
	}
}

void Transform_M_A(MGraph G1, AGraph *G2){
	G2 -> arcnum = G1.arcnum;
	G2 -> vexnum = G1.vexnum;
	for(int i=0;i< G1.vexnum ;i++){
		G2->adjlist[i].data = G1.Vex[i];
		G2->adjlist[i].firstarc = NULL;
		for(int j=0;j< G1.vexnum ;j++)
			if(G1.Edge[i][j]){
				ArcNode *p = new ArcNode;
				p -> adjvex = j;
				p -> nextarc =  G2->adjlist[i].firstarc;
				G2 -> adjlist[i].firstarc = p;//头插法
				/*尾插法
				ArcNode *q;
				p ->nextarc = NULL;
				if(G2->adjlist[i].firstarc){
					q = G2->adjlist[i].firstarc;
					while(q -> nextarc)
						q = q->nextarc;
					q -> nextarc = p;
				}else 
					G2->adjlist[i].firstarc = p;*/
		}
	}
}


// 输出邻接表存储的图
void PrintMGraph(MGraph G){
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
	AGraph *G2 = new AGraph;
	CreateMGraph(G1);
	PrintMGraph(G1);
	Transform_M_A(G1,G2);
	PrintAGraph(G2);
    return 0;
}
