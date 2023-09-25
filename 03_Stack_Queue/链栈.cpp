#include <iostream>

typedef int ElemType; // 假设 ElemType 为 int 类型

struct Linknode {
    ElemType data;
    Linknode* next;
};

typedef Linknode* LiStack;

// 初始化链栈
void InitStack(LiStack& s) {
    s = nullptr;
}

// 判断链栈是否为空
bool IsEmpty(LiStack s) {
    return s == nullptr;
}

// 入栈操作
bool Push(LiStack& s, ElemType x) {
    Linknode* newNode = new Linknode;
    if (newNode == nullptr) {
        std::cerr << "内存分配失败，入栈失败" << std::endl;
        return false;
    }
    newNode->data = x;
    newNode->next = s;
    s = newNode;
    return true;
}

// 出栈操作
bool Pop(LiStack &s,ElemType &x){
    if (IsEmpty(s)) {
        std::cerr << "栈为空，无法出栈" << std::endl;
        return false;
    }
    Linknode* temp = s;
    x = temp->data;
    s = s->next;
    delete temp;
    return true;
}

// 获取栈顶元素
bool GetTop(LiStack s, ElemType& x) {
    if (IsEmpty(s)) {
        std::cerr << "栈为空，无法获取栈顶元素" << std::endl;
        return false;
    }
    x = s->data;
    return true;
}

int main(){
	LiStack s;
	InitStack(s);
	std::cout << (IsEmpty(s) ? "栈为空": "栈非空") << std::endl;
	std::cout << "请输入压栈元素，输入-1时停止" << std::endl;
	ElemType x;
	std::cin >> x;
	while(x != -1){	
		if(!Push(s,x)) std::cout << "栈已满，无法压栈" << std::endl;
		std::cin >> x;
	}
	std::cout << (IsEmpty(s) ? "栈为空": "栈非空") << std::endl;	
	std::cout << "需要弹几次栈？" << std::endl;
	std::cin >> x;
	std::cout << "开始弹栈" << std::endl;
	ElemType e;
	for(int i=1;i<=x;i++){
		if(!IsEmpty(s)){
			if(!Pop(s,e)) std::cout << "栈为空，无法弹栈" << std::endl;;	
			std::cout << e <<std::endl ;
		}else{
			std::cout << "弹栈次数过多" << std::endl;
			break;
		}
	}
	std::cout << (IsEmpty(s) ? "栈为空": "栈非空") << std::endl;
}
