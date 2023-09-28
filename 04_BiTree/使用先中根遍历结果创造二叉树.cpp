#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//使用先中根遍历结果创造二叉树
BiTree CreateByOrder(char A[], int l1, int h1, char B[], int l2, int h2) {
    if (h1 < l1 || h2 < l2) return NULL;
    BiTree T = new BiTNode;
    T->data = A[l1]; // 根节点的值应该是 A[l1]
    int i, llen, rlen;
    for (i = l2; B[i] != A[l1]; i++);
    llen = i - l2;
    rlen = h2 - i;
    T->lchild = CreateByOrder(A, l1 + 1, l1 + llen, B, l2, i - 1);
    T->rchild = CreateByOrder(A, h1 - rlen + 1, h2, B, i + 1, h2);
    return T;
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

void ReverseTree(BiTree &T){
    if(!T)    return;
    ReverseTree(T->lchild);
    ReverseTree(T->rchild);
    BiTNode *temp = T->lchild;
    T->lchild = T-> rchild;
    T->rchild = temp;
}//二叉树的逆置


int main() {
    char A[100], B[100];

    // 输入先序和中序遍历结果
    cout << "请输入先序遍历结果 : ";
    cin >> A;
    cout << "请输入中序遍历结果 : ";
    cin >> B;
    
    // 构建二叉树
    BiTree T = CreateByOrder(A, 0, strlen(A) - 1, B, 0 , strlen(B) - 1);

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