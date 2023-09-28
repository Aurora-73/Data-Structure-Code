#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
    int ltag,rtag;
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

// 先序遍历并输出结果
void PreOrderTraversal(BiTree T) {
    if (T) {
        cout << T->data;
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

// 中序遍历并输出结果
void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        cout << T->data;
        InOrderTraversal(T->rchild);
    }
}

// 后序遍历并输出结果
void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data;
    }
}

void InOrderTreadize(BiTree &p,BiTNode *&pre){
        if(!p)    return;
        InOrderTreadize(p->lchild , pre);
        if(!p -> lchild){
            p -> lchild = pre;
            p -> ltag = 1;
        }
        if(pre && !pre -> rchild){
             pre -> rchild = p;
             pre -> rtag = 1;
        }
        pre = p;
        InOrderTreadize(p->rchild , pre);
}

BiTNode *FindNext(BiTNode *p){
    if(p->rtag)    return p -> rchild;
    p = p -> rchild;
    while(p->lchild)
        p = p -> lchild;
   return p;     
}

void InOrder(BiTNode *T){
    if(!T->ltag) InOrder(T->lchild);
    cout << T -> data << " "; // 添加空格分隔节点值
    InOrder(FindNext(T));
}

int main() {
    char preorder[100], inorder[100];
    
    string input;
    cout << "请输入表示顺序存储的二叉树的字符串：";
    cin >> input;
    
    char A[100];
    StringToArray(input,A);
       
    BiTree T = CreateBySq(A, 1);
  
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
    
    BiTNode *p = T,*pre = NULL;
    InOrderTreadize(p,pre);
    cout << "中序线索化成功 ";
    InOrder(T);
    cout << "中序遍历运行成功";
      
    return 0;
}