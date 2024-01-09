class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return 0;

    int sum = 0;
    if (root->val >= low && root->val <= high) {
      sum += root->val;
    }

    if (low < root->val) {
      sum += rangeSumBST(root->left, low, high);
    }

    if (high > root->val) {
      sum += rangeSumBST(root->right, low, high);
    }

    return sum;
  }
};
