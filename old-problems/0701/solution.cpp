class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    insert(root, val);
    return root;
  }

 private:
  void insert(TreeNode* node, int val) {
    if (val < node->val) {
      if (node->left != nullptr) {
        insert(node->left, val);
      } else {
        node->left = new TreeNode(val);
      }
    } else {
      if (node->right != nullptr) {
        insert(node->right, val);
      } else {
        node->right = new TreeNode(val);
      }
    }
  }
};
