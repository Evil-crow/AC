/*
 * @filename:    6_extra_ergodic_fork_tree.cc
 * @author:      Crow
 * @date:        03/12/2019 21:11:21
 * @description:
 *      这部分是额外内容, 关于树的三类遍历的六种实现
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val_;
  TreeNode *left_;
  TreeNode *right_;

  TreeNode(int val)
    : val_(val), left_(nullptr), right_(nullptr){}
};

void Print(TreeNode *root) {
  std::cout << root->val_ << " ";
}

void PreErgodic(TreeNode *root) {
  if (root == nullptr)
    return;
  Print(root);
  PreErgodic(root->left_);
  PreErgodic(root->right_);
}

void MidErgodic(TreeNode *root) {
  if (root == nullptr)
    return ;
  MidErgodic(root->left_);
  Print(root);
  MidErgodic(root->right_);
}

void PostErgodic(TreeNode *root) {
  if (root == nullptr)
    return ;
  PostErgodic(root->left_);
  PostErgodic(root->right_);
  Print(root);
}

void PreErgodicByStack(TreeNode *root) {
  if (root == nullptr)
    return ;
  
  std::vector<TreeNode *> vec;
  vec.emplace_back(root);              // 根节点入栈
  
  while (!vec.empty()) {
    auto node = vec.back();            // 访问根节点, 并出栈
    vec.pop_back();
    Print(node);

    // 右, 左子树入栈, 可以保证先访问左子树
    if (node->right_)                 
      vec.emplace_back(node->right_);
    if (node->left_)
      vec.emplace_back(node->left_);
  }

}

void MidErgodicByStack(TreeNode *root) {
  if (root == nullptr)
    return ;

  std::vector<TreeNode *> vec;
  while (!vec.empty() || root != nullptr) {
    if (root) {                               // 如果有左子树, 一直入栈到左下角
      vec.emplace_back(root);
      root = root->left_;
    } else {                  
      auto node = vec.back();                 // 到做左下角之后就可以开始访问了
      Print(node);
      vec.pop_back();

      root = node->right_;                    // 访问结束后, 转到对应的右子树, 继续进行原来的移动到左下角
    }
  }
}

void PostErgodicByStack(TreeNode *root) {
  if (root == nullptr)
    return ;

  std::vector<TreeNode *> vec;
  TreeNode *prev{nullptr};

  vec.emplace_back(root);
  while (!vec.empty()) {
    auto node = vec.back();

    if ((node->left_ == nullptr && node->right_ == nullptr) ||          // 对于叶子节点
        (node && (node->left_ == prev || node->right_ == prev))) {      // 对于可访问根节点情况, 有时不一定是完全二叉树
      Print(node);
      vec.pop_back();
      prev = node;
    } else {                                                            // 左侧全部入栈
      if (node->right_)
        vec.emplace_back(node->right_);
      if (node->left_)
        vec.emplace_back(node->left_);
    }
  }
}


int main(void)
{
  TreeNode *root = new TreeNode(1);
  root->left_ = new TreeNode(2);
  root->right_ = new TreeNode(3);
  root->left_->left_ = new TreeNode(4);
  root->left_->right_ = new TreeNode(5);
  root->right_->left_ = new TreeNode(6);
  root->right_->right_ = new TreeNode(7);

  PreErgodicByStack(root);
  std::cout << '\n';
  MidErgodicByStack(root);
  std::cout << '\n';
  PostErgodicByStack(root);
  std::cout << '\n';
}
