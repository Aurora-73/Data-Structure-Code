//查找在Size个整数中最小的未出现的整数
#include <iostream>
#define Size 8

// 定义顺序表结构
struct SqList {
    int data[Size]; // 用数组模拟顺序表
    int length;    // 顺序表的当前长度
};

// 查找、交换、插入函数
int FindMissMin(SqList &L) {
    int B[Size] = {0} , i = 0;
    for(i = 0; i < L.length ; i++)
       if(L.data[i] > 0 && L.data[i] <= L.length)
            B[L.data[i]-1] = 1;
    for(i = 0; i < L.length ;i++)
        if(B[i] == 0)
            return i+1 ;
    return i+1 ;
}

int main() {
    SqList L;
    // 从键盘输入有序表的元素
    L.length = Size;
    std::cout << "请输入" << Size << "个元素: ";
    for (int i = 0; i < L.length; i++) {
        std::cin >> L.data[i];
    }
    // 输出结果
    std::cout << "最小未出现的整数为：";
    std::cout << FindMissMin(L) << std::endl;
    return 0;
}
