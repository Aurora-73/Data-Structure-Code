//头指针指向队头，尾指针指向队尾下一个，牺牲一个元素来区分队空队满。
#include <iostream>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

bool IsEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int HowMany(SqQueue Q) {
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

int main() {
    SqQueue Q;
    InitQueue(Q);

    int choice, element;

    while (true) {
        std::cout << "\n当前队列中元素个数：" << HowMany(Q) << std::endl;
        std::cout << "请选择操作：" << std::endl;
        std::cout << "1. 入队" << std::endl;
        std::cout << "2. 出队" << std::endl;
        std::cout << "3. 退出程序" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "请输入要入队的元素：";
                std::cin >> element;
                if (EnQueue(Q, element)) {
                    std::cout << "入队成功！" << std::endl;
                } else {
                    std::cout << "队列已满，无法入队！" << std::endl;
                }
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

    return 0;
}
