/*
 * @filename:    rotate_list.cc
 * @author:      Crow
 * @date:        12/02/2018 14:37:16
 * @description:
 */

#include <iostream>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 12ms
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr)           // deal with special situation
            return head;

        ListNode *first(head), *last(nullptr);
        int length(0);

        while (first != nullptr) {                              // get the last node + length
            last = first;
            first = first->next;
            length++;
        }

        first = head;                                           // make it a circle list
        last->next = first;
        
        // loop to find the new head
        for (int i = 0; i < (length - k % length); ++i, first = first->next, last = last->next);
        last->next = nullptr;                                   // link last node to nullptr
        
        return first;                                           // get the result
    }
};

int main(void)
{
    Solution s;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

    auto p = s.rotateRight(l, 2);
    for (; p != nullptr; p = p->next)
        std::cout << p->val << "->";
    std::cout << '\n';

    return 0;
}
