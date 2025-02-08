class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    return isEqual(root->left, root->right);
  }

 private:
  static bool isEqual(TreeNode* left, TreeNode* right) {
    if (left != nullptr) {
      if (right == nullptr || left->val != right->val) return false;
      return isEqual(left->left, right->right) &&
          isEqual(left->right, right->left);
    }
    return right == nullptr;
  }
};
