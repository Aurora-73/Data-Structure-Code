#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉查找树插入元素 
bool InsertBST(BiTree &T,int x){
    BiTNode *q = new BiTNode,*p = T,*pre = T;
    cout << x << " : " << q << endl; 
    q -> data = x;
    if(!T){
        T = q;
        return true;
    } 
    while(p){
       if(x == p -> data){
           delete(q);
           return false;
       }else{
           pre = p;
           p = (x > p -> data ? p -> rchild : p -> lchild);
       }
    }
    (pre->data > x ? pre ->lchild : pre ->rchild) = q;
    return true;
}

BiTNode *SearchBST(BiTree T,int x){
    BiTNode *p = T;
    while(p){
       if(x < p -> data)
           p = p -> lchild;
       else if(x > p -> data)
           p = p -> rchild;
       else break;    
    }
    return p;
}

int main() {
    cout << "请输入一个元素，输入9999时停止" << endl;
    
    BiTNode *T = NULL;
    int x = 0;
    while (x != 9999) {
        cin >> x;
        if (x != 9999)
             cout << (InsertBST(T,x) ? "" : "插入失败，结点已存在\n");
    }
    
    cout << "请输入带查找的值，输入9999停止" << endl; 
    x = 0;
    while (x != 9999) {
        cin >> x;
        cout <<x << "的地址为" << SearchBST(T,x) << endl;
    }
    
      
    return 0;
}