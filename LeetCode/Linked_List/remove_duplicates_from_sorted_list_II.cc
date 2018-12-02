/*
 * @filename:    remove_duplicates_from_sorted_list_II.cc
 * @author:      Crow
 * @date:        12/02/2018 14:57:04
 * @description:
 */

#include <iostream>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 4ms
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *phead(new ListNode(0));
        phead->next = head;

        ListNode *cur(head->next), *prev(phead);       // record the previous and current pointer
        ListNode *first(head), *last(head);            // Sign pointer
        int val(head->val);                            // record the val

        while (cur != nullptr) {
            if (cur->val == val) {                     // if val equals, move the last to current pointer;
                last = cur;
            } else {                                   // if not, means to delete duplicated range or a new val
                if (last != first) {                   // delete duplicated range
                    prev->next = last->next;
                    first = prev->next;
                    last = prev->next;
                    val = prev->next->val;             // After delete, we need a new val to compare
                } else {                               // set new val settings
                    first = cur;
                    last = cur;
                    prev = prev->next;
                    val = cur->val;
                }
            }
            cur = cur->next;
        }
        if (first != last)                             // if tha rest are all have same values, we need delete them out of loop
            prev->next = last->next;

        return phead->next;                            // return the result
    }
};

int main(void)
{
    ListNode *l;
    l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(1);
    // l->next->next->next = new ListNode(3);
    // l->next->next->next->next = new ListNode(4);
    // l->next->next->next->next->next = new ListNode(4);
    // l->next->next->next->next->next->next = new ListNode(5);

    Solution s;
    auto p = s.deleteDuplicates(l);
    for (; p != nullptr; p = p->next)
        std::cout << p->val << "->";
    std::cout << '\n';

    return 0;
}
