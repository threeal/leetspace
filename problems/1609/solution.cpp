class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    return root->val % 2 == 0;
  }
};
