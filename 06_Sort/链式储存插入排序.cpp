#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 尾插法建立单链表
void RearInsert(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *p =L;
    int x;
    while(true) {
        scanf("%d",&x);
        if(x==9999)
            break;
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        p -> next = s;
        p = s;
    }
    p -> next = NULL;
}

void InsertSort(LinkList &L) {
    if(!L || !L->next)    return;
    LNode *pre,*p,*q =L->next->next,*r;
    L->next -> next = NULL;//断链应该在循环外面
    while(q) {
        pre = L;
        p = L-> next;
        while(p && p->data < q-> data) {
            pre = p;
            p = p->next;
        }
        r = q -> next;
        q -> next = p;
        pre -> next = q;
        q = r;
    }
}

int main() {
    LinkList L;
    printf("请输入数字，输入9999表示结束：\n");
    RearInsert(L);

    // 打印链表元素
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    
    InsertSort(L);
    printf("排序结果为\n");
    
    p = L -> next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 释放链表内存
    while (L != NULL) {
        p = L;
        L = L->next;
        free(p);
    }

    return 0;
}
