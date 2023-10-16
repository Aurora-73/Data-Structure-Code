#include<iostream>
#include<stdio.h>
using namespace std; 
typedef char VerTexType; 
typedef int ArcType; 
#define MaxInt 32767 
#define MVNum 100
#define ArcNum 100
#define OK 1
#define ERROR -1
int Vexset[MVNum];//辅助数组表示连通分量 
typedef int status;
typedef struct{
	VerTexType vexs[MVNum] {'A','B','C','D','E','F'};
	ArcType arcs[MVNum][MVNum];
	int vexnum = 6,arcnum = 10;
}AMGraph; 

typedef struct{
	VerTexType Head;//起点 
	VerTexType Tail;//终点
	ArcType lowcast; 
}Edge[ArcNum];

status CreateUDN(AMGraph &G){//创建无向图 	
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			if(i==j){
				G.arcs[i][j] = 0;
			}else
				G.arcs[i][j] = MaxInt;//初始状态全部节点之间相互不可达
		}
	}
	G.arcs[0][1]=6;G.arcs[0][2]=1;G.arcs[0][3]=5;
	G.arcs[1][2]=5;G.arcs[1][4]=3;
	G.arcs[2][3]=5;G.arcs[2][4]=6;G.arcs[2][5]=4;
	G.arcs[3][5]=2;
	G.arcs[4][5]=6;
	for(int i=0;i<G.vexnum;i++){
		for(int j=i+1;j<G.vexnum;j++){
			if(G.arcs[i][j]!=MaxInt){
				G.arcs[j][i] = G.arcs[i][j];
			} 
		}
	}//矩阵对称 
	return OK; 
}

void ShowGraph(AMGraph G){
	cout<<" ";
	for(int i=0;i<G.vexnum;i++){
		cout<<" "<<G.vexs[i];
	}
	cout<<endl;
	for(int i=0;i<G.vexnum;i++){
		cout<<G.vexs[i]<<" ";
		for(int j=0;j<G.vexnum;j++){
			if(G.arcs[i][j]==MaxInt){
				cout<<"* ";
			}else{
				cout<<G.arcs[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int LocateVex(AMGraph G, VerTexType v){
	int i;
	for(i=0;i<G.vexnum;i++){
		if(G.vexs[i]==v){
			return i;
		}
	} 
	return ERROR;
}

VerTexType Transform(AMGraph G, int vn){
	return G.vexs[vn]; 
}

void InitailEdge(AMGraph G,Edge &edge){//初始化边表 
	int arcnum = 0;
	for(int i=0;i<G.vexnum;i++){//纵列为起点 
		for(int j=i+1;j<G.vexnum;j++){//横行为终点 
			if(G.arcs[i][j]!=MaxInt&&G.arcs[i][j]!=0){
				edge[arcnum].Head = Transform(G,i);
				edge[arcnum].Tail = Transform(G,j);
				edge[arcnum].lowcast = G.arcs[i][j];
				arcnum++;
			}
		}
	} 
}

void sort(AMGraph G,Edge &edge){
	VerTexType tv;
	ArcType tl;
	for(int i=0;i<G.arcnum;i++){
		for(int j=0;j<G.arcnum-i-1;j++){
			if(edge[j].lowcast>edge[j+1].lowcast){//直接写对象互换报错，忘记咋互换对象了，这样写有点麻烦，先将就着用吧 ，这个操作不是重点 
				tv = edge[j].Head;
				edge[j].Head = edge[j+1].Head;
				edge[j+1].Head = tv;
				
				tv = edge[j].Tail;
				edge[j].Tail = edge[j+1].Tail;
				edge[j+1].Tail = tv;
				
				tl = edge[j].lowcast;
				edge[j].lowcast = edge[j+1].lowcast;
				edge[j+1].lowcast = tl;
			}
		}
	}
}

void ShowEdge(AMGraph G,Edge edge){
	for(int i=0;i<G.arcnum;i++){
		cout<<edge[i].Head<<"-"<<edge[i].lowcast<<"-"<<edge[i].Tail<<endl;
	}
}

void ShowVexset(AMGraph G){
	for(int i=0;i<G.vexnum;i++){
		cout<<Vexset[i]<<" ";
	} 
	cout<<endl;
}

void Kruskal(AMGraph &G){
	Edge edge;
	InitailEdge(G,edge); 
	//	ShowEdge(G,edge);
	sort(G,edge);
	//	ShowEdge(G,edge);
	for(int i=0;i<G.vexnum;i++){
		Vexset[i] = i;//每个节点自成一个分量 
	}
	int headi,taili;//边起点的下标、边终点的下标 
	int headt,tailt;//操作连通分量时的中间量 
	for(int i=0;i<G.arcnum;i++){
		headi = LocateVex(G,edge[i].Head); //起点下标 
		taili = LocateVex(G,edge[i].Tail); //终点下标 
		headt = Vexset[headi];//获取起点的连通分量 
		tailt = Vexset[taili];//获取终点的连通分量 
		if(headt!=tailt){//如果两个点不是同一个连通分量
			cout<<edge[i].Head<<"-"<<edge[i].lowcast<<"-"<<edge[i].Tail<<endl;
			for(int j=0;j<G.vexnum;j++){
				if(Vexset[j]==headt){//更新Vexset数组，把改起点的连通分量改成和终点连通分量一致（其实就是合并连通分量） 
					Vexset[j] = tailt;
					//					ShowVexset(G);
				}
			}
		}
	} 	
}

int main(){
	AMGraph G;
	CreateUDN(G);
	ShowGraph(G);
	Kruskal(G); 
	return 0;
} 

