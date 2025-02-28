class Solution {
 public:
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    if (root->left != nullptr) {
      if (root->right != nullptr) {
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        return (root->left != nullptr || root->right != nullptr) ? root : nullptr;
      } else {
        root->left = sufficientSubset(root->left, limit - root->val);
        return root->left != nullptr ? root : nullptr;
      }
    } else {
      if (root->right != nullptr) {
        root->right = sufficientSubset(root->right, limit - root->val);
        return root->right != nullptr ? root : nullptr;
      } else {
        return root->val >= limit ? root : nullptr;
      }
    }
  }
};
