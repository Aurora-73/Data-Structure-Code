#include <iostream>
#include <vector>
#include <cstring>
#define MaxSize 50
using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 创建二叉树的函数，A[0]为字符串长度
BiTree CreateBySq(char A[], int i) {
	if (i > A[0] || A[i] == '#') 
		return NULL;
	BiTree T = new BiTNode;
	T->data = A[i];
	T->lchild = CreateBySq(A, 2*i);
	T->rchild = CreateBySq(A, 2*i+1);
	return T;
}

//将字符串转为字符数组
void StringToArray(const std::string& str, char A[]) {
	size_t length = str.length();
	A[0] = static_cast<char>(length);
	
	for (size_t i = 0; i < length; i++) {
		A[i + 1] = str[i];
	}
}

int length;
char key;

bool FindLevelKey(BiTree T,int l){
	if(!T)    return false;
	if(l== length && T->data == key) return true;//记录层次
	bool l1 = FindLevelKey(T->lchild,l+1);    
	bool r1 = FindLevelKey(T->rchild,l+1);    
	return l1 || r1 ;
}

int main() {

	 string input;
	 cout << "请输入表示顺序存储的二叉树的字符串：";
	 cin >> input;
 
	 char A[100];
	 StringToArray(input,A);
 
	 BiTree T = CreateBySq(A, 1);
	while(true){
	    cout << "请输入length和key" << endl;
		cin >> length;
		if(length == -1)	break;
		cin >> key;
	    std::cout << (FindLevelKey(T,0) ? "存在":"不存在") <<std::endl;
	}
      
    return 0;
}
