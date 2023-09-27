//二叉树的结构体定义、先序中序构造、后序遍历、计算总结点数、叶结点数、单分支结点数、双分支节点数和树的深度
#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的结构体
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 根据先序和中序遍历结果构造二叉树
BiTree BuildTree(char* preorder, char* inorder, int pre_start, int in_start, int in_end) {
    if (pre_start >= strlen(preorder) || in_start > in_end) {
        return nullptr;
    }

    // 创建当前根节点
    BiTree root = new BiTNode;
    root->data = preorder[pre_start];
    root->lchild = root->rchild = nullptr;

    // 在中序遍历中找到根节点的位置
    int root_index = in_start;
    while (inorder[root_index] != root->data) {
        root_index++;
    }

    // 递归构建左子树和右子树
    root->lchild = BuildTree(preorder, inorder, pre_start + 1, in_start, root_index - 1);
    root->rchild = BuildTree(preorder, inorder, pre_start + root_index - in_start + 1, root_index + 1, in_end);

    return root;
}

// 后序遍历并输出结果
void PostOrderTraversal(BiTree T) {
    if (T) {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        cout << T->data;
    }
}

int AllCount(BiTree T){
    if(!T) 
            return 0;
    return AllCount(T->lchild)+AllCount(T->rchild)+1;
}

int LeafCount(BiTree T){
    if(!T) 
            return 0;
    if(!T->lchild && !T->rchild) 
            return 1;
    return LeafCount(T->lchild)+LeafCount(T->rchild);
}

int DuCount(BiTree T){
    if(!T)        return 0;
    int x = DuCount(T->lchild) + DuCount(T->rchild);
    return (T->lchild && T->rchild) ? x+1 : x;//后两句还可以合并
}

int DuCountS(BiTree T){
    return T ? DuCountS(T->lchild) + DuCountS(T->rchild) + (T->lchild && T->rchild) : 0;
}//计算二叉树双分支结点个数
//最后一项的括号不可省略，否则一直在计算前三项的和＆＆最后半项

int DuCount1(BiTree T){
    if(T){//必须判定是否为空，否则空指针异常
        if(T->lchild && T->rchild)//双分支节点
            return DuCount1(T->lchild)+DuCount1(T->rchild)+1;
        if(T->lchild || T->rchild)//非空 非双 有子 -> 单分支 
            return DuCount1(T->lchild)+DuCount1(T->rchild);
    }
    return 0; //非双 非单 -> 叶\空
}

int DuCount2(BiTree T){
    if(!T)
            return 0;
    if(T->lchild && T->rchild)
            return DuCount2(T->lchild)+DuCount2(T->rchild)+1;
    return DuCount2(T->lchild)+DuCount2(T->rchild);
}

//叶子节点既可以return 0; 也可以DuCount1(T->lchild)+DuCount1(T->rchild);

int SiCount(BiTree T){
    if(!T)        return 0;
    int x = SiCount(T->lchild) + SiCount(T->rchild);
    return (!T->lchild && T->rchild)||(T->lchild && !T->rchild) ? x + 1 : x;//后两句还可以合并
}

int SiCountS(BiTree T){
    return T ? SiCountS(T->lchild) + SiCountS(T->rchild) + ((!T->lchild && T->rchild)||(T->lchild && !T->rchild)) : 0;
}//计算二叉树单分支结点个数
//最后一项的最外层括号不可省略，否则一直在计算前两项半只和||最后半项

int SiCount1(BiTree T){
    if(T){//必须判定是否为空，否则空指针异常
        if(T->lchild && T->rchild)//非空 有左右 -> 双分支
            return SiCount1(T->lchild)+SiCount1(T->rchild);
        if(T->lchild || T->rchild)//非空 非双 有孩子 -> 单分支
            return SiCount1(T->lchild)+SiCount1(T->rchild)+1;
    }
    return 0;       
}

int SiCount2(BiTree T){
    if(!T)//空
            return 0;
    if((!T->lchild && T->rchild)||(T->lchild && !T->rchild))//不判定非双的情况下判定单比较困难
            return SiCount2(T->lchild)+SiCount2(T->rchild)+1;
    return SiCount2(T->lchild)+SiCount2(T->rchild);
}

int Depth(BiTree T){
     return (T ? (Depth(T->lchild) >  Depth(T->rchild) ? Depth(T->lchild) : Depth(T->rchild) )+ 1 : 0);
}//抽象

//叶子节点既可以return 0; 也可以SiCount1(T->lchild)+SiCount1(T->rchild);

int main() {
    char preorder[100], inorder[100];

    // 输入先序和中序遍历结果
    cout << "请输入先序遍历结果: ";
    cin >> preorder;
    cout << "请输入中序遍历结果: ";
    cin >> inorder;

    // 构建二叉树
    BiTree T = BuildTree(preorder, inorder, 0, 0, strlen(inorder) - 1);

    // 输出后序遍历结果
    cout << "后序遍历结果为: ";
    PostOrderTraversal(T);
    cout << endl;
    
    cout << "总结点个数为 " << AllCount(T) << std::endl;
    cout << "叶子结点个数为 " << LeafCount(T) << std::endl;
    cout << "双分支结点个数为 " << DuCount(T) << std::endl;
    cout << "双分支结点个数为 " << DuCountS(T) << std::endl;
    cout << "双分支结点个数为 " << DuCount1(T) << std::endl;
    cout << "双分支结点个数为 " << DuCount2(T) << std::endl;
    cout << "单分支结点个数为 " << SiCount(T) << std::endl;
    cout << "单分支结点个数为 " << SiCountS(T) << std::endl;
    cout << "单分支结点个数为 " << SiCount1(T) << std::endl;
    cout << "单分支结点个数为 " << SiCount2(T) << std::endl;
    cout << "树的深度为 " << Depth(T) << std::endl;
    
    return 0;
}


/*
是的，这四个函数都可以用来计算二叉树中双分支节点的数量，但它们使用了不同的实现方式和逻辑。以下是对这些函数的解释：

1. `DuCount` 和 `DuCountS` 函数已经在之前的回答中讨论过，它们都使用了相似的逻辑，即统计满足条件 `(T->lchild && T->rchild)` 的节点数。这个条件表示双分支节点。这两个函数的实现稍有不同，但都可以正确计算双分支节点数。

2. `DuCount1` 函数的实现方式与前面的 `SiCount1` 函数类似，它首先判断节点是否为空，然后根据节点是否有左右孩子分别处理。如果节点有左右孩子，说明它是双分支节点，计入双分支节点数。如果节点有左孩子或右孩子，说明它是单分支节点，不计入双分支节点数。这个函数的逻辑也是正确的。

3. `DuCount2` 函数与前面的 `SiCount2` 函数类似，它使用递归，在每个节点处进行一次条件判断，判断当前节点是否是双分支节点，如果是，则返回 1，否则返回 0。然后，递归地处理左右子树并累加它们的双分支节点数。这个函数的逻辑同样正确。

总的来说，这四个函数都可以正确计算双分支节点数，但它们使用了不同的实现方式和逻辑。选择哪个函数取决于你的需求和个人偏好。



是的，这四个函数都可以用来计算树的单分支节点数，但它们采用了不同的实现方法和逻辑。让我逐一解释它们：

1. `SiCount` 和 `SiCountS` 函数已经在之前的回答中讨论过，它们都使用了相似的逻辑，即统计满足条件 `(!T->lchild && T->rchild)||(T->lchild && !T->rchild)` 的节点数。这个条件表示单分支节点。这两个函数的实现稍有不同，但都可以正确计算单分支节点数。

2. `SiCount1` 函数采用了不同的逻辑。它首先判断节点是否为空，然后根据节点是否有左右孩子分别处理。如果节点有左右孩子，说明它是双分支节点，不计入单分支节点数。如果节点有左孩子或右孩子，说明它是单分支节点，计入单分支节点数。这个函数的逻辑也是正确的。

3. `SiCount2` 函数也采用了不同的逻辑。它首先检查节点是否为空，如果为空，返回 0。然后它使用条件 `(!T->lchild && T->rchild)||(T->lchild && !T->rchild)` 判断当前节点是否是单分支节点，如果是，则返回 1，否则返回 0。最后，递归地处理左右子树并累加它们的单分支节点数。这个函数的逻辑同样正确。

总的来说，这四个函数都可以正确计算树的单分支节点数，但它们使用了不同的实现方式和逻辑。选择哪个函数取决于你的需求和个人偏好。
*/

    
