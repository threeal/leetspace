#include <limits>

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isInRange(
        root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  }

 private:
  static bool isInRange(TreeNode* root, int min, int max) {
    if (root->val < min || root->val > max) return false;
    if (root->left != nullptr) {
      if (root->val == std::numeric_limits<int>::min()) return false;
      if (!isInRange(root->left, min, root->val - 1)) return false;
    }
    if (root->right != nullptr) {
      if (root->val == std::numeric_limits<int>::max()) return false;
      if (!isInRange(root->right, root->val + 1, max)) return false;
    }
    return true;
  }
};
