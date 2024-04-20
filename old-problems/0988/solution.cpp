#include <algorithm>
#include <string>

class Solution {
 public:
  std::string smallestFromLeaf(TreeNode* root) {
    return smallestFromLeaf(root, "");
  }

  std::string smallestFromLeaf(TreeNode* node, const std::string& str) {
    if (node->left != nullptr) {
      if (node->right != nullptr) {
        return std::min(
            smallestFromLeaf(node->left, static_cast<char>('a' + node->val) + str),
            smallestFromLeaf(node->right, static_cast<char>('a' + node->val) + str));
      } else {
        return smallestFromLeaf(node->left, static_cast<char>('a' + node->val) + str);
      }
    } else if (node->right != nullptr) {
      return smallestFromLeaf(node->right, static_cast<char>('a' + node->val) + str);
    } else {
      return static_cast<char>('a' + node->val) + str;
    }
  }
};
