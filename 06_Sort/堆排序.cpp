#include <iostream>
#include <sstream>
#include <string>

const int MaxSize = 100;  // 假设最大数组长度为10

void HeapAdjust(int A[],int n,int k) {
    int temp = A[k];
    int i = 2*k;
    while(i <= n) {
        if(i < n && A[i + 1] > A[i])
            i++;
        if(A[i] > temp){//这里不应该和A[k]比较，因为我们需要找的是temp的位置，而我们并没有真的把两者互换，我们只是把最大的孩子的值赋给根了，最大的孩子的值并没有变
            A[k] = A[i];
            k = i;
            i = 2*k;
        }
        else break;
    }
    A[k] = temp;
}

void BuildHeap(int A[], int n) {
    for(int i = n/2 ; i > 0; i--){
        HeapAdjust(A, n, i);
        for (int i = 1; i <= A[0]; ++i) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
        }
}

void HeapSort(int A[], int n) {
    BuildHeap(A,n);
    std::cout << "建堆完成" << std::endl;
    for(int i = n; i > 1 ; i--) {
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        HeapAdjust(A,i-1,1);
        for (int i = 1; i <= A[0]; ++i) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
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

    std::cout << "堆排序过程为：" << std::endl;
    HeapSort(A,A[0]);
    // 打印存储在数组中的数据
    std::cout << "堆排序结果为：" << std::endl;
    for (int i = 1; i <= A[0]; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
