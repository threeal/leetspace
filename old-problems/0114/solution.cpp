class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root != nullptr) {
      out = &root;
      traverse(root);
    }
  }

 private:
  TreeNode** out;

  void traverse(TreeNode* node) {
    const auto temp = node->right;

    *out = node;
    out = &(node->right);

    if (node->left != nullptr) {
      traverse(node->left);
      node->left = nullptr;
    }

    if (temp != nullptr) traverse(temp);
  }
};
