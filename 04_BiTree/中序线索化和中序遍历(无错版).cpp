#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 二叉树节点的结构体
typedef struct TreadNode{
    char data;
    struct TreadNode *lchild, *rchild;
    int ltag,rtag;
}TreadNode, *TreadTree;

// 创建二叉树的函数，A[0]为字符串长度
TreadTree CreateBySq(char A[], int i) {
    if (i > A[0] || A[i] == '#') 
        return NULL;
    TreadTree T = new TreadNode;
    T->data = A[i];
    T->lchild = CreateBySq(A, 2*i);
    T->rchild = CreateBySq(A, 2*i+1);
    return T;
}

//将字符串转为字符数组
void StringToArray(const std::string& str, char A[]) {
    size_t length = str.length();
    A[0] = static_cast<char>(length);
    
    for (size_t i = 0; i < length; i++) {
        A[i + 1] = str[i];
    }
}

// 先序遍历并输出结果
void PreOrderTraversal(TreadTree T) {
    if (T) {
        cout << T->data;
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

// 中序遍历并输出结果
void InOrderTraversal(TreadTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        cout << T->data;
        InOrderTraversal(T->rchild);
    }
}

// 后序遍历并输出结果
void PostOrderTraversal(TreadTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data;
    }
}

void InOrderTreadize(TreadTree &p,TreadNode *&pre){
        if(!p)    return;
        InOrderTreadize(p->lchild , pre);
        if(!p -> lchild){
            p -> lchild = pre;
            p -> ltag = 1;
        }
        if(pre && !pre -> rchild){
             pre -> rchild = p;
             pre -> rtag = 1;
        }
        pre = p;
        InOrderTreadize(p->rchild , pre);
}

void InOrderThreadedTraversal(TreadNode *T) {
    if (!T) return;

    // 找到中序遍历的起始点，即最左下的节点
    TreadNode *current = T;
    while (current->ltag == 0) {
        current = current->lchild;
    }

    // 开始中序遍历
    while (current) {
        // 输出当前节点的数据
        cout << current->data;

        // 如果有右线索，跳到后继节点
        if (current->rtag == 1) {
            current = current->rchild;
        } else {
            // 否则，移动到右子树的最左下节点
            current = current->rchild;
            while (current && current->ltag == 0) {
                current = current->lchild;
            }
        }
    }
}

int main() {
    
    string input;
    cout << "请输入表示顺序存储的线索二叉树的字符串：";
    cin >> input;
    
    char A[100];
    StringToArray(input,A);
       
    TreadTree T = CreateBySq(A, 1);
  
   // 输出先序遍历结果
    cout << "先序遍历结果为: ";
    PreOrderTraversal(T);
    cout << endl;
    
    // 输出中序遍历结果
    cout << "中序遍历结果为: ";
    InOrderTraversal(T);
    cout << endl;

    // 输出后序遍历结果
    cout << "后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    
    TreadNode *p = T,*pre = NULL;
    InOrderTreadize(p,pre);
    cout << "中序线索化成功 " << endl;
    InOrderThreadedTraversal(T);
    cout << "\n中序遍历运行成功";
      
    return 0;
}