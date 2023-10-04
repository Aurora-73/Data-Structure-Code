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

// 创建图的函数
void CreateMGraph(MGraph &G) {
    cout << "请输入顶点信息（字符序列）: ";
    cin >> G.Vex;
    G.vexnum = strlen(G.Vex);

    cout << "请逐行输入邻接矩阵，每行只包含0和1，无空格：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < G.vexnum; j++) {
            G.Edge[i][j] = row[j] - '0';
        }
    }
}

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

void DFS(MGraph G, int v, bool visited[]) {
	cout << G.Vex[v];
	visited[v] = true;
	for(int i=0;i< G.vexnum;i++){
		if(G.Edge[v][i] && !visited[i]){
			DFS(G,i, visited);
		}
	}
}

void DFSAll(MGraph G, int v){
	bool *visited = new bool[G.vexnum]; 
	for (int i = 0; i < G.vexnum; i++) 
		visited[i] = false;
	DFS(G,v,visited);
	for (int i = 0; i < G.vexnum; i++){
		if(!visited[i])
			DFS(G,i,visited);
	}
}

int main() {
    MGraph G;
    CreateMGraph(G);
	PrintMGraph(G);
    cout << "从哪个顶点开始深度优先遍历（输入对应的下标）: ";
    int start;
    cin >> start;
    cout << "DFS遍历顺序: ";
	// 调用DFS函数从某个起始节点开始遍历
	DFSAll(G, start);

    return 0;
}
