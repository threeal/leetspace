#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    std::vector<int> output{};
    if (root1 != nullptr) pushNodes(output, root1);
    if (root2 != nullptr) pushNodes(output, root2);
    std::sort(output.begin(), output.end());
    return output;
  }

 private:
  static void pushNodes(std::vector<int>& output, TreeNode* node) {
    output.push_back(node->val);
    if (node->left != nullptr) pushNodes(output, node->left);
    if (node->right != nullptr) pushNodes(output, node->right);
  }
};
