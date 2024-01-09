#include <vector>

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> output;
    push_traversal(output, root);
    return output;
  }

  void push_traversal(std::vector<int>& traversal, TreeNode* node) {
    if (node == nullptr) return;
    push_traversal(traversal, node->left);
    traversal.push_back(node->val);
    push_traversal(traversal, node->right);
  }
};
