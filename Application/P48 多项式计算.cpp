#include <iostream>
using namespace std;

typedef struct PNode{    // 结点类型，单项
	float coef; // 系数
	int expn;   // 指数
	struct PNode *next;
}PNode,*Polynomial;

void CreatePolyn(Polynomial &P, int n){
    P = new PNode;
    P->next = NULL;
    for(int i = 1;i <= n; i++){
        PNode *s = new PNode;
        cout << "请输入多项式第" << i << "项的系数和指数" <<endl;
        char comma;
        cin >> s->coef >> comma >>s->expn;
        PNode *pre = P, *q = P->next;//q指向第一个大于s的系数，pre是p的前驱。
        while(q && q->expn < s->expn){
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}//时间复杂度O(n2)

void ClearPolynomial(Polynomial &P) {
    PNode *current = P->next;
    while (current != NULL) {
        PNode *temp = current;
        current = current->next;
        delete temp; // 释放节点内存
    }
    P->next = NULL; // 多项式为空
}

void AddPolyn(Polynomial &Pa, Polynomial &Pb){
    PNode *p1 = Pa->next , *p2 = Pb->next , *p3 = Pa ,*r;//p3指向多项式的当前结点
    while(p1 && p2){
        if(p1->expn == p2->expn){
            int sum = p1->coef + p2->coef;
            if(sum){//和不为0，则保存
                p1->coef = sum;
                p3->next = p1; p3=p1;
                p1 = p1->next;
                r = p2; 
                p2 = p2->next;
                delete r;
            }else{//和为0，直接讲两个节点释放
                r = p1;    p1 = p1->next;    delete r;
                r = p2;    p2 = p2->next;    delete r;
            }
        }else if(p1->expn < p2->expn){
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3 -> next = p1 ? p1 : p2;
    ClearPolynomial(Pb);
}//时间复杂度O(m+n)

void MinusPolyn(Polynomial &Pa, Polynomial &Pb){
    PNode *p1 = Pa->next , *p2 = Pb->next ,*p3 = Pa ,*r;
    while(p1 && p2){
        if(p1->expn == p2->expn){
            int mis = p1->coef - p2->coef;
            cout <<"系数为" << mis << endl;
            if(mis){
                p1->coef = mis;
                p3->next = p1; p3=p1;
                p1 = p1->next;
                r = p2; 
                p2 = p2->next;
                delete r;
            }else{
                r = p1;    p1 = p1->next;    delete r;
                r = p2;    p2 = p2->next;    delete r;
            }
        }else if(p1->expn < p2->expn){
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3 -> next = p1 ? p1 : p2;
    ClearPolynomial(Pb);
}//时间复杂度O(m+n)

void MultiplyPolyn(Polynomial &Pa, Polynomial &Pb) {
    Polynomial Pc = new PNode;
    Pc->next = NULL;

    PNode *p1 = Pa->next;
    while (p1 != NULL) {
        PNode *p2 = Pb->next;
        while (p2 != NULL) {
            // 计算乘积的系数和指数
            float coef = p1->coef * p2->coef;
            int expn = p1->expn + p2->expn;

            // 在结果多项式中查找是否已存在相同指数的项
            PNode *p3 = Pc->next;
            PNode *pre = Pc;
            bool found = false;

            while (p3 != NULL) {
                if (p3->expn == expn) {
                    // 系数相加
                    p3->coef += coef;
                    found = true;
                    break;
                } else if (p3->expn > expn) {
                    break;
                }

                pre = p3;
                p3 = p3->next;
            }

            if (!found && coef != 0) {
                // 如果不存在相同指数的项且系数不为0，则插入新的项
                PNode *newTerm = new PNode;
                newTerm->coef = coef;
                newTerm->expn = expn;
                newTerm->next = p3;
                pre->next = newTerm;
            }

            p2 = p2->next;
        }
        p1 = p1->next;
    }
    ClearPolynomial(Pa);
    ClearPolynomial(Pb);
    Pa = Pc;
}


void DisplayPolyn(Polynomial P){
    if (!P) {
        cout << "多项式为空" << endl;
        return;
    }

    while (P) {
        if (P->coef != 0) {
            cout << P->coef;
            if (P->expn != 0) {
                cout << "X^" << P->expn;
            }
            if (P->next) {
                cout << " + ";
            }
        }
        P = P->next;
    }

    cout << endl;
}


int main() {
    Polynomial Pa, Pb;
    int n1, n2;
    cout << "请输入第一个多项式的项数: ";
    cin >> n1;
    CreatePolyn(Pa, n1);
    DisplayPolyn(Pa);

    char operation;
    do {
        cout << "请选择操作 (+/-/*): ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << "请输入加数多项式的项数: ";
                cin >> n2;
                CreatePolyn(Pb, n2);
                DisplayPolyn(Pb);
                AddPolyn(Pa, Pb);
                cout << "结果已保存到第一个多项式：" << endl;
                DisplayPolyn(Pa);
                break;
            case '-':
                cout << "请输入减数多项式的项数: ";
                cin >> n2;
                CreatePolyn(Pb, n2);
                DisplayPolyn(Pb);
                MinusPolyn(Pa, Pb);
                cout << "结果已保存到第一个多项式：" << endl;
                DisplayPolyn(Pa);
                break;
            case '*':
                cout << "请输入乘数多项式的项数: ";
                cin >> n2;
                CreatePolyn(Pb, n2);
                DisplayPolyn(Pb);
                MultiplyPolyn(Pa, Pb);
                cout << "结果已保存到第一个多项式：" << endl;
                DisplayPolyn(Pa);
                break;
            default:
                return 0;
        }
    } while (true);

    return 0;
}
