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

// 先序遍历并输出结果
void PreOrderTraversal(BiTree T) {
    if (T) {
        cout << T->data << "  ";
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

// 中序遍历并输出结果
void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        cout << T->data << "  ";
        InOrderTraversal(T->rchild);
    }
}

// 后序遍历并输出结果
void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data <<"  ";
    }
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
    
   // 输出先序遍历结果
    cout << "先序遍历结果为: ";
    PreOrderTraversal(T);
    cout << endl;
    
    // 输出中序遍历结果
    cout << "中序遍历结果为: ";
    InOrderTraversal(T);
    cout << endl;

    // 输出后序遍历结果
    cout << "后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    
      
    return 0;
}