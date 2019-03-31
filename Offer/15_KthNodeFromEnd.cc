/*
 * @filename:    KthNodeFromEnd.cc
 * @author:      Crow
 * @date:        03/31/2019 22:25:26
 * @description:
 *           问题描述: 返回链表倒数第K个节点
 *           解法: 双指针, 判环, 判交点, 都是类似做法
 *           注意事项:
 *             1. 空链表
 *             2. K == 0
 *             3. list.size() < K
 *             此三种边界情况全部返回 nullptr
 *
 *           相似题目:
 *             1. 求解中间节点 => V ptrA : V ptrB = 1 : 2, 则ptrB到达尾节点时, ptrA即为所求
 *             2. 判断是否有环
 *             3. 判断两条链表是否相交, 即可连接一条首尾, 判断有无环即可.
 */   

#include <iostream>

struct ListNode {
  int val_;
  ListNode *next_;
  ListNode(int val) : val_(val), next_(nullptr) { ; }
};

ListNode *KthNodeFromEnd(ListNode *head, int K) {
  if (head == nullptr)                                  // 处理空链表情况
    return nullptr;

  if (K == 0)                                           // 处理K == 0
    return nullptr;

  ListNode *ptrA_(head), *ptrB_(head);
  for (int i = 0; i <= K - 1; ++i) {
    if (ptrA_ != nullptr)
      ptrA_ = ptrA_->next_;
    else                                                // 一旦list.size() < K, 则肯定返回nullptr
      return nullptr;
  }

  while (ptrA_ != nullptr) {                            // 双指针移动定位node
    ptrA_ = ptrA_->next_;
    ptrB_ = ptrB_->next_;
  }

  return ptrB_;
}

int main(void) {
  ListNode *l = new ListNode(1);
  l->next_ = new ListNode(2);
  l->next_->next_ = new ListNode(3);
  l->next_->next_->next_ = new ListNode(4);

  std::cout << KthNodeFromEnd(l, 1)->val_ << std::endl;
  std::cout << KthNodeFromEnd(l, 2)->val_ << std::endl;
}
