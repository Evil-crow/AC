/*
 * @filename:    merge_two_sorted_lists.cc
 * @author:      Crow
 * @date:        10/11/2018 09:56:09
 * @description: 此版本的代码, 大量使用了构造, 可以预想在list比较长的情况下
 *            构造会有极大的开销 => 事实: leetcode上, 14ms (14.33%)
 *            另一个版本,是进行链表的串联, 效率大幅提高 => 8ms (90.50%)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { ; }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto head = new ListNode(0);                            // 切记, nullptr和分配的头节点不同
        auto temp(head);                                        // 进行尾插的中继节点
        auto val(0);

        // 核心: 两个指针相继移动, val较小者, 进行构造
        for (; l1 != nullptr && l2 != nullptr; temp = temp->next) {    
            if (l1->val > l2->val) {                            
                val = l2->val;
                l2 = l2->next;
            } else {
                val = l1->val;
                l1 = l1->next;
            }
            temp->next = new ListNode(val);                     // 构造新节点
        }
        
        auto list_ptr = (l1 == nullptr) ? l2 : l1;              // 将剩余节点全部连接
        for (; list_ptr != nullptr; list_ptr = list_ptr->next) {
            temp->next = new ListNode(list_ptr->val);
            temp = temp->next;
        }
        
        return head->next;                                      // 返回头之后的节点
    }
};

ListNode *create_list()
{
    int count(3);
    int val(0);
    auto head = new ListNode(0);
    auto temp(head);

    while (count--) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    
    return head->next;
}

int main(void)
{
    Solution temp;
    auto l1 = create_list();
    auto l2 = create_list();

    auto l3 = temp.mergeTwoLists(l1, l2);
    for (; l3 != nullptr; l3 = l3->next)
        cout << l3->val << "->";
    cout << endl;

    return 0;
}
