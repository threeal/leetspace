class Solution {
 public:
  TreeNode* bstToGst(TreeNode* root) {
    sumOf(root, 0);
    return root;
  }

  int sumOf(TreeNode* node, int sum) {
    node->val += node->right != nullptr ? sumOf(node->right, sum) : sum;
    return node->left != nullptr ? sumOf(node->left, node->val) : node->val;
  }
};
