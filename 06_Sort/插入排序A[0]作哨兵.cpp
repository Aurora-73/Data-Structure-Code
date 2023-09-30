#include <iostream>
#include <sstream>
#include <string>

const int MaxSize = 100;  // 假设最大数组长度为10

void InsertSort(int A[],int n) {
    int i, j,temp = A[0];
    for(i = 2 ; i <= n ; i++) {
        A[0] = A[i];
        for(j = i - 1 ; A[j] > A[0] ; j--)
            A[j+1] = A[j];
        A[j+1] = A[0];
        for(int i = 1;i <= n;i++)
            std::cout << A[i] << " ";
            std::cout << std::endl;
        }
        A[0] = temp;
}


int main() {
    int A[MaxSize + 1];  // 创建一个固定大小的整数数组，额外一个位置用于存储元素个数

    std::string input;
    std::cout << "请输入用逗号分隔的数组: ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string token;
    int count = 0;  // 数组元素个数计数器

    // 使用逗号分隔符解析输入字符串，并将整数存储在数组中
    while (std::getline(ss, token, ',')) {
        if (count < MaxSize) {
            std::istringstream(token) >> A[count + 1];  // 数组下标从1开始
            count++;
        } else {
            std::cout << "数组已满，无法继续添加元素。" << std::endl;
            break;
        }
    }
    A[0] = count;
    std::cout << "插入排序过程为：" << std::endl;
    InsertSort(A,A[0]);
    // 打印存储在数组中的数据
    std::cout << "插入排序结果为：" << std::endl;
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }

    return 0;
}
