#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std; 

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

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


// 定义操作函数，用于计算操作符的结果
float op(float a, float b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0; // 如果操作符不是+、-、*、/，可以根据需要添加其他操作
}


// 计算表达式的值
float Compute(BiTree T) {
    if (!T) return 0;
    if (T->lchild && T->rchild)
        return op(Compute(T->lchild), Compute(T->rchild), T->data);
    else
        return T->data - '0';
}

int main() {

    string input;
    cout << "请输入表示顺序存储的二叉树表达式的字符串：";
    cin >> input;
    
    char A[100];
    StringToArray(input,A);
    
    BiTree T = CreateBySq(A, 1);
    PreOrderTraversal(T);
    cout << endl;  
    std::cout << "表达式的值为: " << Compute(T) << std::endl;
    
    return 0;
}
