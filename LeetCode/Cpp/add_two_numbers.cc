/*
 * @filename:    add_two_numbers.cc
 * @author:      Crow
 * @date:        11/26/2018 23:09:45
 * @description:
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int over(0), val(0);
        ListNode *head(new ListNode(0)), *temp(head);

        while (l1 != nullptr && l2 != nullptr) {                // while l1 && l2, add the listnode
            val = l1->val + l2->val;
            temp->next = new ListNode(val % 10);                // deal with %
            temp->next->val = (temp->next->val + over) % 10;    // save the new over. When [node->val + over] overflow
            over = (val + over)/10;                             // save the new over
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        if (l1 != nullptr) {                                    // l1 && l2 == nullptr
            while (l1 != nullptr) {
                int l1_val = l1->val + over;
                temp->next = new ListNode(l1_val % 10);
                over = l1_val / 10;
                temp = temp->next;
                l1 = l1->next;
            }
        } else {                                                // the opposite
            while (l2 != nullptr) {
                int l2_val = l2->val + over;
                temp->next = new ListNode(l2_val % 10);
                over = l2_val / 10;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        if (over)                                               // l1 == nullptr && l2 == nullptr && over != 0
            temp->next = new ListNode(over);
        
        return head->next;                                      // return the node pointer.
    }
};


class Solution_ {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3(new ListNode(0)), *temp(l3);
        int sum(0);

        while (l1 != nullptr || l2 != nullptr || sum > 0) {        // set the end 
            if (l1) {                                              // add l1->val => sum if (l1)
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {                                              // add l2->val => sum if (l2)
                sum += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(sum % 10);                   // add new node ListNode(sum % 10)
            sum /= 10;                                             // record new sum(sum / 10)
            temp = temp->next;                                     // for next loop
        }
       
        return l3->next;                                           // get the real first node (not head node)
    }
};

int main(void)
{
    Solution_ temp;

    ListNode *l1, *l2;

    // l1 = new ListNode(2);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);

    // l2 = new ListNode(5);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);

    // The overflow test
    
    l1 = new ListNode(3);
    l1->next = new ListNode(7);
    l2 = new ListNode(9);
    l2->next = new ListNode(2);

    auto t = temp.addTwoNumbers(l1, l2);
    for (; t != nullptr; t = t->next) {
        cout << t->val << " " << endl;
    }

    return 0;
}
