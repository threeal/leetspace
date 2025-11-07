class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int neg{0};
    if (root->left != nullptr) {
      const int res{kthSmallest(root->left, k)};
      if (res >= 0) return res;
      neg += res;
    }

    --neg;
    if (k + neg == 0) return root->val;

    if (root->right != nullptr) {
      const int res{kthSmallest(root->right, k + neg)};
      if (res >= 0) return res;
      neg += res;
    }

    return neg;
  }
};
