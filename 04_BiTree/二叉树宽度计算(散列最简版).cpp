#include <iostream>
#include <vector>
#define MaxSize 50
using namespace std;



// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 队列的结构体和函数定义
typedef struct QueueNode {
    BiTree data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 初始化队列
void InitQueue(Queue& Q) {
    Q.front = Q.rear = nullptr;
}

// 入队列
void EnQueue(Queue& Q, BiTree data) {
    QueueNode* newNode = new QueueNode;
    newNode->data = data;
    newNode->next = nullptr;
    if (Q.rear == nullptr) {
        Q.front = Q.rear = newNode;
    } else {
        Q.rear->next = newNode;
        Q.rear = newNode;
    }
}

// 出队列
bool DeQueue(Queue& Q, BiTree& data) {
    if (Q.front == nullptr) {
        return false; // 队列为空
    }
    QueueNode* temp = Q.front;
    data = temp->data;
    Q.front = temp->next;
    delete temp;
    if (Q.front == nullptr) {
        Q.rear = nullptr;
    }
    return true;
}

// 栈的结构体和函数定义
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

// 判断队列是否为空
bool IsEmpty(const Queue& Q) {
    return Q.front == nullptr;
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

void FindLevel(BiTree T,int l,int a[]){
    if(!T)    return;
    a[l]++;//记录层次
    FindLevel(T->lchild,l+1,a);    
    FindLevel(T->rchild,l+1,a);    
}//将先序遍历的每个元素的层次号都记录在a中，a[]是哈希表

int FindMax(int a[]){
    int max = 0;
    for(int i = 1; a[i] != 0;i++ )
        if(a[i] > max) max = a[i];
    return max;
}//查找不为0的连续数组的最大值


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
   
    int a[MaxSize]={0};//散列存储
    FindLevel(T,1,a);//记录每个节点的层次到a[]
    std::cout << "二叉树的宽度是"<< FindMax(a) <<std::endl;
    
      
    return 0;
}