#include <vector>

class Solution {
 public:
  TreeNode* getTargetCopy(
      TreeNode* original, TreeNode* cloned, TreeNode* target) {
    (void)original;
    return findNode(cloned, target->val);
  }

 private:
  static TreeNode* findNode(TreeNode* node, int val) {
    if (node->val == val) return node;

    if (node->left != nullptr) {
      TreeNode* left{findNode(node->left, val)};
      if (left != nullptr) return left;
    }

    if (node->right != nullptr) {
      TreeNode* right{findNode(node->right, val)};
      if (right != nullptr) return right;
    }

    return nullptr;
  }
};
