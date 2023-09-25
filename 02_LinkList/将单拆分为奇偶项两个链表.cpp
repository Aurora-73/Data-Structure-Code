#include <iostream>

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;


void Divide1(LinkList &A,LinkList &B){
    int i = 1;
    B = (LinkList)malloc(sizeof(LNode));
    LNode *q = A -> next, *tailA = A, *tailB = B;
    while(q != NULL){
        LNode *temp = q -> next;
        if(i%2 == 1){
          	q -> next = tailA -> next;
           tailA -> next = q;
           tailA = q;
         }else{
           q ->next = tailB -> next;
           tailB -> next = q;
           tailB = q;
         }
         q = temp;
         i++;
     }
    tailA -> next = NULL;
    tailB -> next = NULL;
}
 
void Insert(LNode *&N,LNode *&q){
    q -> next = N -> next;
    N -> next = q;
    N = q;
}  

           
void Divide(LinkList &A,LinkList &B){
    int i = 1;
    B = (LinkList)malloc(sizeof(LNode));
    LNode *q = A -> next, *tailA = A, *tailB = B;
    while(q != NULL){
        LNode *temp = q -> next;
        if(i%2 == 1)
          	Insert(tailA,q);
        else
          Insert(tailB,q);
         q = temp;
         i++;
     }
    tailA -> next = NULL;
    tailB -> next = NULL;
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
    LinkList A,B;
    CreateList(A);

    std::cout << "原始链表：" << std::endl;
    PrintList(A);

    Divide(A,B);
    std::cout << "新的A链表：" << std::endl;
    PrintList(A);

    std::cout << "新的B链表：" << std::endl;
    PrintList(B);
    
    // 释放链表内存
    while (A != NULL) {
        LNode* temp = A;
        A = A->next;
        delete temp;
    }

    return 0;
}
