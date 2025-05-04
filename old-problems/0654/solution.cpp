#include <vector>

class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    return new TreeNode(nums.front());
  }
};
