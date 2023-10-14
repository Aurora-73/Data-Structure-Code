//使用循环单链表实现队列，设立尾指针，队尾的next域就是队头，同时方便删除和插入。
#include <iostream>

#define MaxSize 50
typedef int ElemType;

typedef struct QNode {
    int data;
    QNode *next;
} QNode;

typedef struct LinkQueue {
    QNode *rear;
} LiQueue;

void InitQueue(LiQueue &Q) {
    Q.rear = NULL;
}

void EnQueue(LiQueue &Q,int x) {
    QNode *p = new QNode;
    p -> data = x;
    if(Q.rear) {
        p -> next = Q.rear -> next;
        Q.rear -> next = p;
    } else {
        p -> next = p;
    }
    Q.rear = p;
}

bool DeQueue(LiQueue &Q,int &x) {
    if(!Q.rear)
        return false;
    QNode *p = Q.rear -> next;
    x = p -> data;
    if(Q.rear == p) 
        Q.rear = NULL;
    else
        Q.rear -> next = p -> next;
    delete p;
    return true;
}


bool IsEmpty(LiQueue Q) {
    return !Q.rear;
}

int main() {
    LiQueue Q;
    InitQueue(Q);

    int choice, element;

    while (true) {
        std::cout << "请选择操作：" << std::endl;
        std::cout << "1. 入队" << std::endl;
        std::cout << "2. 出队" << std::endl;
        std::cout << "3. 退出程序" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "请输入要入队的元素：";
            std::cin >> element;
            EnQueue(Q, element);
            std::cout << "入队成功！" << std::endl;
            break;

        case 2:
            if (!IsEmpty(Q)) {
                DeQueue(Q, element);
                std::cout << "出队元素：" << element << std::endl;
            } else {
                std::cout << "队列为空，无法出队！" << std::endl;
            }
            break;

        case 3:
            std::cout << "程序已退出。" << std::endl;
            return 0;

        default:
            std::cout << "无效的选择，请重新选择。" << std::endl;
        }
    }

    while (!IsEmpty(Q)) {
        DeQueue(Q, element);    // 释放头节点
    }

    std::cout << "程序已退出。" << std::endl;
    return 0;

}
