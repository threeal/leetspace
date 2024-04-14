class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    int sum{0};

    if (root->left != nullptr) {
      if (root->left->left == nullptr && root->left->right == nullptr) {
        sum += root->left->val;
      } else {
        sum += sumOfLeftLeaves(root->left);
      }
    }

    if (root->right != nullptr) {
      sum += sumOfLeftLeaves(root->right);
    }

    return sum;
  }
};
