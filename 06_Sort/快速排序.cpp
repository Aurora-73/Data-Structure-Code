#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组大小

int partition(int A[],int low,int high) {
    int pivot = A[low];
    while(low < high) {
        while(low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];//因为要先对low进行赋值而不能对high进行复制，因此必须先找high而不是low，否则会丢失元素
        while(low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[],int low,int high) {
    if(low >= high)    return;//应该包含等号，因为只有一个元素则不需要划分
    int pivotpos = partition(A,low,high);
    for (int i = low; i <= high; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    QuickSort(A,low,pivotpos-1);
    QuickSort(A,pivotpos+1,high);
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
    std::cout << "快速排序过程为: \n";
    // 使用插入排序对数组进行排序
    QuickSort(A,0,count-1);

    std::cout << "快速排序结果为 \n";
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
    