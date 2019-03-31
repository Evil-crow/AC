/*
 * @filename:    5_print_node_reverse.cc
 * @author:      Crow
 * @date:        03/12/2019 19:03:11
 * @description:
 *        题目: 输入一个链表的头节点, 从尾到头打印链表的节点值
 *        思路: 栈或者递归进行操作,即可实现倒序输出.
 */

#include <iostream>
#include <vector>

struct ListNode {
  ListNode(int val):
    val_(val), next_(nullptr) {}
  
  int val_;
  ListNode *next_;
};


// 递归解法
// class Solution {
//  public:
//   void PrintNodeReverse(ListNode *head) {
//     if (head == nullptr)
//       return ;
//     PrintNodeReverse(head->next_);
//     std::cout << head->val_ << " ";
//   }
// };

// 使用栈的解法，可使用std::vector 亦可使用std::stack进行容器适配器操作
class Solution {
 public:
  void PrintNodeReverse(ListNode *head) {
    std::vector<ListNode *> vec; 
    while (head != nullptr) {
      vec.emplace_back(head);
      head = head->next_;
    }
    while (!vec.empty()) { 
      auto var = vec.back();
      std::cout << var->val_ << " ";
      vec.pop_back();
    }
    std::cout << std::endl;
  }
};



int main(void)
{
  Solution solution;

  ListNode *head = new ListNode(1);
  head->next_ = new ListNode(2);
  head->next_->next_ = new ListNode(3);
  head->next_->next_->next_ = new ListNode(4);

  solution.PrintNodeReverse(head);

  ListNode *ptr = nullptr;
  solution.PrintNodeReverse(ptr);
}
