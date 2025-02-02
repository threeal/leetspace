class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return root != nullptr && root->val == targetSum;
  }
};
