/*
 * @filename:    linked_list_circle.cc
 * @author:      Crow
 * @date:        12/04/2018 15:51:22
 * @description:
 */

#include <iostream>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)                           // deal with exceptional case
            return false;

        ListNode *fast(head), *slow(head);
        while (fast->next != nullptr && fast->next->next != nullptr) {          // length is odd/even
            fast = fast->next->next;                                            // fast pointer move 2 steps each time
            slow = slow->next;                                                  // slow pointer move 1 step each time
            if (fast == slow)                                                   // if fast == slow means , there is a cycle
                return true;
        }

        return false;                                                           // out of loop, means no cycle
    }
};

int main(void)
{
    ListNode *l;
    l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next = l->next->next;

    Solution s;
    auto res = s.hasCycle(l);

    std::cout << res << std::endl;

    return 0;
}
