#include <iostream>
#include <stdbool.h>

#define MAX_SIZE 100

using namespace std;

typedef struct {
    int data[MAX_SIZE + 1]; // 数组从下标1开始
    int size;
} PriorityQueue;

// 初始化优先队列
void Init(PriorityQueue &Q) {
    Q.size = 0;
}

// 入队操作
void Push(PriorityQueue &Q, int x) {
    if (Q.size >= MAX_SIZE) {
        cout << "队列已满，无法入队" << endl;
        return;
    }
    int i = ++Q.size;//首先假设当前元素应该插入到最后一个位置，但是并不真的插入，也可将i理解为当前的空位，和待插入的位置。
    while (i > 1 && x < Q.data[i / 2]) {
        Q.data[i] = Q.data[i / 2];
        i /= 2;
    }//如果待插入的值比当前插入位置的父结点小，则待插入的值应该做父结点，将待插入位置的父结点放入当前空位，将待插入位置改为父结点的位置。
    Q.data[i] = x;//跳出循环说明当前插入的位置的父结点比待插入的值小，可以插入当前位置中，插入
}

// 出队操作
bool Pop(PriorityQueue &Q, int &x) {
    if (Q.size == 0) {
        cout << "队列为空，无法出队" << endl;
        return false;
    }
    x = Q.data[1];
    int tmp = Q.data[Q.size--];//首先记录最后一个值，将队列大小减一，重新插入这个值
    int i = 1;//i为当前空位的下标
    int j = 2;//j为i的左右孩子中的一个
    while (j <= Q.size) {
        if (j < Q.size && Q.data[j] > Q.data[j + 1]) {
            j++;//将j调整为i的左右孩子中较大的
        }
        if (tmp <= Q.data[j]) {
            break;
        }//若待插入的值可以放到当前空位则跳出循环
        Q.data[i] = Q.data[j];//执行这里说明当前空位的孩子中有比待插入值小的，将孩子中小的放入空位中
        i = j;//空位的记录更改为两个孩子中小的一个
        j *= 2;//修改空位的孩子的下标
    }
    Q.data[i] = tmp;//将最后一个值插入到合适的位置
    return true;
}

// 获取队首元素
bool Top(PriorityQueue &Q, int &x) {
    if (Q.size == 0) {
        cout << "队列为空" << endl;
        return false;
    }
    x = Q.data[1];
    return true;
}

// 获取队列大小
int Size(PriorityQueue &Q) {
    return Q.size;
}

// 检查队列是否为空
bool Empty(PriorityQueue &Q) {
    return Q.size == 0;
}

int main() {
    PriorityQueue Q;
    Init(Q);
    int x = 0;
    cout << "请依次输入待排序元素，输入-1时停止" << endl;
    while (x != -1) {
        cin >> x;
        if(x == -1)
            break;
        Push(Q, x);
    }
    cout << "排序结果为：" << endl;
    while (!Empty(Q)) {
        Pop(Q, x);
        cout << x << " ";
    }

    return 0;
}