#include <iostream>
#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top[2];
}Stack;

bool Push(Stack &S,int i ,int x){
    if(S.top[0] +1 == S.top[1])
        return false;
    if(i==0)
        S.data[++S.top[0]] = x;
    else if(i == 1)
        S.data[--S.top[0]] =   x;
    else 
        return false;
     return true;   
}

bool Pop(Stack &S,int i,int &x){
    if(i == 0)
        if(S.top[0] == -1)
            return false;
        else 
            x = S.data[S.top[0]--];    
    else if(i == 1)
        if(S.top[1] == MaxSize)
            return false;
        else 
            x = S.data[S.top[1]++];    
    else 
        return false;
     return true;   
}



// 前面的 Stack 结构体和 Push 函数应该放在这里

int main() {
    Stack sharedStack;
    sharedStack.top[0] = -1;  // 初始化栈0的栈顶
    sharedStack.top[1] = MaxSize;  // 初始化栈1的栈顶

    while (true) {
        std::cout << "请选择操作类型 (0 表示弹栈，1 表示压栈，其他数字退出): ";
        int operationType;
        std::cin >> operationType;

        if (operationType != 0 && operationType != 1) {
            std::cout << "退出程序。" << std::endl;
            break;
        }

        std::cout << "请选择要操作的栈 (0 表示栈0，1 表示栈1): ";
        int stackIndex;
        std::cin >> stackIndex;

        if (stackIndex != 0 && stackIndex != 1) {
            std::cout << "无效的栈选择。" << std::endl;
            continue;
        }

        int value;

        if (operationType == 1) {
            std::cout << "请输入要压入栈的值: ";
            std::cin >> value;
            if (Push(sharedStack, stackIndex, value)) {
                std::cout << "成功压入栈" << stackIndex << ": " << value << std::endl;
            } else {
                std::cout << "栈" << stackIndex << "已满，无法压入。" << std::endl;
            }
        } else {
            if (Pop(sharedStack, stackIndex, value)) {
                std::cout << "成功弹出栈" << stackIndex << "，弹出的值为: " << value << std::endl;
            } else {
                std::cout << "栈" << stackIndex << "已空，无法弹出。" << std::endl;
            }
        }
    }

    return 0;
}