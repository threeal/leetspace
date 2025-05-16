class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    root->val = val;
    return root;
  }
};
