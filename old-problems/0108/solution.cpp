#include <vector>

class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return divideAndConquer(nums.data(), 0, nums.size() - 1);
  }

 private:
  TreeNode* divideAndConquer(int* nums, std::size_t l, std::size_t r) {
    const std::size_t mid{r - (r - l) / 2};
    TreeNode* node{new TreeNode(nums[mid])};

    if (l < mid) node->left = divideAndConquer(nums, l, mid - 1);
    if (mid < r) node->right = divideAndConquer(nums, mid + 1, r);

    return node;
  }
};
