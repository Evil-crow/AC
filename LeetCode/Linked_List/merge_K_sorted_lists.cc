/*
 * @filename:    merge_K_sorted_lists.cc
 * @author:      Crow
 * @date:        11/30/2018 19:56:29
 * @description:
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 396ms
class Solution_1 {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        ListNode *head(new ListNode(0)), *temp(head);
        ListNode **list_node_min(nullptr);                  // will be used for record the node to link

restart:    while (lists.size() != 0) {
            list_node_min = &lists[0];
            for (auto pos = lists.begin(); pos != lists.end(); ++pos) {
                if (!(*pos)) {                              // if pos == nullptr, remove it and restart.
                    pos = lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
                    goto restart;
                }
                if ((*pos)->val < (*list_node_min)->val)    // record the min node
                    list_node_min = &*pos;
            }
            temp->next = new ListNode((*list_node_min)->val);      // new node to link
            *list_node_min = (*list_node_min)->next;               // the node which insert to move to ->next
            temp = temp->next;
        }

        return head->next;                                  // return list head;
    }
};

// 28ms
class Solution_2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> temp;

        for (auto var : lists) {                            // emplace_bakc all val into vector
            while (var != nullptr) {
                temp.emplace_back(var->val);
                var = var->next;
            }
        }

        sort(temp.begin(), temp.end());                     // sort it
        ListNode *head(new ListNode(0)), *list_temp(head);

        for (auto var : temp) {                             // make new list
            list_temp->next = new ListNode(var);
            list_temp = list_temp->next;
        }

        return head->next;                                  // return node
    }
};

int main(void)
{
    Solution_2 s;
    ListNode *l1, *l2, *l3;

    l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    std::vector<ListNode *> vec{l1, l2, l3};
    auto head = s.mergeKLists(vec);

    for (; head != nullptr; head = head->next)
        cout << head->val << "->";
    cout << endl;

    return 0;
}
