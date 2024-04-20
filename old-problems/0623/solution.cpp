class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    switch (depth) {
      case 1:
        return new TreeNode(val, root, nullptr);

      case 2:
        root->left = new TreeNode(val, root->left, nullptr);
        root->right = new TreeNode(val, nullptr, root->right);
        return root;

      default:
        if (root->left != nullptr) addOneRow(root->left, val, depth - 1);
        if (root->right != nullptr) addOneRow(root->right, val, depth - 1);
        return root;
    }
  }
};
