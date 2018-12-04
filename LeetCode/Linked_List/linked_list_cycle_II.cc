/*
 * @filename:    linked_list_cycle_II.cc
 * @author:      Crow
 * @date:        12/04/2018 16:07:47
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
/*
 * How to get the entrance of the list ?
 * First: this list must have a cycle, (How to judge ? => LeetCode 141);
 * Then, we have these inferences:
 *
 *  |       L       |
 *  |  a  |    x    |
 *  1 → → 2 → → 3 → 4
 *        ↑         ↓   <- r 
 *        ← ← ← ← ← ←       
 *  L: the list whole length
 *  a: from head -> entrance
 *  x: from entrance -> meeting point
 *  r: the cycle length
 *
 *  we can get this conclusion: 
 *  When fast == slow, if has revolve N circles,
 *  => 2s = s + n * r;
 *  => s = n * r;
 *  => a + x = n * r;
 *  => a = n * r - x;
 *  => a = (n - 1) * r + r - x;
 *  => a = (n - 1) * r + (L - a - x);
 *
 *  In time, the n = 1, so
 *  => a = (L - a - x);
 *  It means: from (head -> entrance) = from (meeting point -> entrance)
 */

// 16ms
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        bool cycle(false);
        ListNode *fast(head), *slow(head);
        while (fast->next != nullptr                           // to judge if the list has a cycle;
                && fast->next->next != nullptr
                && slow->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                cycle = true;                                  // sign it
                break;
            }
        }

        if (!cycle)                                            // if the list doesn't have a cycle
            return nullptr;

        fast = head;
        while (fast != slow) {                                 // to find the entrance
            fast = fast->next;
            slow = slow->next;
        }
        return fast;                                           // return the result
    }
};

int main(void)
{
    ListNode *l;
    l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = l->next;

    Solution s;
    auto p = s.detectCycle(l);

    std::cout << "val: " << p->val << '\n';
    return 0;
}
