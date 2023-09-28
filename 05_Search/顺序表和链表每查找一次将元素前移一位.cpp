#include <iostream>

// 定义顺序表结构
struct Sqlist {
    int data[100];
    int length;
};

// 定义链表结构
typedef struct LNode {
    int data;
    LNode* next;
}*Linklist;

void SChange(Sqlist &L,int x){
    if(L.data[0]==x)    return;
    for(int i = 0;i < L.length;i++){
        if(L.data[i] == x){
            int temp = L.data[i];
            L.data[i] = L.data[i-1];
            L.data[i-1] = temp;
            return;
        }
    }
}

void LChange(Linklist &L,int x){
    LNode *p = L,*pre = NULL;
    if(p->next->data == x)    return;
    while(p->next){
        if(p->next->data == x){
            LNode *temp = p -> next;
            pre->next = temp;
            p->next = temp->next;
            temp ->next = p;
            return;//若使用break并将这一段移动到括号外面则需要判断p是否为空，否则第32行的代码闪退
        }    
         pre = p;
         p = p -> next;       
    } 
}

// 函数：输出顺序表
void PrintSqlist(const Sqlist& L) {
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << " ";
    }
    std::cout << std::endl;
}

// 函数：输出链表
void PrintLinklist(LNode* L) {
    LNode* p = L->next;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    Sqlist sqlist;
    LNode *linklist = new LNode,*r = linklist;
    linklist->next = nullptr;

    std::cout << "请输入元素，输入-1结束：" << std::endl;
    int num;
    sqlist.length = 0;
    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        sqlist.data[sqlist.length++] = num;

        LNode* newNode = new LNode;
        newNode->data = num;
        newNode->next = NULL;
        r->next = newNode;
        r = newNode;
    }

    std::cout << "顺序表：";
    PrintSqlist(sqlist);
    std::cout << "链表：";
    PrintLinklist(linklist);

    std::cout << "请输入要查找的元素，输入-1结束：" << std::endl;
    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        SChange(sqlist, num);
        LChange(linklist, num);

        std::cout << "顺序表：";
        PrintSqlist(sqlist);
        std::cout << "链表：";
        PrintLinklist(linklist);
    }

    // 释放链表内存
    LNode* p = linklist;
    while (p) {
        LNode* temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}
