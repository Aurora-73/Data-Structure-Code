#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 二叉查找树插入元素
bool InBST(BiTree &T, int x) {
    if (!T) {
        BiTNode *q = new BiTNode;
        q->data = x;
        q->lchild = q->rchild = NULL;
        T = q;
        cout << q->data << " : " << q << endl;
        return true;
    }
    if (T->data > x)
        return InBST(T->lchild, x);
    else if (T->data < x)
        return InBST(T->rchild, x);
    else
        return false;
}

// 先序遍历并输出结果
void PreOrderTraversal(BiTree T) {
    if (T) {
        cout << T->data << "  ";
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

// 中序遍历并输出结果
void InOrderTraversal(BiTree T) {
    if (T) {
        InOrderTraversal(T->lchild);
        cout << T->data << "  ";
        InOrderTraversal(T->rchild);
    }
}

// 后序遍历并输出结果
void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data << "  ";
    }
}

void deleteNode(BiTNode *&bt) {
    BiTNode *p, *pre, *q = bt;
    if (!bt->rchild && !bt->lchild) {
        bt = NULL;
    } else if (!bt->rchild || !bt->lchild) {
        bt = bt->lchild ? bt->lchild : bt->rchild;
    } else {
        pre = bt;
        p = bt -> lchild;
        while (p->rchild) {
            pre = p;
            p = p->rchild;
        }
        if(pre != bt) {
            pre->rchild = p-> lchild;
            p->lchild = bt ->lchild;
            p->rchild = bt ->rchild;
            bt = p;
        }
        else {
            p -> rchild = bt -> rchild;
            bt = p;
        }
    }
    delete q;
}

bool deleteBST(BiTNode *&bt, int key) {
    if (!bt) return false;
    if (bt->data > key)
        return deleteBST(bt->lchild, key);
    if (bt->data < key)
        return deleteBST(bt->rchild, key);
    deleteNode(bt);
    return true;
}

void Traversal(BiTree T) {
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
}

int main() {
    cout << "请输入元素，输入9999时停止" << endl;
    BiTNode *T = NULL;
    int x = 0;
    while (x != 9999) {
        cin >> x;
        if (x != 9999) cout << (InBST(T, x) ? "" : "插入失败，结点已存在\n");
    }
    Traversal(T);

    int choice;

    do {
        cout << "请选择操作：1、插入 2、删除 3、退出: ";
        cin >> choice;

        if (choice == 1) {
            cout << "请输入要插入的元素: ";
            cin >> x;
            cout << (InBST(T, x) ? "插入成功" : "插入失败，结点已存在") << endl;
        } else if (choice == 2) {
            cout << "请输入要删除的元素: ";
            cin >> x;
            if (deleteBST(T, x)) {
                cout << "删除成功" << endl;
            } else {
                cout << "删除失败，元素不存在" << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "无效的选择，请重新选择" << endl;
        }

        Traversal(T);

    } while (true);

    return 0;
}
