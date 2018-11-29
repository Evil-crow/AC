/*
 * @filename:    symmetric_tree.cc
 * @author:      Crow
 * @date:        10/15/2018 21:45:59
 * @description:
 */

#include <iostream>
#include <string>
#include <vector>

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
    bool isSymmetric(TreeNode* root) {
        middle_tree(root);
        
        for (auto i : valvertor)
            cout << i << " ";
        cout << endl;
        vector<int> reverse(valvertor.crbegin(), valvertor.crend());
        for (size_t i = 0; i < valvertor.size(); ++i) {
            if (valvertor[i] == reverse[i])
                continue;
            else
                return false;
        }

        return true;
    }
private:
    vector<int> valvertor;
    void middle_tree(TreeNode *root)
    {
        if (root != nullptr) {
            middle_tree(root->left);
            valvertor.emplace_back(root->val);
            middle_tree(root->right);
        }
    }
};

int main(void)
{
    Solution temp;
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(2);

    cout << temp.isSymmetric(root) << endl;
    return 0;

}
