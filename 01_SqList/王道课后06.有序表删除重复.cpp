//删除顺序表中的重复内容
#include <iostream>

const int MAX_SIZE = 100; // 请根据实际情况修改最大长度

struct Sqlist {
    int data[MAX_SIZE];
    int length;
};

bool Del_Same(Sqlist &L) {
    if (L.length == 0)
        return false;

    int temp = L.data[0];
    int i, k = 0;
    
    for (i = 1; i < L.length; i++) {
        if (L.data[i] == temp) {
            k++;
        }
        L.data[i - k] = L.data[i];
        temp = L.data[i];
    }
    
    L.length -= k;
    return true;
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
    int n;
    std::cout << "请输入顺序表的长度: ";
    std::cin >> n;
    Init_Sqlist(L, n);

    // 调用函数删除相邻相同元素
    if (Del_Same(L)) {
        std::cout << "删除后的列表：" << std::endl;
        for (int i = 0; i < L.length; i++) {
            std::cout << L.data[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "列表为空，无法删除相邻相同元素。" << std::endl;
    }

    return 0;
}
