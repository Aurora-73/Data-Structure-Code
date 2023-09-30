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
        if(x==-1)
            break;
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        p -> next = s;
        p = s;
    }
    p -> next = NULL;
}

void SelectSort(LinkList  &L) {
    LNode *p,*pre,*maxp,*maxpre,*r;
    r = L;//r是有序部分的最后一个
    while(r->next) {
        maxpre = pre = r;
        maxp = p = r->next;
        while(p) {
            if(p->data > maxp->data) {
                maxp = p;
                maxpre = pre;
            }
            pre = p;
            p = p->next;
        }
        maxpre->next = maxp->next;
        maxp->next = L->next;
        L->next = maxp;
        if(r == L)    r = maxp;
    }
}

int main() {
    LinkList L;
    printf("请输入正数，输入-1表示结束：\n");
    RearInsert(L);

    // 打印链表元素
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    SelectSort(L);
    p = L->next;
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
