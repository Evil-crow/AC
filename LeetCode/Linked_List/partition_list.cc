/*
 * @filename:    partition_list.cc
 * @author:      Crow
 * @date:        12/02/2018 19:05:02
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

// 8ms
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *phead(new ListNode(0));
        phead->next = head;

        // @link is where to insert
        // @cur is current node
        // @prev is used to sign previous node to insert node
        
        ListNode *link(phead), *cur(head), *prev(phead);
        while (cur != nullptr) {                           // loop until the end of list
            if (cur->val < x) {                            // need to swap
                prev->next = cur->next;                    // link the prev to cur->next, means cut the node out
                cur->next = link->next;                    // insert the node to correct position
                link->next = cur;
                link = cur;
            }
            prev = cur;                                    // update the "prev" and "cur" position
            cur = cur->next;
        }

        return phead->next;
    }
};

int main(void)
{
    ListNode *l;
    l = new ListNode(1);
    l->next = new ListNode(4);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(2);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = new ListNode(2);

    Solution s;
    auto p = s.partition(l, 4);
    for (; p != nullptr; p = p->next)
        cout << p->val << "->";
    cout << '\n';

    return 0;
}
