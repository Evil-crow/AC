/*
 * @filename:    middle_of_the_linked_list.cc
 * @author:      Crow
 * @date:        12/05/2018 10:07:58
 * @description:
 */

#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 0ms
class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *fast(head), *slow(head);

        // use fast-slow pointer to find the middle one-pass
        while (fast->next != nullptr
                && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast->next)                                     // odd number length
            return slow->next;
        return slow;                                        // even number length
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
    // l->next->next->next->next->next = new ListNode(6);

    Solution s;
    auto p = s.middleNode(l);

    cout << p->val << '\n';

    return 0;
}
