class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (root->left != nullptr) root->left = pruneTree(root->left);
    if (root->right != nullptr) root->right = pruneTree(root->right);
    return root->val == 0 && root->left == nullptr && root->right == nullptr
        ? nullptr
        : root;
  }
};
