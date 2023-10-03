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

// 广度优先遍历
void BFS(MGraph G, int v, int visited[]) {
    Queue Q;
    InitQueue(Q);
    cout << G.Vex[v] << " ";
    visited[v] = 1;
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        for (int i = 0; i < G.vexnum; i++) {
            if (!visited[i] && G.Edge[v][i]) {
                cout << G.Vex[i] << " ";
                visited[i] = 1;
                EnQueue(Q, i);
            }
        }
    }
}

void BFSAll(MGraph G,int v){
    int *visited = new int[G.vexnum];
    for(int i = 0; i < G.vexnum ; i++)
        visited[i] = 0;
    BFS(G,v,visited);
    for(int i = 0; i < G.vexnum ; i++)
        if(visited[i] == 0)
            BFS(G,i,visited);
    delete[] visited;
}

int main() {
    MGraph G;
    CreateMGraph(G);
	PrintMGraph(G);
    cout << "从哪个顶点开始广度优先遍历（输入对应的下标）: ";
    int start;
    cin >> start;
    cout << "BFS遍历顺序: ";
    BFSAll(G,start);

    return 0;
}
