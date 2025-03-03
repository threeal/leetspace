#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> printTree(TreeNode* root) {
    const int depth = getDepth(root);

    std::vector<std::vector<std::string>> output(
        depth, std::vector<std::string>((1 << depth) - 1, ""));

    print(output, root, 0, 0, output[0].size() - 1);
    return output;
  }

 private:
  static int getDepth(TreeNode* node) {
    if (node->left != nullptr) {
      if (node->right != nullptr) {
        return 1 + std::max(getDepth(node->left), getDepth(node->right));
      } else {
        return 1 + getDepth(node->left);
      }
    } else {
      if (node->right != nullptr) {
        return 1 + getDepth(node->right);
      } else {
        return 1;
      }
    }
  }

  static void print(
      std::vector<std::vector<std::string>>& output, TreeNode* node,
      std::size_t i, std::size_t l, std::size_t r) {
    const std::size_t m = l + (r - l) / 2;
    output[i][m] = std::to_string(node->val);
    if (node->left != nullptr) print(output, node->left, i + 1, l, m - 1);
    if (node->right != nullptr) print(output, node->right, i + 1, m + 1, r);
  }
};
