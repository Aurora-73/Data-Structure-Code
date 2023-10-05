#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组大小

int partition(int A[],int n){
    int high = n,low = 1,pivot = A[high];
    while(low < high) {
        while(low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];//因为要对最后一个进行排序因此最后一个最先可以被覆盖
        while(low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
    }
    A[high] = pivot;
    return low;
}

int main() {
    std::string input;
    std::cout << "请输入以逗号分隔的数字: ";
    std::getline(std::cin, input);

    int A[MaxSize];
    int count = 0;

    std::istringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (count < MaxSize) {
            try {
                int num = std::stoi(token);
                A[count + 1] = num;
                count++;
            } catch (const std::invalid_argument& e) {
                std::cerr << "无效的数字: " << token << std::endl;
            }
        } else {
            std::cerr << "数组已满，无法再添加更多元素。" << std::endl;
            break;
        }
    }
    // 使用插入排序对数组进行排序

	partition(A,count);
    std::cout << "最后一个元素放置到正确的位置\n";
    for (int i = 1; i < count + 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
    
