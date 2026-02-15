class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root->val >= low) {
      if (root->val <= high) {
        if (root->left != nullptr) {
          root->left = trimBST(root->left, low, high);
        }

        if (root->right != nullptr) {
          root->right = trimBST(root->right, low, high);
        }

        return root;
      } else {
        return root->left != nullptr
            ? trimBST(root->left, low, high)
            : nullptr;
      }
    } else {
      return root->right != nullptr
          ? trimBST(root->right, low, high)
          : nullptr;
    }
  }
};
