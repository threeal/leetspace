class Solution {
 public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    dfs(root, target);
    return root;
  }

  void dfs(TreeNode*& root, int target) {
    if (root->left != nullptr) dfs(root->left, target);
    if (root->right != nullptr) dfs(root->right, target);

    if (root->left == nullptr && root->right == nullptr && root->val == target) {
      root = nullptr;
    }
  }
};
