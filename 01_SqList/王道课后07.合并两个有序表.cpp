//合并两个有序表
#include <iostream>

const int MAX_SIZE = 100; // 请根据实际情况修改最大长度

struct Sqlist {
    int data[MAX_SIZE];
    int length;
};

void merge(Sqlist A, Sqlist B, Sqlist &C) {
    int i = 0, j = 0, k = 0;
    C.length = A.length + B.length;

    while (i < A.length && j < B.length) {
        if (A.data[i] < B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }

    while (i < A.length)
        C.data[k++] = A.data[i++];

    while (j < B.length)
        C.data[k++] = B.data[j++];
}

int main() {
    Sqlist A, B, C;
    
    // 输入第一个有序顺序表 A
    std::cout << "请输入第一个有序顺序表 A 的长度: ";
    std::cin >> A.length;
    std::cout << "请输入 " << A.length << " 个整数:" << std::endl;
    for (int i = 0; i < A.length; i++) {
        std::cin >> A.data[i];
    }

    // 输入第二个有序顺序表 B
    std::cout << "请输入第二个有序顺序表 B 的长度: ";
    std::cin >> B.length;
    std::cout << "请输入 " << B.length << " 个整数:" << std::endl;
    for (int i = 0; i < B.length; i++) {
        std::cin >> B.data[i];
    }

    // 合并两个有序顺序表到 C
    merge(A, B, C);

    // 输出合并后的顺序表 C
    std::cout << "合并后的有序顺序表 C：" << std::endl;
    for (int i = 0; i < C.length; i++) {
        std::cout << C.data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
