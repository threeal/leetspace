class Solution {
 public:
  int maxProduct(TreeNode* root) {
    searchSum(root);
    return searchMaxProduct(root, 0) % 1000000007;
  }

 private:
  static void searchSum(TreeNode* node) {
    if (node->left != nullptr) {
      searchSum(node->left);
      node->val += node->left->val;
    }

    if (node->right != nullptr) {
      searchSum(node->right);
      node->val += node->right->val;
    }
  }

  static long long searchMaxProduct(TreeNode* node, int prevSum) {
    long long maxProduct{0};

    if (node->left != nullptr) {
      const long long rightSum{prevSum + node->val - node->left->val};
      long long product{(node->left->val * rightSum)};
      if (product > maxProduct) maxProduct = product;

      product = searchMaxProduct(node->left, rightSum);
      if (product > maxProduct) maxProduct = product;
    }

    if (node->right != nullptr) {
      const long long leftSum{prevSum + node->val - node->right->val};
      long long product{(node->right->val * leftSum)};
      if (product > maxProduct) maxProduct = product;

      product = searchMaxProduct(node->right, leftSum);
      if (product > maxProduct) maxProduct = product;
    }

    return maxProduct;
  }
};
