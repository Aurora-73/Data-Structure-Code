#include <iostream>
#include <cstring>
#include <climits> // For INT_MAX
using namespace std;

const int MaxSize = 10;
const int NOPATH = 999;

// 邻接矩阵表示的图结构体
typedef struct MGraph {
    char Vex[MaxSize];
    int Edge[MaxSize][MaxSize];
    int vexnum, arcnum;
} MGraph;

void CreateMGraph(MGraph &G) {
    cout << "请输入顶点信息（字符序列）: ";
    cin >> G.Vex;
    G.vexnum = strlen(G.Vex);
    cout << "请逐行输入邻接矩阵，每行只包含个位数，其中#代表没有路径，无空格：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < G.vexnum; j++) {
            if(row[j] != '#')
                G.Edge[i][j] = row[j] - '0';
            else
                G.Edge[i][j] = NOPATH;
        }
    }
}

void PrintMGraph(MGraph G) {
    cout << "邻接矩阵存储的图内容如下：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.Vex[i] << " -> ";
        for (int j = 0; j < G.vexnum; j++) {
            if (G.Edge[i][j] != NOPATH && G.Edge[i][j] != 0) {
                cout << G.Vex[j] << " -> ";
            }
        }
        cout << "NULL" << endl;
    }
}

void Floyd(MGraph G, int A[][MaxSize], int path[][MaxSize]) {
    int vn = G.vexnum, i, j, k, nowd;
    for (i = 0; i < vn; i++) {
        for (j = 0; j < vn; j++) {
            A[i][j] = G.Edge[i][j];
            path[i][j] = -1;
        }
    }
    for (k = 0; k < vn; k++) {
        for (i = 0; i < vn; i++) {
            for (j = 0; j < vn; j++) {
                nowd = A[i][k] + A[k][j];
                if (nowd < A[i][j]) {
                    A[i][j] = nowd;
                    path[i][j] = k;
                }
            }
        }
    }
}

int main() {
    MGraph G;
    CreateMGraph(G);
    PrintMGraph(G);

    cout << "请输入起点和终点，用空格隔开（-1 -1 结束）:" << endl;
    int start, end;
    while (cin >> start >> end) {
        if (start == -1 || end == -1) {
            break;
        }

        int A[MaxSize][MaxSize];
        int path[MaxSize][MaxSize];
        Floyd(G, A, path);

        if (start < 0 || start >= G.vexnum || end < 0 || end >= G.vexnum) {
            cout << "起点或终点无效，请重新输入：" << endl;
            continue;
        }

        if (A[start][end] >= NOPATH) {
            cout << "从顶点 " << G.Vex[start] << " 到顶点 " << G.Vex[end] << " 无路径可达" << endl;
        } else {
            cout << "从顶点 " << G.Vex[start] << " 到顶点 " << G.Vex[end] << " 的最短距离为: " << A[start][end] << endl;
            cout << "路径为: " << G.Vex[start];
            int j = end;
            while (path[start][j] != -1) {
                cout << " <- " << G.Vex[path[start][j]];
                j = path[start][j];
            }
            cout << " <- " << G.Vex[end] << endl;
        }
    }

    return 0;
}
