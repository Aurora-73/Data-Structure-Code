#include <iostream>

using namespace std;

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

void conversion(int N,int n) {
    SqStack S;
    InitStack(S);
    int e;
    while(N) {
        Push(S,N % n);
        N = N/n;
    }//循环进行：将N对n的余数压栈，将N对n取商 （余数压栈，数变为商）
    while(!IsEmpty(S)) {
        Pop(S,e);
        cout << e;
    }//倒序输出余数
    cout << endl;
}

int main() {
    int N,n;
    cout << "请输入要转换的十进制数" << endl;
    cin >> N;
    cout << "请输入想要转换的进制" << endl;
    cin >> n;
    cout << "结果为" << endl;
    conversion(N,n);
    return 1;
}
