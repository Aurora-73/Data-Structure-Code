#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉查找树插入元素 
void InsertBST(BiTree &T,int x){
    BiTNode *q = new BiTNode,*p = T,*pre = T;
    cout << x << " : " << q << endl; 
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
    cout << "请输入元素，输入9999时停止" << endl;
    
    BiTNode *T = new BiTNode;
    cin >> T->data;
    cout << T->data << " : " << T << endl; 
    T->lchild = NULL; // 设置左子树为空
    T->rchild = NULL; // 设置右子树为空
    

    int x = 0;
    while (x != 9999) {
        cin >> x;
        if (x != 9999) {
            InsertBST(T, x);
        }
    }
    
    cout << "请输入带查找的值: (输入9999停止)" << endl; 
    while (x != 99999) {
        cin >> x;
        cout << "它的地址为" << SearchBST(T,x) << endl;
    }
    
      
    return 0;
}