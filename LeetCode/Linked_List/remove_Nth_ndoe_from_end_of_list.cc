/*
 * @filename:    remove_Nth_ndoe_from_end_of_list.cc
 * @author:      Crow
 * @date:        11/29/2018 17:42:45
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

// Time: 4ms
// I think Solution::reverse() is ugly
// And we need to judge these especial situation -> no elements / only one elements
// It makes code so messy.

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return nullptr;

        ListNode *phead = new ListNode(0);
        phead->next = head;

        phead->next = reverse(phead->next);
        ListNode *temp(phead);
        for (int i = 1; i <= n - 1; ++i)
            temp = temp->next;
        temp->next = temp->next->next;
        phead->next = reverse(phead->next);

        return phead->next;
    }

private:
    // we can reverse if and only if the list.size() >= 2
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *cur(head);
        ListNode *phead = new ListNode(0);
        phead->next = head;

        while (cur->next != NULL) {
            ListNode *prev = phead->next;
            phead->next = cur->next;
            cur->next = cur->next->next;
            phead->next->next = prev;
        }

        return phead->next;
    }
};


// Time: 8ms
// Maybe the time is twice to Solution. 
// But this solution is so easy to make it
// Two passing Emmmm, sometimes may do superfluous work
// There is another method use recurise. 
// But I think stack space cost is so expensive to use that method
class Solution_1 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *temp(head);
        int length(0), pos(0);

        // get the length
        for (; temp != nullptr; temp = temp->next, length++);
        pos = length - n;

        ListNode *phead = new ListNode(0);
        phead->next = head;

        ListNode *prev(phead);
        temp = phead->next;
        while (pos--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        return phead->next;
    }
};

// Also , I have thought anthor method. USE STL => std::list<ListNode>
// 1. PUSH INTO Container
// 2. ERASE the element
// 3. GET OUT FROM Container
// I haven't test it. Maybe the cost is not cheap 233.

int main(void)
{
    Solution_1 s;
    ListNode *l;

    l = new ListNode(1);
    l->next = new ListNode(2);
    // l->next->next = new ListNode(3);
    // l->next->next->next = new ListNode(4);
    // l->next->next->next->next = new ListNode(5);

    l = s.removeNthFromEnd(l, 1);
    for (; l != nullptr; l = l->next)
        cout << l->val << endl;

    return 0;
}
