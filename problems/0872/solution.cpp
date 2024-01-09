#include <list>

class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::list<int> leaves1, leaves2;
    pushLeaves(leaves1, root1);
    pushLeaves(leaves2, root2);

    auto it1 = leaves1.begin();
    auto it2 = leaves2.begin();
    while (it1 != leaves1.end() && it2 != leaves2.end()) {
      if (*it1 != *it2) return false;
      ++it1;
      ++it2;
    }

    return it1 == leaves1.end() && it2 == leaves2.end();
  }

  void pushLeaves(std::list<int>& leaves, TreeNode* node) {
    if (node->left != nullptr) {
      pushLeaves(leaves, node->left);
      if (node->right != nullptr) {
        pushLeaves(leaves, node->right);
      }
    } else {
      if (node->right != nullptr) {
        pushLeaves(leaves, node->right);
      } else {
        leaves.push_back(node->val);
      }
    }
  }
};
