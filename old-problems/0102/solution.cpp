#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    std::queue<TreeNode*> nodes{};
    nodes.push(root);

    std::vector<std::vector<int>> output{};
    while (!nodes.empty()) {
      output.push_back({});
      output.back().reserve(nodes.size());
      for (std::size_t n{nodes.size()}; n != 0; --n) {
        TreeNode* node{nodes.front()};
        nodes.pop();

        if (node->left != nullptr) nodes.push(node->left);
        if (node->right != nullptr) nodes.push(node->right);

        output.back().push_back(node->val);
      }
    }

    return output;
  }
};
