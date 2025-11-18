#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<double> averageOfLevels(TreeNode* root) {
    std::queue<TreeNode*> nodes{};
    if (root != nullptr) nodes.push(root);

    std::vector<double> output{};
    while (!nodes.empty()) {
      double sum{0.0};
      std::size_t n{nodes.size()};
      for (std::size_t i{0}; i < n; ++i) {
        TreeNode* node{nodes.front()};
        nodes.pop();

        sum += node->val;
        if (node->left != nullptr) nodes.push(node->left);
        if (node->right != nullptr) nodes.push(node->right);
      }
      output.push_back(sum / n);
    }

    return output;
  }
};
