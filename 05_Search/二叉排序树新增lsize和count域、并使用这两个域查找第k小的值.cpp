#include <iostream>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
    int lsize;  // 新增的左子树结点个数域
    int count;  // 新增的子树结点数域
} BiTNode, * BiTree;

// 初始化节点的函数
BiTNode* InitNode(int x) {
    BiTNode* node = new BiTNode;
    node->data = x;
    node->lchild = NULL;
    node->rchild = NULL;
    node->lsize = 1;  // 初始化左子树结点个数为1
    node->count = 1;  // 初始化子树结点数为1
    return node;
}

// 二叉查找树插入元素
bool InsertBST(BiTree& T, int x) {
    BiTNode* q = InitNode(x);
    BiTNode* p = T;
    BiTNode* pre = T;
    cout << x << " : " << q << endl;

    if (!T) {
        T = q;
        return true;
    }
    while (p) {
        pre = p;
        pre->count++;  // 更新子树结点数
        if (x == p->data) {
            delete (q);
            return false;
        } else if (x < p->data) {
            p->lsize++;  // 更新左子树结点个数
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    if (x < pre->data) {
        pre->lchild = q;
    } else {
        pre->rchild = q;
    }
    return true;
}

BiTNode *SearchBST(BiTree T,int x) {
    BiTNode *p = T;
    while(p) {
        if(x < p -> data)
            p = p -> lchild;
        else if(x > p -> data)
            p = p -> rchild;
        else break;
    }
    return p;
}

//假设二叉排序树新增了一个lsize域，用于存放左孩子的结点个数加一，请查找二叉树中第k小的结点
BiTNode *Min_k_L(BiTree T, int k) {
    if(k < 1 || !T)    return NULL;
    if(T -> lsize == k)
        return T;
    if(T -> lsize > k)
        return Min_k_L(T -> lchild, k);
    return Min_k_L(T -> rchild, k-T->lsize);
}

//假设二叉排序树新增了一个count域，用于存放该结点的子树中的结点数(包含自身)，请查找二叉树中第k小的结点
BiTNode *Min_k_C(BiTree T,int k) {
    if(k < 1|| !T || k > T->count)    return NULL;
    if(!T->lchild)
        if(k == 1)    return T;//这里要讨论是否为根节点
        else return Min_k_C(T->rchild,k-1);
    if(T->lchild->count + 1 == k)//这里应该加一因为是根节点的次序
        return T;
    if(T->lchild->count + 1 > k)
        return Min_k_C(T->lchild,k);
    return Min_k_C(T->rchild,k-T->rchild->count-1);
}

int main() {
    cout << "请输入一个元素，输入9999时停止" << endl;

    BiTNode* T = NULL,*p;
    int x = 0;
    while (x != 9999) {
        cin >> x;
        if (x != 9999)
            cout << (InsertBST(T, x) ? "" : "插入失败，结点已存在\n");
    }

    cout << "请输入带查找的值，输入9999停止" << endl;
    x = 0;
    while (x != 9999) {
        cin >> x;
        p = SearchBST(T,x);
        if (x != 9999) {
            if(p) {
                cout <<x << "的地址为" << p << endl;
                cout <<"它的lsize为" << p->lsize << endl;
                cout <<"它的count为" << p->count << endl;
            } else    cout << "不合法" << endl;
        }
    }

    x = 0;
    while (x != 9999) {
        cout << "你想要第几小的结点？输入9999停止" << endl;
        cin >> x;
        if (x != 9999) {
            p = Min_k_L(T,x);
            if(p)
                cout <<"使用lsize的查找结果为" << p->data << endl;
            else cout <<"lsize认为不合法"<<endl;
            p = Min_k_C(T,x);
            if(p)
                cout <<"使用count的查找结果为" << p->data << endl;
            else cout <<"count认为不合法"<<endl;
        }
    }

    return 0;
}
