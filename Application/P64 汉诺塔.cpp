//Hanoi塔问题
#include <iostream>
using namespace std;
int m = 0;
void move(char A,int n,char C){
	cout << ++m << "," << n << "," << A << "," << C << endl;
}
void Hanoi(int n,char from,char by,char to){
	if(n == 1)	move(from,1,to);
	else{
		Hanoi(n-1,from,to,by);
		move(from,n,to);
		Hanoi(n-1,by,from,to);
	}
}

int main(){
	Hanoi(4,'A','B','C');
}
//八皇后问题
//迷宫问题
