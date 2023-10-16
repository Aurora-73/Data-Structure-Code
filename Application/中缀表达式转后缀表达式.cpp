#include <iostream>
#include <cstring>

typedef char ElemType; // 顺序栈中元素的数据类型

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

void GetTop(SqStack S,char c) {
    c = S.data[S.top];
}

int dist(char c) {
    if(( '0'<= c && c <= '9' ) || ( 'A'<= c && c <= 'Z' ))
        return 1;//操作数
    if(c == '(')
        return 2;//左括号
    if(c == ')')
        return 3;//右括号
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 4;//运算符
}

bool IsHigher(char a, char b) {
    if(a == '+' || a == '-')
        return true;
    if((a == '*' || a == '/') && (b == '*' || b == '/'))
        return true;
    return false;
}

void Transform(char zhong[],char hou[]) {
    SqStack S;
    InitStack(S);
    int j = 0;
    char c;
    for(int i = 0; zhong[i] != '#'; i++) {
        switch(dist(zhong[i]))
        {
        case 1:
            hou[j++] = zhong[i];
            break;
        case 2:
            Push(S,zhong[i]);
            break;
        case 3:
            Pop(S,c);
            while(c != '(') {
                hou[j++] = c;
                Pop(S,c);
            }
            break;
        case 4:
            while(!IsEmpty(S)) {
                Pop(S,c);
                if(!IsHigher(zhong[i],c) || c == '(') {
                    Push(S,c);
                    break;
                }
                hou[j++] = c;
            }
            Push(S,zhong[i]);
            break;
        }
    }
    while(!IsEmpty(S)) {
        Pop(S,c);
        hou[j++] = c;
    }
    hou[j++] = '#';
}

int main() {
    char zhong[MaxSize],hou[MaxSize]; // 定义一个字符数组，大小为50
    std::cout << "请输入中缀表达式: (以＃结尾)" << std::endl;
    std::cin.getline(zhong, MaxSize); // 从键盘输入字符并存储到数组a中，最多50个字符（包括'\0'）
    std::cout << "中缀表达式为: " << std::endl;
    for(int i = 0; zhong[i] != '#' ; i++)
        std::cout << zhong[i];
    std::cout << std::endl;

    Transform(zhong,hou);
    std::cout << "后缀表达式为: " << std::endl;
    for(int i = 0; hou[i] != '#' ; i++)
        std::cout << hou[i];
    std::cout << std::endl;


    return 0;
}
