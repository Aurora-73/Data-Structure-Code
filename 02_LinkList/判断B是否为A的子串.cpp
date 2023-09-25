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

bool IsSub(LinkList &A,LinkList &B){
    LNode *pos = A -> next , *a,*b;
    bool flag = false;
    while( pos && !flag){
        b = B -> next;
        a = pos;
        while(a && b && b -> data == a -> data){
               b = b -> next;
               a = a -> next;
        }
        flag = !b;
        pos = pos -> next;   
    }
    return flag; 
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
    
    std::cout << (IsSub(A,B)? "是子串":"不是子串")<< std::endl;

    return 0;
}