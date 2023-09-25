#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;


void Del_x(LinkList &L,int x){
    LNode *p = L;
    while(p->next){
        if(p->next->data == x){
            LNode *temp = p -> next;
            p -> next = p -> next -> next;
            free(temp);
            }
        else
            p = p -> next;
    }
}

// 创建单链表函数
void CreateList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    LNode* p = L;
    int x;
    std::cout << "请输入链表元素，以-1结束输入：" << std::endl;
    while (true) {
        std::cin >> x;
        if (x == -1) {
            break;
        }
        LNode* newNode = new LNode;
        newNode->data = x;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
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

int main() {
    LinkList myList;
    CreateList(myList);

    std::cout << "原始链表：" << std::endl;
    PrintList(myList);
    
    std::cout << "请输入待删除值" << std::endl;
    int x;
    std::cin >> x;
    Del_x(myList,x);
    std::cout << "处理后的链表：" << std::endl;
    PrintList(myList);
    
    // 释放链表内存
    while (myList != NULL) {
        LNode* temp = myList;
        myList = myList->next;
        delete temp;
    }

    return 0;
}
    