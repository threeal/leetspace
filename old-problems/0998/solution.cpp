class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    root->val = val;
    return root;
  }
};
