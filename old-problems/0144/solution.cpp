#include <vector>

class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> out{};
    if (root != nullptr) traverse(out, root);
    return out;
  }

 private:
  void traverse(std::vector<int>& out, TreeNode* root) {
    out.push_back(root->val);
    if (root->left != nullptr) traverse(out, root->left);
    if (root->right != nullptr) traverse(out, root->right);
  }
};
