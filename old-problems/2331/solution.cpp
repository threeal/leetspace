class Solution {
 public:
  bool evaluateTree(TreeNode* root) {
    switch (root->val) {
      case 0:
        return false;

      case 1:
        return true;

      case 2:
        if (evaluateTree(root->left)) return true;
        return evaluateTree(root->right);

      case 3:
        if (!evaluateTree(root->left)) return false;
        return evaluateTree(root->right);
    }

    return 0;
  }
};
