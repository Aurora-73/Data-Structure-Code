#include <iostream>

typedef int ElemType; // 顺序栈中元素的数据类型
#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack; // 将结构体名Stack改为SqStack

void InitStack(SqStack& S) {
    S.top = -1;
}

bool IsEmpty(SqStack& S) {
    return (S.top == -1) ? true : false;
}

bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack& S, ElemType& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack& S, ElemType& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

int main() {
    SqStack s;
    InitStack(s);
    std::cout << (IsEmpty(s) ? "栈为空" : "栈非空") << std::endl;
    std::cout << "请输入压栈元素，输入-1时停止" << std::endl;
    ElemType x;
    std::cin >> x;
    while (x != -1) {
        if (!Push(s, x))
            std::cout << "栈已满，无法压栈" << std::endl;
        std::cin >> x;
    }
    std::cout << (IsEmpty(s) ? "栈为空" : "栈非空") << std::endl;
    std::cout << "需要弹几次栈？" << std::endl;
    std::cin >> x;
    std::cout << "开始弹栈" << std::endl;
    ElemType e;
    for (int i = 1; i <= x; i++) {
        if (!IsEmpty(s)) {
            if (!Pop(s, e))
                std::cout << "栈为空，无法弹栈" << std::endl;
            std::cout << e << std::endl;
        } else {
            std::cout << "弹栈次数过多" << std::endl;
            break;
        }
    }
    std::cout << (IsEmpty(s) ? "栈为空" : "栈非空") << std::endl;
}
