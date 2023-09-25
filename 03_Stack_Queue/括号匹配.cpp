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

bool BracketsCheck(char a[]){
    char x;
    SqStack S;
    InitStack(S);
    for(int i = 0 ; a[i] != '\0' ; i++){
        switch(a[i]){
              case '(':  
              case '[':
              case '{':
                  Push(S,a[i]);
                  break;
              case ')':
              case ']':
              case '}':
                  if(IsEmpty(S))
                      return false;
                  Pop(S,x);
                  if((x+1 != a[i]) && (x+2 != a[i]))
                      return false;
                      break;    
              default:    
                  break;
        }
    }
    return IsEmpty(S);
}



int main() {
    char a[MaxSize]; // 定义一个字符数组，大小为50
    std::cout << "请输入一串字符: ";
    std::cin.getline(a, MaxSize); // 从键盘输入字符并存储到数组a中，最多50个字符（包括'\0'）

    // 打印输入的字符串
    std::cout << "匹配" <<(BracketsCheck(a) ? "" : "不" )<< "成功"<< std::endl;

    return 0;
}

/*
第52行解释：
因为如果运行到了这个判断条件，就说明x必定为左括号，而a[i]必定为右括号。
这时只需要判断他们是否配对即可，而在ASCII值中，()相差1，[]和{}相差2，且不同种类括号之间不相邻。
因此如果两者相差1或者2则说明成功，否则则失败

以下是括号和其对应的ASCII值：


- '(' 左圆括号的ASCII值为 40
- ')' 右圆括号的ASCII值为 41
- '[' 左方括号的ASCII值为 91
- ']' 右方括号的ASCII值为 93
- '{' 左大括号的ASCII值为 123
- '}' 右大括号的ASCII值为 125


合法的括号匹配:
1. "(9＋1＋2)"                     => 合法
2. "{[(9+2)-1]*3}/4"        => 合法
3. "(1＋2{－3[＋1(－5＊2)]})"               => 合法


不合法的括号匹配:
4. "([)]"                   => 不合法
5. "(]"                     => 不合法
6. "[(])"                   => 不合法
7. "{[("                    => 不合法
8. "((())"                  => 不合法

*/