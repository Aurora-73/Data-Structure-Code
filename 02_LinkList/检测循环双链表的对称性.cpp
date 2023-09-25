#include <iostream>

using namespace std;

// 循环双链表节点的定义
struct DNode {
    int data;
    DNode *next;
    DNode *prior;
    DNode(int val) : data(val), next(nullptr), prior(nullptr) {}
};

// 创建循环双链表
DNode* CreateDLinkList() {
    DNode *head = new DNode(0);  // 创建头节点
    DNode *tail = head;  // 尾指针，初始指向头节点

    int val;
    cout << "请输入链表节点的值（输入-1结束）：";
    cin >> val;

    while (val != -1) {
        DNode *newNode = new DNode(val);
        tail->next = newNode;
        newNode->prior = tail;
        tail = newNode;
        cout << "请输入链表节点的值（输入-1结束）：";
        cin >> val;
    }

    // 将链表首尾相连，形成循环链表
    tail->next = head;
    head->prior = tail;

    return head;
}

// 检测循环双链表的对称性
bool IsSym0(DNode *L){
    DNode *p = L -> next,*q = L -> prior;
    while(p != q && q -> next != p){
        if(p -> data != q -> data)
            return false;
        p = p -> next;
        q = q -> prior;
    }
    return true;
}

bool IsSym1(DNode *L) {
    DNode *front = L->next;  // 前向指针
    DNode *back = L->prior;  // 后向指针

    while (front != back && front->prior != back) {
        if (front->data != back->data) {
            return false;
        }
        front = front->next;
        back = back->prior;
    }
    return true;
}


int main() {
    DNode* head = CreateDLinkList();
    
    if (IsSym0(head)) {
        cout << "你认为对称" << endl;
    } else {
        cout << "你认为不对称" << endl;
    }
    if (IsSym1(head)) {
        cout << "GPT认为对称" << endl;
    } else {
        cout << "GPT认为不对称" << endl;
    }

    return 0;
}
