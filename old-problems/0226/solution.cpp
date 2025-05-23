#include <algorithm>

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) {
      std::swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
    }
    return root;
  }
};
