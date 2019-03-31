/*
 * @filename:    6_rebuild_fork_tree.cc
 * @author:      Crow
 * @date:        03/12/2019 20:14:50
 * @description:
 *          题目: 给定一颗二叉树的前序遍历和中序遍历的顺序, 重建这棵二叉树
 *          思路: 前序遍历的第一个节点就是root, 据此在中序遍历中划分出左右子树序列, 递归求解即可
 */

#include <vector>
#include <exception>
#include <iostream>

using namespace std;

// 定义二叉树节点
struct TreeNode {
  int val_;
  TreeNode *left_;
  TreeNode *right_;

  TreeNode(int val):
    val_(val), left_(nullptr), right_(nullptr) {}
};

class Solution {
 public:
  TreeNode *RebuildForkTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
      return nullptr;

    return ConstructCore(preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
  }
              // 递归函数的参数为: 前序序列起始, 前序序列结束, 中序序列起始, 中序序列结束
 private:
  TreeNode *ConstructCore(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
    auto tree_node = new TreeNode(*pre_begin);          // 构建节点
    
    if (pre_begin == pre_end) {                         // 判断序列为1时, 无子序列可返回
      if (in_begin == in_end &&
        *pre_begin == *in_begin) {
        return tree_node;
      } else {
        throw std::runtime_error("Invalid Order");
      }
    }

    vector<int>::iterator root;                         // 根据前序的根节点, 在中序中查找分节点, 划分子序列
    for (auto iter = in_begin; iter != in_end + 1; iter++) {
      if (*iter == *pre_begin) {
        root = iter;
      }
    }

    int left_len = root - in_begin;                     // 求出左子序列的长度

    auto left_pre_end = pre_begin + left_len;
    if (left_len > 0) {                                 // 若存在左子序列, 递归构建
      tree_node->left_ = ConstructCore(pre_begin + 1, left_pre_end, in_begin, root - 1);
    }
    if (left_len < pre_end - pre_begin) {               // 若存在右子序列, 递归构建
      tree_node->right_ = ConstructCore(left_pre_end + 1, pre_end, root + 1, in_end);
    }
    
    return tree_node;                                   // 最后返回根节点
  }
};

void Print(TreeNode *root)
{
  if (root == nullptr)
    return ;
  Print(root->left_);
  Print(root->right_);
  std::cout << root->val_ << std::endl;
}

int main(void)
{
  Solution solution;

  vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> in{4, 7, 2, 1, 5, 3, 8, 6};
  auto root = solution.RebuildForkTree(pre, in);
  Print(root);
}
