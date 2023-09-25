#include <iostream>
#include <cstdlib> // 添加此头文件以使用 malloc 和 free

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;

void Divide1(LinkList &A,LinkList &B){
    int i = 1;
    B = (LinkList)malloc(sizeof(LNode));
    LNode *q = A -> next, *tailA = A;
    A -> next = NULL;
    B -> next = NULL;
    while(q != NULL){
        LNode *temp = q -> next;
        if(i%2 == 1){
          q -> next = tailA -> next;
           tailA -> next = q;
           tailA = q;
         }else{
           q ->next = B -> next;
           B -> next = q;
         }
         q = temp;
         i++;
     }
    tailA -> next = NULL;
}

void Divide2(LinkList &A,LinkList &B){
    B = (LinkList)malloc(sizeof(LNode));
    LNode *q = A -> next, *r = A, *p;
    A -> next = B -> next = NULL;
    while(q != NULL){
        r -> next = q;
        r = q;
        q = q -> next;
        if(q == NULL)
            break;
        p = q-> next;
        q -> next = B -> next;
        B -> next = q;
        q = p;
     }
    r -> next = NULL;
}

// 创建单链表函数
void CreateList(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    LNode* p = L; // 修改变量名以匹配后续使用
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
    LNode* p = L->next; // 修改变量名以匹配后续使用
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkList A1, B1, A2, B2;
    CreateList(A1);
    // 复制 A1 以创建 A2
    A2 = new LNode;
    A2->next = NULL;
    LNode* p = A1->next;
    LNode* p2 = A2;
    while (p != NULL) {
        LNode* newNode = new LNode;
        newNode->data = p->data;
        newNode->next = NULL;
        p2->next = newNode;
        p2 = newNode;
        p = p->next;
    }

    std::cout << "原始链表：" << std::endl;
    PrintList(A1);

    Divide1(A1, B1);
    Divide2(A2, B2);

    std::cout << "新的A1链表：" << std::endl;
    PrintList(A1);

    std::cout << "新的B1链表：" << std::endl;
    PrintList(B1);

    std::cout << "新的A2链表：" << std::endl;
    PrintList(A2);

    std::cout << "新的B2链表：" << std::endl;
    PrintList(B2);

    // 释放链表内存
    while (A1 != NULL) {
        LNode* temp = A1;
        A1 = A1->next;
        delete temp;
    }

    while (A2 != NULL) {
        LNode* temp = A2;
        A2 = A2->next;
        delete temp;
    }

    free(B1); // 释放B1链表内存
    free(B2); // 释放B2链表内存

    return 0;
}
