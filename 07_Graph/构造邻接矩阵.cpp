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

int main() {
    MGraph G;
    CreateMGraph(G);
	PrintMGraph(G);
    return 0;
}
