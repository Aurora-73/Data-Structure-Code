#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool IsCircle(ListNode* head) {
    ListNode* fast = head->next, *slow = head;
    while (fast && fast->next) {
      if (fast != slow) {
         fast = fast->next->next;
         slow = slow->next;
         }else
            return true;
      }
    return false;
}

int main() {
    // 创建一个带环的链表
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    //node5->next = node2;  // 将尾节点连接到第二个节点，形成环

    // 调用 IsCircle 函数检查是否有环
    if (IsCircle(head)) {
        std::cout << "链表包含环。" << std::endl;
    } else {
        std::cout << "链表不包含环。" << std::endl;
    }

    // 清理内存
    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
