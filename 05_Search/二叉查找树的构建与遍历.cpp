#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉查找树插入元素 
void InsertBS(BiTree &T,int x){
    BiTNode *q = new BiTNode,*p = T,*pre = T;
    q -> data = x;
    while(p){
       if(x < p -> data){
           pre = p;
           p = p -> lchild;
       }else if(x > p -> data){
           pre = p;
           p = p -> rchild;
       }else{ 
           delete(q);
           return;
       };
    }
    if(pre->data > x)
        pre ->lchild = q;
   else
        pre ->rchild = q;
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
    cout << "请输入根的值: " << endl;
    
    BiTNode *T = new BiTNode;
    cin >> T->data;
    T->lchild = NULL; // 设置左子树为空
    T->rchild = NULL; // 设置右子树为空
    
    int x = 0;
    while (x != 99999) {
        cout << "请输入一个元素，输入99999时停止" << endl;
        cin >> x;
        if (x != 99999) {
            InsertBS(T, x);
        }
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