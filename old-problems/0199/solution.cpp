#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> output{};
    if (root != nullptr) {
      std::queue<TreeNode*> nodes{};
      nodes.push(root);

      while (!nodes.empty()) {
        output.push_back(nodes.front()->val);
        for (std::size_t n{nodes.size()}; n != 0; --n) {
          TreeNode* node{nodes.front()};
          nodes.pop();

          if (node->right != nullptr) nodes.push(node->right);
          if (node->left != nullptr) nodes.push(node->left);
        }
      }
    }
    return output;
  }
};
