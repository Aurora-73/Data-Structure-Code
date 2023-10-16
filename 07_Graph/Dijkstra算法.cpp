#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MaxSize = 100;
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

void Dijkstra(MGraph G,int v,int dist[],int path[]) {
    int vn = G.vexnum, i, j, k, min, nowd;
    bool *visited = new bool[vn];
    for(i = 0; i < vn ; i++) {
        visited[i] = false;
        dist[i] = G.Edge[v][i];
        path[i] = v;
    }
    visited[v] = true;
    for(i = 0; i < vn - 1; i++) {
        min = INT_MAX;
        for(j = 0; j < vn; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        visited[k] = true;
        for(j = 0 ; j < vn ; j++) {
            nowd = dist[k] + G.Edge[k][j];
            if(nowd < dist[j] ) {
                dist[j] = nowd;
                path[j] = k;
            }
        }
    }
}

int main() {
    MGraph G;
    CreateMGraph(G);
    PrintMGraph(G);
    cout << "源头是哪个顶点: ";
    int start;
    cin >> start;
    int *dist = new int[G.vexnum];
    int *path = new int[G.vexnum];
    Dijkstra(G, start,dist,path);
    for (int i = 0; i < G.vexnum; i++) {
        if (i != start) {
            cout << "从顶点 " << G.Vex[start] << " 到顶点 " << G.Vex[i] << " 的最短距离为: " << dist[i] << endl;
            cout << "路径为: ";
            int j = i;
            if (dist[i] >= NOPATH) {
                cout << "无路径" << endl;
            } else {
                cout << G.Vex[i];
                while (path[j] != start) {
                    j = path[j];
                    cout << " <- " << G.Vex[j];
                }
                cout << " <- " << G.Vex[start] << endl;
            }

        }
    }
    return 0;
}
