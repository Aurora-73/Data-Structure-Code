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

void Del_x(BiTree &T) {
    if (!T) return;
    
    // 递归删除左子树和右子树
    Del_x(T->lchild);
    Del_x(T->rchild);
    
    // 删除当前节点并将指针置为 NULL
    delete T;
    T = NULL;
}

void Find_x(BiTree &T, char x) {
    if (!T) return;
    
    // 如果当前节点的数据等于 x，则删除以当前节点为根的子树（包括自身）
    if (T->data == x) {
        Del_x(T);
    } else {
        // 否则递归查找左右子树
        Find_x(T->lchild, x);
        Find_x(T->rchild, x);
    }
}


int main() {
    char preorder[100], inorder[100];

    // 输入先序和中序遍历结果
    cout << "请输入先序遍历结果 : ";
    cin >> preorder;
    cout << "请输入中序遍历结果 : ";
    cin >> inorder;
    
    // 构建二叉树
    BiTree T = BuildTree(preorder, inorder, 0, 0, strlen(inorder) - 1);

    // 输出后序遍历结果
    cout << "后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    cout << "你要删除的值为 "<<endl;
    char x;
    std::cin >> x;
    Find_x(T,x);
    
   // 输出先序遍历结果
    cout << "左右孩子互换后的先序遍历结果为: ";
    PreOrderTraversal(T);
    cout << endl;
    
    // 输出中序遍历结果
    cout << "左右孩子互换后的中序遍历结果为: ";
    InOrderTraversal(T);
    cout << endl;

    // 输出后序遍历结果
    cout << "左右孩子互换后的后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    
      
    return 0;
}