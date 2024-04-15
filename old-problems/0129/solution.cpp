class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
  }

  int sumNumbers(TreeNode* root, int parent) {
    if (root->left != nullptr) {
      if (root->right != nullptr) {
        return sumNumbers(root->left, (parent + root->val) * 10) + sumNumbers(root->right, (parent + root->val) * 10);
      } else {
        return sumNumbers(root->left, (parent + root->val) * 10);
      }
    } else if (root->right != nullptr) {
      return sumNumbers(root->right, (parent + root->val) * 10);
    } else {
      return parent + root->val;
    }
  }
};
