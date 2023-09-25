#include <iostream>

// 定义顺序表结构
struct SqList {
    int data[100]; // 用数组模拟顺序表
    int length;    // 顺序表的当前长度
};

// 查找、交换、插入函数
void SearchSwapInsert(SqList &L, int x) {
    int low = 0, high = L.length - 1, mid, index = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == x) {
            index = mid;
            break;
        } else if (L.data[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (index != -1 && index != L.length - 1) {
        int temp = L.data[index];
        L.data[index] = L.data[index + 1];
        L.data[index + 1] = temp;
    }
    if (index == -1) {
        for (int i = L.length - 1; x < L.data[i] ; i--) {
            L.data[i + 1] = L.data[i];
        }
        L.data[high + 1] = x;
        L.length++;
    }// 这里的判断条件也可以是 i > high
}

int main() {
    SqList L;

    // 从键盘输入有序表的元素
    std::cout << "请输入有序表的元素个数: ";
    std::cin >> L.length;
    std::cout << "请输入有序表的元素: ";
    for (int i = 0; i < L.length; i++) {
        std::cin >> L.data[i];
    }

    // 输入要查找或插入的元素x
    int x;
    std::cout << "请输入要查找或插入的元素x: ";
    std::cin >> x;

    // 调用查找、交换、插入函数
    SearchSwapInsert(L, x);

    // 输出结果
    std::cout << "处理后的有序表: ";
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
