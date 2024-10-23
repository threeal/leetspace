#include <queue>

class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    std::queue<TreeNode*> nodes{};

    root->val = 0;
    if (root->left != nullptr) {
      nodes.push(root->left);
      root->left->val = 0;
    }
    if (root->right != nullptr) {
      nodes.push(root->right);
      root->right->val = 0;
    }

    while (!nodes.empty()) {
      int cousinSum{0};
      for (std::size_t n{nodes.size()}; n > 0; --n) {
        if (nodes.front()->left != nullptr)
          cousinSum += nodes.front()->left->val;

        if (nodes.front()->right != nullptr)
          cousinSum += nodes.front()->right->val;

        nodes.push(nodes.front());
        nodes.pop();
      }

      for (std::size_t n{nodes.size()}; n > 0; --n) {
        int sum{0};
        if (nodes.front()->left != nullptr) {
          nodes.push(nodes.front()->left);
          sum += nodes.front()->left->val;
        }

        if (nodes.front()->right != nullptr) {
          nodes.push(nodes.front()->right);
          sum += nodes.front()->right->val;
        }

        if (nodes.front()->left != nullptr)
          nodes.front()->left->val = cousinSum - sum;

        if (nodes.front()->right != nullptr)
          nodes.front()->right->val = cousinSum - sum;

        nodes.pop();
      }
    }

    return root;
  }
};
