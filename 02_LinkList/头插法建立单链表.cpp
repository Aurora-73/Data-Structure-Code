#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法建立单链表
void HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode)); // 初始化链表头节点
    L->next = NULL;

    while (true) {
        scanf("%d", &x);
        if (x == -1) break;
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
}

int main() {
    LinkList L;
    printf("请输入正数，输入-1表示结束：\n");
    HeadInsert(L);

    // 打印链表元素
    LNode *p = L->next;
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
