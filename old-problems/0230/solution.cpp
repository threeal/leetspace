class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    return root->val + k;
  }
};
