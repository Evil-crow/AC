/*
 * @filename:    swap_nodes_in_pairs.cc
 * @author:      Crow
 * @date:        12/01/2018 18:34:41
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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *phead(new ListNode(0));
        ListNode *prev(phead), *cur(phead), *next(phead);
        phead->next = head;            // use head pointer to make sure the first node is safe

        // make sure while the rest list has odd number node, that we'll swap the pair, 
        while (cur->next != nullptr && cur->next->next != nullptr) {          
            prev = cur;
            cur = cur->next;
            next = cur->next;
            cur->next = next->next;
            prev->next = next;
            next->next = cur;
        }

        return phead->next;
    }
};

int main(void)
{
    Solution t;

    ListNode *l;
    l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);

    auto p = t.swapPairs(l);

    for (; p != nullptr; p = p->next)
        std::cout << p->val << "->";
    std::cout << "\n";

    return 0;
}
