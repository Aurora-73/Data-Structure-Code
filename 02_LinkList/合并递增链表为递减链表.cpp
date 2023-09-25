//合并递增链表为递减链表
#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;

void Insert(LNode *&p,LNode *&c){
    LNode *temp = p -> next;
    p -> next = c -> next;
    c -> next = p;
    p = temp;
}//头插法

LinkList Merge(LinkList &A,LinkList &B){
    LinkList C = (LinkList)malloc(sizeof(LNode));
    LNode *a = A -> next, *b =B -> next;
    while(a!=NULL && b!=NULL){
        if(a->data < b->data)//仍然是取小的，因为链表是递增链表，只能选择最小的
            Insert(a,C);
        else
            Insert(b,C);
    }
    if(b!=NULL) a = b;//归一操作，后续一次就行
    while(a) Insert(a,C);//依次头插，自动逆序
    return C;
}

// 创建单链表函数
void CreateList(LinkList &L,char c) {
    L = new LNode;
    L->next = NULL;
    LNode* p = L;
    int x;
    std::cout << "请输入链表"<< c <<"的元素，以-1结束输入：" << std::endl;
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
    LinkList A,B;
    CreateList(A,'A');
    CreateList(B,'B');

    std::cout << "原始链表A：" << std::endl;
    PrintList(A);
    
    std::cout << "原始链表B：" << std::endl;
    PrintList(B);
    
    std::cout << "合并后的链表：" << std::endl;
    PrintList(Merge(A,B));

    return 0;
}