#include <vector>

class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return new TreeNode(nums.size());
  }
};
