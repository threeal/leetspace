class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    if (root != nullptr) explore(root, 0);
    return root;
  }

 private:
  static int explore(TreeNode* node, int sum) {
    if (node->right != nullptr) {
      sum = explore(node->right, sum);
    }

    sum += node->val;
    node->val = sum;

    if (node->left != nullptr) {
      sum = explore(node->left, sum);
    }

    return sum;
  }
};
