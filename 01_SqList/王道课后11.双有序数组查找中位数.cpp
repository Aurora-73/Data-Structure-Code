//查找两个数列的中位数
#include <iostream>

const int MAX_SIZE = 100; // 请根据实际情况修改最大长度

struct Sqlist {
    int data[MAX_SIZE];
    int length;
};

int SearchMid(Sqlist LA,Sqlist LB){
    int i = 0 , j = 0 , count = 0;
    bool flag;
    while(count < (LA.length + LB.length)/2){
        if(LA.data[i] < LB.data[j]){
            flag = true;
            i++;
        }else{
            flag = false;
            j++;
        }
        count++;
    }
    return flag ? LA.data[--i] : LB.data[--j];
}

int SearchMid2(Sqlist LA,Sqlist LB){
    int i = 0 , j = 0 , mid = (LA.length+LB.length)/2;
    while(i + j < mid){
        if(LA.data[i] <= LB.data[j]){
            i++;
        }else{
            j++;
        }
    }
    return LA.data[--i] > LB.data[--j] ? LA.data[i] : LB.data[j];
}

int SearchMid3(Sqlist LA,Sqlist LB){
    int s1 = 0 , d1 = LA.length - 1 , m1 , s2 = 0,d2 = LB.length - 1 , m2;
    while(s1 != d1 ||s2 != d2){
        m1 = (s1 + d1 ) / 2;
        m2 = (s2 + d2 ) / 2;
        if(LA.data[m1] == LB.data[m2]){
            return LA.data[m1];
        }
        if(LA.data[m1] < LB.data[m2]){
            if((s1 + d1) % 2 == 0){
                s1 = m1;
                d2 = m2;
            }else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }else{
            if((s1 + d1) % 2 == 0){
                d1 = m1;
                s2 = m2;
            }else{
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return LA.data[s1] < LB.data[s2] ? LA.data[s1] : LB.data[s2];
}

int main(){
    Sqlist A, B;
    
    // 输入第一个有序顺序表 A
    std::cout << "请输入第一个有序顺序表 A 的长度: ";
    std::cin >> A.length;
    std::cout << "请输入 " << A.length << " 个整数:" << std::endl;
    for (int i = 0; i < A.length; i++) {
        std::cin >> A.data[i];
    }

    // 输入第二个有序顺序表 B
    std::cout << "请输入第二个有序顺序表 B 的长度: ";
    std::cin >> B.length;
    std::cout << "请输入 " << B.length << " 个整数:" << std::endl;
    for (int i = 0; i < B.length; i++) {
        std::cin >> B.data[i];
    }
    
    std::cout << "你的结果为: ";
    std::cout << SearchMid(A, B) << std::endl;
    std::cout << "匡姐结果为: ";
    std::cout << SearchMid2(A, B) << std::endl;
    std::cout << "答案结果为: ";
    std::cout << SearchMid3(A, B) << std::endl;
    return 0;
}
    
    
/*  
从平均查找时间复杂度的角度来考虑，三个代码的性能可以进行如下分析：

1. `SearchMid` 函数使用了一个简单的循环，每次比较两个数组的元素并根据比较结果移动指针，循环次数为 `(LA.length + LB.length) / 2`。因此，它的平均查找时间复杂度为 O((LA.length + LB.length) / 2)，即 O(n)，其中 n 为两个数组的总长度。

2. `SearchMid2` 函数也使用了一个循环，每次比较两个数组的元素并根据比较结果移动指针，循环次数为 `(LA.length + LB.length) / 2`。因此，它的平均查找时间复杂度也为 O((LA.length + LB.length) / 2)，即 O(n)。

3. `SearchMid3` 函数使用了类似二分查找的思路，每次将查找范围缩小一半，循环次数取决于查找范围的缩小次数。在最坏情况下，它的循环次数也是 O(n)。但在平均情况下，由于二分查找的特性，它的平均查找时间复杂度可能会更低，接近 O(log n)。

综上所述，从平均查找时间复杂度的角度来看，`SearchMid3` 函数的性能可能更优，因为它采用了二分查找的思路，平均情况下可能会比线性搜索的 `SearchMid` 和 `SearchMid2` 更快。不过，在具体应用中，性能的差异可能不会太大，因为输入数据的规模和分布也会影响算法的性能表现。在实际应用中，可以根据具体情况选择最合适的算法。
*/