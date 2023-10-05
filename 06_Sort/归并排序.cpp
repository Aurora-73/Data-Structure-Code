#include <iostream>
#include <sstream>

const int MaxSize = 100; // 设置最大数组大小

void Merge(int A[], int B[], int left, int mid, int right){
    int l_pos = left , r_pos = mid+1 , pos = left;
    while(l_pos <= mid && r_pos <= right)
        if(A[l_pos] <= A[r_pos])//取等号可以保证稳定性，即左右等大取左
            B[pos++] = A[l_pos++];
        else
            B[pos++] = A[r_pos++];
    while(l_pos <= mid)    B[pos++] = A[l_pos++];
    while(r_pos <= right)    B[pos++] = A[r_pos++];
    for(; left <= right; left++)    A[left] = B[left];
}//合并函数，负责A中left到right之间的以mid为分隔的两部分合并到B中，然后将其复制回A

void msort(int A[], int B[], int left ,int right){
    if(left >= right)    return;
    int mid = (left + right) / 2;
    msort(A,B,left,mid);
    msort(A,B,mid+1,right);
    Merge(A,B,left,mid,right);
}//归并函数主体，负责递归分隔和合并

void MergeSort(int A[], int n){
    int *B = (int *)malloc(n * sizeof(int));
    if(B){
        msort(A, B, 0, n-1);
        free(B);
    }
    else
        std::cout << "分配空间失败" << std::endl;
}//归并函数调用函数，负责分配临时数组和调用主题


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
   
    MergeSort(A, count);

    std::cout << "归并排序结果为 \n";
    for (int i = 0; i < count; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
