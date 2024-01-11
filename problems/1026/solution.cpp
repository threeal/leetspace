#include <list>

class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    std::list<int> ancestors{root->val};
    return maxDifferences(ancestors, root);
  }

  int maxDifferences(std::list<int>& ancestors, TreeNode* node) {
    int differences = std::max(
        std::abs(ancestors.front() - node->val),
        std::abs(ancestors.back() - node->val));

    if (node->left == nullptr && node->right == nullptr) {
      return differences;
    }

    ancestors.insert(std::lower_bound(ancestors.begin(), ancestors.end(), node->val), node->val);

    if (node->left != nullptr) {
      if (node->right != nullptr) {
        differences = std::max({
            differences,
            maxDifferences(ancestors, node->left),
            maxDifferences(ancestors, node->right)});
      } else {
        differences = std::max(differences, maxDifferences(ancestors, node->left));
      }
    } else if (node->right != nullptr) {
      differences = std::max(differences, maxDifferences(ancestors, node->right));
    }

    ancestors.erase(std::find(ancestors.begin(), ancestors.end(), node->val));

    return differences;
  }
};
