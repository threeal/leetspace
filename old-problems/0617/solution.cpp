class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return root1 != nullptr ? root1 : root2;
  }
};
