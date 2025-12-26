class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftDepth{0};
    for (TreeNode* node{root->left}; node != nullptr; node = node->left) {
      ++leftDepth;
    }

    int rightDepth{0};
    for (TreeNode* node{root->right}; node != nullptr; node = node->left) {
      ++rightDepth;
    }

    return leftDepth == rightDepth
        ? (1 << leftDepth) + countNodes(root->right)
        : (1 << rightDepth) + countNodes(root->left);
  }
};
