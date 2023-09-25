#include <iostream>
#include <vector>

// 定义线性表结构
struct Sqlist {
    std::vector<int> data;
    int length;
};

// 遍历输出线性表
void Visit(Sqlist L) {
    for (int i = 0; i < L.length; i++) {
        std::cout << L.data[i] << "  ";
    }
    std::cout << std::endl;
}

// 删除线性表中范围在[t, s]之间的值
void DeleteRange(Sqlist &L, int t, int s) {
    int k = 0;  // 用于记录保留下来的元素个数

    // 遍历线性表，将不在范围[t, s]内的元素保留下来
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < t || L.data[i] > s) {
            L.data[k] = L.data[i];
            k++;
        }
    }

    // 更新线性表长度
    L.length = k;
}

int main() {
    Sqlist L;
    L.length = 0;

    // 输入线性表元素
    std::cout << "请输入线性表元素，输入-1结束：" << std::endl;
    int x;
    while (true) {
        std::cin >> x;
        if (x == -1)
            break;
        L.data.push_back(x);
        L.length++;
    }

    // 输入t和s的值
    int t, s;
    std::cout << "请输入t和s的值：" << std::endl;
    std::cin >> t >> s;

    std::cout << "你创建的表为" << std::endl;
    Visit(L);
    
    // 删除范围在[t, s]之间的值
    DeleteRange(L, t, s);

    // 输出删除后的线性表
    std::cout << "删除范围在[" << t << ", " << s << "]之间的值后，线性表为：" << std::endl;
    Visit(L);

    return 0;
}
