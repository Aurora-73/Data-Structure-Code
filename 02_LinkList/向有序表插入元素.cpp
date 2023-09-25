//有序表插入元素
#include <iostream>

const int MAX_SIZE = 100; // 请根据实际情况修改最大长度

struct Sqlist {
    int data[MAX_SIZE];
    int length;
};

void Insert(Sqlist &L , int x){
    int i = 0;
    for (i = L.length-1; i >= 0 ; i--){
        if (L.data[i] > x) {
            L.data[i+1] = L.data[i];
        }else{
            break;
           } 
    }
    L.data[i+1] = x;
    L.length++; 
    return ;
}

// 初始化顺序表
void Init_Sqlist(Sqlist &L, int n) {
    if (n <= MAX_SIZE) {
        L.length = n;
        std::cout << "请输入 " << n << " 个整数:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> L.data[i];
        }
    } else {
        std::cout << "输入的长度超过了最大允许长度" << MAX_SIZE << "，请重新运行程序并输入较小的长度。" << std::endl;
        exit(1);
    }
}

int main() {
    Sqlist L;
    int n , x;
    std::cout << "请输入顺序表的长度: ";
    std::cin >> n;
    Init_Sqlist(L, n);
    std::cout << "请输入待插入元素: ";
    std::cin >> x;
    // 调用函数删除相邻相同元素
    Insert(L,x);
    std::cout << "插入后的列表：" << std::endl;
    for (int i = 0; i < L.length; i++) 
      std::cout << L.data[i] << std::endl;
    return 0;
}
