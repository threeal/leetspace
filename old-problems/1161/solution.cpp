#include <queue>

class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    int maxSum{root->val}, maxSumLevel{1};

    std::queue<TreeNode*> nodes{};
    if (root->left) nodes.push(root->left);
    if (root->right) nodes.push(root->right);

    for (int level{2}; !nodes.empty(); ++level) {
      int sum{0};

      for (std::size_t n{nodes.size()}; n != 0; --n) {
        TreeNode* node{nodes.front()};
        nodes.pop();

        sum += node->val;
        if (node->left) nodes.push(node->left);
        if (node->right) nodes.push(node->right);
      }

      if (sum > maxSum) {
        maxSum = sum;
        maxSumLevel = level;
      }
    }

    return maxSumLevel;
  }
};
