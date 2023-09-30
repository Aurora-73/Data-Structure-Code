#include <iostream>
#include <sstream>
#include <string>
const int MaxSize = 100;// 假设最大数组长度为100

void ShellSort(int A[], int n) {
    int i,j,d,temp;
    for(d = n / 2 ; d  >= 1 ; d = d / 2) {
        for(i = d + 1; i <=n ; i++) {
            if(A[i] < A[i - d]) {
                temp = A[i];
                for(j = i - d ; j > 0 && A[j] > temp ; j -= d)
                    A[j + d] = A[j];
                A[j + d] = temp;
            }
            for (int i = 1; i <= A[0]; ++i) {
                std::cout << A[i] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int A[MaxSize + 1];
    // 创建一个固定大小的整数数组，额外一个位置用于存储元素个数
    std::string input;
    std::cout << "请输入用逗号分隔的数组: ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string token;
    int count = 0;
    // 数组元素个数计数器
    // 使用逗号分隔符解析输入字符串，并将整数存储在数组中
    while (std::getline(ss, token, ',')) {
        if (count < MaxSize) {
            std::istringstream(token) >> A[count + 1];
            // 数组下标从1开始
            count++;
        }
        else {
            std::cout << "数组已满，无法继续添加元素。" << std::endl;
            break;
        }
    }
    std::cout << "数组创建成功" << std::endl;
    A[0] = count;
    std::cout << "数组为：" << std::endl;
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "希尔排序过程为：" << std::endl;
    ShellSort(A,count);
    // 打印存储在数组中的数据
    std::cout << "希尔排序结果为：" << std::endl;
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }
    return 0;
}