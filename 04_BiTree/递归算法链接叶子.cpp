//二叉树的结构体定义、先序中序构造、后序遍历、计算总结点数、叶结点数、单分支结点数、双分支节点数和树的深度
#include <iostream>
#include <vector>
#define MaxSize 100

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//栈的结构体和函数定义
typedef struct StackNode {
    BiTree data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

// 初始化栈
void InitStack(Stack& S) {
    S.top = nullptr;
}

// 入栈
void Push(Stack& S, BiTree data) {
    StackNode* newNode = new StackNode;
    newNode->data = data;
    newNode->next = S.top;
    S.top = newNode;
}

// 出栈
bool Pop(Stack& S, BiTree& data) {
    if (S.top == nullptr) {
        return false; // 栈为空
    }
    StackNode* temp = S.top;
    data = temp->data;
    S.top = temp->next;
    delete temp;
    return true;
}

// 出栈
bool GetTop(Stack S, BiTree& data) {
    if (S.top == nullptr) {
        return false; // 栈为空
    }
    data = S.top->data;
    return true;
}

// 判断栈是否为空
bool IsEmpty(const Stack& S) {
    return S.top == nullptr;
}

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

void TrackAllLeaf(BiTree T){
    BiTNode *S[MaxSize],*p=T,*r=NULL;
    int top = -1,i;
    while(p || top !=-1){
        if(p){
            S[++top] = p;
            p = p -> lchild;
        }else{
            p = S[top];
            if(p->rchild && p->rchild != r)
                p = p -> rchild;
            else{
                r = S[top--];
                if(!p->lchild && !p->rchild){
                    for(i = 0; i <= top ; i++)
                        cout << S[i]->data << "->" ;
                    cout << p->data <<endl;    
            }
            p = NULL;
        }
    }
  }
}

void LinkLeaf(BiTree &T,BiTNode *&q,BiTNode *&b){
    if(!T) return ;
    if(!T->lchild && !T->rchild){
        if(!q)    q = b = T;
        else{
            q->rchild = T;
            q = T; 
            return;
        }
    }
    LinkLeaf(T->lchild,q,b);
    LinkLeaf(T->rchild,q,b);
}

int main() {
    char preorder[MaxSize], inorder[MaxSize];

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
    cout << "所有根到叶的路径为: "<< endl;
    TrackAllLeaf(T);
    BiTNode *q = NULL,*b;
    
    LinkLeaf(T,q,b);
    cout << "叶子链接成功: "<< endl;
    while(b){
        cout << b->data;
        if(b->rchild){
            cout << "->";
        }else{
            cout <<endl;
        }
        b = b->rchild;
    }
    
    
    return 0;
}


    