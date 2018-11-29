/*
 * @filename:    merge_two_sorted_lists.cc
 * @author:      Crow
 * @date:        10/11/2018 09:56:09
 * @description:
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
        auto head = new ListNode(0);
        auto temp(head);
        ListNode *val(nullptr);
        

        // 核心: 相较于第一版, 使用链表串联, 可以避免大量构造的开销, 提升效率
        for (; l1 != nullptr && l2 != nullptr; temp = temp->next) {    
            if (l1->val > l2->val) {
                val = l2;
                l2 = l2->next;
            } else {
                val = l1;
                l1 = l1->next;
            }
            temp->next = val;
        }
        
        auto list_ptr = (l1 == nullptr) ? l2 : l1;
        temp->next = list_ptr;
        
        return head->next;
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
