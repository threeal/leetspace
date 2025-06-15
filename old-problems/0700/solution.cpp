class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root->val == val) return root;
    if (root->left != nullptr) {
      TreeNode* node{searchBST(root->left, val)};
      if (node != nullptr) return node;
    }
    if (root->right != nullptr) {
      TreeNode* node{searchBST(root->right, val)};
      if (node != nullptr) return node;
    }
    return nullptr;
  }
};
