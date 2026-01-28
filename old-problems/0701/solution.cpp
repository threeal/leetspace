class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    root->val = val;
    return root;
  }
};
