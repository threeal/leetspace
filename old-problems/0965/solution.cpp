class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    if (root->left != nullptr &&
        (root->val != root->left->val || !isUnivalTree(root->left))) {
      return false;
    }

    if (root->right != nullptr &&
        (root->val != root->right->val || !isUnivalTree(root->right))) {
      return false;
    }

    return true;
  }
};
