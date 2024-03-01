#include <list>

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    std::list<TreeNode*> nodes{root};
    std::list<TreeNode*> prevNodes{};

    while (!nodes.empty()) {
      prevNodes = nodes;
      nodes.clear();

      for (const auto node : prevNodes) {
        if (node->left != nullptr) nodes.push_back(node->left);
        if (node->right != nullptr) nodes.push_back(node->right);
      }
    }

    return prevNodes.front()->val;
  }
};
