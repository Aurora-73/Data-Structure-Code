#include <iostream>
#include <cstring>

using namespace std;

typedef struct HuffmanNode {
    char data;
    int weight;
    int lchild, rchild, parent;
} HuffmanNode;

void select(HuffmanNode HuffTree[], int n, int &l, int &r) {
    l = -1;
    r = -1;
    for (int i = 0; i < n; i++) {
        if (HuffTree[i].parent == -1) {
            if (l == -1) {
                l = i;
            } else if (HuffTree[i].weight < HuffTree[l].weight) {
                r = l;
                l = i;
            } else if (r == -1 || HuffTree[i].weight < HuffTree[r].weight) {
                r = i;
            }
        }
    }
}

void HuffmanCoding(HuffmanNode HuffTree[], char *HuffCode[], int n) {
    char *temp = new char[n];
    temp[n - 1] = '\0';
    for (int i = 0; i < n; i++) {
        int start = n - 1;
        int pos = i;
        int parent = HuffTree[i].parent;
        while (parent != -1) {
            if (HuffTree[parent].lchild == pos)
                temp[--start] = '0';
            else
                temp[--start] = '1';
            pos = parent;
            parent = HuffTree[parent].parent;
        }
        HuffCode[i] = new char[n - start];
        strcpy(HuffCode[i], &temp[start]);
    }
    delete[] temp;
}

void HuffTreeBuild(HuffmanNode HuffTree[], int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        HuffTree[i].parent = -1;
        HuffTree[i].lchild = -1;
        HuffTree[i].rchild = -1;
    }
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个节点的值" << endl;
        cin >> HuffTree[i].data;
        cout << "请输入第" << i + 1 << "个节点的权重" << endl;
        cin >> HuffTree[i].weight;
    }
    for (int k = n; k < 2 * n - 1; k++) {
        int l, r;
        select(HuffTree, k, l, r);
        HuffTree[k].weight = HuffTree[l].weight + HuffTree[r].weight;
        HuffTree[l].parent = HuffTree[r].parent = k;
        HuffTree[k].lchild = l;
        HuffTree[k].rchild = r;
    }
}

int main() {
    int n;
    cout << "请输入编码个数" << endl;
    cin >> n;
    HuffmanNode *HuffTree = new HuffmanNode[2 * n - 1];
    char **HuffCode = new char *[n];
    HuffTreeBuild(HuffTree, n);
    HuffmanCoding(HuffTree, HuffCode, n);

    // 输出哈夫曼编码
    for (int i = 0; i < n; i++) {
        cout << "字符 " << HuffTree[i].data << " 的哈夫曼编码为: " << HuffCode[i] << endl;
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        delete[] HuffCode[i];
    }
    delete[] HuffCode;
    delete[] HuffTree;

    return 0;
}
    