class Solution {
 public:
  int sumRootToLeaf(TreeNode* root) {
    return explore(root, 0);
  }

 private:
  static int explore(TreeNode* node, int val) {
    val = (val << 1) | node->val;
    if (node->left != nullptr) {
      return node->right != nullptr
          ? explore(node->left, val) + explore(node->right, val)
          : explore(node->left, val);
    } else {
      return node->right != nullptr
          ? explore(node->right, val)
          : val;
    }
  }
};
