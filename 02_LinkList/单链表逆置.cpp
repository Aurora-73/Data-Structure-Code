#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;


void Reverse0(LinkList &L){
    if (L == NULL || L->next == NULL) {
        // 空链表或只有一个节点，无需逆置，前一个判断是必要的，否则空指针异常
        return;
    }

    LNode *p = L->next->next, *q = L->next;
    L->next = NULL;

    while (q != NULL) {
        LNode *temp = q->next;
        q->next = L->next;
        L->next = q;
        q = temp;
    }
}

void Reverse1(LinkList &L) {
    if (L == NULL || L->next == NULL) {
        // 空链表或只有一个节点，无需逆置，前一个判断是必要的，否则会空指针异常
        return;
    }

    LNode *p = L->next->next, *q = L->next;
    L->next = NULL;

    while (true) {
        q->next = L->next;
        L->next = q;
        q = p;
        if (p == NULL) {
            break;
        }
        p = p->next;
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

    Reverse0(myList);

    std::cout << "逆置一次后的链表：" << std::endl;
    PrintList(myList);

    Reverse1(myList);
    std::cout << "逆置两次后的链表：" << std::endl;
    PrintList(myList);
    
    // 释放链表内存
    while (myList != NULL) {
        LNode* temp = myList;
        myList = myList->next;
        delete temp;
    }

    return 0;
}
