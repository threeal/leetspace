#include <vector>

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> output{};
    if (root != nullptr) traverse(output, root);
    return output;
  }

  void traverse(std::vector<int>& output, TreeNode* node) {
    if (node->left != nullptr) traverse(output, node->left);
    if (node->right != nullptr) traverse(output, node->right);
    output.push_back(node->val);
  }
};
