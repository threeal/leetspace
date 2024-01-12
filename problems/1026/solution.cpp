#include <set>

class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    std::multiset<int> ancestors{root->val};
    return maxDifferences(ancestors, root);
  }

  int maxDifferences(std::multiset<int>& ancestors, TreeNode* node) {
    int differences = std::max(
        std::abs(*ancestors.begin() - node->val),
        std::abs(*ancestors.rbegin() - node->val));

    if (node->left == nullptr && node->right == nullptr) {
      return differences;
    }

    ancestors.insert(node->val);

    if (node->left != nullptr) {
      if (node->right != nullptr) {
        differences = std::max(
            differences,
            std::max(
                maxDifferences(ancestors, node->left),
                maxDifferences(ancestors, node->right)));
      } else {
        differences = std::max(differences, maxDifferences(ancestors, node->left));
      }
    } else if (node->right != nullptr) {
      differences = std::max(differences, maxDifferences(ancestors, node->right));
    }

    ancestors.erase(node->val);

    return differences;
  }
};
