//循环数组前移p个位置
#include <iostream>

void Reverse(int A[], int m, int n) {
    int temp;
    for (int i = 0;i < (n-m+1)/2; i++) {
        temp = A[m + i];
        A[m + i] = A[n -i];
        A[n - i] = temp;
    }
}

void Exchange(int A[], int Length_A, int Length_B) {
    // 调用伪代码中的 Exchange 函数
    Reverse(A, 0, Length_A + Length_B - 1);
    Reverse(A, 0, Length_B - 1);
    Reverse(A, Length_B, Length_A + Length_B - 1);
}

int main() {
    int Length_A, Length_B;
    
    std::cout << "请输入数组 A 的长度: ";    
    std::cin >> Length_A;
    
    std::cout << "请输入数组 B 的长度: ";
    std::cin >> Length_B;

    // 创建一个足够大的数组以容纳数组 A 和 B
    int A[Length_A + Length_B];

    // 输入数组 A 的元素
    std::cout << "请输入数组 A 的元素:" << std::endl;
    for (int i = 0; i < Length_A; i++) {
        std::cin >> A[i];
    }

    // 输入数组 B 的元素
    std::cout << "请输入数组 B 的元素:" << std::endl;
    for (int i = Length_A; i < Length_A + Length_B; i++) {
        std::cin >> A[i];
    }

    // 输出原始数组 A
    std::cout << "原始数组 A：" << std::endl;
    for (int i = 0; i < Length_A + Length_B; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    Exchange(A, Length_A, Length_B);

    // 输出交换后的数组 A
    std::cout << "交换后的数组 A：" << std::endl;
    for (int i = 0; i < Length_A + Length_B; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
