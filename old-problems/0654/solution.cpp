#include <vector>

class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    std::vector<TreeNode*> nodes{};
    for (const int num : nums) {
      TreeNode* node{new TreeNode(num)};
      while (!nodes.empty() && nodes.back()->val < num) {
        node->left = nodes.back();
        nodes.pop_back();
      }
      if (!nodes.empty()) nodes.back()->right = node;
      nodes.push_back(node);
    }
    return nodes.front();
  }
};
