#include <limits>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> largestValues(TreeNode* root) {
    std::vector<int> values{};
    if (root == nullptr) return values;

    std::queue<TreeNode*> nodes{};
    nodes.push(root);

    while (!nodes.empty()) {
      int maxValue{std::numeric_limits<int>::min()};
      for (std::size_t n{nodes.size()}; n > 0; --n) {
        const auto node = nodes.front();
        nodes.pop();

        if (node->val > maxValue) maxValue = node->val;
        if (node->left != nullptr) nodes.push(node->left);
        if (node->right != nullptr) nodes.push(node->right);
      }
      values.push_back(maxValue);
    }

    return values;
  }
};
