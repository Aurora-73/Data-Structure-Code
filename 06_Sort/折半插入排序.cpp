#include <iostream>
#include <sstream>
#include <string>
const int MaxSize = 100;// 假设最大数组长度为100

void BInsertSort(int A[],int n) {
    int i,l,h,j,mid,temp;
    for(i = 2; i <= n; i++) {
        l = 1;
        h = i - 1;
        temp = A[i];
        while(l <= h) {
            mid = (l+h)/2;
            if(A[mid] < temp)
                l = mid + 1;
            else if(A[mid] > temp)
                h = mid - 1;
            else
                break;
        }
        for(j = i - 1 ; j >= l; j--)
            A[j+1] = A[j];
        A[l] = temp;
        for (int i = 1; i <= A[0]; ++i) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
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
    std::cout << "折半插入排序过程为：" << std::endl;
    BInsertSort(A,count);
    // 打印存储在数组中的数据
    std::cout << "折半插入排序结果为：" << std::endl;
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}