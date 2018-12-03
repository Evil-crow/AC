/*
 * @filename:    reverse_linked_list_II.cc
 * @author:      Crow
 * @date:        12/03/2018 19:23:50
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

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *phead(new ListNode(0));
        ListNode *first(phead);
        phead->next = head;

        for (int i = 1; i < m; ++i)                     // find the start point
            first = first->next;
        
        first->next = reverse(first->next, n - m);      // reverse list

        return phead->next;                             // get result
    } 

private:
    ListNode *reverse(ListNode *head, int times) {      // the same as other problem
        ListNode *phead(new ListNode(0));
        phead->next = head;
        ListNode *cur(head), *next(head->next);

        while (times--) {                               // reverse The nums times node
            cur->next = next->next;
            next->next = phead->next;
            phead->next = next;
            next = cur->next;
        }

        return phead->next;
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

    Solution s;

    auto p = s.reverseBetween(l, 2, 4);
    for (; p != nullptr; p = p->next)
        std::cout << p->val << "->";
    std::cout << '\n';

    return 0;
}

