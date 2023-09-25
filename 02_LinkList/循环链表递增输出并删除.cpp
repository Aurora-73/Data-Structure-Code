#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;

// 打印链表函数
void PrintList(LinkList L) {
    LNode* p;
    if(L)
       p = L->next;
    else std::cout << "链表为空" << std::endl;
    while (p != L) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void FindMinPrintDel(LinkList &L) {
    LNode *p = L, *pos = L->next, *prior = L;
    int min = pos->data;
    std::cout << "开始排序" <<std::endl;
    while (p->next != p) {
        if (p->next == L) {
            std::cout << pos->data << "  ";
            prior->next = pos->next;
            free(pos);
            pos = L->next;
            prior = L;
            min = pos->data;
        } else if (p->next->data < min) {
            prior = p;
            pos = p->next;
            min = pos->data;
        }
        p = p->next;
    }
    std::cout << std::endl;
    LNode *temp = L;
    L = NULL;
    free(temp);
}

// 创建循环单链表函数
void CreateList(LinkList &L) {
    L = new LNode;
    L->next = L; // 将头节点指向自身，形成一个空的循环单链表
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
        newNode->next = L; // 将新节点的next指向头节点，形成循环
        p->next = newNode;
        p = newNode;
    }
}


int main() {
    LinkList myList;
    CreateList(myList);

    std::cout << "原始链表：" << std::endl;
    PrintList(myList);

    FindMinPrintDel(myList);
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
