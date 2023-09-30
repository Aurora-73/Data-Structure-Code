#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组

void BiBubbleSort(int A[], int n) {
    int temp, flag = 1,low = 0,high = n - 1;
    while(low < high && flag){
        flag = 0;
        for (int i = high ; i > low ; i--){
            if (A[i- 1] > A[i]) {
                temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                flag = 1;
            }
        }
        low++;
        if(!flag)    return;
        for (int i = low ; i < high ; i++){
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = 1;
            }
        }
        high--;
        if(!flag)    return;
    }
}//这个是标准的双向冒泡排序

/*
void BiBubbleSort(int A[], int n) {
    int temp, flag = 1,low = -1,high = n;
    while(low < high && flag){
        flag = 0;
        for (int i = high - 1 ; i > low + 1; i--){
            if (A[i- 1] > A[i]) {
                temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                flag = 1;
            }
        }
        low++;
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << (!flag ? "\n本轮未移动过" : "") << std::endl;
        if(!flag) return;
        for (int i = low + 1 ; i < high - 1 ; i++){
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = 1;
            }
        }
        high--;
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << (!flag ? "\n本轮未移动过" : "") << std::endl;
        if(!flag) return;
    }
}
//这个也行 */

int main() {
    std::string input;
    std::cout << "请输入以逗号分隔的数字: ";
    std::getline(std::cin, input);

    int A[MaxSize]={0};
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
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "冒泡排序过程为: \n";
    // 使用插入排序对数组进行排序
    BiBubbleSort(A, count);

    std::cout << "冒泡排序结果为 \n";
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
    