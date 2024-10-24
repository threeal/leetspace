class Solution {
 public:
  bool flipEquiv(TreeNode* a, TreeNode* b) {
    if (a == nullptr || b == nullptr) return a == b;
    if (a->val != b->val) return false;
    return (flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right)) ||
        (flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left));
  }
};
