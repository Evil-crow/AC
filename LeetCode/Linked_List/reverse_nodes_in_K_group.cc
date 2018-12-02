/*
 * @filename:    reverse_nodes_in_K_group.cc
 * @author:      Crow
 * @date:        12/02/2018 14:16:44
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

// 24ms normal
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int length(0);
        ListNode *temp(head);
        
        for (; temp != nullptr; temp = temp->next, ++length);           // get the length of list
        
        ListNode *phead(new ListNode(0)), 
                 *cur(head), *prev(phead);
        phead->next = head;
        
        int times = length / k;                                         // to calculate how many times to reverse
        while (times--) {
            for (int i = 1; i < k; ++i) {                               // reverse K groups
                temp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;
            }
            prev = cur;                                                 // update two pointers
            cur = cur->next;
        }

        return phead->next;                                             // get the result
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
    l->next->next->next->next->next = new ListNode(6);

    auto p = s.reverseKGroup(l, 2);

    for (; p != nullptr; p = p->next)
        cout << p->val << "->";
    cout << '\n';

    return 0;
}
