class Solution {
 public:
  int sumEvenGrandparent(TreeNode* root) {
    return sumNodes(false, false, root);
  }

 private:
  static int sumNodes(bool grandparent, bool parent, TreeNode* node) {
    int sum{grandparent ? node->val : 0};

    if (node->left != nullptr) {
      sum += sumNodes(parent, node->val % 2 == 0, node->left);
    }

    if (node->right != nullptr) {
      sum += sumNodes(parent, node->val % 2 == 0, node->right);
    }

    return sum;
  }
};
