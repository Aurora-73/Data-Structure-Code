//二叉树的结构体定义、先序中序构造、后序遍历、计算总结点数、叶结点数、单分支结点数、双分支节点数和树的深度
#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 根据先序和中序遍历结果构造二叉树
BiTree BuildTree(char* preorder, char* inorder, int pre_start, int in_start, int in_end) {
    if (pre_start >= strlen(preorder) || in_start > in_end) {
        return nullptr;
    }

    // 创建当前根节点
    BiTree root = new BiTNode;
    root->data = preorder[pre_start];
    root->lchild = root->rchild = nullptr;

    // 在中序遍历中找到根节点的位置
    int root_index = in_start;
    while (inorder[root_index] != root->data) {
        root_index++;
    }

    // 递归构建左子树和右子树
    root->lchild = BuildTree(preorder, inorder, pre_start + 1, in_start, root_index - 1);
    root->rchild = BuildTree(preorder, inorder, pre_start + root_index - in_start + 1, root_index + 1, in_end);

    return root;
}

// 后序遍历并输出结果
void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data;
    }
}

int Depth0(BiTree T){
     return (T ? (Depth0(T->lchild) >  Depth0(T->rchild) ? Depth0(T->lchild) : Depth0(T->rchild)) + 1 : 0);
}//抽象

int Depth1(BiTree T){
    BiTNode *Q[100],*p;
    int front = -1 ,rear =0, last = 0,deep = 0;
    Q[0] = T;
    while(front != rear){
        p = Q[++front];
        if(p->lchild)
            Q[++rear] = p->lchild;
       if(p->rchild)
            Q[++rear] = p->rchild;
        if(front == last){
            last = rear;
            deep++;
        }        
    }
    return deep;
}

int main() {
    char preorder[100], inorder[100];

    // 输入先序和中序遍历结果
    cout << "请输入先序遍历结果: ";
    cin >> preorder;
    cout << "请输入中序遍历结果: ";
    cin >> inorder;

    // 构建二叉树
    BiTree T = BuildTree(preorder, inorder, 0, 0, strlen(inorder) - 1);

    // 输出后序遍历结果
    cout << "后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    
    cout << "树的深度为 " << Depth0(T) << std::endl;
    cout << "树的深度为 " << Depth1(T) << std::endl;
    
    return 0;
}


    