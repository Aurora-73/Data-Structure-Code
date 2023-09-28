//首先输入小于100个不为－1的整数，创建顺序表，递增存储这些数值，输出顺序表，
//然后逆置顺序表为递减，输出逆置结果，输入一个值，定位它是递减第几个，输入个位置，输出对对应的值
#include <iostream>

#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int length;
} Sqlist;

void Visit(Sqlist L){
    for(int i = 0; i < L.length ; i++){
        std::cout << L.data[i] << "  ";
    }
    std::cout << std::endl;
}

//在递增有序表中插入元素，保持有序
void Insert(Sqlist &L,int x){
    int i;
    for(i = L.length-1; i >= 0; i--){
        if(L.data[i] > x)
            L.data[i+1] = L.data[i];
        else
            break;
        }
        L.data[i+1] = x;
        L.length++;
}

//创建递增单链表，输入-1结束
void CreatIncrease(Sqlist &L){
    int x = 0;
    L.length = 0;
    while(true){
        std::cin >> x ;
        if(x == -1)
            return ;
        Insert(L,x);    
    }
}

int SqSearch(Sqlist L ,int x){
    for(int i = 0;i <L.length ;i++)
        if(L.data[i] == x) return i;
    return -1;    
}

int BinarySearch(Sqlist L, int key){
    int low = 0 , high = L.length-1 , mid;
    while(low <= high){
        mid = (high + low)/2;
        if(key > L.data[mid])
            low = mid + 1;
        else if(key < L.data[mid])
            high = mid - 1;
        else
            return mid;         
    } 
    return -1;
}

int BinarySearch2(Sqlist L, int key, int high,int low){
    if(low > high)    return -1;
    int mid = (high + low) / 2;
    if(key > L.data[mid])
       return BinarySearch2(L,key,high,mid+1);
    if(key < L.data[mid])
       return BinarySearch2(L,key,mid -1,low);
   return mid;    
}

//主函数
int main(){
    Sqlist L;
    std::cout << "请输入顺序表元素,输入-1结束。" << std::endl;
    CreatIncrease(L);
    std::cout << "创建的递增顺序表为" << std::endl;
    Visit(L);
    std::cout << "请输入待查找的元素值"  << std::endl;
    int x;
    std::cin >> x;
    
    std::cout << "顺序查找的结果为" << SqSearch(L,x) + 1<< std::endl;
    std::cout << "非递归折半查找的结果为" << BinarySearch(L,x) + 1<< std::endl;
    std::cout << "递归查找的结果为" << BinarySearch2(L,x,L.length-1,0) + 1<< std::endl;
}