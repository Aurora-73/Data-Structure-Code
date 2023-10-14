#include <iostream>

using namespace std;

// 定义链表节点结构体
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

void PrintList(LinkList L) {
    // 打印链表元素
    LNode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 尾插法建立单链表
void RearInsert(LinkList& L, int& n) {
    L = (LNode*)malloc(sizeof(LNode));
    LNode* s, * p = L;
    int x;
    while (true) {
        cin >> x;
        if (x == 9999)
            break;
        s = (LNode*)malloc(sizeof(LNode));
        n++;
        s->data = x;
        p->next = s;
        p = s;
    }
    p->next = NULL;
}

void Merge(LinkList& A, LinkList& B) {
    LinkList pa = A->next;
    LNode* r = A;
    LinkList pb = B->next;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    r->next = pa ? pa : pb;
}


void MergeSort(LinkList& L1, int n) {
    if (n <= 1)
        return;
    LNode* p = L1->next;
    LinkList L2 = new LNode;
    int mid = n / 2;
    for (int i = 1; i < mid; i++)//i应该从1开始
        p = p->next;
    L2->next = p->next;
    p->next = NULL;
    cout << "分开后的L1为" <<endl;
    PrintList(L1);
    cout << "分开后的L2为" <<endl;
    PrintList(L2);
    MergeSort(L1, mid);
    MergeSort(L2, n - mid);
    Merge(L1, L2);
    cout << "合并结果为" <<endl;
    PrintList(L1);
}

/*
void MergeSort(LinkList& L1, int n) {
    if (n <= 1)
        return;
    LNode* p = L1->next;
    LinkList L2 = new LNode;
    int mid = n / 2;
    for (int i = 1; i < mid; i++)//i应该从1开始
        p = p->next;
    L2->next = p->next;
    p->next = NULL;
    MergeSort(L1, mid);
    MergeSort(L2, n - mid);
    Merge(L1, L2);
}
*/

int main() {
    LinkList L;
    int n = 0;
    cout << "请输入数字，输入9999表示结束：" << endl;
    RearInsert(L, n);
    cout << "元素个数为" << n << endl;
    PrintList(L);

    MergeSort(L, n);
    cout << "归并排序结果为" << endl;

    PrintList(L);
    LNode* p;
    // 释放链表内存
    while (L != NULL) {
        p = L;
        L = L->next;
        free(p);
    }

    return 0;
}
