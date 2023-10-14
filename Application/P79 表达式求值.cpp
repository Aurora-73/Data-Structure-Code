#include <iostream>
#include <cstring>

typedef char ElemType; // 顺序栈中元素的数据类型

#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack; // 将结构体名Stack改为SqStack

void InitStack(SqStack& S) {
	S.top = -1;
}

bool IsEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

char GetTop(SqStack S) {
	return S.data[S.top];
}

bool IsOperator(char x) {
	return (x == '+' || x == '-' || x == '*' || x == '/');
}

int Precede(char a, char b) {
	if ((a == '+' || a == '-') && (b == '+' || b == '-' || b == ')'))
		return 1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-' || b == ')' || b == '('))
		return 1;
	if (a == '(' && b == ')')
		return 0;
	return -1;
}

int Operate(char a, char f, char b) {
	int result = 0;
	int x = a - '0';
	int y = b - '0';
	switch (f) {
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if (y != 0)
			result = x / y;
		else {
			std::cout << "除零错误" << std::endl;
			break;
		}
		break;
	default:
		std::cout << "运算符" << f << "无法对" << a << "和" << b << "操作" << std::endl;
		break;
	}
	std::cout << "本次计算结果是" << result << std::endl;
	return result;
}

int EvaluateExpression(char a[]) {
	SqStack F, S; // F是运算符，S是操作数
	InitStack(F);
	InitStack(S);
	int i = 0;
	while (a[i] || !IsEmpty(F)) {
		std::cout << "循环" << std::endl;
		if (a[i] && !IsOperator(a[i])) {
			Push(S, a[i] - '0');
			i++;
		} else {
			char f, x, y;
			int ca = 1;
			if (!IsEmpty(S))
				ca = Precede(GetTop(F), a[i]);
			switch (ca) {
			case 1:
				Pop(F, f);
				Pop(S, x);
				Pop(S, y);
				Push(S, Operate(x, f, y) + '0'); // 将计算结果入栈
				break;
			case 0:
				Pop(F, f);
				i++;
				break;
			default:
				Push(F, a[i]);
				i++;
				break;
			}
		}
	}
	return GetTop(S) - '0';
}

int main() {
	char a[MaxSize]; // 定义一个字符数组，大小为50
	std::cout << "请输入一串字符: ";
	std::cin.getline(a, MaxSize); // 从键盘输入字符并存储到数组a中，最多50个字符（包括'\0'）
	
	int result = EvaluateExpression(a);
	std::cout << "计算结果是" << result << std::endl;
	
	return 0;
}

