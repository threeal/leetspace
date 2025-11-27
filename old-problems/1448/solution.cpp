class Solution {
 public:
  int goodNodes(TreeNode* root) {
    return search(root, root->val - 1);
  }

 private:
  int search(TreeNode* node, int max) {
    int count{0};

    if (node->val >= max) {
      max = node->val;
      ++count;
    }

    if (node->left != nullptr) count += search(node->left, max);
    if (node->right != nullptr) count += search(node->right, max);

    return count;
  }
};
