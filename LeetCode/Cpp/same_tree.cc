/*
 * @filename:    same_tree.cc
 * @author:      Crow
 * @date:        10/15/2018 21:04:16
 * @description:
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { ; }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        front_tree(p, pres);
        front_tree(q, qres);

        return pres == qres;
    }
private:
    string pres, qres;
    void front_tree(TreeNode *root, string &str)
    {
        if (root != nullptr) {
            str += std::to_string(root->val);
            front_tree(root->left, str);
            front_tree(root->right, str);
        } else
            str += "null";
    }
};

int main(void)
{
    Solution temp;

    auto a = new TreeNode(1);
    a->left = new TreeNode(2);

    auto b = new TreeNode(1);
    b->right = new TreeNode(2);

    cout << temp.isSameTree(a, b) << endl;

    return 0;
}


 // 标程: 传统的递归遍历求解判断
// bool isSameTreee(TreeNode *p, TreeNode *q)
// {
//     return dfsTree(p, q);
// }
//
// bool dfsTree(TreeNode *p, TreeNode *q)
// {
//     if (!p && !q) return true;
//     if (!p && q) return false;
//     if (p && !q) return false;
//     if (p->val != q->val) return false;
//
//     return dfsTree(p->left, q->left) && (p->right, q->right);
// }
