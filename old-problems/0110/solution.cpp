#include <limits>

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    return explore(root, 1) != -1;
  }

 private:
  static int explore(TreeNode* node, int depth) {
    if (node->left != nullptr) {
      if (node->right != nullptr) {
        const int leftDepth{explore(node->left, depth + 1)};
        if (leftDepth == -1) return -1;

        const int rightDepth{explore(node->right, depth + 1)};
        if (rightDepth == -1) return -1;

        return leftDepth > rightDepth
            ? (leftDepth - rightDepth <= 1 ? leftDepth : -1)
            : (rightDepth - leftDepth <= 1 ? rightDepth : -1);
      } else {
        const int leftDepth{explore(node->left, depth + 1)};
        return leftDepth != -1 && leftDepth - depth <= 1 ? leftDepth : -1;
      }
    } else {
      if (node->right != nullptr) {
        const int rightDepth{explore(node->right, depth + 1)};
        return rightDepth != -1 && rightDepth - depth <= 1 ? rightDepth : -1;
      } else {
        return depth;
      }
    }
  }
};
