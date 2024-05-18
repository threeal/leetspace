#include <cstdlib>

class Solution {
 public:
  int distributeCoins(TreeNode* root) {
    int movement{0};

    if (root->left != nullptr) movement += distributeCoins(root, root->left);
    if (root->right != nullptr) movement += distributeCoins(root, root->right);

    return movement;
  }

  int distributeCoins(TreeNode* parent, TreeNode* node) {
    int movement{0};

    if (node->left != nullptr) movement += distributeCoins(node, node->left);
    if (node->right != nullptr) movement += distributeCoins(node, node->right);

    if (node->val != 1) {
      parent->val += node->val - 1;
      movement += std::abs(node->val - 1);
    }

    return movement;
  }
};
