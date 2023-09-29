#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

bool InBST(BiTree &T,int x){
    if(!T){
        BiTNode *q = new BiTNode;
        q -> data = x;
        q -> lchild = q -> rchild = NULL;
        T = q;
        cout << q -> data << " : " << q << endl;
        return true;
    }
    if(T -> data > x)
        return InBST(T -> lchild, x);
    else if(T -> data < x)
        return InBST(T -> rchild, x);
    else    return false;    
}

BiTNode *SearBST(BiTree T,int x){
    if(!T)    return T;
    if(T->data > x)   
        return SearBST(T->rchild , x);
    if(T->data < x)   
        return SearBST(T->lchild , x);    
    return T;
}

int main() {
    cout << "请输入元素，输入9999时停止" << endl;
    
    BiTNode *T = NULL;
    int x = 0;
    while (x != 9999) {
        cin >> x;
        if (x != 9999) 
          cout << (InBST(T, x) ? "" : "插入失败，结点已存在\n");   
    }
    
    cout << "请输入带查找的值，输入9999停止" << endl; 
    x = 0;
    while (x != 9999) {
        cin >> x;
        cout << x << "的地址为" << SearBST(T,x) << endl;
    }
    
      
    return 0;
}