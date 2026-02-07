#include <vector>

class Solution {
 public:
  std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    std::vector<int> output{};
    findTarget(output, root, target, k);
    return output;
  }

 private:
  int findTarget(
      std::vector<int>& output, TreeNode* node, TreeNode* target, int k) {
    if (node == target) {
      findNodes(output, node, k);
      return k - 1;
    } else {
      if (node->left != nullptr) {
        const int res{findTarget(output, node->left, target, k)};
        if (res != -1) {
          if (res == 0) {
            output.push_back(node->val);
          } else if (node->right != nullptr) {
            findNodes(output, node->right, res - 1);
          }
          return res - 1;
        }
      }

      if (node->right != nullptr) {
        const int res{findTarget(output, node->right, target, k)};
        if (res != -1) {
          if (res == 0) {
            output.push_back(node->val);
          } else if (node->left != nullptr) {
            findNodes(output, node->left, res - 1);
          }
          return res - 1;
        }
      }

      return -1;
    }
  }

 private:
  void findNodes(std::vector<int>& output, TreeNode* node, int k) {
    if (k == 0) {
      output.push_back(node->val);
    } else {
      if (node->left != nullptr) findNodes(output, node->left, k - 1);
      if (node->right != nullptr) findNodes(output, node->right, k - 1);
    }
  }
};
