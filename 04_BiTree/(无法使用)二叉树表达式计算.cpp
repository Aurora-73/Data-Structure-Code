//compute函数正确，但是构造函数不正确，无法使用
#include <iostream>
#include <stack>
#include <cctype>
#include <string>

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

// 定义操作函数，用于计算操作符的结果
int op(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0; // 如果操作符不是+、-、*、/，可以根据需要添加其他操作
}

// 函数用于构建二叉树表达式
BiTree BuildExpressionTree(const std::string& expression) {
    std::stack<BiTree> nodeStack;
    for (char c : expression) {
        if (std::isdigit(c)) {
            BiTree newNode = new BiTNode;
            newNode->data = c;
            newNode->lchild = nullptr;
            newNode->rchild = nullptr;
            nodeStack.push(newNode);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (nodeStack.size() < 2) {
                std::cerr << "表达式不合法" << std::endl;
                return nullptr;
            }
            BiTree rightNode = nodeStack.top();
            nodeStack.pop();
            BiTree leftNode = nodeStack.top();
            nodeStack.pop();
            BiTree newNode = new BiTNode;
            newNode->data = c;
            newNode->lchild = leftNode;
            newNode->rchild = rightNode;
            nodeStack.push(newNode);
        } else {
            std::cerr << "表达式包含非法字符" << std::endl;
            return nullptr;
        }
    }
    if (nodeStack.size() != 1) {
        std::cerr << "表达式不合法" << std::endl;
        return nullptr;
    }
    return nodeStack.top();
}

// 计算表达式的值
int Compute(BiTree T) {
    if (!T) return 0;
    if (T->lchild && T->rchild)
        return op(Compute(T->lchild), Compute(T->rchild), T->data);
    else
        return T->data - '0';
}

int main() {
    std::string expression;
    std::cout << "请输入二叉树表达式: ";
    std::getline(std::cin, expression);
    BiTree root = BuildExpressionTree(expression);
    if (root) {
        int result = Compute(root);
        std::cout << "表达式的值为: " << result << std::endl;
    }
    return 0;
}
