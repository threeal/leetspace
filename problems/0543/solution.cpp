class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int max = 0;
    findDiameter(root, max);
    return max;
  }

  int findDiameter(TreeNode* node, int& max) {
    if (node == nullptr) return 0;
    const int left = findDiameter(node->left, max);
    const int right = findDiameter(node->right, max);
    if (left + right > max) max = left + right;
    return 1 + (left > right ? left : right);
  }
};
