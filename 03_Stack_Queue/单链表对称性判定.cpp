#include <iostream>
#include <typeinfo>
#include <cstdlib> // 包含用于转换的头文件

typedef char ElemType; // 使用 ElemType 定义链表类型，可以在int和char间切换，当其为char是若输出整数则为对应的ASCII码，小于34时无字符输出

// 输入函数，根据用户输入的类型保存为int型或将char类型转换为int型
int getInput() {
    char input[256];
    std::cin.getline(input, sizeof(input));
    // 尝试将输入解析为整数
    int result;

    if (std::isdigit(input[0]) || (input[0] == '-' && std::isdigit(input[1]))) {
        result = std::atoi(input); // 转换为整数
    } else if (std::isalpha(input[0])) {
        result = static_cast<int>(input[0]); // 将字符转换为对应的ASCII值
    } else {
        std::cerr << "无法识别的输入" << std::endl;
        result = 0; // 无法识别的输入，设置为默认值
    }

    return result;
}

struct LNode {
    ElemType data;
    LNode* next;
};

typedef LNode* LinkList;

// 创建单链表函数
int CreateList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    LNode* p = L;
    int x;
    int n = 0;
    std::cout << "请输入" << ( (typeid(ElemType).name()[0] == 'c' ) ? "char" : "int")<< "类型的链表，以-1结束输出"<< std::endl;
    while (true) {
        x = getInput(); // 使用 ElemType 作为数据类型
        if (x == -1) {
            break;
        }
        LNode* newNode = new LNode;
        newNode->data = (ElemType)x; // 转换为 ElemType 类型
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
        n++;
    }
    return n;
}


// 打印链表函数
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

struct Linknode {
    ElemType data;
    Linknode* next;
};

typedef Linknode* LiStack;

// 初始化链栈
void InitStack(LiStack& s) {
    s = nullptr;
}

// 判断链栈是否为空
bool IsEmpty(LiStack s) {
    return s == NULL;
}

// 入栈操作
bool Push(LiStack& s, ElemType x) {
    Linknode* newNode = new Linknode;
    if (newNode == nullptr) {
        std::cerr << "内存分配失败，入栈失败" << std::endl;
        return false;
    }
    newNode->data = x;
    newNode->next = s;
    s = newNode;
    return true;
}

// 出栈操作
bool Pop(LiStack &s, ElemType &x) {
    if (IsEmpty(s)) {
        std::cerr << "栈为空，无法出栈" << std::endl;
        return false;
    }
    Linknode* temp = s;
    x = temp->data;
    s = s->next;
    delete temp;
    return true;
}

// 获取栈顶元素
bool GetTop(LiStack s, ElemType &x) {
    if (IsEmpty(s)) {
        std::cerr << "栈为空，无法获取栈顶元素" << std::endl;
        return false;
    }
    x = s->data;
    return true;
}

bool IsSym(LinkList L, int n) {
    if (!n) return true;
    char *S = new char[n/2];
    int i;
    LNode *p = L->next;

    for (i = 0; i < n / 2; i++) {
        S[i] = p->data;
        p = p->next;
    }
    i--;
    if(n%2)    p = p -> next;
    while(p && S[i] == p->data) {
        p = p->next;
        i--;
    }
    if(p) return false;
    return true;
}

int main() {
    LinkList myList;
    int n = CreateList(myList);

    std::cout << "原始链表：" << std::endl;
    PrintList(myList);

    std::cout << (IsSym(myList, n) ? "对称" : "不对称") << std::endl;

    // 释放链表内存
    while (myList != NULL) {
        LNode* temp = myList;
        myList = myList->next;
        delete temp;
    }

    return 0;
}
