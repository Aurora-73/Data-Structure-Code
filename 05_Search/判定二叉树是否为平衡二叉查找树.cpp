#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

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

bool IsBST(BiTree T,int &x) {
    if(!T)    return true;
    bool l = IsBST(T->lchild, x);
    bool p = T->data > x;
    x = T -> data;
    bool r = IsBST(T->rchild, x);
    return l&&p&&r ;
}

int OneNode(BiTree T){
    if(!T)    return 0;
    int l = OneNode(T -> lchild);
    int r = OneNode(T -> rchild);
    if(l==-1 || r == -1 || r-l > 1 || l-r > 1)
        return -1;
    return (l > r ? l : r) + 1;
}

bool IsAVL(BiTree T){
    return OneNode(T)+1 ;
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

    int x = INT_MIN; // 初始值设为负无穷小
    cout << ( IsBST(T, x) ? (IsAVL(T) ? "它是平衡二叉树" : "它不是平衡二叉树"): "它根本就不是二叉查找树") <<endl;

    return 0;
}