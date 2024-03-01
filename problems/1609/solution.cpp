#include <list>
#include <utility>

class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    std::list<TreeNode*> nodes{root};
    std::list<TreeNode*> prevNodes;

    bool isOdd = true;
    while (!nodes.empty()) {
      std::swap(prevNodes, nodes);
      nodes.clear();

      int prevVal = isOdd ? 0 : 1000001;
      for (const auto node : prevNodes) {
        if (isOdd) {
          if (node->val <= prevVal || node->val % 2 != 1)
            return false;
        } else {
          if (node->val >= prevVal || node->val % 2 != 0)
            return false;
        }
        prevVal = node->val;
        if (node->left != nullptr) nodes.push_back(node->left);
        if (node->right != nullptr) nodes.push_back(node->right);
      }

      isOdd = !isOdd;
    }

    return true;
  }
};
