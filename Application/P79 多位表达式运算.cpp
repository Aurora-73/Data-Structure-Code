#include <iostream>
#include <cstring>



const char oper[7] = {'+','-','*','/','(',')','#'};

template <class ElemType, int MaxSize>
class SqStack {
public:
	SqStack() {
		top = -1;
	}
	
	bool IsEmpty() const {
		return (top == -1) ? true : false;
	}
	
	bool Push(ElemType x) {
		if (top == MaxSize - 1)
			return false;
		data[++top] = x;
		return true;
	}
	
	bool Pop(ElemType& x) {
		if (top == -1)
			return false;
		x = data[top--];
		return true;
	}
	
	ElemType GetTop() const {
		return data[top];
	}
	
private:
	ElemType data[MaxSize];
	int top;
};

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


float Operate(float a, char f, float b) {
	float result = 0;
	switch (f) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b != '0')
			result = a / b;
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

float EvaluateExpression(char a[]) {
	SqStack<char,50> F;// F是运算符，S是操作数
	SqStack<float,50> S;
	F.Push(a[0]);
	int i = 1;
	char f;
	float num1 = 0 , num2 = 0, x, y;
	bool bN1 = false;
	bool bN2 = false;
	
	while (( a[i] != '#' || F.GetTop() != '#')) {
		//std::cout << " i =  " << i <<  "   a[i] =    " << a[i] << "   F = " << GetTop(F) << std::endl;
		if (!IsOperator(a[i])) {
			if(a[i] != '.' && bN2 == false){
				bN1 = true;
				num1 = num1*10+(a[i] - '0');
			}else if(bN2 == true)
				num2 += num2*10+(a[i]-'0');
			else
				bN2 = true;
			i++;
		} else {
			if(bN1){
				while(num2 > 1)
					num2 /= 10;
				S.Push(num1 + num2);
			    num1 = 0 ;   num2 = 0;
				bN1 = false; bN2 = false;
			}
			char Pre = Precede(F.GetTop(), a[i]);
			//std::cout << a[i] << Pre <<  GetTop(F) << std::endl;
			switch (Pre) {
			case '<':
				F.Push(a[i]);
				i++;
				break;
			case '=':
				F.Pop(f);
				i++;
				break;
			case '>':
				F.Pop(f);
				S.Pop(y);
				S.Pop(x);
				S.Push(Operate(x, f, y)); // 将计算结果入栈
				break;
			}
		}
	}
	return S.GetTop();
}

int main() {
	char a[50]; // 定义一个字符数组，大小为50
	std::cout << "请输入一串字符: (以#开头和结尾)" << std::endl;
	std::cin.getline(a,50); // 从键盘输入字符并存储到数组a中，最多50个字符（包括'\0'）
	
	for(int i = 1; a[i] != '#' ; i++)
		std::cout << a[i];
	std::cout << std::endl;
	float result = EvaluateExpression(a);
	std::cout << "计算结果是" << result << std::endl;
	
	return 0;
}
