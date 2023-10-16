#include <iostream>
#include <cstring>

typedef char ElemType; // 顺序栈中元素的数据类型
const char oper[7] = {'+','-','*','/','(',')','#'};

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
	for(int i = 0; i < 7 ; i++) {
		if(x == oper[i])
			return true;
	}
	return false;
}//判断传进来的是不是运算符

char Precede(char a, char b) {
	// 定义运算符的优先级
	char precedence[7][7] = {
		//       +  -  *  /  (  )  #
		/* + */ {'>', '>', '<', '<', '<', '>', '>'},
		/* - */ {'>', '>', '<', '<', '<', '>', '>'},
		/* * */ {'>', '>', '>', '>', '<', '>', '>'},
		/* / */ {'>', '>', '>', '>', '<', '>', '>'},
		/* ( */ {'<', '<', '<', '<', '<', '=', ' '},
		/* ) */ {'>', '>', '>', '>', ' ', '>', '>'},
		/* # */ {'<', '<', '<', '<', '<', ' ', '='}
	};
	
	int i, j;
	
	for (i = 0; i < 7; i++) {
		if (oper[i] == a) break;
	}
	
	for (j = 0; j < 7; j++) {
		if (oper[j] == b) break;
	}
	
	return precedence[i][j];
}


char Operate(char a, char f, char b) {
	char result = 0;
	switch (f) {
	case '+':
		result = (a - '0') + (b - '0') + 48;
		break;
	case '-':
		result = (a - '0') - (b - '0') + 48;
		break;
	case '*':
		result = (a - '0') * (b - '0') + 48;
		break;
	case '/':
		if (b != '0')
			result = (a - '0') / (b - '0') + 48;
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
	Push(F,a[0]);
	int i = 1;
	while (( a[i] != '#' || GetTop(F) != '#')) {
		//std::cout << " i =  " << i <<  "   a[i] =    " << a[i] << "   F = " << GetTop(F) << std::endl;
		if (!IsOperator(a[i])) {
			Push(S, a[i]);
			i++;
		} else {
			char f, x, y;
			char Pre = Precede(GetTop(F), a[i]);
			//std::cout << a[i] << Pre <<  GetTop(F) << std::endl;
			switch (Pre) {
			case '<':
				Push(F, a[i]);
				i++;
				break;
			case '=':
				Pop(F, f);
				i++;
				break;
			case '>':
				Pop(F, f);
				Pop(S,y);
				Pop(S, x);
				Push(S, Operate(x, f, y)); // 将计算结果入栈
				break;
			}
		}
	}
	return GetTop(S) - '0';
}

int main() {
	char a[MaxSize]; // 定义一个字符数组，大小为50
	std::cout << "请输入一串字符: (以#开头和结尾)" << std::endl;
	std::cin.getline(a, MaxSize); // 从键盘输入字符并存储到数组a中，最多50个字符（包括'\0'）
	
	for(int i = 1; a[i] != '#' ; i++)
		std::cout << a[i];
	std::cout << std::endl;
	int result = EvaluateExpression(a);
	std::cout << "计算结果是" << result << std::endl;
	
	return 0;
}
