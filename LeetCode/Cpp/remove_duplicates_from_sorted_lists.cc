/*
 * @filename:    remove_duplicates_from_sorted_lists.cc
 * @author:      Crow
 * @date:        10/14/2018 16:37:16
 * @description:
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)                            // Runtime Error: 一旦head是nullptr, 会造成cur, UB, 使用空指针
            return nullptr;
        ListNode *prev(head), *cur(head->next);
        while (cur != nullptr) {                        // 去重后, 自动移动
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = prev->next;
            } else {                                    // 不进行去重时, 手动移动
                cur = cur->next;
                prev = prev->next;
            }
        }

        return head;
    }
};

ListNode *create_list()
{
    int val;
    int count(5);
    auto head = new ListNode(0);
    auto temp(head);

    while (count--) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    return head->next;
}

int main(void)
{
    Solution temp;
    auto a = create_list();
    auto x = temp.deleteDuplicates(a);
    while (x != nullptr) {
        cout << x->val << "->";
        x = x->next;
    }

    cout << endl;
    return 0;
}
