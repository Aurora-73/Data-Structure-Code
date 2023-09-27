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
    cout << root->data << "："<< root<< endl;
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

//后序遍历并输出结果
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data;
    }
}

//非递归先序遍历
void PreOrderTraversal(BiTree T){
    Stack S;
    InitStack(S);
    BiTNode *p = T;
    //不需要提前入站。
    while(p || !IsEmpty(S))//有一个满足即可，p不为空或者S不为空。
    {
        cout << "\n新一轮while开始 \np为" << p << ",  栈"<< (IsEmpty(S) ? "为" : "不为" )<< "空" << endl; 
        if(p){
            cout <<"输出元素" << p->data <<endl;
            Push(S,p);
            cout << p <<"压栈" <<endl;
            cout << "进入p的左孩子：" << p->lchild <<endl;
            p = p -> lchild;//p不为空，输出p，进入p的左孩子。
        }else{
            Pop(S,p);
            cout << "p为空，弹栈" << p <<endl;
            cout << "进入" << p << "的右孩子" << p -> rchild <<endl;
            p = p -> rchild;//p为空，将S弹栈到p，进入p的右孩子。
        }
    }
    cout << "栈和队列都为空，循环结束" <<endl;
}

//非递归中序
void InOrderTraversal(BiTree T) {
    Stack S;
    InitStack(S);
    BiTNode *p = T;
    while(p || !IsEmpty(S)){
        cout << "\n新一轮while开始 \np为" << p << ",  栈"<< (IsEmpty(S) ? "为" : "不为" )<< "空" << endl; 
        if(p){
            Push(S,p);
            cout << p <<"压栈" <<endl;
            cout << "进入p的左孩子：" << p->lchild <<endl;
            p = p -> lchild;
        }else{
            Pop(S,p);
            cout <<"p为空，弹栈"<< p <<endl;
            cout <<"输出元素" << p->data <<endl;
            cout <<"进入"<< p <<"的右孩子" << p -> rchild <<endl;
            p = p -> rchild;
        }
    }
    cout << "栈和队列都为空，循环结束" <<endl;
}



//非递归后序遍历
void PostOrderTraversal(BiTree T) {
    Stack S;
    InitStack(S);
    BiTNode *p = T,*r = NULL;
    while(p || !IsEmpty(S)){
        cout << "\n新一轮while开始 \np为" << p << ",  栈"<< (IsEmpty(S) ? "为" : "不为" )<< "空" << endl; 
        if(p){
            Push(S,p);
            cout << p <<"压栈" <<endl;
            cout << "进入p的左孩子：" << p->lchild <<endl;
            p = p -> lchild;
        }else{
            GetTop(S,p);
            cout <<"p为空，栈顶的结点为"<< p <<endl;
            cout <<"上一个访问的节结为"<< r<<endl;
            if(p->rchild && p->rchild != r){
                cout <<"两者不同，栈顶未被访问过\n进入栈顶的右孩子"<< p->rchild <<endl;
                p = p -> rchild;
           }else{
               cout << "两者相同，栈顶已被访问过"<<endl;
               Pop(S,p);
               cout << "弹栈："<< p <<endl;
               cout << "输出元素" << p->data <<endl;
               r=p;
               cout << "将上一个访问过的节点更新为" << p <<endl;
               cout << "将p置空" <<endl;
               p = NULL;
           }    
        }
    }
    cout << "栈和队列都为空，循环结束" <<endl;
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
    PostOrder(T);
    cout << "\n"<< endl;

    
   // 输出先序遍历结果
    cout << "非递归先序遍历过程为: " << endl;
    PreOrderTraversal(T);
    cout << endl;
    
    // 输出中序遍历结果
    cout << "非递归中序遍历过程为: " << endl;
    InOrderTraversal(T);
    cout << endl;

    // 输出后序遍历结果
    cout << "非递归后序遍历过程为: " << endl;
    PostOrderTraversal(T);
    cout << endl;
    
      
    return 0;
}