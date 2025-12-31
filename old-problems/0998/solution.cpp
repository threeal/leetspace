class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root->val < val) {
      return new TreeNode(val, root, nullptr);
    }

    root->right = root->right != nullptr
        ? insertIntoMaxTree(root->right, val)
        : new TreeNode(val);

    return root;
  }
};
