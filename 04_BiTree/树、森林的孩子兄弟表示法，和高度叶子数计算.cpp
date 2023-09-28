#include <stdio.h>
#include <stdlib.h>

// 孩子兄弟表示法的树节点结构
typedef struct CSNode {
    int data;
    struct CSNode* firstChild; // 指向第一个孩子节点
    struct CSNode* nextSibling; // 指向下一个兄弟节点
} CSNode,*CSTree;

// 创建一个新的孩子兄弟树节点
CSNode* createCSNode(int data) {
    CSNode* newNode = (CSNode*)malloc(sizeof(CSNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
/*
// 构造森林的示例函数
CSNode* createForest() {
    // 创建第一棵树
    CSNode* root1 = createCSNode(1);
    root1->firstChild = createCSNode(2);
    root1->firstChild->nextSibling = createCSNode(3);

    // 创建第二棵树
    CSNode* root2 = createCSNode(4);
    root2->firstChild = createCSNode(5);
    root2->firstChild->nextSibling = createCSNode(6);

    // 创建第三棵树
    CSNode* root3 = createCSNode(7);
    root3->firstChild = createCSNode(8);

    // 构建森林
    root1->nextSibling = root2;
    root2->nextSibling = root3;

    return root1; // 返回森林的第一棵树的根节点
}

// 修改 createForest() 函数
CSNode* createForest() {
    // 创建第一棵树
    CSNode* root1 = createCSNode(1);
    root1->firstChild = createCSNode(2);
    root1->firstChild->nextSibling = createCSNode(3);

    // 创建第二棵树
    CSNode* root2 = createCSNode(4);
    root2->firstChild = createCSNode(5);

    // 创建第三棵树
    CSNode* root3 = createCSNode(6);
    root3->firstChild = createCSNode(7);

    // 创建第四棵树
    CSNode* root4 = createCSNode(8);

    // 构建森林
    root1->nextSibling = root2;
    root2->nextSibling = root3;
    root3->nextSibling = root4;

    return root1; // 返回森林的第一棵树的根节点
}

// 修改 createForest() 函数
CSNode* createForest() {
    // 创建第一棵树（高度为5）
    CSNode* root1 = createCSNode(1);
    root1->firstChild = createCSNode(2);
    root1->firstChild->firstChild = createCSNode(3);
    root1->firstChild->firstChild->firstChild = createCSNode(4);
    root1->firstChild->firstChild->firstChild->firstChild = createCSNode(5);

    // 创建第二棵树
    CSNode* root2 = createCSNode(6);

    // 创建第三棵树
    CSNode* root3 = createCSNode(7);
    root3->firstChild = createCSNode(8);
    root3->firstChild->nextSibling = createCSNode(9);

    // 创建第四棵树
    CSNode* root4 = createCSNode(10);

    // 创建第五棵树
    CSNode* root5 = createCSNode(11);
    root5->firstChild = createCSNode(12);

    // 创建第六棵树
    CSNode* root6 = createCSNode(13);

    // 构建森林
    root1->nextSibling = root2;
    root2->nextSibling = root3;
    root3->nextSibling = root4;
    root4->nextSibling = root5;
    root5->nextSibling = root6;

    return root1; // 返回森林的第一棵树的根节点
}
*/

// 修改 createForest() 函数
CSNode* createForest() {
    // 创建第一棵树（高度为8）
    CSNode* root1 = createCSNode(1);
    root1->firstChild = createCSNode(2);
    root1->firstChild->firstChild = createCSNode(3);
    root1->firstChild->firstChild->firstChild = createCSNode(4);
    root1->firstChild->firstChild->firstChild->firstChild = createCSNode(5);
    root1->firstChild->firstChild->firstChild->firstChild->firstChild = createCSNode(6);
    root1->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild = createCSNode(7);
    root1->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild = createCSNode(8);

    // 创建第二棵树（高度为3）
    CSNode* root2 = createCSNode(9);
    root2->firstChild = createCSNode(10);
    root2->firstChild->firstChild = createCSNode(11);

    // 创建第三棵树（高度为2）
    CSNode* root3 = createCSNode(12);
    root3->firstChild = createCSNode(13);

    // 创建第四棵树（高度为2）
    CSNode* root4 = createCSNode(14);
    root4->firstChild = createCSNode(15);

    // 创建第五棵树（高度为1）
    CSNode* root5 = createCSNode(16);

    // 构建森林
    root1->nextSibling = root2;
    root2->nextSibling = root3;
    root3->nextSibling = root4;
    root4->nextSibling = root5;

    return root1; // 返回森林的第一棵树的根节点
}


int LeafCount(CSTree T){
    if(!T) return 0;
    int n = LeafCount(T->nextSibling);
    int m = 1;
    if(T->firstChild) m = LeafCount(T->firstChild);
    return m+n;
    
}

int Height(CSTree T){
    if(!T) return 0;
    int m = Height(T->firstChild);
    int n = Height(T->nextSibling);
    return m+1 > n ? m+1 : n;
}

int main() {
    // 构造森林
    CSNode* forest = createForest();

    // 验证 LeafCount 和 Height 函数
    int leafCount = LeafCount(forest);
    int height = Height(forest);

    printf("叶子节点数：%d\n", leafCount);
    printf("树的高度：%d\n", height);

    return 0;
}
