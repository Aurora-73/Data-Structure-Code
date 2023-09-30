#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组大小

void InsertSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = A[i], j = i - 1;
        for (; j >= 0 && A[j] > temp; j--)
            A[j + 1] = A[j];
        A[j + 1] = temp;
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;

    }
}

int main() {
    std::string input;
    std::cout << "请输入以逗号分隔的数字: ";
    std::getline(std::cin, input);

    int A[MaxSize];
    int count = 0;

    std::istringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (count < MaxSize) {
            try {
                int num = std::stoi(token);
                A[count] = num;
                count++;
            } catch (const std::invalid_argument& e) {
                std::cerr << "无效的数字: " << token << std::endl;
            }
        } else {
            std::cerr << "数组已满，无法再添加更多元素。" << std::endl;
            break;
        }
    }
    std::cout << "插入排序过程为: \n";
    // 使用插入排序对数组进行排序
    InsertSort(A, count);

    std::cout << "插入排序结果为 \n";
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
