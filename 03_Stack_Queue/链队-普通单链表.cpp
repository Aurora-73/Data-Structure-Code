//使用设立首尾指针的单链表实现队列，带头结点，队头就是表头，队尾就是表尾（表头容易插入和删除，但是表尾只容易插入，不容易删除）
#include <iostream>

#define MaxSize 50
typedef int ElemType;

typedef struct QNode {
    int data;
    QNode *next;
} QNode;

typedef struct LinkQueue {
    QNode *front,*rear;
} LiQueue;

void InitQueue(LiQueue &Q) {
    Q.front = Q.rear = new QNode;//带头结点可以统一插入删除操作
    Q.front-> next = NULL;
}

void EnQueue(LiQueue &Q,int x) {
    QNode *p = new QNode;
    p -> data = x;
    p -> next = NULL;
    Q.rear -> next = p;
    Q.rear = p;
}

bool DeQueue(LiQueue &Q,int &x) {
    if(Q.rear == Q.front)
        return false;
    QNode *p = Q.front -> next;
    x = p -> data;
    Q.front -> next = p -> next;
    if(Q.rear == p) {
        Q.rear = Q.front;
    }
    delete p;
    return true;
}

bool IsEmpty(LiQueue Q) {
    return Q.rear == Q.front;
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
    if (Q.front != NULL) {
        free(Q.front);
    }
    std::cout << "程序已退出。" << std::endl;
    return 0;

}
