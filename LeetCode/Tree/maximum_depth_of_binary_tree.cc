/*
 * @filename:    maximum_depth_of_binary_tree.cc
 * @author:      Crow
 * @date:        10/16/2018 15:53:34
 * @description:
 */

#include <iostream>
#include <vector>
#include <functional>

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
    int maxDepth(TreeNode* root) {
        auto num(0);
        cal_depth(root, num, max);

        return max;
    }
private:
    int max;
    void cal_depth(TreeNode *root, int num, int &max) {
        if (root == nullptr)
            return ;
        if (root != nullptr)
            num++;
        max = (max > num) ? max : num;
        cal_depth(root->left, num, max);
        cal_depth(root->right, num, max);
    }
};

// lambda ver.
class _Solution {
public:
    int maxDepth(TreeNode *root) {
        auto num{0}, max{0};
        std::function<void (TreeNode *root, int num)> x = 
            [&x, &max](TreeNode *root, int num) {
            if (root == nullptr)
                return ;
            num++;
            max = std::max(max, num);
            x(root->left, num);
            x(root->right, num);
        };
        x(root, num);

        return max;
    }
private:

}

int main(void)
{
    Solution temp;

    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << temp.maxDepth(root) << endl;
    
    return 0;
}
