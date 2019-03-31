/*
 * @filename:    13_delete_node_O1.cc
 * @author:      Crow
 * @date:        03/31/2019 21:41:10
 * @description:
 *         问题描述: 在O(1)时间内删除链表节点
 *         思路: 不同于平常的思路, 
 *               我们采用拷贝下一节点的内容,并删除下一节点来实现O(1)时间复杂度
 *               往常我们通过遍历, 找寻上一节点, 进行删除, 是O(N)复杂度.
 *               (不过, 一般我们只知道val, 并不知道Node *)
 *
 *               此外, 考虑这么几种情况:
 *               1. 节点是尾节点, 得进行遍历操作
 *               2. 只有一个节点, 则直接返回NULL
 */

#include <iostream>

struct ListNode {
  int val_;
  ListNode *next_;
  ListNode(int val) : val_(val), next_(nullptr) { ; }
};

ListNode *DeleteNode(ListNode *head, ListNode *node) {
  if (head == nullptr)                                      // 处理空指针
    return nullptr;

  if (head->next_ == nullptr)                               // 仅仅只有一个节点
    return nullptr;

  if (head->next_ != nullptr && node->next_ == nullptr) {   // Node是最后一个节点
    ListNode *temp = head;
    while (temp->next_ != node)
      temp = temp->next_;
    temp->next_ = nullptr;
    return head;
  }
                                                            // 正常情况, O(1)删除
  auto next_node = node->next_;
  node->val_ = next_node->val_;
  node->next_ = next_node->next_;

  return head;
}

void Print(ListNode *head) {
  while (head->next_ != nullptr) {
    printf("%d -> ", head->val_);
    head = head->next_;
  }
  printf("\n");
}

int main(void) {
  auto l1 = new ListNode(1);
  l1->next_ = new ListNode(2);
  l1->next_->next_ = new ListNode(3);
  Print(l1);                                // 原链表

  DeleteNode(l1, l1->next_);                // O(1)删除
  Print(l1);

  DeleteNode(l1, l1->next_);                // 删除尾节点
  Print(l1);

  DeleteNode(l1, l1);                       // 有且仅有一个节点
  Print(l1);

  return 0;
}
