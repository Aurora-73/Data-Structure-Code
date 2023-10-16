#include <iostream>
#include <string>
using namespace std;

constexpr const auto INF = 0x3f3f3f3f;
#define MAXN 100
//点集合
struct Vetrix
{
	int id;
	string info;
};
struct Graph
{
	int n, e;	//n：点数  e：边数
	int edge[MAXN][MAXN];	//边集合
	Vetrix v[MAXN];			//点集合
};

//创建邻接矩阵
void createGraph(Graph& g, int A[][5], int n, int e)
{
	g.e = e;
	g.n = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g.edge[i][j] = A[i][j];
		}
	}
}

//普里姆算法
void Prim(Graph& g, int u)
{
	//以u为最小生成树的起点
	
	//两个辅助数组
	int closest[MAXN], lowcost[MAXN];
	for (int i = 0; i < g.n; i++)
	{
		closest[i] = u;				//i: 顶点	
		lowcost[i] = g.edge[u][i];	//edge[u][i]： u->i 这条边所具有的权值
	}
	int min, k;
	for (int i = 1; i < g.n; i++)
	{
		min = INF, k = -1;
		for (int j = 0; j < g.n; j++)
		{
			//lowcost[j] != 0 表示所选的点不能是U中的点，只能是V-E中的
			//lowcost[j] < min 表示依次选取权值最小的边
			if (lowcost[j] != 0 && lowcost[j] < min)	//在V-E中找出离U最近的顶点
			{
				min = lowcost[j];	
				k = j;				//k为最近顶点编号
			}
		}
		//k：记录了权值最小的边在V-E中的顶点编号
		//min：记录了这个最小权值
		printf(" 边(%d -> %d) 权值:%d\n", closest[k],k, min);
		//修正数组
		lowcost[k] = 0;	//这个边已经选过了
		for (int j = 0; j < g.n; j++)
		{
			//以k作为起点，寻找与k点连接的边的权值是否比之前记录的权值小
			if (lowcost[j] != 0 && g.edge[k][j] < lowcost[j])
			{
				lowcost[j] = g.edge[k][j];	//更新为最小权值
				closest[j] = k;				//记录这个点
			}
		}
	}
}

int main()
{
	Graph g;
	int n = 5, e = 8;
	int A[][5] = {
		{0,1,3,4,7},
		{1,0,2,INF,INF},
		{3,2,0,5,8},
		{4,INF,5,0,6},
		{7,INF,8,6,0}
	};
	createGraph(g, A, n, e);
	Prim(g, 0);
	return 0;
}

