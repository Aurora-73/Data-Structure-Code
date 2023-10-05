#include <iostream>
#include <sstream>
#include <string>

const int MaxSize = 100;  // 假设最大数组长度为10

bool IsMinHeap1(int A[],int n) {
    int temp = A[n+1];
    if(n%2 == 0) 
        A[n+1] = INT_MAX;
    for(int i = n/2; i > 0 ; i--)
        if(A[i] > A[2*i] || A[i] > A[2*i+1]) {
            A[n+1] = temp;
            return false;
        }
    A[n+1] = temp;
    return true;
}

bool IsMinHeap2(int A[],int n){
    if(n%2 == 0){
        if(A[n/2] > A[n])
            return false;
        n = n - 1;    
    }
    for(int i = n/2; i > 0 ; i--)
        if(A[i] > A[2*i] || A[i] > A[2*i+1])
            return false;
    return true;
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
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << (IsMinHeap1(A,A[0]) ? "是小根堆" :"不是小根堆")<< std::endl;
    std::cout << (IsMinHeap2(A,A[0]) ? "是小根堆" :"不是小根堆")<< std::endl;


    return 0;
}
