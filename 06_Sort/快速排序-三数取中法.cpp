#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组大小
int count = 0;

void PrintList(int A[]) {
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int medianOfThree(int A[], int low, int high) {
    int mid = low + (high - low) / 2;

    // 选择左端、右端和中间位置的元素
    int left = A[low];
    int middle = A[mid];
    int right = A[high];

    // 找出这三个元素的中位数
    if ((left < middle && middle < right) || (right < middle && middle < left))
        return mid;
    else if ((middle < left && left < right) || (right < left && left < middle))
        return low;
    else
        return high;
}

int partition(int A[], int low, int high) {
    // 使用三数取中法来选择枢纽元素
    int pivotIndex = medianOfThree(A, low, high);
    int pivot = A[pivotIndex];

    // 交换枢纽元素到数组末尾
    std::swap(A[pivotIndex], A[low]);
    while(low < high) {
        while(low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];//因为要先对low进行赋值而不能对high进行复制，因此必须先找high而不是low，否则会丢失元素
        while(low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    PrintList(A);
    return low;
}

void QuickSort(int A[],int low,int high) {
    if(low >= high)    return;//应该包含等号，因为只有一个元素则不需要划分
    int pivotpos = partition(A,low,high);
    QuickSort(A,low,pivotpos-1);
    QuickSort(A,pivotpos+1,high);
}

int main() {
    std::string input;
    std::cout << "请输入以逗号分隔的数字: ";
    std::getline(std::cin, input);

    int A[MaxSize];

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

    PrintList(A);
    std::cout << "快速排序过程为: \n";

    QuickSort(A,0,count-1);

    std::cout << "快速排序结果为 \n";
    PrintList(A);
    return 0;
}
