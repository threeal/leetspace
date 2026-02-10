#include <algorithm>

class Solution {
 public:
  int longestZigZag(TreeNode* root) {
    return explore(root, 0, 0);
  }

  int explore(TreeNode* node, int left, int right) {
    if (node->left != nullptr) {
      if (node->right != nullptr) {
        return std::max(
            explore(node->left, 1 + right, 0),
            explore(node->right, 0, 1 + left));
      } else {
        return std::max(left, explore(node->left, 1 + right, 0));
      }
    } else {
      if (node->right != nullptr) {
        return std::max(right, explore(node->right, 0, 1 + left));
      } else {
        return std::max(left, right);
      }
    }
  }
};
