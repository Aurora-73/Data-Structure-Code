#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;

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

void PrintDelMin(LinkList &L){
    LNode *p = L -> next, *pos = L -> next ,
                    *prior = L;
    int min = pos -> data;
    while(p->next){
        if(p->next->data < min){
            pos = p->next;
            prior = p;
            min = p->next->data;
        }
        p = p->next;
    }
    prior -> next = pos -> next;
    std::cout << pos -> data << "  ";
    free(pos);
}

void AllPDM(LinkList &L){
    while(L-> next)
        	PrintDelMin(L);
    std::cout << std::endl;
    free(L);
    L = NULL;
}

// 打印链表函数
void PrintList(LinkList L) {
    LNode* p;
    if(L) p = L -> next;
    else std::cout << "L为空" << std::endl;
    while (p != NULL) {
        std::cout << p->data << "  ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkList myList;
    CreateList(myList);

    std::cout << "原始链表：" << std::endl;
    PrintList(myList);

    std::cout << "递增输出链表为：" << std::endl;
    AllPDM(myList);
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
    