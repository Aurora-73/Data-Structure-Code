//首先输入小于100个不为－1的整数，创建顺序表，递增存储这些数值，输出顺序表，
//然后逆置顺序表为递减，输出逆置结果，输入一个值，定位它是递减第几个，输入个位置，输出对对应的值
#include <iostream>

#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int length;
} Sqlist;

//遍历输出顺序表
void Visit(Sqlist L){
    for(int i = 0; i < L.length ; i++){
        std::cout << L.data[i] << "  ";
    }
    std::cout << std::endl;
}

//返回值为e的元素的下标
int Locate(Sqlist L,int e){
    for(int i = 0; i < L.length ; i++){
        if(L.data[i] == e){
            return i;
        }
    }
    return -1;
}

//查找第i个元素
int GetElem(Sqlist L,int i){
    if(i > L.length || i <1)
        return -1;
    return L.data[i-1];
}

void Swap(int &a ,int &b){
    int temp = a;
    a = b;
    b = temp; 
}

//顺序表逆置
void Reverse(Sqlist &L){
    int m = 0 , n = L.length-1;
    while(m < n){
        Swap(L.data[m++],L.data[n--]);
    }
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

//主函数
int main(){
    Sqlist L;
    std::cout << "请输入顺序表元素,输入-1结束。" << std::endl;
    CreatIncrease(L);
    std::cout << "创建的递增顺序表为" << std::endl;
    Visit(L);
    Reverse(L);
    std::cout << "转置为递减后顺序表为" << std::endl;
    Visit(L);
    std::cout << "请输入待定位元素值"  << std::endl;
    int x,i;
    std::cin >> x;
    i = Locate(L,x)+1;
    if(i)  
        std::cout << "该元素是递减的第 "  << i << " 个元素" << std::endl;
    else
        std::cout << "不存在" <<std::endl;
    std::cout << "你想查找第几个元素？"  << std::endl;
    std::cin >> i;
    if(i+1) 
        std::cout << "值为 " <<GetElem(L,i) << std::endl;
    else 
        std::cout << "不合法" << std::endl;
}