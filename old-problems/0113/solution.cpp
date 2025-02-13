#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> output{};
    if (root != nullptr) {
      std::vector<int> path{};
      explore(output, path, 0, root, targetSum);
    }
    return output;
  }

 private:
  static void explore(
      std::vector<std::vector<int>>& output, std::vector<int>& path, int sum,
      TreeNode* root, int targetSum) {
    path.push_back(root->val);
    sum += root->val;
    if (root->left != nullptr) {
      explore(output, path, sum, root->left, targetSum);
      if (root->right != nullptr) {
        explore(output, path, sum, root->right, targetSum);
      }
    } else {
      if (root->right != nullptr) {
        explore(output, path, sum, root->right, targetSum);
      } else {
        if (sum == targetSum) output.push_back(path);
      }
    }
    path.pop_back();
  }
};
