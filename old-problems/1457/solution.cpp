#include <stdint.h>

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    return countPseudoPalindromic(root, 0);
  }

  int countPseudoPalindromic(TreeNode* root, uint16_t flags) {
    flags ^= 1 << root->val;
    if (root->left != nullptr) {
      if (root->right != nullptr) {
        return countPseudoPalindromic(root->left, flags) + countPseudoPalindromic(root->right, flags);
      } else {
        return countPseudoPalindromic(root->left, flags);
      }
    } else if (root->right != nullptr) {
      return countPseudoPalindromic(root->right, flags);
    } else {
      return __builtin_popcount(flags) <= 1 ? 1 : 0;
    }
  }
};
