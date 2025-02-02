class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    if (root->left != nullptr) {
      return root->right != nullptr
          ? hasPathSum(root->left, targetSum - root->val) ||
              hasPathSum(root->right, targetSum - root->val)
          : hasPathSum(root->left, targetSum - root->val);
    } else {
      return root->right != nullptr
          ? hasPathSum(root->right, targetSum - root->val)
          : root->val == targetSum;
    }
  }
};
