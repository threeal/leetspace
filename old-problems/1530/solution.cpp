class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    return root->val + distance;
  }
};
