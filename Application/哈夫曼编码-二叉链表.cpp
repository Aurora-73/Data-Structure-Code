#include <iostream>
#include <cstring>

using namespace std;

typedef struct HuffmanNode {
    char data;
    int weight;
    HuffmanNode *lchild, *rchild;
} HuffmanNode;

typedef struct ElemCode {
    char data;
    char *code;
} ElemCode;

typedef HuffmanNode *ElemType; // 顺序栈中元素的数据类型
#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int pos[MaxSize];
    int top;
} SqStack; // 将结构体名Stack改为SqStack

void InitStack(SqStack& S) {
    S.top = -1;
}

bool IsEmpty(SqStack& S) {
    return (S.top == -1) ? true : false;
}

bool Push(SqStack& S, ElemType x,int p) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    S.pos[S.top] = p;
    return true;
}

bool Pop(SqStack& S, ElemType& x, int &p) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    p = S.pos[S.top--];
    return true;
}

bool GetTop(SqStack& S, ElemType &x,int &p) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    p = S.pos[S.top];
    return true;
}

void HNInsert(HuffmanNode *H[], HuffmanNode *temp, int low,int high) {
    int i;
    if(high + 1 == low) {
        H[low] = temp;
        return;
    }
    for(i = high; i >= low ; i--) {
        if(H[i]->weight > temp->weight)
            H[i+1] = H[i];
        else
            break;
    }
    H[i+1] = temp;
}//传入的high和low是插入之前的下标

void HuffListBuild(HuffmanNode *HuffList[], int n) {
    for(int i = 0; i < n ; i++) {
        HuffmanNode *temp = new HuffmanNode;
        cout << "请输入第" << i+1 << "个节点的值" << endl;
        cin >> temp -> data;
        cout << "请输入第" << i+1 << "个节点的权重" << endl;
        cin >> temp -> weight;
        temp -> lchild = temp -> rchild = NULL;
        HNInsert(HuffList,temp,0,i - 1);
    }
}

int HuffTreeBuild(HuffmanNode *H[], int n) {
    int low = 0,high = n - 1;
    while(high > low) {
        HuffmanNode *temp = new HuffmanNode;
        temp -> weight = H[low]->weight + H[low+1]->weight;
        temp -> lchild = H[low];
        temp -> rchild = H[low+1];
        low = low + 2;
        HNInsert(H,temp,low,high);
        high++;
    }
    return high;
}

void HuffmanCoding(HuffmanNode *H, ElemCode HuffCode[],int n) {
    SqStack S;
    int i = 0,k = 0;
    char *temp = new char[n-1];
    InitStack(S);
    HuffmanNode *p = H;
    while(p || !IsEmpty(S)) {
        if(p->lchild && p->rchild) {
            Push(S,p,i);
            p = p -> lchild;
            temp[i++] = '0';
        } else {
            HuffCode[k].data = p -> data;
            HuffCode[k].code = new char[n];
            for(int x = 0; x < i ; x++) {
                HuffCode[k].code[x] = temp[x];
            }
            k++;
            Pop(S,p,i);
            p = p -> rchild;
            temp[i++] = '1';
        }
    }
}

void PrintAllCodes(ElemCode* HuffCode, int n) {
    std::cout << "Huffman Codes:" << std::endl;
    for (int i = 0; i < n; ++i) {
        cout << "字符 " << HuffCode[i].data << " 的哈夫曼编码为: " << HuffCode[i].code << endl;
        delete[] HuffCode[i].code;
    }
}

// 后序遍历并删除
void DeleteHuffmanTree(HuffmanNode *&T) {
    if (T) {
        DeleteHuffmanTree(T->lchild);
        DeleteHuffmanTree(T->rchild);
        delete T;
        T = NULL;
    }
}

int main() {
    int n;
    cout << "请输入编码个数" << endl;
    cin >> n;
    HuffmanNode* *HuffList = new HuffmanNode*[2*n-1];
    HuffListBuild(HuffList, n);
    
    cout << "这些元素按权重递增排序为" << endl;
    for (int i = 0; i < n; i++) {
        cout << HuffList[i]->data;
    }
    cout << endl;
    
    int pos = HuffTreeBuild(HuffList,n);
    HuffmanNode *HuffmanTree = HuffList[pos];
    
    delete[] HuffList;
    cout << "哈夫曼树的WSL是" << HuffmanTree->weight << endl;
    
    ElemCode *HuffCode = new ElemCode[n-1];
    HuffmanCoding(HuffmanTree, HuffCode,n);
    
    PrintAllCodes(HuffCode, n);

    delete[] HuffCode;
    DeleteHuffmanTree(HuffmanTree);
    delete HuffmanTree;

    return 0;
}